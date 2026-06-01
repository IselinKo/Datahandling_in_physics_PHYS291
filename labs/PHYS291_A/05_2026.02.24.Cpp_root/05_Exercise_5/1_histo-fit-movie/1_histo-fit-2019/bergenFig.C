{

TString backgr = "[0]-x*[1]";
TString efunc = "+[2]*exp(-(x-[4])*(x-[4])*[3])";
TF1 *plotter=new TF1("plotter",backgr+efunc,0.0,8.0);
plotter->SetParameter(0,4);
plotter->SetParameter(1,0.3);  // lin backgr
plotter->SetParameter(2,3);
plotter->SetParameter(3,1.8);
plotter->SetParameter(4,5.0);
plotter->SetParameter(0,0);   // lin backgr  to 0
plotter->SetParameter(1,0);
TCanvas *C1 = new TCanvas("C1","Bergen",600,300,700,500);
TH1F *hB = new TH1F("hB","Bergen Data",100,0,8);
hB->FillRandom("plotter",5000);
hB->Draw();

}

