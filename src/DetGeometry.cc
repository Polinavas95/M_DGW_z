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

G4Box *box1 = new G4Box("box1", 15.* mm, 15. * mm, 15. * mm);
	auto box1_log = new G4LogicalVolume(box1, nist->FindOrBuildMaterial("G4_POLYETHYLENE"), "box1_LOG");
	box1_log->SetVisAttributes(G4Colour::Red());
	new G4PVPlacement(0, G4ThreeVector(-50.*cm, 0, 0.), box1_log, "box1_PV", logicWorld, false, 0);

	G4Box *box2 = new G4Box("box2", 20.* mm, 20.* mm,20.* mm);
	auto box2_log = new G4LogicalVolume(box2, nist->FindOrBuildMaterial("G4_POLYETHYLENE"), "box2_LOG");
	box2_log->SetVisAttributes(G4Colour::Red());
	new G4PVPlacement(0, G4ThreeVector(-50.*cm, 50.*cm, 0.), box2_log, "box2_PV", logicWorld, false, 0);

	G4Box *box3 = new G4Box("box3", 30.* mm, 30.* mm, 30. * mm);
	auto box3_log = new G4LogicalVolume(box3, nist->FindOrBuildMaterial("G4_POLYETHYLENE"), "box3_LOG");
	box3_log->SetVisAttributes(G4Colour::Red());
	new G4PVPlacement(0, G4ThreeVector(50.*cm, 0, 0.), box3_log, "box_PV", logicWorld, false, 0);

	G4Box *box4 = new G4Box("box4", 45.* mm, 45. * mm, 45.* mm);
	auto box4_log = new G4LogicalVolume(box4, nist->FindOrBuildMaterial("G4_POLYETHYLENE"), "box4_LOG");
	box4_log->SetVisAttributes(G4Colour::Red());
	new G4PVPlacement(0, G4ThreeVector(50.*cm, 50.*cm, 0.), box4_log, "box4_PV", logicWorld, false, 0);


    return physWorld;
}


