#include <Randomize.hh>
#include <G4Neutron.hh>
#include "PrimaryGen.hh"
PrimaryGen::PrimaryGen() {
    gun = new G4ParticleGun(1);


    gun->SetParticleDefinition(G4Neutron::NeutronDefinition());
    gun->SetParticlePosition(G4ThreeVector(0, 0, 0));
    gun->SetParticleEnergy(5 *MeV);
}

PrimaryGen::~PrimaryGen(){

 }

void PrimaryGen::GeneratePrimaries(G4Event* anEvent) {
    gun->SetParticleMomentum(G4ThreeVector(0,0,0));

    gun->GeneratePrimaryVertex(anEvent);
}
