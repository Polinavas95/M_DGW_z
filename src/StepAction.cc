//
// Created by student on 27.04.18.
//

#include "StepAction.hh"
#include <G4Step.hh>
#include <G4VProcess.hh>


void StepAction::UserSteppingAction(const G4Step* step) {
    if (step->GetTrack()->GetTrackID()){
      event->AddEvent(step->GetTrack()->GetVolume()->GetName(),step->GetTotalEnergyDeposit());
    }
    mel=step->GetTrack()->GetTrackID();
}
G4double StepAction::getMel(){
    return mel;
}
