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
    result = new std::map<G4double, G4int>;
    tubs=0;
}

RunAction::~RunAction() {
    delete result;
}

void RunAction::BeginOfRunAction(const G4Run* aRun) {
    result->clear();
    tubs=0;

}

void RunAction::EndOfRunAction(const G4Run* aRun) {
    ofstream fout("../result.txt");
    fout.clear();
    for (auto it: *result){
        fout << it.first << " | " << it.second << '\n';

}
    fout <<"\ngtubs="<<tubs<<endl;
         fout.close();
}


void RunAction::AddEvent(G4String name,G4double Energy){
   result->lower_bound(Energy)->second++;
        tubs++;
}