void bergenFig()
{
TString backgr = "[0]-x*[1]";
TString efunc = "+[2]*exp(-(x-[4])*(x-[4])*[3])";
TF1 *plotter=new TF1("plotter",backgr+efunc,0.0,8.0);

plotter->SetParameter(0,0);   // lin backgr  to 0
plotter->SetParameter(1,0);   // lin steepness to 0
plotter->SetParameter(2,3);
plotter->SetParameter(3,2.8);
plotter->SetParameter(4,2.0);    //peak position

TCanvas *CBergen = new TCanvas("CBergen","Bergen",120,80,700,500);
TH1F *hB = new TH1F("hB","Bergen Data",100,0,8);
hB->FillRandom("plotter",5000);
hB->Draw();
}
