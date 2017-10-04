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
// $Id: OpNoviceSteppingAction.cc 71007 2013-06-09 16:14:59Z maire $
//
/// \file OpNoviceSteppingAction.cc
/// \brief Implementation of the OpNoviceSteppingAction class

#include "OpNoviceSteppingAction.hh"

#include "G4Step.hh"
#include "G4Track.hh"
#include "G4OpticalPhoton.hh"

#include "G4Event.hh"
#include "G4RunManager.hh"
#include "G4SystemOfUnits.hh"

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

OpNoviceSteppingAction::OpNoviceSteppingAction()
: G4UserSteppingAction()
{ 
  fScintillationCounter = 0;
  fCerenkovCounter      = 0;
  fEventNumber = -1;
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

OpNoviceSteppingAction::~OpNoviceSteppingAction()
{ ; }

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void OpNoviceSteppingAction::UserSteppingAction(const G4Step* step)
{
  G4int eventNumber = G4RunManager::GetRunManager()->
                                              GetCurrentEvent()->GetEventID();

  if (eventNumber != fEventNumber) {
     fEventNumber = eventNumber;
     fScintillationCounter = 0;
     fCerenkovCounter = 0;
  }

  G4Track* track = step->GetTrack();
  if(track->GetTrackStatus()!=fAlive) { return; } 

  G4String ParticleName = track->GetDynamicParticle()->
                                 GetParticleDefinition()->GetParticleName();

//between World and Tank2
G4VPhysicalVolume* prevolume  =
    step->GetPreStepPoint()->GetTouchableHandle()->GetVolume();
G4VPhysicalVolume* postvolume  =
    step->GetPostStepPoint()->GetTouchableHandle()->GetVolume();

    G4double preX = step->GetPreStepPoint()->GetPosition().x();
    G4double preY = step->GetPreStepPoint()->GetPosition().y();
    G4double preZ  = step->GetPreStepPoint()->GetPosition().z();
    G4double preKinE  = step->GetPreStepPoint()->GetKineticEnergy();	
    G4double Gtime  =  track->GetGlobalTime();	
    G4int copyNumber = step->GetPreStepPoint()->GetTouchableHandle()->GetCopyNumber();
//    if (preZ<-3*m)

/*   if (prevolume->GetName() == "f1")
{	
    std::cout<<"ABCDEF "<<eventNumber<<" 1 "<<preY/mm<<" "<<preKinE/eV
	<<" "<<Gtime/ns<<" "<<track->GetCreatorProcess()->GetProcessName()<<std::endl;
	track->SetTrackStatus(fStopAndKill);
}*/

    std::cout<<"MNOPQ "<<prevolume->GetName()<<std::endl;

   if (prevolume->GetName() == "up" && track->GetCreatorProcess()->GetProcessName()=="Scintillation"){
    std::cout<<"ABCDEF "<<eventNumber<<" up "<<copyNumber<<" "<<preX/mm<<" "<<preY/mm<<" "<<preKinE/eV
	<<" "<<Gtime/ns<<" 1"<<std::endl;
    track->SetTrackStatus(fStopAndKill);}

   if (prevolume->GetName() == "up" && track->GetCreatorProcess()->GetProcessName()=="Cerenkov"){
    std::cout<<"ABCDEF "<<eventNumber<<" up "<<copyNumber<<" "<<preX/mm<<" "<<preY/mm<<" "<<preKinE/eV
	<<" "<<Gtime/ns<<" 2"<<std::endl;
    track->SetTrackStatus(fStopAndKill);}


//   if (prevolume->GetName() == "f1" && track->GetCreatorProcess()->GetProcessName()=="Scintillation"){
//    std::cout<<"ABCDEF "<<eventNumber<<" 1 "<<preX/mm<<" "<<preY/mm<<" "<<preKinE/eV
//	<<" "<<Gtime/ns<<" 1"<<std::endl;
//    track->SetTrackStatus(fStopAndKill);}

//   if (prevolume->GetName() == "f1" && track->GetCreatorProcess()->GetProcessName()=="Cerenkov"){
//    std::cout<<"ABCDEF "<<eventNumber<<" 1 "<<preX/mm<<" "<<preY/mm<<" "<<preKinE/eV
//	<<" "<<Gtime/ns<<" 2"<<std::endl;
//    track->SetTrackStatus(fStopAndKill);}


//   if (prevolume->GetName() == "a1" && track->GetCreatorProcess()->GetProcessName()=="Scintillation"){
//    std::cout<<"ABCDEF "<<eventNumber<<" 2 "<<preX/mm<<" "<<preY/mm<<" "<<preKinE/eV
//	<<" "<<Gtime/ns<<" 1"<<std::endl;
//    track->SetTrackStatus(fStopAndKill);}

//   if (prevolume->GetName() == "a1" && track->GetCreatorProcess()->GetProcessName()=="Cerenkov"){
//    std::cout<<"ABCDEF "<<eventNumber<<" 2 "<<preX/mm<<" "<<preY/mm<<" "<<preKinE/eV
//	<<" "<<Gtime/ns<<" 2"<<std::endl;
//    track->SetTrackStatus(fStopAndKill);}



 //  if (prevolume->GetName() == "a5"  &&  postvolume->GetName() == "World")
 //   std::cout<<" a5 "<<prevolume->GetName()<<" "<<postvolume->GetName()<<" "<<ParticleName
//	<<" "<<preZ/m<<" "<<preKinE/eV<<" "<<Gtime/ns<<std::endl;


 if (ParticleName == "opticalphoton" && preX>-5*mm && preX<5*mm)  std::cout<<"GHIJKL "<<track->GetTrackID()<<" "<<preKinE/eV<<" "<<Gtime/ns<<std::endl;
  if (ParticleName == "opticalphoton") return;

  const std::vector<const G4Track*>* secondaries =
                                            step->GetSecondaryInCurrentStep();

  if (secondaries->size()>0) {
     for(unsigned int i=0; i<secondaries->size(); ++i) {
        if (secondaries->at(i)->GetParentID()>0) {
           if(secondaries->at(i)->GetDynamicParticle()->GetParticleDefinition()
               == G4OpticalPhoton::OpticalPhotonDefinition()){
              if (secondaries->at(i)->GetCreatorProcess()->GetProcessName()
               == "Scintillation")fScintillationCounter++;
              if (secondaries->at(i)->GetCreatorProcess()->GetProcessName()
               == "Cerenkov")fCerenkovCounter++;
           }
        }
     }
  }
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
