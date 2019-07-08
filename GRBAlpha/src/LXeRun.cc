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


void filePutContents3(std::string& name, std::vector<G4int> & content, bool append = false) {
    std::ofstream outfile;
    if (append)
		outfile.open(name.c_str(), std::ios_base::app);
    else
        outfile.open(name.c_str());
        
     for(std::vector<G4int>::iterator it = content.begin(); it != content.end();it++)   
    outfile << *it << "\n";
}

LXeRun::LXeRun()
{
for (G4int i=0; i<1000; i++) {
   PMTHitNo2.push_back(0);
   PMTHitNo1.push_back(0);
  }
  
for (G4int i=0; i<10000; i++) {
   PrimaryEnergies.push_back(0);

} 
  

// fEDepScoreID = G4SDManager::GetSDManager()->GetCollectionID("myDet/myEDepScorer"); 
}

LXeRun::~LXeRun()
{}

void LXeRun::RecordEvent(const G4Event* evt)
{
	//  G4cout << evt->GetPrimaryVertex()->GetPrimary()->GetKineticEnergy() << G4endl;
	
      G4SDManager* SDman = G4SDManager::GetSDMpointer();
        G4String sdName="/LXeDet/pmtSD";
        LXePMTSD* pmtSD = (LXePMTSD*)SDman->FindSensitiveDetector(sdName);     

		assert(pmtSD->Return_NO_of_Photons()<1001);
		
		if(pmtSD->Return_NO_of_Photons1() != -1 && pmtSD->Return_NO_of_Photons2() != -1){
		PMTHitNo1[pmtSD->Return_NO_of_Photons1()]++;
		PMTHitNo2[pmtSD->Return_NO_of_Photons2()]++;
		if(int(evt->GetPrimaryVertex()->GetPrimary()->GetKineticEnergy() + 0.5) < 10){
			PrimaryEnergies[int(evt->GetPrimaryVertex()->GetPrimary()->GetKineticEnergy()*1000 + 0.5)]++;
			}
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

 for (G4int i=0; i<10000; i++) {
    PrimaryEnergies[i] += localRun->PrimaryEnergies[i];
  }

 //G4cout << "mergeok" << G4endl;

  G4Run::Merge(aRun);
} 

void LXeRun::Calculations()
{
  G4int NbOfEvents = GetNumberOfEvent();
  G4cout << "No of Ev: " << NbOfEvents << G4endl;


// Printing out Photon Hit numbers

std::string FNAME1 = "PMT1.dat";
std::string FNAME2 = "PMT2.dat";
std::string FNAME3 = "PrimaryEnergiesCreatedSignal.dat";
filePutContents3(FNAME1, PMTHitNo1, false);
filePutContents3(FNAME2, PMTHitNo2, false);
filePutContents3(FNAME3, PrimaryEnergies, false);

	for(std::vector<G4int>::iterator it = PMTHitNo2.begin(); it != PMTHitNo2.end() ; it++){
		//G4cout << "No2 osszeg " << *it << G4endl;
		}	
}
