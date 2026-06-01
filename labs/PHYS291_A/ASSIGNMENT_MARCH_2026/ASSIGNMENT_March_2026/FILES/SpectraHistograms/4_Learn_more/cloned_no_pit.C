void cloned_no_pit() {

TString backfunc = "[0]-x*[1]";   //  parameters  p0 .... p4  as [0],[1]....[4]
TString gausfunc = "+[2]*exp(-(x-[4])*(x-[4])*[3])"; // [2] size, [4] position

TF1 *plotFun=new TF1("plotFun",backfunc+gausfunc,0.0,8.0);   // Function plotFun

plotFun->SetParameter(0,4.0);
plotFun->SetParameter(1,0.3);
plotFun->SetParameter(2,4.0);
plotFun->SetParameter(3,6.0);
plotFun->SetParameter(4,4.0);
plotFun->SetLineColor(kYellow);
TCanvas *cst = new TCanvas("cst","Comparing Fits",480,10,800,700);
cst->Divide(2,2);

cst->cd(1);      // upper left
        plotFun->SetTitle("Original Functions");
plotFun->Draw();

TF1 * Hmaker = (TF1 *) plotFun->Clone("Hmaker");
TH1F *hB = new TH1F("hB","Broad_peak",100,0,8);
Hmaker->SetParameter(3,0.5);
hB->FillRandom("Hmaker",30000);
Hmaker->SetLineColor(kBlue);
Hmaker->Draw("SAME");

cst->cd(3);      // lower left
hB->SetMinimum(0);
hB->Draw();

TF1 * fitfun = (TF1 *) plotFun->Clone("fitfun");
fitfun->SetParameter(2,400.0);
fitfun->SetParameter(0,400.0);
fitfun->SetLineColor(kBlue);
hB->Fit(fitfun);

cst->cd(2);
fitfun->SetTitle("Fitted Functions");
fitfun->Draw();
//    Here starts  second part

TF1 * plotFun2 = (TF1 *) plotFun->Clone("plotFun2");
plotFun2->SetParameter(1,-0.3);
plotFun2->SetParameter(3,4.8);
plotFun2->SetParameter(4,2.0);
plotFun2->SetLineColor(kGreen);
cst->cd(1);          // upper right
plotFun->SetMinimum(0);  plotFun->SetMaximum(plotFun2->GetMaximum());

plotFun2->Draw("same");    

TH1F *hA = new TH1F("hA","Narrow_Peak",100,0,8);
hA->FillRandom("plotFun2",50000);

cst->cd(4);
hA->SetMinimum(0);
hA->Draw();
TF1 * fitfun2 = (TF1 *) fitfun->Clone("fitfun2");
fitfun2->SetLineColor(kGreen);
hA->Fit(fitfun2);

cst->cd(2);
fitfun->SetMinimum(0);  fitfun->SetMaximum(fitfun2->GetMaximum());
fitfun2->Draw("same");

cst->Print("fits_9cloned.png");


}
