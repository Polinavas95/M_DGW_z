//
// Created by student on 27.04.18.
//
#include <fstream>
#include <G4SIunits.hh>

#include "EventAction.hh"
#include "StepAction.hh"
using namespace std;


EventAction::EventAction(RunAction* runAct) :run(runAct) {
    run=runAct;

}

EventAction::~EventAction() {

}

void EventAction::BeginOfEventAction(const G4Event* anEvent) {
    res=0;
}

void EventAction::EndOfEventAction(const G4Event* anEvent) {
            run->AddEvent(res);
}

void EventAction::Dat(G4double energy){
    res += energy;

}
