//
// Created by student on 27.04.18.
//
#include <fstream>
#include "RunAction.hh"
#include <G4SystemOfUnits.hh>
#include <iostream>
#include <QtCore/qatomic_armv6.h>
#include <G4Run.hh>
using namespace std;


RunAction::RunAction() {
    result = new std::map<G4double, G4int>;
}

RunAction::~RunAction() {
    delete result;
}

void RunAction::BeginOfRunAction(const G4Run* aRun) {
    result->clear();
    box1=0;
    G4int nStep = 100000;
    G4double eMax = 50 * keV;
    for (int i = 0; i < nStep; i++)
        result->insert(std::pair<G4double, G4int>(i*eMax / nStep, 0));
}

void RunAction::EndOfRunAction(const G4Run* aRun) {
    ofstream fout("../result.txt");
    for (auto it: *result){
        fout << it.first << " | " << it.second << '\n';
}
    fout.close();
}


void RunAction::AddEnergy(G4String name,G4double Energy){
   result->lower_bound(Energy)->second++;
    if(name == "box1") {
        box1++;
    }
}