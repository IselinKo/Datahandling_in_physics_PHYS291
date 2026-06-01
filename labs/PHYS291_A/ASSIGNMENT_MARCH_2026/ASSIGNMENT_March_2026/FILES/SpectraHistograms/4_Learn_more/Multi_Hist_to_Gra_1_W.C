{
// Example of stacked histograms: class THStack - multiHistogram
//                                 option        "nostack bar"
//                            SetBarWidth();    h2st->SetBarOffset();
//  Author: Ladislav Kocbach  /  based on hstack.C by Rene Brun
//
   THStack *multiHist = new THStack("multiHist","Multi-histogram 1D class THStack");
//
//create three 1-d histograms
   TH1F *h1st = new TH1F("h1st","Test1",20,-4,4);
   TH1F *h2st = new TH1F("h2st","No 2",20,-4,4);
   TH1F *h3st = new TH1F("h3st","Third",20,-4,4);
//
   double b; int ii;        
   for (ii=0;ii<3000;ii++){ b=gRandom->Gaus(2.0,1.5); h1st->Fill(b); }
      h1st->SetFillColor(6);
      h1st->SetBarWidth(0.2);  h1st->SetBarOffset(-0.2);
      multiHist->Add(h1st);  
//
   for (ii=0;ii<3000;ii++){ b=gRandom->Gaus(0.0,1.45); h2st->Fill(b); }  
      h2st->SetFillColor(18);
      h2st->SetBarWidth(0.2); h2st->SetBarOffset(0.0);
      multiHist->Add(h2st);
//
   for (ii=0;ii<3000;ii++){ b=-4+8*gRandom->Rndm(); h3st->Fill(b); } 
                       // { b=gRandom->Gaus(-2.0,0.75); h3st->Fill(b); } 
     h3st->SetFillColor(8);
     h3st->SetBarWidth(0.2); h3st->SetBarOffset(0.2);
    multiHist->Add(h3st);
//
    TCanvas *cst = new TCanvas("cst","Multi-histogram To Graphs",400,10,900,700);
//
     cst->Divide(1,2);
     cst->cd(1);
     multiHist->Draw("nostack bar");
     cst->Modified();          //  Use in interactive 

     cst->cd(2);

double xp1[1000];   double yp1[1000];
double xp2[1000];   double yp2[1000];
double xp3[1000];   double yp3[1000];
                            ////////     h1st
int kp;
int Np1=h1st->GetSize()-2;
for(kp=0;kp<Np1;kp++){
         xp1[kp]=h1st->GetBinCenter(kp+1);   yp1[kp]=h1st->GetBinContent(kp+1);}
TGraph *gr1=new TGraph(Np1,xp1,yp1);  gr1->SetLineWidth(6);  gr1->SetLineColor(6);
// gr1->Draw();

                           ////////     h2st
                           
int Np2=h2st->GetSize()-2;
for(kp=0;kp<Np2;kp++){
         xp2[kp]=h2st->GetBinCenter(kp+1);   yp2[kp]=h2st->GetBinContent(kp+1);}
TGraph *gr2=new TGraph(Np2,xp2,yp2);  gr2->SetLineWidth(6); gr2->SetLineColor(18);
// gr2->Draw();
                             ////////     h3st
int Np3=h3st->GetSize()-2;
for(kp=0;kp<Np3;kp++){
         xp3[kp]=h3st->GetBinCenter(kp+1);   yp3[kp]=h3st->GetBinContent(kp+1);}
TGraph *gr3=new TGraph(Np3,xp3,yp3);  gr3->SetLineWidth(6); gr3->SetLineColor(8);

// gr3->Draw();

    TMultiGraph *multiGr = new TMultiGraph();
    multiGr->Add(gr1);
    multiGr->Add(gr2);
    multiGr->Add(gr3);
    multiGr->Draw("ALP");  
    multiGr->SetTitle("Histograms to Graphs");
    cst->Modified();

    cst->Print("Multi_Hist_to_Graph.png");    
}
