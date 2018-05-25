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
    if (step->GetTrack()->GetVolume()->GetName()=="tubs_PV" && gamma!=1){
    event->Dat(step->GetTotalEnergyDeposit());

    }else{
//        if(step->GetTrack()->GetParticleDefinition()->GetParticleName()=="gamma" || step->GetTrack()->GetParentID())
        event->Dat(step->GetTotalEnergyDeposit());
    }

}
StepAction::StepAction() {
    classGammames = new Gammames(this);
}
Gammames::Gammames(StepAction* cls):Gammamesclass(cls) {
    myDir = new G4UIdirectory ("/my_dir/");
    set_new_value = new G4UIcmdWithADouble ("/my_dir/set_new_value", this);
}
void Gammames::SetNewValue(G4UIcommand* cmd, G4String newvalue){
    if (cmd == set_new_value){
        Gammamesclass->SetNewValue(set_new_value -> GetNewDoubleValue(newvalue));
    }
}
Gammames::~Gammames(){
}
void StepAction::SetNewValue(G4double nvalue){
    gamma = nvalue;
}


