#include <iostream>
#include <TString.h>
#include <TF1.h>
#include <TH1F.h>
#include <TCanvas.h>
#include "TApplication.h"
#include "TMath.h"


//  g++ getRand.cpp -o getRand `root-config --cflags --libs`

int main()
{
TApplication thePApp("App", 0, 0);

system("date");
TString backgr = "[0]-x*[1]";
TString efunc = "+[2]*exp(-(x-[4])*(x-[4])*[3])";
TF1 *plotter=new TF1("plotter",backgr+efunc,0.0,8.0);

plotter->SetParameter(0,4);        // lin backgr  large
plotter->SetParameter(1,0.03);      // lin steepness nearly 0
plotter->SetParameter(2,4.0);
plotter->SetParameter(3,2.8);
plotter->SetParameter(4,4.0);      //peak position


TCanvas *Cbackgr = new TCanvas("Cbackgr","Background",300,200,700,500);
TH1F *hB = new TH1F("hB","Background",100,0,8);
for (int k=0;k<200000000;k++) hB->Fill(plotter->GetRandom());
hB->SetMinimum(0);
hB->Draw();
system("date");
Cbackgr->Modified();
Cbackgr->Update();

thePApp.Run();

}

