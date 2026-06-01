{
int npeaks=30;           int np=6;
gROOT->ProcessLine(".L fpeeks.C");
//  This crashed script, but works in interactive  Thus ProcessLine
gROOT->ProcessLine("TF1 *f = new TF1(\"f\",fpeaks,0,1000,2+np*3);");
   Double_t Spar[3000]; Double_t Zeros[3000]; int K; int N=1;
   TF1 *fitvec[1000];
   npeaks=np;
   TH1F *h = new TH1F("h","test",500,0,1000);
   gRandom->SetSeed();
   //generate n peaks at random positions
   Double_t par[3000];
   par[0] = 0.8;   par[1] = -0.6/1000;   Int_t p;   
   float L=1000.0; float Dx;
   Dx=L/float(np+1);
   for (p=0;p<npeaks;p++) {
      par[3*p+2] = 0.2+0.8*gRandom->Rndm();   // strength (1.0 max)
      par[3*p+3] = Dx*(p+1)+(-0.5+gRandom->Rndm())*Dx; // pos
      par[3*p+4] = 20+10*gRandom->Rndm();     //   width
   }
   f->SetNpx(1000);           //  f = new TF1("f",fpeaks,.......
   f->SetParameters(par);
   f->SetParameter(29,2+np*3);
   TCanvas *c1 = new TCanvas("c1","c1",10,10,1000,900);
   c1->Divide(1,2);        c1->cd(1);
   h->FillRandom("f",200000);        h->SetMinimum(0);
   h->Draw();
cout<<"\nContinue by:\n  .x Pspectra_1.C\n"; // gROOT->ProcessLine(".x Pspectra_1.C");   
// gROOT->ProcessLine(".x Pspectra_2.C");   
// gROOT->ProcessLine(".x Pspectra_3.C");   
}



