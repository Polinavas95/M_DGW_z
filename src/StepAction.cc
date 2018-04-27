//
// Created by student on 27.04.18.
//

#include "StepAction.hh"
#include <G4Step.hh>
#include <StepAction.hh>
#include <G4VProcess.hh>
#include <G4SIunits.hh>

void StepAction::UserSteppingAction(const G4Step* step) {
    if (step->GetTrack()->GetVolume()->GetLogicalVolume()->GetMaterial()->GetName() == "box1_LOG"){
        if(step->GetNonIonizingEnergyDeposit(100.*keV))
            event->AddEnDep(step->GetTotalEnergyDeposit());
    }
        event->AddEnDep(step->GetTotalEnergyDeposit());
    if (step->GetTrack()->GetVolume()->GetLogicalVolume()->GetMaterial()->GetName() == "box2_LOG"){
        if(step->GetNonIonizingEnergyDeposit(200.*keV))
            event->AddEnDep(step->GetTotalEnergyDeposit());
    }
        event->AddEnDep(step->GetTotalEnergyDeposit());
    if (step->GetTrack()->GetVolume()->GetLogicalVolume()->GetMaterial()->GetName() == "box3_LOG"){
        if(step->GetNonIonizingEnergyDeposit(500.*keV))
            event->AddEnDep(step->GetTotalEnergyDeposit());
    }
        event->AddEnDep(step->GetTotalEnergyDeposit());
    if (step->GetTrack()->GetVolume()->GetLogicalVolume()->GetMaterial()->GetName() == "box4_LOG"){
        if(step->GetNonIonizingEnergyDeposit(1.*MeV))
            event->AddEnDep(step->GetTotalEnergyDeposit());
    }
      //  event->AddEnDep(step->GetTotalEnergyDeposit());
}