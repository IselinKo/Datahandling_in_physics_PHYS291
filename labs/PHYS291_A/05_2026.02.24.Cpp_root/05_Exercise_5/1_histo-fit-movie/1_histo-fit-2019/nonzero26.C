{

TString backgr = "[0]-x*[1]";
TString efunc = "+[2]*exp(-(x-[4])*(x-[4])*[3])";
TF1 *plotter=new TF1("plotter",backgr+efunc,0.0,8.0);
plotter->SetParameter(0,4);
plotter->SetParameter(1,1.3);
plotter->SetParameter(2,4.0);
plotter->SetParameter(3,6.8);
plotter->SetParameter(4,2.0);
//  plotter->SetParameter(0,0);
plotter->SetParameter(1,0);
TCanvas *Cbackgr = new TCanvas("Cbackgr","Background",600,300,700,500);
TH1F *hB = new TH1F("hB","Background",100,0,8);
hB->FillRandom("plotter",30000);
hB->SetMinimum(0);
hB->Draw();

}

