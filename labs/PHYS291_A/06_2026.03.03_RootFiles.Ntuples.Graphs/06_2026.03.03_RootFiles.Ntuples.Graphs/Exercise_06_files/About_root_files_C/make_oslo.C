// Generating the histogram data Oslo 
{
//   PART 1   TF1 Function   ->  histogram
//
//   Fit the  histogram   ->    filename.root
//
TCanvas *cfunO = new TCanvas("cfunO","Function",350,50,600,400);
TCanvas *chistO = new TCanvas("chistO","Histogram",300,350,600,400);

TString backgr = "[0]-x*[1]";
TString efunc = "+[2]*exp(-(x-[4])*(x-[4])*[3])";
TF1 *plotFun=new TF1("plotFun",backgr+efunc,0.0,8.0);
plotFun->SetParameter(0,4);
plotFun->SetParameter(1,0.3);
plotFun->SetParameter(2,3);   // Peak  height
plotFun->SetParameter(3,2.8);  // inv width
plotFun->SetParameter(4,4.0); // Pos    4.1
plotFun->SetMinimum(0);       // start plot from 0

// Oslo

TF1 *plotFunO=(TF1*)plotFun->Clone("plotFunO");
plotFunO->SetParameter(0,2);
plotFunO->SetParameter(1,0.1);
plotFun->SetParameter(2,3);     // Peak  height
plotFunO->SetParameter(3,2.0);   // inv width
plotFunO->SetParameter(4,4.5);  // Pos     4.5
plotFunO->SetMinimum(0);       // start plot from 0
cfunO->cd();
plotFunO->Draw();

chistO->cd();
TH1F *hO = new TH1F("hO","Oslo Data",50,0,8);
hO->FillRandom("plotFunO",300000);
hO->SetMinimum(0);
hO->Draw();


 ffO= new TFile("OSLO.root","RECREATE");
 ffO->WriteTObject(hO,"histOslo");
 ffO->ls();

 
}

