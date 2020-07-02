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
// $Id: LXeSteppingAction.cc 73915 2013-09-17 07:32:26Z gcosmo $
//
/// \file optical/LXe/src/LXeSteppingAction.cc
/// \brief Implementation of the LXeSteppingAction class
//
//
#include "LXeSteppingAction.hh"
#include "LXeEventAction.hh"
#include "LXeTrackingAction.hh"
#include "LXeTrajectory.hh"
#include "LXePMTSD.hh"
#include "LXeUserTrackInformation.hh"
#include "LXeUserEventInformation.hh"
#include "LXeSteppingMessenger.hh"
#include "LXeRecorderBase.hh"

#include "LXeEventAction.hh"
#include "G4SteppingManager.hh"
#include "G4SDManager.hh"
#include "G4EventManager.hh"
#include "G4ProcessManager.hh"
#include "G4Track.hh"
#include "G4Step.hh"
#include "G4Event.hh"
#include "G4StepPoint.hh"
#include "G4TrackStatus.hh"
#include "G4VPhysicalVolume.hh"
#include "G4ParticleDefinition.hh"
#include "G4ParticleTypes.hh"
#include "G4SystemOfUnits.hh"
#include "G4RunManager.hh"


void filePutContents(const std::string& name, const std::string& content, bool append = false) {
    std::ofstream outfile;
    if (append)
		outfile.open(name.c_str(), std::ios_base::app);
    else
        outfile.open(name.c_str());
    outfile << content;
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

LXeSteppingAction::LXeSteppingAction(LXeRecorderBase* r,LXeEventAction*  eventAction)
  : fRecorder(r),fOneStepPrimaries(false),fEventAction(eventAction)
{
  fSteppingMessenger = new LXeSteppingMessenger(this);
  fExpectedNextStatus = Undefined;
  

}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

LXeSteppingAction::~LXeSteppingAction() {}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void LXeSteppingAction::UserSteppingAction(const G4Step * theStep){

G4Track* theTrack = theStep->GetTrack();

  G4StepPoint* thePrePoint = theStep->GetPreStepPoint();
  G4VPhysicalVolume* thePrePV = thePrePoint->GetPhysicalVolume();

  G4StepPoint* thePostPoint = theStep->GetPostStepPoint();
  G4VPhysicalVolume* thePostPV = thePostPoint->GetPhysicalVolume();
 G4int eventNumber = G4RunManager::GetRunManager()->
                                              GetCurrentEvent()->GetEventID();
  G4ParticleDefinition* particleType = theTrack->GetDefinition();
	if(theStep->GetPostStepPoint()->GetStepStatus()!=0 && theTrack->GetParentID()==0){
		if((thePrePV->GetLogicalVolume()->GetName()=="expHall_log" && thePostPV->GetLogicalVolume()->GetName()=="Shielding_log"))
		{
	//	G4RunManager::GetRunManager()->SetRandomNumberStore(true);
	//	G4RunManager::GetRunManager()->rndmSaveThisEvent(); 
		
		G4double preX = theStep->GetPreStepPoint()->GetPosition().x();
		G4double preY = theStep->GetPreStepPoint()->GetPosition().y();
		G4double preZ  = theStep->GetPreStepPoint()->GetPosition().z();
		G4double preKinE  = theStep->GetPreStepPoint()->GetKineticEnergy();	
		
	//	G4cout << theStep->GetPostStepPoint()->GetStepStatus() << G4endl; //printf("%G4string \n",thePrePV->GetName());}
	//	G4cout << "*** Warning *** : msc loop for " << theTrack->GetDefinition()->GetParticleName() << " in " << thePostPV->GetLogicalVolume()->GetName() << G4endl; 
	//	G4cout << "*** Warning *** : msc loop for " << theTrack->GetDefinition()->GetParticleName() << " in " << thePostPV->GetLogicalVolume()->GetName() << G4endl; 
		
		std::ostringstream oss;
		oss <<eventNumber<<" "<<preX/mm<<" "<<preY/mm<<" "<<preZ/mm<<" "<<preKinE/eV << " " << "In" << " "
		<< std::endl;		
		std::string var = oss.str();	
		filePutContents("./gamma.txt",var,true);
		}//printf("%G4string \n",thePrePV->GetName());}


}

}
