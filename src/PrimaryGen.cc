#include <Randomize.hh>
#include <G4Neutron.hh>
#include "PrimaryGen.hh"
PrimaryGen::PrimaryGen() {

    gun = new G4ParticleGun(1);
    gun->SetParticleDefinition(G4Gamma::GammaDefinition());
    gun->SetParticlePosition(G4ThreeVector(30.*cm, 0, 0));
    gun->SetParticleEnergy(4.*keV);
    gun->SetParticleMomentum(G4ThreeVector(0, 1, 0));
}

PrimaryGen::~PrimaryGen(){

 }

void PrimaryGen::GeneratePrimaries(G4Event* anEvent) {
    G4double i=G4UniformRand();

    if(i<=0.4) {
        gun->SetParticleDefinition(G4Gamma::GammaDefinition());
        gun->SetParticlePosition(G4ThreeVector(30.*cm, 0, 0));
        gun->SetParticleEnergy(4.*keV);
        gun->SetParticleMomentum(G4ThreeVector(0, 1, 0));
        gun->GeneratePrimaryVertex(anEvent);
    }
    gun->GeneratePrimaryVertex(anEvent);
}

