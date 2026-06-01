{
TString backgr = "[0]-x*[1]";
TString efunc = "+[2]*exp(-(x-[4])*(x-[4])*[3])";
TF1 *plotter=new TF1("plotter",backgr+efunc,0.0,8.0);
plotter->SetParameter(0,4);
plotter->SetParameter(1,0.3);
plotter->SetParameter(2,3);
plotter->SetParameter(3,2.8);
plotter->SetParameter(4,4.0);
plotter->SetParameter(0,0);
plotter->SetParameter(1,0);
plotter->SetParameter(4,2.0);

TCanvas *c1 = new TCanvas("c1","Oslo",300,300,700,500);
TH1F *hO = new TH1F("hO","Oslo Data",100,0,8);
hO->FillRandom("plotter",7000);
hO->Draw();
}
