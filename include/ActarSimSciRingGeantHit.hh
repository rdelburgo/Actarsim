// - AUTHOR: Hector Alvarez-Pol 04/2008
/******************************************************************
 * Copyright (C) 2005-2016, Hector Alvarez-Pol                     *
 * All rights reserved.                                            *
 *                                                                 *
 * License according to GNU LESSER GPL (see lgpl-3.0.txt).         *
 * For the list of contributors see CREDITS.                       *
 ******************************************************************/

#ifndef ActarSimSciRingGeantHit_h
#define ActarSimSciRingGeantHit_h 1

#include "G4VHit.hh"
#include "G4THitsCollection.hh"
#include "G4Allocator.hh"
#include "G4ThreeVector.hh"
#include "G4Step.hh"

class ActarSimSciRingGeantHit : public G4VHit {
private:
  G4double      edep;     ///< Energy deposited in the step

  G4ThreeVector pos;      ///< Position of the start of the step
  G4ThreeVector prePos;   ///< Position of the end of the step
  G4ThreeVector localPos; ///< LLcal (for the given detName and detID) coordinates of interaction (postStep)
  G4ThreeVector localPrePos;  ///< Local (for the given detName and detID) coordinates of interaction (postStep)

  G4String      detName;  ///< Name of the volume where the interaction takes place
  G4String      postDetName;  ///< Name of the volume at the previous step
  G4String      preDetName;   ///< Name of the volume at the following step
  G4int         detID;        ///< ID (copy) of the detector where the interaction takes place

  G4double      toF;     ///< ToF of the interaction (postStep)

  G4int         trackID;   ///< TrackID of the particle
  G4int         parentID;  ///< Particle parent ID

  G4int         particleID;      ///< Particle ID
  G4double      particleCharge;  ///< Particle charge
  G4double      particleMass;    ///< Particle mass

public:
  ActarSimSciRingGeantHit();
  ~ActarSimSciRingGeantHit();
  ActarSimSciRingGeantHit(const ActarSimSciRingGeantHit&);
  const ActarSimSciRingGeantHit& operator=(const ActarSimSciRingGeantHit&);
  G4int operator==(const ActarSimSciRingGeantHit&) const;

  inline void* operator new(size_t);
  inline void  operator delete(void*);

  void Draw();
  void Print();
  void PrinttoFile();

  void SetEdep(G4double de){ edep = de; }

  void SetPos(G4ThreeVector xyz){ pos = xyz; }
  void SetPrePos(G4ThreeVector xyz){ prePos = xyz; }
  void SetLocalPos(G4ThreeVector xyz){ localPos = xyz; }
  void SetLocalPrePos(G4ThreeVector xyz){ localPrePos = xyz; }

  void SetDetName(G4String Name){ detName = Name; }
  void SetPreDetName(G4String Name){ preDetName = Name; }
  void SetPostDetName(G4String Name){ postDetName = Name; }
  void SetDetID(G4int id){ detID = id; }

  void SetToF(G4double Time){ toF = Time; }

  void SetTrackID(G4int track){ trackID = track; }
  void SetParentID(G4int id){ parentID = id; }

  void SetParticleID(G4int ID){ particleID = ID; }
  void SetParticleCharge(G4double charge){ particleCharge = charge; }
  void SetParticleMass(G4double mass){particleMass = mass;}

  G4double      GetEdep(){ return edep; }

  G4ThreeVector GetPos(){ return pos; }
  G4ThreeVector GetPrePos(){ return prePos; }
  G4ThreeVector GetLocalPos(){ return localPos; }
  G4ThreeVector GetLocalPrePos(){ return localPrePos; }

  G4String      GetDetName(){ return detName; }
  G4String      GetPreDetName(){ return preDetName; }
  G4String      GetPostDetName(){ return postDetName; }
  G4int         GetDetID(){ return detID; }

  G4double      GetToF(){ return toF; }

  G4int      GetTrackID(){ return trackID; }
  G4int      GetParentID(){ return parentID; }

  G4int      GetParticleID(){ return particleID; }
  G4double   GetParticleCharge(){ return particleCharge; }
  G4double   GetParticleMass(){return particleMass;}

};

typedef G4THitsCollection<ActarSimSciRingGeantHit> ActarSimSciRingGeantHitsCollection;

extern G4Allocator<ActarSimSciRingGeantHit> ActarSimSciRingGeantHitAllocator;

inline void* ActarSimSciRingGeantHit::operator new(size_t) {
  void *aHit;
  aHit = (void *) ActarSimSciRingGeantHitAllocator.MallocSingle();
  return aHit;
}

inline void ActarSimSciRingGeantHit::operator delete(void *aHit) {
  ActarSimSciRingGeantHitAllocator.FreeSingle((ActarSimSciRingGeantHit*) aHit);
}
#endif
