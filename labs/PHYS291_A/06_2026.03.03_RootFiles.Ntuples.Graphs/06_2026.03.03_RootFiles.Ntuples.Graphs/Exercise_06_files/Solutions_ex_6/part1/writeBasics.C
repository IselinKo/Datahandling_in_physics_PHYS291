{

   TFile *fold = new TFile("basic.root");   // Note: NO RECREATE, only READ
   fold->ls();
//  get the ntuple   and try  simple histograms
   TNtuple *ntp  = (TNtuple*) fold->Get("ntuple"); 

   TCanvas *c1= new TCanvas("c1","Canv 1",30,30,600,400);
   TCanvas *c2= new TCanvas("c2","Canv 2",500,30,600,400);
   TCanvas *c3= new TCanvas("c3","Canv 3",50,200,600,400);

//   c1->cd();   ntp->Draw("x");
//   c2->cd();   ntp->Draw("y");
//   c3->cd();   ntp->Draw("z");

   TH1F *hx = new TH1F("hx","x distribution",100,-4,4);
   TH1F *hy = new TH1F("hy","y distribution",100,-4,4);
   TH1F *hz = new TH1F("hz","z distribution",100,0,11);

   c1->cd();   ntp->Draw("x>>hx","","HIST");
   c2->cd();   ntp->Draw("y>>hy","","HIST");
   c3->cd();   ntp->Draw("z>>hz","","HIST");
   
   TFile *ff;
   ff= new TFile("basicX.root","RECREATE");
   hx->Write();
   ff->Close();

   ff= new TFile("basicY.root","RECREATE");
   hy->Write();
   ff->Close();

   ff= new TFile("basicZ.root","RECREATE");
   hz->Write();
   ff->Close();
   
   ff = new TFile("basicN.root","RECREATE");
   ntp->Write();
   ff->Close();

}
