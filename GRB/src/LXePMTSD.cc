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
// $Id: LXePMTSD.cc 73915 2013-09-17 07:32:26Z gcosmo $
//
/// \file optical/LXe/src/LXePMTSD.cc
/// \brief Implementation of the LXePMTSD class
//
//
#include "LXePMTSD.hh"
#include "LXePMTHit.hh"
#include "LXeDetectorConstruction.hh"
#include "LXeUserTrackInformation.hh"

#include "G4VPhysicalVolume.hh"
#include "G4LogicalVolume.hh"
#include "G4Track.hh"
#include "G4Step.hh"
#include "G4VTouchable.hh"
#include "G4TouchableHistory.hh"
#include "G4ios.hh"
#include "G4ParticleTypes.hh"
#include "G4ParticleDefinition.hh"

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

LXePMTSD::LXePMTSD(G4String name)
  : G4VSensitiveDetector(name),fPMTHitCollection(0),fPMTPositionsX(0)
  ,fPMTPositionsY(0),fPMTPositionsZ(0)
{
  collectionName.insert("pmtHitCollection");
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

LXePMTSD::~LXePMTSD() {}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void LXePMTSD::SetPmtPositions(const std::vector<G4ThreeVector>& positions)
{
  for (G4int i=0; i<G4int(positions.size()); ++i) {
    if(fPMTPositionsX)fPMTPositionsX->push_back(positions[i].x());
    if(fPMTPositionsY)fPMTPositionsY->push_back(positions[i].y());
    if(fPMTPositionsZ)fPMTPositionsZ->push_back(positions[i].z());
  }
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void LXePMTSD::Initialize(G4HCofThisEvent* hitsCE){
  fPMTHitCollection = new LXePMTHitsCollection
                      (SensitiveDetectorName,collectionName[0]);
  //Store collection with event and keep ID
  static G4int hitCID = -1;
  if(hitCID<0){
    hitCID = GetCollectionID(0);
  }
  hitsCE->AddHitsCollection( hitCID, fPMTHitCollection );
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

G4bool LXePMTSD::ProcessHits(G4Step* ,G4TouchableHistory* ){
  return false;
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

//Generates a hit and uses the postStepPoint's mother volume replica number
//PostStepPoint because the hit is generated manually when the photon is
//absorbed by the photocathode

G4bool LXePMTSD::ProcessHits_constStep(const G4Step* aStep,
                                       G4TouchableHistory* ){

/*
G4cout << aStep->GetTrack()->GetParentID() << G4endl;
  if(aStep->GetTrack()->GetParentID()==-1)
  {
   G4cout << aStep->GetTrack()->GetVertexKineticEnergy() << G4endl;
   }
*/

  //need to know if this is an optical photon
  if(aStep->GetTrack()->GetDefinition()
     != G4OpticalPhoton::OpticalPhotonDefinition()) return false;
 
  //User replica number 1 since photocathode is a daughter volume
  //to the pmt which was replicated -> Not true anymore as pmt became the volume
  G4int pmtNumber=
  aStep->GetPostStepPoint()->GetTouchable()->GetReplicaNumber();
  G4int scintNumber=
  aStep->GetPostStepPoint()->GetTouchable()->GetReplicaNumber(1); 
 //   aStep->GetPostStepPoint()->GetTouchable()->GetReplicaNumber(1);
    
//  G4cout << "scintno " << scintNumber << G4endl;

    
  G4VPhysicalVolume* physVol=
    aStep->GetPostStepPoint()->GetTouchable()->GetVolume();
  //  aStep->GetPostStepPoint()->GetTouchable()->GetVolume(1);

  //Find the correct hit collection
  G4int n=fPMTHitCollection->entries();
  LXePMTHit* hit=NULL;
  for(G4int i=0;i<n;i++){
    if(
		(*fPMTHitCollection)[i]->GetPMTNumber()==pmtNumber 
		&& 
		(*fPMTHitCollection)[i]->GetScintCpyNo()==scintNumber
		)
		{
      hit=(*fPMTHitCollection)[i];
      break;
    }
  }
 
  if(hit==NULL){//this pmt wasnt previously hit in this event
    hit = new LXePMTHit(); //so create new hit
    hit->SetPMTNumber(pmtNumber);
    hit->SetScintCpyNo(scintNumber);
    hit->SetPMTPhysVol(physVol);
    fPMTHitCollection->insert(hit);
    hit->SetPMTPos((*fPMTPositionsX)[pmtNumber],(*fPMTPositionsY)[pmtNumber],
                   (*fPMTPositionsZ)[pmtNumber]);
  }

  hit->IncPhotonCount(); //increment hit for the selected pmt
  hit->SetDrawit(true);
 
  return true;
}

G4int LXePMTSD::Return_NO_of_Photons(){
	
	G4int NoOfPhot = 0;
  //need to know if this is an optical photon
 //G4cout << fPMTHitCollection->entries() << G4endl;

if(
fPMTHitCollection->entries() !=0 
){
	
	
//G4cout <<	fPMTHitCollection->entries()<< G4endl;

//  LXePMTHit* hit2 = NULL;
//hit2 = (*fPMTHitCollection)[0];
//G4cout << "Start" << G4endl;
//G4cout << (*fPMTHitCollection)[0]->GetPMTNumber() << " " << (*fPMTHitCollection)[0]->GetScintCpyNo()  << G4endl;
}
  //Return number of photons
  G4int n=fPMTHitCollection->entries();
  LXePMTHit* hit=NULL;
  for(G4int i=0;i<n;i++){
	  
      hit=(*fPMTHitCollection)[i];
     
      //G4cout << "The no: " << (*fPMTHitCollection)[i]->GetPMTNumber() << " " << (*fPMTHitCollection)[i]->GetScintCpyNo() << " " << hit->GetPhotonCount()  << G4endl;

      
      NoOfPhot += hit->GetPhotonCount();
  }
  
//  if(NoOfPhot != 0) G4cout << NoOfPhot << G4endl;
  
  
  return NoOfPhot;
}

G4int LXePMTSD::Return_NO_of_Photons1(){
	
	G4int NoOfPhot = 0;
   //Return number of photons for PMT NO 0


	if(fPMTHitCollection->entries() == 0) return -1;
	//if(fPMTHitCollection->entries() != 2) return -1;

  
//  assert(fPMTHitCollection->entries() == 2);
  LXePMTHit* hit=NULL;
  
  hit=(*fPMTHitCollection)[0];
  NoOfPhot += hit->GetPhotonCount();  
  
  return NoOfPhot;
}

G4int LXePMTSD::Return_NO_of_Photons2(){
	
	G4int NoOfPhot = 0;
  //Return number of photons for PMT NO 1
	if(fPMTHitCollection->entries() == 0) return -1;
//	if(fPMTHitCollection->entries() != 2) return -1;
  
  //assert(fPMTHitCollection->entries() == 2);
  LXePMTHit* hit=NULL;
  hit=(*fPMTHitCollection)[1];
  NoOfPhot += hit->GetPhotonCount();
  
  return NoOfPhot;
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void LXePMTSD::EndOfEvent(G4HCofThisEvent* ) {
	/* G4int nofHits = fPMTHitCollection->entries();
     G4cout << G4endl
            << "-------->Hits Collection: in this event there are " << nofHits 
            << " hits in the PMTs: " << G4endl;
     for ( G4int i=0; i<nofHits; i++ ) (*fPMTHitCollection)[i]->Print(); */
     }

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void LXePMTSD::clear() {}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void LXePMTSD::DrawAll() {}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void LXePMTSD::PrintAll() {}
