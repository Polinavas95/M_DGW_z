//
// Created by student on 27.04.18.
//
#include <fstream>
#include "RunAction.hh"
#include <G4SystemOfUnits.hh>
#include <iostream>

#include <G4Run.hh>
using namespace std;


RunAction::RunAction() {
    result=new std::map<G4double ,G4int>;
}

RunAction::~RunAction() {
    delete result;
}

void RunAction::BeginOfRunAction(const G4Run* aRun) {
    result->clear();
    int nStep=500;
    G4double eMax=14.*MeV;
    for(int i=0;i<nStep;i++){
        result->insert(std::pair<G4double,G4int>(i*eMax/nStep,0));
    }


}

void RunAction::EndOfRunAction(const G4Run* aRun) {
    for (auto &it: *result){
        cout << it.first << " | " << it.second << '\n';

    }
}
void RunAction::AddEvent(G4double Energy){
    result->lower_bound(Energy)->second++;
}

