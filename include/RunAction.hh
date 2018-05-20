//
// Created by student on 27.04.18.
//

#ifndef M_DGW_4_RUNACTION_HH
#define M_DGW_4_RUNACTION_HH


#include <G4UserRunAction.hh>
#include <map>

class RunAction : public G4UserRunAction {
public:
    RunAction();
    ~RunAction();
    void BeginOfRunAction(const G4Run* aRun);
    void EndOfRunAction(const G4Run* aRun);
    void AddEvent(G4double energy);

private:
    std::map<G4double, G4int>* result;
    G4double box1;
};

#endif //M_DGW_4_RUNACTION_HH
