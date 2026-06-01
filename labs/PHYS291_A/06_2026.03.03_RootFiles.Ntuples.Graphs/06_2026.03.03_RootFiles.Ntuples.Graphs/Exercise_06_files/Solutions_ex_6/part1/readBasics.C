{

   TFile *fold = new TFile("basic.root");   // Note: NO RECREATE, only READ
   fold->ls();
//  get the ntuple   and try  simple histograms
   TNtuple *ntp  = (TNtuple*) fold->Get("ntuple"); 

   TCanvas *c1= new TCanvas("c1","Canv 1",30,30,600,400);
   TCanvas *c2= new TCanvas("c2","Canv 2",500,30,600,400);
   TCanvas *c3= new TCanvas("c3","Canv 3",50,200,600,400);

   c1->cd();   ntp->Draw("x");
   c2->cd();   ntp->Draw("y");
   c3->cd();   ntp->Draw("z");

}
