//
// ********************************************************************
// * License and Disclaimer                                           *
// *                                                                  *
// * The  Geant4 software  is  copyright of the Copyright Holders  of *
// * the Geant4 Collaboration.  It is provided  under  the terms  and *
// * conditions of the Geant4 Software License,  included in the file *
// * LICENSE and available at  http://cern.ch/geant4/license .  These *
// * include a list of copyright holders.                             *
// *                                                                  *
// * Neither the authors of this software system, nor their employing *
// * institutes,nor the agencies providing financial support for this *
// * work  make  any representation or  warranty, express or implied, *
// * regarding  this  software system or assume any liability for its *
// * use.  Please see the license in the file  LICENSE  and URL above *
// * for the full disclaimer and the limitation of liability.         *
// *                                                                  *
// * This  code  implementation is the result of  the  scientific and *
// * technical work of the GEANT4 collaboration.                      *
// * By using,  copying,  modifying or  distributing the software (or *
// * any work based  on the software)  you  agree  to acknowledge its *
// * use  in  resulting  scientific  publications,  and indicate your *
// * acceptance of all terms of the Geant4 Software license.          *
// ********************************************************************
//
// $Id: SimGRBCubeDetectorConstruction.cc 75117 2013-10-28 09:38:37Z gcosmo $
//
/// \file SimGRBCubeDetectorConstruction.cc
/// \brief Implementation of the SimGRBCubeDetectorConstruction class

#include "LXeDetectorConstruction.hh"


// CADMESH //
#include "CADMesh.hh"

#include "G4RunManager.hh"
#include "G4NistManager.hh"
#include "G4Box.hh"
#include "G4Tubs.hh"
#include "G4Cons.hh"
#include "G4Orb.hh"
#include "G4Sphere.hh"
#include "G4Trd.hh"
#include "G4LogicalVolume.hh"
#include "G4PVPlacement.hh"
#include "G4SystemOfUnits.hh"
#include "G4Element.hh"
#include "G4Material.hh"
#include "G4SDManager.hh"
//#include "SimGRBCubeDetectorSD.hh"
#include "G4SubtractionSolid.hh"
#include "G4Trap.hh"
#include "G4Transform3D.hh"
#include "G4AssemblyVolume.hh"
#include "G4UnionSolid.hh"

#include "G4Colour.hh"
#include "G4VisAttributes.hh"

#include "G4GDMLParser.hh"

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

SimGRBCubeDetectorConstruction::SimGRBCubeDetectorConstruction()
: G4VUserDetectorConstruction(),
  fScoringVolume(0)
{ }

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

SimGRBCubeDetectorConstruction::~SimGRBCubeDetectorConstruction()
{ }

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

