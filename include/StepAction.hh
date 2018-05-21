//
// Created by student on 27.04.18.
//

#ifndef M_DGW_4_STEPACTION_HH
#define M_DGW_4_STEPACTION_HH


#include <G4UserSteppingAction.hh>
#include "EventAction.hh"

class EventAction;

class StepAction :public G4UserSteppingAction {
public:
   // StepAction(G4double Mel):mel(Mel){};
    //G4double getMel();
    StepAction(EventAction* eventAction) {
        event=eventAction;
    };
    ~StepAction() {};
    void UserSteppingAction(const G4Step* step);

private:
   // G4double mel;
    EventAction * event;
    RunAction* tubs;

};

#endif //M_DGW_4_STEPACTION_HH
