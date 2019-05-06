
#ifndef LXeRun_h
#define LXeRun_h 1


#include "G4Run.hh"

#include "G4ThreeVector.hh"
#include "globals.hh"

#include <vector>



class LXeRun : public G4Run
{
 public:
	LXeRun();
	std::vector<G4int> PMTHitNo1;
	std::vector<G4int> PMTHitNo2;
  virtual ~LXeRun();
  virtual void RecordEvent(const G4Event*);
  virtual void Merge(const G4Run*);
  virtual void Calculations();

 private:
 
 
};

#endif
