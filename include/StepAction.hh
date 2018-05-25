//
// Created by student on 27.04.18.
//

#ifndef M_DGW_4_STEPACTION_HH
#define M_DGW_4_STEPACTION_HH


#include <G4UserSteppingAction.hh>
#include <G4UImessenger.hh>
#include <G4UIcmdWithADouble.hh>
#include "EventAction.hh"
class Gammames;
class EventAction;

class StepAction :public G4UserSteppingAction {
public:
   // StepAction(G4double Mel):mel(Mel){};
    //G4double getMel();
    StepAction(EventAction* eventAction) {
        event=eventAction;
       gamma=0;
    };
    StepAction();
    Gammames* classGammames;
    void SetNewValue(G4double nvalue);
    ~StepAction() {};
    void UserSteppingAction(const G4Step* step);
    //void AddEvent (G4double energy);
private:
    G4double gamma;
    EventAction * event;
    //RunAction* tubs;

};
class Gammames : public G4UImessenger{
private:
    StepAction* Gammamesclass;
    G4UIdirectory* myDir;
    G4UIcmdWithADouble* set_new_value;
public:
    Gammames(StepAction* cls);
    ~Gammames();
    void SetNewValue(G4UIcommand* cmd, G4String name);
};

#endif //M_DGW_4_STEPACTION_HH
