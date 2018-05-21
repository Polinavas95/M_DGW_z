#include <G4VisAttributes.hh>
#include "DetGeometry.hh"
#include "G4Tubs.hh"
#include "G4PhysicalConstants.hh"
DetGeometry::DetGeometry() {
    world_sizeXYZ   = 5 * m;
    nist            = G4NistManager::Instance();
    world_mat       = nist->FindOrBuildMaterial("G4_AIR");

    solidWorld      = new G4Box("solWorld", 0.5*world_sizeXYZ, 0.5*world_sizeXYZ, 0.5*world_sizeXYZ);
    logicWorld      = new G4LogicalVolume(solidWorld, world_mat, "logWorld");
    physWorld       = new G4PVPlacement(0, G4ThreeVector(), logicWorld, "phyWorld", 0, false, 0);
    G4cout<<"Geometry of detector is build successfully\t\t\t\t\t\tOK!!!"<<G4endl;
}

DetGeometry::~DetGeometry() {}

G4VPhysicalVolume* DetGeometry::Construct(){

G4Box *box = new G4Box("box1", 5.* cm, 5. * cm, 5. * cm);
	auto box_log = new G4LogicalVolume(box, nist->FindOrBuildMaterial("G4_C"), "box1_LOG");
	box_log->SetVisAttributes(G4Colour::Red());
	new G4PVPlacement(0, G4ThreeVector(0, 0, 0.), box_log, "box1_PV", logicWorld, false, 0);

G4Tubs *tubs = new G4Tubs("tubs",0,7.6*cm,6.5*cm,0,2*pi);
    auto tubs_log = new G4LogicalVolume(tubs, nist->FindOrBuildMaterial("G4_BGO"), "tubs_LOG");
    //tubs_log->SetVisAttributes(G4Colour::Red());
    new G4PVPlacement(0, G4ThreeVector(15*cm,0, 0), tubs_log, "tubs_PV", logicWorld, false, 0);


    return physWorld;
}


