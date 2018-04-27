//
// Created by student on 27.04.18.
//

#include "RunAction.hh"
#include <G4SystemOfUnits.hh>
#include <iostream>
#include <QtCore/qatomic_armv6.h>
#include <G4Run.hh>


RunAction::RunAction() {
    result = new std::map<G4double, G4int>;
}

RunAction::~RunAction() {
    delete result;
}

void RunAction::BeginOfRunAction(const G4Run* aRun) {
    result->clear();
    G4int nStep = 500;
    G4double eMax = 5 * MeV;
    for (int i = 0; i < nStep; i++)
        result->insert(std::pair<G4double, G4int>(i*eMax / nStep, 0));
}

void RunAction::EndOfRunAction(const G4Run* aRun) {
    for (auto it: * result)
        std::cout << it.first << " | "<< it.second << '\n';
}

void RunAction::AddEvent(G4double energy) {
    auto it = result->lower_bound(energy);
    it->second++;
}