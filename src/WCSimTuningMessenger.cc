#include "WCSimTuningMessenger.hh"
#include "WCSimTuningParameters.hh"

#include "G4UIdirectory.hh"
#include "G4UIcommand.hh"
#include "G4UIparameter.hh"
#include "G4UIcmdWithADouble.hh"
#include "G4UIcmdWithABool.hh" //jl145
#include "G4UIcmdWithAnInteger.hh"


WCSimTuningMessenger::WCSimTuningMessenger(WCSimTuningParameters* WCTuningPars):WCSimTuningParams(WCTuningPars) { 
  WCSimDir = new G4UIdirectory("/WCSim/tuning/");
  WCSimDir->SetGuidance("Commands to change tuning parameters");

  Rayff = new G4UIcmdWithADouble("/WCSim/tuning/rayff",this);
  Rayff->SetGuidance("Set the Rayleigh scattering parameter");
  Rayff->SetParameterName("Rayff",true);
  Rayff->SetDefaultValue(0.75);

  Bsrff = new G4UIcmdWithADouble("/WCSim/tuning/bsrff",this);
  Bsrff->SetGuidance("Set the Blacksheet reflection parameter");
  Bsrff->SetParameterName("Bsrff",true);
  Bsrff->SetDefaultValue(2.50);

  Abwff = new G4UIcmdWithADouble("/WCSim/tuning/abwff",this);
  Abwff->SetGuidance("Set the water attenuation parameter");
  Abwff->SetParameterName("Abwff",true);
  Abwff->SetDefaultValue(1.30);

  Rgcff = new G4UIcmdWithADouble("/WCSim/tuning/rgcff",this);
  Rgcff->SetGuidance("Set the cathode reflectivity parameter");
  Rgcff->SetParameterName("Rgcff",true);
  Rgcff->SetDefaultValue(0.32);

  Mieff = new G4UIcmdWithADouble("/WCSim/tuning/mieff",this);
  Mieff->SetGuidance("Set the Mie scattering parameter");
  Mieff->SetParameterName("Mieff",true);
  Mieff->SetDefaultValue(0.0);

  PMTSurfType = new G4UIcmdWithAnInteger("/WCSim/tuning/pmtsurftype",this);
  PMTSurfType->SetGuidance("Set the PMT photocathode surface optical model");
  PMTSurfType->SetParameterName("PMTSurfType",true);
  PMTSurfType->SetDefaultValue(0);
  
  CathodePara = new G4UIcmdWithAnInteger("/WCSim/tuning/cathodepara",this);
  CathodePara->SetGuidance("Set the PMT photocathode surface parameters");
  CathodePara->SetParameterName("CathodePara",true);
  CathodePara->SetDefaultValue(0);

  //jl145 - for Top Veto
  TVSpacing = new G4UIcmdWithADouble("/WCSim/tuning/tvspacing",this);
  TVSpacing->SetGuidance("Set the Top Veto PMT Spacing, in cm.");
  TVSpacing->SetParameterName("TVSpacing",true);
  TVSpacing->SetDefaultValue(100.0);

  TopVeto = new G4UIcmdWithABool("/WCSim/tuning/topveto",this);
  TopVeto->SetGuidance("Turn Top Veto simulation on/off");
  TopVeto->SetParameterName("TopVeto",true);
  TopVeto->SetDefaultValue(0);

}

WCSimTuningMessenger::~WCSimTuningMessenger()
{
  delete Rayff;
  delete Bsrff;
  delete Abwff;
  delete Rgcff;
  delete Mieff;

  delete PMTSurfType;
  delete CathodePara;
  
  //jl145 - for Top Veto
  delete TVSpacing;
  delete TopVeto;

  delete WCSimDir;
}

void WCSimTuningMessenger::SetNewValue(G4UIcommand* command,G4String newValue)
{    

  if(command == Rayff) {
	  // Set the Rayleigh scattering parameter
	  //	  printf("Input parameter %f\n",Rayff->GetNewDoubleValue(newValue));

  WCSimTuningParams->SetRayff(Rayff->GetNewDoubleValue(newValue));

  printf("Setting Rayleigh scattering parameter %f\n",Rayff->GetNewDoubleValue(newValue));

  }

 if(command == Bsrff) {
	  // Set the blacksheet reflection parameter
	  //	  printf("Input parameter %f\n",Bsrff->GetNewDoubleValue(newValue));

  WCSimTuningParams->SetBsrff(Bsrff->GetNewDoubleValue(newValue));

  printf("Setting blacksheet reflection parameter %f\n",Bsrff->GetNewDoubleValue(newValue));

  }

 if(command == Abwff) {
	  // Set the water attenuation  parameter
	  //	  printf("Input parameter %f\n",Abwff->GetNewDoubleValue(newValue));

  WCSimTuningParams->SetAbwff(Abwff->GetNewDoubleValue(newValue));

  printf("Setting water attenuation parameter %f\n",Abwff->GetNewDoubleValue(newValue));

  }

 if(command == Rgcff) {
	  // Set the cathode reflectivity parameter
	  //	  printf("Input parameter %f\n",Rgcff->GetNewDoubleValue(newValue));

  WCSimTuningParams->SetRgcff(Rgcff->GetNewDoubleValue(newValue));

  printf("Setting cathode reflectivity parameter %f\n",Rgcff->GetNewDoubleValue(newValue));

  }

 if(command == Mieff) {
	  // Set the Mie scattering parameter
	  //	  printf("Input parameter %f\n",Mieff->GetNewDoubleValue(newValue));

  WCSimTuningParams->SetMieff(Mieff->GetNewDoubleValue(newValue));

  printf("Setting Mie scattering parameter %f\n",Mieff->GetNewDoubleValue(newValue));

  }

  if(command == PMTSurfType) {

   WCSimTuningParams->SetPMTSurfType(PMTSurfType->GetNewIntValue(newValue));

   printf("Setting PMT photocathode surface optical model as Model %i (0 means default dielectric model)\n",PMTSurfType->GetNewIntValue(newValue));
  }

  if(command == CathodePara) {

   WCSimTuningParams->SetCathodePara(CathodePara->GetNewIntValue(newValue));

   printf("Setting PMT photocathode surface parameters as Choice %i (0 = SK, 1 = KCsRb, 2 = RbCsCb)\n",CathodePara->GetNewIntValue(newValue));
  }

  //jl145 - For Top Veto

  else if(command == TVSpacing) {
    // Set the Top Veto PMT Spacing
    WCSimTuningParams->SetTVSpacing(TVSpacing->GetNewDoubleValue(newValue));
    printf("Setting Top Veto PMT Spacing %f\n",TVSpacing->GetNewDoubleValue(newValue));
  }

  else if(command == TopVeto) {
    // Set the Top Veto on/off
    WCSimTuningParams->SetTopVeto(TopVeto->GetNewBoolValue(newValue));
    if(TopVeto->GetNewBoolValue(newValue))
      printf("Setting Top Veto On\n");
    else
      printf("Setting Top Veto Off\n");
  }


}
