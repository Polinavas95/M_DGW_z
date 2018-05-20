//
// Created by student on 27.04.18.
//

#include "StepAction.hh"
#include <G4Step.hh>
#include <StepAction.hh>
#include <G4VProcess.hh>
#include <G4SIunits.hh>

void StepAction::UserSteppingAction(const G4Step* step) {
    if (step->GetTotalEnergyDeposit()&&step->GetTrack()->GetVolume()->GetLogicalVolume()->GetMaterial()->GetName() == "box_LOG"){
      event->AddEnDep(step->GetTrack()->GetVolume()->GetName(),step->GetTotalEnergyDeposit());
    }

}