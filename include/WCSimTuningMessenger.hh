#ifndef WCSimTuningMessenger_h
#define WCSimTuningMessenger_h 1

// Contains detector parameters that need to be set up before detector is constructed
// KS Mar 2010

#include "globals.hh"
#include "G4UImessenger.hh"

class WCSimTuningParameters;
class G4UIdirectory;
class G4UIcommand;
class G4UIcmdWithADouble;
class G4UIcmdWithABool; //jl145
class G4UIcmdWithAnInteger;


class WCSimTuningMessenger: public G4UImessenger
{
public:
  WCSimTuningMessenger(WCSimTuningParameters*);
  ~WCSimTuningMessenger();

  void SetNewValue(G4UIcommand* command, G4String newValue);

private:

  WCSimTuningParameters* WCSimTuningParams;

  G4UIdirectory*      WCSimDir;
  G4UIcmdWithADouble* Rayff;
  G4UIcmdWithADouble* Bsrff;
  G4UIcmdWithADouble* Abwff;
  G4UIcmdWithADouble* Rgcff;
  G4UIcmdWithADouble* Mieff;

  G4UIcmdWithAnInteger* PMTSurfType;
  G4UIcmdWithAnInteger* CathodePara;

  //For Top Veto - jl145
  G4UIcmdWithADouble* TVSpacing;
  G4UIcmdWithABool* TopVeto;

};

#endif
