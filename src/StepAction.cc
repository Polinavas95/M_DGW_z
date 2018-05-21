//
// Created by student on 27.04.18.
//


#include <fstream>
#include "StepAction.hh"
#include <G4Step.hh>
#include <G4VProcess.hh>
#include <G4SIunits.hh>
using namespace std;

void StepAction::UserSteppingAction(const G4Step* step) {
    if (step->GetTrack()->GetParticleDefinition()->GetParticleName()=="gamma" &&
            step->GetTrack()->GetKineticEnergy()>=4.4)
    event->Dat(step->GetTrack()->GetParticleDefinition()->GetParticleName(),step->GetTrack()->GetKineticEnergy());

//cout<<"Gamma ="<<tubs<<endl;
}
//G4double StepAction::getMel(){
//    return mel;
//}