G4VPhysicalVolume* SimGRBCubeDetectorConstruction::Construct()
{
	// Define materials //

	G4double margin = 0.1*mm;

	G4String matname, symbol;
	G4double a, z, density;

	G4int ncomponents, natoms;
	G4double abundance, fractionmass;
	G4double temperature, pressure;



	G4Element *elH = new G4Element(matname="Hydrogen", "H", 1, 1.00794 *g/mole);
	G4Element* elHe = new G4Element("Helium", "He", 2, 4.002602 *g/mole);
	G4Element* elLi = new G4Element("Lithium", "Li", 3, 6.941 *g/mole);
	G4Element* elBe = new G4Element("Beryllium", "Be", 4, 9.012182 *g/mole);
	G4Element* elB = new G4Element("Boron", "B", 5, 10.811 *g/mole);
	G4Element* elC = new G4Element("Carbon", "C", 6, 12.011 *g/mole);
	G4Element* elN = new G4Element("Nitrogen", "N" , 7, 14.00674 *g/mole);
	G4Element* elO = new G4Element("Oxygen" , "O" , 8,  15.994 *g/mole);
        G4Element* elF = new G4Element("Fluorine", "F", 9, 18.9984032 *g/mole);
	G4Element* elNe = new G4Element("Neon", "Ne", 10, 20.1797 *g/mole);
	G4Element* elNa = new G4Element("Sodium", "Na", 11, 22.989768 *g/mole);
	G4Element* elMg = new G4Element("Magnesium", "Mg", 12, 24.3050 *g/mole);
	G4Element* elAl = new G4Element("Aluminium", "Al", 13, 26.981539 *g/mole);
	G4Element* elSi = new G4Element("Silicon", "Si", 14, 28.0855 *g/mole);
	G4Element* elP = new G4Element("Phosphor", "P" , 15, 30.9738 *g/mole);
	G4Element* elS = new G4Element("Sulfur", "S", 16, 32.066 *g/mole);
	G4Element* elCl = new G4Element("Chlorine", "Cl", 17, 35.4527 *g/mole);
	G4Element* elAr = new G4Element("Argon", "Ar", 18, 39.984 *g/mole);
	G4Element* elK = new G4Element("Potassium", "K", 19, 39.0983 *g/mole);
	G4Element* elCa = new G4Element("Calcium", "Ca", 20, 40.078 *g/mole);
	G4Element* elSc = new G4Element("Scandium", "Sc", 21, 44.955910 *g/mole);
	G4Element* elTi = new G4Element("Titanium", "Ti", 22, 47.867 *g/mole);
	G4Element* elV = new G4Element("Vanadium", "V", 23, 50.9415 *g/mole);
	G4Element* elCr = new G4Element("Chromium", "Cr", 24, 51.9961 *g/mole);
	G4Element* elMn = new G4Element("Manganese", "Mn", 25, 54.93805 *g/mole);
	G4Element* elFe = new G4Element("Iron", "Fe", 26, 55.847 *g/mole);
	G4Element* elCo = new G4Element("Cobalt", "Co", 27, 58.93320 *g/mole);
	G4Element* elNi = new G4Element("Nickel", "Ni", 28, 58.6934 *g/mole);
	G4Element* elCu = new G4Element("Copper", "Cu", 29, 63.546 *g/mole);
	G4Element* elZn = new G4Element("Zinc", "Zn", 30, 65.39 *g/mole);
	G4Element* elGa = new G4Element("Gallium", "Ga", 31, 69.723 *g/mole);
	G4Element* elGe = new G4Element("Germanium", "Ge", 32, 72.61 *g/mole);
	G4Element* elMo = new G4Element("Molybdenum","Mo", 42, 95.94 *g/mole);
	G4Element* elAg = new G4Element("Silver", "Ag", 47, 107.8682 *g/mole);
	G4Element* elCd = new G4Element("Cadmium", "Cd", 48, 112.411 *g/mole);
	G4Element* elSn = new G4Element("Tin", "Sn", 50, 118.710 *g/mole);
	G4Element* elTe = new G4Element("Tellurium", "Te", 52, 127.60 *g/mole);
	G4Element* elI = new G4Element("Iodine", "I", 53, 126.90447 *g/mole);
	G4Element* elCs = new G4Element("Cesium", "Cs", 55, 132.90543 *g/mole);
	G4Element* elBa = new G4Element("Barium", "Ba", 56, 137.327 *g/mole);
	G4Element* elCe = new G4Element("Cerium", "Ce", 58, 140.115 *g/mole);
	G4Element* elGd = new G4Element("Gadolinium","Gd", 64, 157.25 *g/mole);
	G4Element* elPt = new G4Element("Platinum", "Pt", 78, 195.078 *g/mole);
	G4Element* elAu = new G4Element("Gold", "Au", 79, 196.96654 *g/mole);
	G4Element* elHg = new G4Element("Hydrargentum","Hg",80, 200.59 *g/mole);
	G4Element* elPb = new G4Element("Lead", "Pb", 82, 207.19 *g/mole);
	G4Element* elBi = new G4Element("Bismuth", "Bi", 83, 208.98037 *g/mole);

	density = CLHEP::universe_mean_density;
	G4Material *vacuum = new G4Material(matname="Vacuum",density,ncomponents=1);
	vacuum->AddElement(elH,natoms=1);

	density = 1.290 *mg/cm3;
	G4Material *air = new G4Material(matname="Air",density,ncomponents=3);
	air->AddElement(elN, fractionmass=75.575 *perCent);
	air->AddElement(elO, fractionmass=23.143 *perCent);
	air->AddElement(elAr, fractionmass=1.282 *perCent);

	density = 8.83 *g/cm3;
	G4Material *cusnp = new G4Material(matname="CuSNP",density,ncomponents=3);
        cusnp->AddElement(elCu, fractionmass=92.5*perCent);
        cusnp->AddElement(elSn, fractionmass=7.0*perCent);
	cusnp->AddElement(elP, fractionmass=0.5*perCent);

	density = 7.13 *g/cm3;
	G4Material *bgo = new G4Material(matname="BGO",density,ncomponents=3);
        bgo->AddElement(elBi, natoms=4);
        bgo->AddElement(elGe, natoms=3);
	bgo->AddElement(elO, natoms=12);

	density = 2.34 *g/cm3;
	G4Material *si = new G4Material(matname="Si",density,ncomponents=1);
	si->AddElement(elSi,natoms=1);

	density = 2.70 *g/cm3;
	G4Material *al = new G4Material(matname="Al",density, ncomponents=1);
	al->AddElement(elAl, natoms=1);

	density = 11.34 *g/cm3;
	G4Material *pb = new G4Material(matname="Pb",density, ncomponents=1);
	pb->AddElement(elPb, natoms=1);

	density = 7.9 *g/cm3;
	G4Material *sus304 = new G4Material(matname="SUS304", density, ncomponents=5);
	sus304->AddElement(elFe, fractionmass=70.5 *perCent);
	sus304->AddElement(elCr, fractionmass=19.0 *perCent);
	sus304->AddElement(elNi, fractionmass=9.0 *perCent);
	sus304->AddElement(elMn, fractionmass=1.0 *perCent);
	sus304->AddElement(elSi, fractionmass=0.5 *perCent);

	density = 1.2 *g/cm3;   // PolyEtilen
	G4Material *polyethylene = new G4Material(matname="polyethylene", density, ncomponents=2);
	polyethylene->AddElement(elC, natoms=1);
	polyethylene->AddElement(elH, natoms=2);

	// Al diecast (ADC10)
	density = 2.70 *g/cm3;
	G4Material *aldiecast = new G4Material(matname="aldiecast",density, ncomponents=11);
	aldiecast->AddElement(elCu, fractionmass=4.0 *perCent);
	aldiecast->AddElement(elSi, fractionmass=9.5 *perCent);
	aldiecast->AddElement(elMg, fractionmass=0.3 *perCent);
	aldiecast->AddElement(elZn, fractionmass=1.0 *perCent);
	aldiecast->AddElement(elFe, fractionmass=1.3 *perCent);
	aldiecast->AddElement(elMn, fractionmass=0.5 *perCent);
	aldiecast->AddElement(elNi, fractionmass=0.5 *perCent);
	aldiecast->AddElement(elSn, fractionmass=0.2 *perCent);
	aldiecast->AddElement(elPb, fractionmass=0.2 *perCent);
	aldiecast->AddElement(elTi, fractionmass=0.2 *perCent);
	aldiecast->AddElement(elAl, fractionmass=82.3 *perCent);

	//CsI(Tl)
        density = 4.53*g/cm3;
        G4Material *CsI = new G4Material(matname="CsI" , density , ncomponents=2);
        CsI->AddElement(elCs ,fractionmass=1./2.);
        CsI->AddElement(elI ,fractionmass=1./2.);

	// (PET)
	density = 1.38 *g/cm3;
	G4Material *PET = new G4Material(matname="PET", density, ncomponents=3);
	PET->AddElement(elC, natoms=10);
	PET->AddElement(elH, natoms=8);
	PET->AddElement(elO, natoms=4);


	// CFRP
	density = 2.0 *g/cm3;
	G4Material *CFRP = new G4Material(matname="CFRP",density,ncomponents=3);
	CFRP->AddElement(elC, fractionmass=89.5 *perCent);
	CFRP->AddElement(elH, fractionmass=3.1 *perCent);
	CFRP->AddElement(elO, fractionmass=7.4 *perCent);

	//Aluminum 6061-T6
	density = 2.70 *g/cm3;
	G4Material* Aluminum_6061_T6 = new G4Material(matname="Aluminum_6061_T6",density,ncomponents=5);
	Aluminum_6061_T6->AddElement(elAl, fractionmass=96.90 *perCent);
	Aluminum_6061_T6->AddElement(elMg, fractionmass=1.20 *perCent);
	Aluminum_6061_T6->AddElement(elSi, fractionmass=0.80 *perCent);
	Aluminum_6061_T6->AddElement(elFe, fractionmass=0.70 *perCent);
	Aluminum_6061_T6->AddElement(elCu, fractionmass=0.40 *perCent);

	//Aluminum 7075-T73
	density = 2.81 *g/cm3;
	G4Material* Aluminum_7075_T73 = new G4Material(matname="Aluminum_7075_T73",density,ncomponents=5);
	Aluminum_7075_T73->AddElement(elAl, fractionmass=88.60 *perCent);
	Aluminum_7075_T73->AddElement(elZn, fractionmass=6.10 *perCent);
	Aluminum_7075_T73->AddElement(elMg, fractionmass=2.90 *perCent);
	Aluminum_7075_T73->AddElement(elCu, fractionmass=2.00 *perCent);
	Aluminum_7075_T73->AddElement(elSi, fractionmass=0.40 *perCent);

	//Stainless Steel A2-70 AlSl304
	density = 8.0 *g/cm3;
	G4Material* STS_A2_70 = new G4Material(matname="STS_A2_70",density,ncomponents=5);
	STS_A2_70->AddElement(elFe, fractionmass=66.50 *perCent);
	STS_A2_70->AddElement(elCr, fractionmass=20.0 *perCent);
	STS_A2_70->AddElement(elNi, fractionmass=10.5 *perCent);
	STS_A2_70->AddElement(elMn, fractionmass=2.00 *perCent);
	STS_A2_70->AddElement(elSi, fractionmass=1.00 *perCent);

	// Glass Borsillicate N-BK7
	density = 2.51 *g/cm3;
	G4Material* Glass_Borsillicate = new G4Material(matname="Glass_Borsillicate",density,ncomponents=4);
	Glass_Borsillicate->AddElement(elSi, fractionmass=42.10 *perCent);
	Glass_Borsillicate->AddElement(elO, fractionmass=54.80 *perCent);
	Glass_Borsillicate->AddElement(elB, fractionmass=3.10 *perCent);

	// Glass Epoxy FR4
	density = 1.85 *g/cm3;
	G4Material* Glass_Epoxy = new G4Material(matname="Glass_Epoxy",density,ncomponents=4);
	Glass_Epoxy->AddElement(elSi, fractionmass=23.39 *perCent);
	Glass_Epoxy->AddElement(elO, fractionmass=36.02 *perCent);
	Glass_Epoxy->AddElement(elC, fractionmass=37.04 *perCent);
	Glass_Epoxy->AddElement(elH, fractionmass=3.55 *perCent);

	// Brass Generic
	density = 8.5 *g/cm3;
	G4Material* Brass = new G4Material(matname="Brass",density,ncomponents=2);
	Brass->AddElement(elCu, fractionmass=85.00 *perCent);
	Brass->AddElement(elZn, fractionmass=15.00 *perCent);

	//Solar Panel
	density = 4.16 *g/cm3;
	G4Material* SAP = new G4Material(matname="SAP",density,ncomponents=6);
	SAP->AddElement(elGe, fractionmass=38.00 *perCent);
	SAP->AddElement(elSi, fractionmass=24.00 *perCent);
	SAP->AddElement(elO, fractionmass=20.00 *perCent);
	SAP->AddElement(elC, fractionmass=13.00 *perCent);
	SAP->AddElement(elH, fractionmass=4.00 *perCent);
	SAP->AddElement(elB, fractionmass=1.00 *perCent);

//LiFePO4 battery
density = 2.35 *g/cm3;
G4Material* LiFePO4 = new G4Material(matname="LiFePO4",density,ncomponents=4);
LiFePO4->AddElement(elLi, natoms=1);
LiFePO4->AddElement(elFe, natoms=1);
LiFePO4->AddElement(elP, natoms=1);
LiFePO4->AddElement(elO, natoms=4);



	G4bool surfaceCheck = true;


	// Local World //////////////////////

	G4double LocalWorld_xSize = 1000.0*cm;
//		G4double LocalWorld_xSize = 800.0*mm;
	G4double LocalWorld_ySize = 1000.0*cm;
	//    G4double LocalWorld_ySize = 800.0*mm;
	G4double LocalWorld_zSize = 1000.0*cm;
	//	G4double LocalWorld_zSize = 800.0*mm;
	G4VSolid* LocalWorld_Solid = new G4Box("LocalWorld_Solid", LocalWorld_xSize*0.5, LocalWorld_ySize*0.5, LocalWorld_zSize*0.5);
	G4LogicalVolume* LocalWorld_Logical = new G4LogicalVolume(LocalWorld_Solid, vacuum, "LocalWorld_Logical");
	G4VPhysicalVolume* LocalWorld_Physical = new  G4PVPlacement(0,G4ThreeVector(0,0,0),LocalWorld_Logical,"World",0,false,0,surfaceCheck);

	G4VisAttributes* worldattributes = new G4VisAttributes();
	worldattributes->SetVisibility(false);
	LocalWorld_Logical->SetVisAttributes(worldattributes);

// Containeer of whole structure to put them into world center
G4double AssemblyGRBAlphaSize = 25*cm;
G4VSolid* SolidAssemblyGRBAlpha = new G4Box("AssemblyGRBAlpha",AssemblyGRBAlphaSize/2.0,AssemblyGRBAlphaSize/2.0,AssemblyGRBAlphaSize/2.0);
G4LogicalVolume* LogicAssemblyGRBAlpha = new G4LogicalVolume(SolidAssemblyGRBAlpha, vacuum, "LogicAssemblyGRBAlpha");
G4VPhysicalVolume* PhysAssemblyGRBAlpha = new G4PVPlacement(0,G4ThreeVector(-5*cm,5*cm,-5*cm),LogicAssemblyGRBAlpha,"GRBAlphaAssembly",LocalWorld_Logical,false,0,surfaceCheck);
LogicAssemblyGRBAlpha->SetVisAttributes(worldattributes);
	// GRBCube Satellite Body imported from CAD STL file with CADMESH //

	// Load CAD file as tessellated solid //
		std::string CADFile_Basedir = "/massalia2/ohno/exp/GRBCube/Simulation/CADtoGDML/GRBAlpha/";
 	G4ThreeVector offset(0,0,0);
  std::string cadfile=CADFile_Basedir+"1U_skelton_onlyframe.stl";
  CADMesh *mesh = new CADMesh((char*)cadfile.c_str(), mm, offset, false);
  skelton_frame_cad_solid = mesh->TessellatedMesh();
  skelton_frame_cad_logic = new G4LogicalVolume(skelton_frame_cad_solid, Aluminum_7075_T73, "skelton_frame_logic", 0, 0, 0);


  cadfile = CADFile_Basedir+"base_v3.stl";
  CADMesh *mesh2 = new CADMesh((char*)cadfile.c_str(), mm, offset, false);
  casingBtm_cad_solid = mesh2->TessellatedMesh();
  casingBtm_cad_logic = new G4LogicalVolume(casingBtm_cad_solid, Aluminum_7075_T73, "casingBtm_logic", 0, 0, 0);
    cadfile = CADFile_Basedir+"top_v2_stp1_01.stl";
  CADMesh *mesh21 = new CADMesh((char*)cadfile.c_str(), mm, offset, false);
  casingTop_cad_solid = mesh21->TessellatedMesh();
  casingTop_cad_logic = new G4LogicalVolume(casingTop_cad_solid, Aluminum_7075_T73, "casingTop_logic", 0, 0, 0);

  cadfile = CADFile_Basedir+"pb_cover_full.stl";
  CADMesh *mesh3 = new CADMesh((char*)cadfile.c_str(), mm, offset, false);
  Pbshield_cad_solid = mesh3->TessellatedMesh();
  Pbshield_cad_logic = new G4LogicalVolume(Pbshield_cad_solid, pb, "Pbshield_logic", 0, 0, 0);


//Pb shield hand-maid (since CAD file is too complicated to avoid a geometry overlapping..)
// For top/btm layer
G4double PbshieldXLength = 78.0*mm;
G4double PbshieldYLength = 12.5*mm;
G4double PbshieldZLength = 13.0*mm;
G4double PbshieldThickness = 2.50*mm;
G4Box *SolidPbshieldTopBtm = new G4Box("PbshieldTopBtm",PbshieldXLength/2, PbshieldYLength/2, PbshieldThickness/2);
G4LogicalVolume *LogicPbshieldTopBtm = new G4LogicalVolume(SolidPbshieldTopBtm, pb, "PbshieldTopBtm_Logic",0,0,0);

// For side layer
G4Box *SolidPbshieldSide = new G4Box("PbshieldSide",PbshieldThickness/2, PbshieldYLength/2, PbshieldZLength/2);
G4LogicalVolume *LogicPbshieldSide = new G4LogicalVolume(SolidPbshieldSide, pb, "PbshieldSide_Logic",0,0,0);

// FOr back layer
G4double PbshieldBackLayerThickness = 0.5*mm;
G4Box *SolidPbshieldBackLayer = new G4Box("PbshieldBacklayer",(PbshieldXLength+PbshieldThickness*2)/2, PbshieldBackLayerThickness/2, PbshieldZLength/2);
G4LogicalVolume *LogicPbshieldBackLayer = new G4LogicalVolume(SolidPbshieldBackLayer, pb, "PbshieldBackLayer_Logic",0,0,0);

// Upper Rib
//G4double PbshieldRibThickness = 2.0*mm;
G4double PbshieldRibThickness = 0.5*mm;
G4double PbshieldUpperRibZLength = 4.80*mm;
G4Box *SolidPbshieldUpperRib = new G4Box("PbshieldUpperRib", (PbshieldXLength+PbshieldThickness*2)/2, PbshieldRibThickness/2, PbshieldUpperRibZLength/2);
G4LogicalVolume *LogicPbshieldUpperRib = new G4LogicalVolume(SolidPbshieldUpperRib, pb, "PbshieldUpperRib_Logic",0,0,0);
// Lower Rib

G4double PbshieldLowerRibZLength = 5.30*mm;
G4double PbshieldLowerRibXLength = 70.4*mm;
G4Box *SolidPbshieldLowerRib = new G4Box("PbshieldLowerRib", PbshieldLowerRibXLength/2, PbshieldRibThickness/2, PbshieldLowerRibZLength/2);
G4LogicalVolume *LogicPbshieldLowerRib = new G4LogicalVolume(SolidPbshieldLowerRib, pb, "PbshieldLowerRib_Logic",0,0,0);


// Test Assenmbly
/*
new G4PVPlacement(0,G4ThreeVector(0,0,PbshieldZLength/2-PbshieldThickness/2),LogicPbshieldTopBtm,"PbshieldTop",LocalWorld_Logical,false,0,surfaceCheck);
new G4PVPlacement(0,G4ThreeVector(0,0,-PbshieldZLength/2+PbshieldThickness/2),LogicPbshieldTopBtm,"PbshieldBtm",LocalWorld_Logical,false,1,surfaceCheck);
new G4PVPlacement(0,G4ThreeVector(PbshieldXLength/2+PbshieldThickness/2,0,0),LogicPbshieldSide,"PbshieldSide",LocalWorld_Logical,false,0,surfaceCheck);
new G4PVPlacement(0,G4ThreeVector(-PbshieldXLength/2-PbshieldThickness/2,0,0),LogicPbshieldSide,"PbshieldSide",LocalWorld_Logical,false,1,surfaceCheck);
new G4PVPlacement(0,G4ThreeVector(0,PbshieldYLength/2+PbshieldBackLayerThickness/2,0),LogicPbshieldBackLayer,"PbshieldBack",LocalWorld_Logical,false,1,surfaceCheck);
new G4PVPlacement(0,G4ThreeVector(0,(PbshieldYLength+PbshieldBackLayerThickness*2)/2+PbshieldRibThickness/2,(PbshieldZLength-PbshieldUpperRibZLength)/2),LogicPbshieldUpperRib,"PbshieldUpperRib",LocalWorld_Logical,false,1,surfaceCheck);
new G4PVPlacement(0,G4ThreeVector(0,(PbshieldYLength+PbshieldBackLayerThickness*2)/2+PbshieldRibThickness/2,-(PbshieldZLength-PbshieldLowerRibZLength)/2),LogicPbshieldLowerRib,"PbshieldLowerRib",LocalWorld_Logical,false,1,surfaceCheck);
*/

// G4UnionSolid for Pb shield
G4VSolid *solid_union = new G4UnionSolid("union",SolidPbshieldTopBtm,SolidPbshieldTopBtm,0,G4ThreeVector(0,0,PbshieldZLength-PbshieldThickness));
G4VSolid *solid_union2 = new G4UnionSolid("union2",solid_union,SolidPbshieldSide,0,G4ThreeVector(PbshieldXLength/2+PbshieldThickness/2,0,(PbshieldZLength-PbshieldThickness)/2));
G4VSolid *solid_union3 = new G4UnionSolid("union3",solid_union2,SolidPbshieldSide,0,G4ThreeVector(-(PbshieldXLength/2+PbshieldThickness/2),0,(PbshieldZLength-PbshieldThickness)/2));
G4VSolid *solid_union4 = new G4UnionSolid("union4",solid_union3,SolidPbshieldBackLayer,0,G4ThreeVector(0,PbshieldYLength/2+PbshieldBackLayerThickness/2,(PbshieldZLength-PbshieldThickness)/2));
G4VSolid *solid_union5 = new G4UnionSolid("union5",solid_union4,SolidPbshieldUpperRib,0,G4ThreeVector(0,(PbshieldYLength+PbshieldBackLayerThickness*2)/2+PbshieldRibThickness/2,(PbshieldZLength-PbshieldUpperRibZLength)/2+(PbshieldZLength-PbshieldThickness)/2));
G4VSolid *SolidUnionPbShield = new G4UnionSolid("SolidUnionPbShield",solid_union5,SolidPbshieldLowerRib,0,G4ThreeVector(0,(PbshieldYLength+PbshieldBackLayerThickness*2)/2+PbshieldRibThickness/2,-(PbshieldZLength-PbshieldLowerRibZLength)/2+(PbshieldZLength-PbshieldThickness)/2));

G4LogicalVolume *LogicUnionPbshield = new G4LogicalVolume(SolidUnionPbShield,pb,"UnionPbShield_logic",0,0,0);



G4double FrameXSize = 100.0*mm;
G4double CasingYsize = 91.8*mm;


G4double PbshieldZsize = PbshieldThickness*2;
G4double PbshieldZoffset = 10.0*mm;
G4double FrameRibOffset = 7.55*mm;
G4double CasingTopZsize = 1.0*mm;
G4double CasingBtmZsize = 7.0*mm;
G4double CasingScrewPadWidth = 3.0*mm;
G4double CasingTopZoffset = FrameRibOffset-CasingScrewPadWidth;
G4double CasingBtmZoffset = CasingTopZoffset+CasingTopZsize;
G4double CasingZsize = CasingTopZsize+CasingBtmZsize;
G4RotationMatrix *rotpbshield = new G4RotationMatrix();
rotpbshield->rotateX(180*deg);
//G4double temporal_caseZoffset = 9.0*mm; //addtinal offset to prevent geometry overlapping
G4double temporal_caseZoffset = 0*mm; //addtinal offset to prevent geometry overlapping
G4ThreeVector CasingBtmOffset = G4ThreeVector(FrameXSize/2,-CasingYsize/2-1*mm,CasingBtmZoffset);
//G4ThreeVector CasingTopOffset = G4ThreeVector(FrameXSize/2,-CasingYsize/2,FrameRibOffset-CasingTopZsize-temporal_caseZoffset);
G4ThreeVector CasingTopOffset = G4ThreeVector(FrameXSize/2,-CasingYsize/2,CasingTopZoffset);
G4ThreeVector PbshieldOffset = G4ThreeVector(CasingBtmOffset.x(),CasingBtmOffset.y()*2-(-7.300000)*mm,CasingBtmOffset.z()+CasingZsize/2-2.0*mm+(PbshieldZLength-PbshieldThickness)/2);


  new G4PVPlacement(0, G4ThreeVector(0,0,0), skelton_frame_cad_logic, "skelton_frame_phys", LogicAssemblyGRBAlpha, false, 0, surfaceCheck);
  new G4PVPlacement(0, CasingTopOffset, casingTop_cad_logic, "casingTop_phys", LogicAssemblyGRBAlpha, false, 0, surfaceCheck);
    new G4PVPlacement(0, CasingBtmOffset, casingBtm_cad_logic, "casingBtm_phys", LogicAssemblyGRBAlpha, false, 0, surfaceCheck);
//  new G4PVPlacement(rotpbshield, G4ThreeVector(FrameXSize/2,-CasingYsize-0.7*mm,CasingZsize/2-2.0*mm+FrameRibOffset/2), Pbshield_cad_logic, "Pbshield_phys", LogicAssemblyGRBAlpha, false, 0, surfaceCheck);
//  new G4PVPlacement(rotpbshield, PbshieldOffset, Pbshield_cad_logic, "Pbshield_phys", LogicAssemblyGRBAlpha, false, 0, surfaceCheck);
new G4PVPlacement(rotpbshield,PbshieldOffset,LogicUnionPbshield,"Pbshield",LogicAssemblyGRBAlpha,false,0,surfaceCheck);



	G4double scintisizeX = 75*mm;
	G4double scintisizeY = 75*mm;
	G4double scintisizeZ = 5*mm;
  G4double scintiCasingOffset = 1.5*mm;
  G4double CasingXoffset = 0;
  G4double CasingYoffset = 0;
  G4double CasingZoffset = 0;
G4ThreeVector offsetDet0(CasingBtmOffset.x(),CasingBtmOffset.y()+scintiCasingOffset,CasingBtmOffset.z()+scintisizeZ/2);
	//CsI scintillator
	G4Box *SolidScinti0 = new G4Box("SolidScinti0",scintisizeX/2, scintisizeY/2, scintisizeZ/2);
	G4LogicalVolume *LogicScinti0 = new G4LogicalVolume(SolidScinti0, CsI, "LogicScinti0");
    	new G4PVPlacement(0,offsetDet0, LogicScinti0, "Scintillator0",LogicAssemblyGRBAlpha, false, 0, surfaceCheck);
G4VisAttributes *visDet = new G4VisAttributes();
visDet->SetColor(0,174,239,0.1);
visDet->SetForceSolid(true);
LogicScinti0->SetVisAttributes(visDet);

  //dummy PCBs;
  G4double PCBAssemblySizeX = 80*mm; //96*mm is real value, this is just for preventing overlapp...
  G4double PCBAssemblySizeY = 80*mm;
  G4double PCBAssemblyHeight = 16.5*mm;
  G4double PCBAssemblyHeight_forBAT = 22.0*mm;
  G4double PCBSizeZ = 1.6*mm;

//mother volume
G4Box *SolidPCBAssembly = new G4Box("SolidPCBAssembly",PCBAssemblySizeX/2,PCBAssemblySizeY/2,PCBAssemblyHeight/2);
G4LogicalVolume *LogicPCBAssembly = new G4LogicalVolume(SolidPCBAssembly,vacuum,"LogicPCBAssembly");
// PCB layer with battery
G4Box *SolidPCBAssemblyBAT = new G4Box("SolidPCBAssemblyBAT",PCBAssemblySizeX/2,PCBAssemblySizeY/2,PCBAssemblyHeight_forBAT/2);
G4LogicalVolume *LogicPCBAssemblywithBAT = new G4LogicalVolume(SolidPCBAssemblyBAT,vacuum,"LogicPCBAssemblywithBAT");
G4VisAttributes *visPCBAssembly = new G4VisAttributes();
visPCBAssembly->SetVisibility(false);
LogicPCBAssembly->SetVisAttributes(visPCBAssembly);
LogicPCBAssemblywithBAT->SetVisAttributes(visPCBAssembly);

//Contents
//PCB Body
G4Box *SolidPCBBody = new G4Box("SolidPCBBody",PCBAssemblySizeX/2, PCBAssemblySizeY/2,PCBSizeZ/2);
G4LogicalVolume *LogicPCBBody = new G4LogicalVolume(SolidPCBBody,Glass_Epoxy,"LogicPCBBody");
new G4PVPlacement(0,G4ThreeVector(0,0,-PCBAssemblyHeight/2+PCBSizeZ/2),LogicPCBBody,"PCBBody",LogicPCBAssembly,false,0,surfaceCheck);
new G4PVPlacement(0,G4ThreeVector(0,0,-PCBAssemblyHeight_forBAT/2+PCBSizeZ/2),LogicPCBBody,"PCBBody",LogicPCBAssemblywithBAT,false,0,surfaceCheck);
//Spacers
G4double SpacerRadius = 3.0*mm;
G4double SpacerHeight = PCBAssemblyHeight-PCBSizeZ;
G4double SpacerHeight_forBAT = PCBAssemblyHeight_forBAT-PCBSizeZ;
G4Tubs *SolidPCBSpacers = new G4Tubs("SolidPCBSpacers",0,SpacerRadius/2.0,SpacerHeight/2,0,360*deg);
G4LogicalVolume *LogicPCBSpacers = new G4LogicalVolume(SolidPCBSpacers,sus304,"LogicPCBSpacers");
G4Tubs *SolidPCBSpacersBAT = new G4Tubs("SolidPCBSpacersBAT",0,SpacerRadius/2.0,SpacerHeight_forBAT/2,0,360*deg);
G4LogicalVolume *LogicPCBSpacersBAT = new G4LogicalVolume(SolidPCBSpacersBAT,sus304,"LogicPCBSpacersBAT");
G4double spacer_offset = PCBAssemblySizeX/2-SpacerRadius;
G4double zoffset = -PCBAssemblyHeight/2+PCBSizeZ+SpacerHeight/2;
  G4ThreeVector vec_offset(0,0,0);

//Lithium ion battery APR18650
G4double BAT_radius = 18.2*mm;
G4double BAT_height = 65.0*mm;
G4Tubs *solidBAT = new G4Tubs("solidBAT",0,BAT_radius/2.0,BAT_height/2.0,0,360*deg);
G4LogicalVolume *logicBAT = new G4LogicalVolume(solidBAT,LiFePO4,"LogicBAT");

for (int i=0; i<4; ++i){
if ( i == 0 )  vec_offset = G4ThreeVector(spacer_offset,spacer_offset,zoffset);
else if ( i == 1 ) vec_offset = G4ThreeVector(-spacer_offset,spacer_offset,zoffset);
else if ( i == 2 ) vec_offset = G4ThreeVector(spacer_offset,-spacer_offset,zoffset);
else if ( i == 3 ) vec_offset = G4ThreeVector(-spacer_offset,-spacer_offset,zoffset);

  new G4PVPlacement(0,vec_offset,LogicPCBSpacers,"PCBSpacers",LogicPCBAssembly,false,i,surfaceCheck);
  new G4PVPlacement(0,vec_offset,LogicPCBSpacersBAT,"PCBSpacersBAT",LogicPCBAssemblywithBAT,false,i,surfaceCheck);
}


G4RotationMatrix *rotBAT = new G4RotationMatrix();
rotBAT->rotateX(90*deg);
new G4PVPlacement(rotBAT,G4ThreeVector(2.5*cm,PCBSizeZ/2),logicBAT, "bat1",LogicPCBAssemblywithBAT,false,0,surfaceCheck);
new G4PVPlacement(rotBAT,G4ThreeVector(-2.5*cm,PCBSizeZ/2),logicBAT, "bat2",LogicPCBAssemblywithBAT,false,1,surfaceCheck);

//Placement PCB assembly
G4int num_of_PCBs = 4;
G4int center_of_PCBs = (int)num_of_PCBs/2;
G4double PCBAssembly_Zoffset=30*mm;
char assemblyname[256];
for (int i=0; i<num_of_PCBs; ++i){
  sprintf(assemblyname,"PCBAssembly%d",i);
  if ( i != center_of_PCBs ){
 new G4PVPlacement(0,G4ThreeVector(CasingBtmOffset.x(),CasingBtmOffset.y(),PCBAssembly_Zoffset),LogicPCBAssembly,assemblyname,LogicAssemblyGRBAlpha,false,i,surfaceCheck);
PCBAssembly_Zoffset+=PCBAssemblyHeight;
}
else{
  PCBAssembly_Zoffset-=PCBAssemblyHeight;
  PCBAssembly_Zoffset+=(PCBAssemblyHeight+PCBAssemblyHeight_forBAT)/2;
 new G4PVPlacement(0,G4ThreeVector(CasingBtmOffset.x(),CasingBtmOffset.y(),PCBAssembly_Zoffset),LogicPCBAssemblywithBAT,assemblyname,LogicAssemblyGRBAlpha,false,i,surfaceCheck);
PCBAssembly_Zoffset+=(PCBAssemblyHeight+PCBAssemblyHeight_forBAT)/2;
}
}



	// define sensitive detector
	//G4SDManager* SDmanager = G4SDManager::GetSDMpointer();
	//SimGRBCubeDetectorSD * detsd = new SimGRBCubeDetectorSD("/simpledetector");
	//SDmanager->AddNewDetector(detsd);
	//LogicScinti0->SetSensitiveDetector(detsd);
	//LogicBox->SetSensitiveDetector(detsd);

	return LocalWorld_Physical;
}


// For Compton Camera Geometry
