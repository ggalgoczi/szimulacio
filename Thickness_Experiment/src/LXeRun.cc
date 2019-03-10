#include "G4SDManager.hh"
#include "LXeRun.hh"
#include "LXePMTSD.hh"
#include "LXePMTHit.hh"
#include "LXeRunAction.hh"
#include "LXeUserEventInformation.hh"

#include "G4Run.hh"
#include "G4RunManager.hh"
#include "G4UnitsTable.hh"
#include "G4Threading.hh"

#include "G4SystemOfUnits.hh"
#include <iomanip>

#include "Randomize.hh"

LXeRun::LXeRun()
{
// fEDepScoreID = G4SDManager::GetSDManager()->GetCollectionID("myDet/myEDepScorer"); 
}

LXeRun::~LXeRun()
{}

void LXeRun::RecordEvent(const G4Event* evt)
{
	
      G4SDManager* SDman = G4SDManager::GetSDMpointer();
        G4String sdName="/LXeDet/pmtSD";
        LXePMTSD* pmtSD = (LXePMTSD*)SDman->FindSensitiveDetector(sdName);     

		assert(pmtSD->Return_NO_of_Photons()<1001);
		
		if(pmtSD->Return_NO_of_Photons1() != -1 && pmtSD->Return_NO_of_Photons2() != -1){
		PMTHitNo1[pmtSD->Return_NO_of_Photons1()]++;
		PMTHitNo2[pmtSD->Return_NO_of_Photons2()]++;
		}
		else{
		PMTHitNo1[0]++;
		PMTHitNo2[0]++;
			}	
					
}

void LXeRun::Merge(const G4Run* aRun)
{
  const LXeRun* localRun = static_cast<const LXeRun*>(aRun);
 // fEDep += localRun->fEDep;
 


  for (G4int i=0; i<1001; i++) {
    PMTHitNo2[i] += localRun->PMTHitNo2[i];
  }

  for (G4int i=0; i<1001; i++) {
    PMTHitNo1[i] += localRun->PMTHitNo1[i];
  }

 //G4cout << "mergeok" << G4endl;

  G4Run::Merge(aRun);
} 

void LXeRun::Calculations()
{

	for(std::vector<G4int>::iterator it = PMTHitNo2.begin(); it != PMTHitNo2.end() ; it++){
		//G4cout << "No2 osszeg " << *it << G4endl;
		}	
}
