// Generating the histogram data Oslo 
{
//   PART 1   TF1 Function   ->  histogram
//
//   Fit the  histogram   ->    filename.root
//


TString RootFileName;       TString HistoName;
int Nsample;

RootFileName="Paris.root";     HistoName="PariHist";
//               bckHei bkGslope    peakHeig  peakInvWid    PeakPos
//double params[]={4.0 ,    0.3,       3.0 ,   2.8 ,           4.0 };
Nsample=275000;

RootFileName="berlin.root";     HistoName="Hberlin";
//               bckHei bkGslope    peakHeig  peakInvWid    PeakPos
//double params[]={2.0 ,    0.03,       5.0 ,   4.8 ,           3.85 };
Nsample=575000;

RootFileName="Roma.root";     HistoName="histoROM";
//               bckHei bkGslope    peakHeig  peakInvWid    PeakPos
double params[]={3.0 ,    0.259,       4.0 ,   2.8 ,           4.3 };
Nsample=75000;


TCanvas *cfunO = new TCanvas("cfunO","Function",350,50,600,400);
TCanvas *chistO = new TCanvas("chistO","Histogram",300,350,600,400);

TString backgr = "[0]-x*[1]"; 
TString efunc = "+[2]*exp(-(x-[4])*(x-[4])*[3])";
TF1 *plotFun=new TF1("plotFun",backgr+efunc,0.0,8.0);
plotFun->SetParameters(params);
plotFun->SetMinimum(0);       // start plot from 0
cfunO->cd();
plotFun->Draw();



chistO->cd();
//  TH1F *hO = new TH1F("hO",RootFileName,50,0,8);
TH1F *hO = new TH1F("hO",RootFileName,100,0,8);
hO->FillRandom("plotFun",Nsample);
hO->SetMinimum(0);
hO->Draw();


 TFile * ffO= new TFile(RootFileName,"RECREATE");
 ffO->WriteTObject(hO,HistoName);
 ffO->ls();

 
}

