TCanvas  * Canv_Control;  TCanvas *c1;TButton	*stop_button; TButton	*go_button;  TButton*save_button;
TH1F *h;TFile * ff;void save_this() {ff = new TFile("histS.root","UPDATE");ff->WriteTObject(h,"hist01");
ff->Close();} Int_t npeaks = 30; Double_t fpeaks(Double_t *x, Double_t *par) {Double_t result = par[0] + par[1]*x[0];
for (Int_t p=0;p<npeaks;p++) {Double_t norm  = par[3*p+2];Double_t mean  = par[3*p+3];
Double_t sigma = par[3*p+4];result += norm*TMath::Gaus(x[0],mean,sigma);}return result;}
void spectraPLUS(int  np  ); void exit_here();    void spect_wrapper();void spectraU() {
   gRandom->SetSeed();   c1= new TCanvas("c1","c1",10,10,1000,900);c1->Divide(1,2);Canv_Control=new TCanvas("Canv_Control","Controls",1000,30,200,300);  stop_button = new TButton("QUIT", "exit_here()",0.1,0.1,0.8,0.3);
stop_button->Draw();   save_button = new TButton("SAVE IT", "save_this()",0.1,0.4,0.8,0.55);save_button->Draw(); go_button = new TButton("NEXT", "spect_wrapper()",0.1,0.7,0.8,0.9);go_button->Draw();
   spectraPLUS( 3 );}void exit_here(){     gROOT->ProcessLine(".q");}void spect_wrapper(){   int  nn;nn= gRandom->Integer(12);
   if (nn<2) {nn=2;}   spectraPLUS(nn);}void spectraPLUS(int  np) {   Double_t Spar[3000]; Double_t Zeros[3000]; int K; int N=1;
   TF1 *fitvec[1000];   npeaks=np;h = new TH1F("h","test",500,0,1000);
   char titl[100];   sprintf(titl,"Generated histogram of %d random peaks",np);
   h->SetTitle(titl);Double_t par[3000];par[0] = 0.8;par[1] = -0.6/1000;   Int_t p;   float L=1000.0; float Dx;
   Dx=L/float(np+1);for (p=0;p<npeaks;p++) {par[3*p+2] = 0.2+0.8*gRandom->Rndm();par[3*p+3] = Dx*(p+1)+(-0.5+gRandom->Rndm())*Dx;par[3*p+4] = 15+3*gRandom->Rndm(); // width
   }   TF1 *f = new TF1("f",fpeaks,0,1000,2+3*npeaks);   f->SetNpx(1000);   f->SetParameters(par);c1->cd(1);
   h->FillRandom("f",200000);h->SetMinimum(0);h->Draw();   TH1F *h2 = (TH1F*)h->Clone("h2");   TSpectrum *s = new TSpectrum(2*npeaks);
   Int_t nfound = s->Search(h,2,"",0.10);printf("Found %d candidate peaks to fit\n",nfound);
   TH1 *hb = s->Background(h,20,"same");   if (hb) c1->Update();if (np <0) return;
   c1->cd(2);TF1 *fline = new TF1("fline","pol1",0,1000);h->Draw();h->Fit("fline","qn");c1->Update();c1->Modified();
   par[0] = fline->GetParameter(0);par[1] = fline->GetParameter(1);   npeaks = 0;   Double_t *xpeaks = s->GetPositionX();
   for (p=0;p<nfound;p++) {Double_t xp = xpeaks[p];
Int_t bin = h->GetXaxis()->FindBin(xp);      Double_t yp = h->GetBinContent(bin);if (yp-TMath::Sqrt(yp) < fline->Eval(xp)) continue;
      par[3*npeaks+2] = yp;par[3*npeaks+3] = xp;par[3*npeaks+4] = 3;npeaks++;}printf("Found %d useful peaks to fit\n",nfound);
   printf("Now fitting: Be patient\n");TF1 *fit = new TF1("fit",fpeaks,0,1000,2+3*npeaks);
   TVirtualFitter::Fitter(h2,10+3*npeaks);   fit->SetParameters(par);   fit->SetLineColor(kGreen);fit->SetLineWidth(5);
   fit->SetNpx(1000);sprintf(titl,"Attempted fit using %d peaks",nfound);h2->SetTitle(titl);h2->Fit("fit");fit->GetParameters(Spar);
for(N=0;  N<nfound;  N++) {fitvec[N] = new TF1("fitvec",fpeaks,0,1000,2+3*npeaks);fitvec[N]->SetNpx(1000);
      fitvec[N]->SetParameters(Zeros);   for(K=0;K<3;K++) fitvec[N]->SetParameter(2+3*N+K,Spar[2+3*N+K]);fitvec[N]->Draw("same");}c1->Update();c1->Modified();}

