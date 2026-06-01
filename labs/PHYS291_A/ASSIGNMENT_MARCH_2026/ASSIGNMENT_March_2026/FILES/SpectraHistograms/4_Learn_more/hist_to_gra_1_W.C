{
 TCanvas *cst = new TCanvas("cst","histogram to graph",50,10,1000,700);
   TH1F *hi = new TH1F("gaus", "gaus", 100, -5, 5);
   hi->FillRandom("gaus", 10000);

     cst->Divide(2,1);
     cst->cd(1);

   hi->Draw();

cout << "hi->GetEntries()  "<< hi->GetEntries() << endl;

cout << "hi->GetSize()  "<<  hi->GetSize()  << endl;

int Np=hi->GetSize()-2;

     cst->cd(2);
     
double xp[1000];   //  1000 big enough
double yp[1000];

int kp=0;
xp[kp]=hi->GetBinCenter(kp+1);
yp[kp]=hi->GetBinContent(kp+1);

for(kp=0;kp<Np;kp++)
 {xp[kp]=hi->GetBinCenter(kp+1);
  yp[kp]=hi->GetBinContent(kp+1);}

TGraph *gr1=new TGraph(Np,xp,yp);
gr1->Draw();
   cst->Print("Hist_2_Graph.png");
}

