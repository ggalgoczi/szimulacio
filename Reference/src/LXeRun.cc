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
// fEDepScoreID = G4SDManager::GetSDManager()->GetCollectionID("myDet/myEDepScorer"); 
}

LXeRun::~LXeRun()
{}

void LXeRun::RecordEvent(const G4Event* evt)
{
	
 
					
}

void LXeRun::Merge(const G4Run* aRun)
{

} 

void LXeRun::Calculations()
{
}
