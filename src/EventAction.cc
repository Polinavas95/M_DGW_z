//
// Created by student on 27.04.18.
//

#include "EventAction.hh"
EventAction::EventAction(RunAction* runAct) :run(runAct) {

}

EventAction::~EventAction() {

}

void EventAction::BeginOfEventAction(const G4Event* anEvent) {
    EnergyDep = 0;
}

void EventAction::EndOfEventAction(const G4Event* anEvent) {
    run->AddEvent(EnergyDep);
}

void EventAction::AddEnDep(G4double en) {
    EnergyDep += en;}
