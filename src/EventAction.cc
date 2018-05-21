//
// Created by student on 27.04.18.
//
#include <fstream>
#include <G4SIunits.hh>

#include "EventAction.hh"
#include "StepAction.hh"
using namespace std;
//class StepAction;
StepAction obj();

EventAction::EventAction(RunAction* runAct) :run(runAct) {
    run=runAct;
    res=new map<G4String, G4double>;
}

EventAction::~EventAction() {

}

void EventAction::BeginOfEventAction(const G4Event* anEvent) {
}

void EventAction::EndOfEventAction(const G4Event* anEvent) {

    ofstream fout("../result.txt",ios_base::app); //Автоматически переставляет указатель текущего символа потока в конец
    fout.clear();
    for (auto it: *res) {
        fout << it.first << " | " << it.second << "\n";
        if((it.first == "gamma") && (it.second >=4.4*MeV)) {
            run->AddEvent(it.first, it.second);
           // cout<<"gammaEn= "<<it.second<<endl;
        }
    }
}

void EventAction::Dat(G4String Name,G4double energy){
    if( res->find(Name) == res->end()) {
        res->emplace(Name, energy);//функция принимает параметры, которые будут перенаправлены конструктору объекта, хранящегося в контейнере
    }
    res->find(Name)->second += energy;
}
