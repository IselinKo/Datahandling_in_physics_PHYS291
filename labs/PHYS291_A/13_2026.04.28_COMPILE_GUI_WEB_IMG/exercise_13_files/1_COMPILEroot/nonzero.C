#include <TString.h>
#include <TF1.h>
#include <TH1F.h>
#include <TCanvas.h>

void nonzero()
{
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
hB->FillRandom("plotter",40000000);
hB->FillRandom("plotter",200000000);
hB->SetMinimum(0);
hB->Draw();
system("date");
}

