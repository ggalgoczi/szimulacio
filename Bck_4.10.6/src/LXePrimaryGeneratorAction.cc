#include "LXePrimaryGeneratorAction.hh"

#include "G4Event.hh"
#include "G4GeneralParticleSource.hh"
#include "G4ParticleTable.hh"
#include "G4ParticleDefinition.hh"
#include "globals.hh"
#include "Randomize.hh"
#include "LXeRunAction.hh"

// Constructor
LXePrimaryGeneratorAction::LXePrimaryGeneratorAction(LXeRunAction*  RunAction)
:fRunAction(RunAction){
	

    particleGun = new G4GeneralParticleSource();
}


// Destructor
LXePrimaryGeneratorAction::~LXePrimaryGeneratorAction()
{
    delete particleGun;
}


void LXePrimaryGeneratorAction::GeneratePrimaries(G4Event* anEvent)
{
	//particleGun->Set
    particleGun -> GeneratePrimaryVertex(anEvent);
}

