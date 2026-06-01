{
    gROOT->ProcessLine(".L axlabel.C");

   //    Nameless script / macro   multigraph.C 
   //
   //    Draw three simple graphs
   //
   //    Using   TMultiGraph    
   //
   //    Author: L. Kocbach modifying R. Brun   
   TCanvas *cthr = new TCanvas("cthr","ThreeM Simple Graphs",200,10,800,600);
   TMultiGraph *ThreeMGr = new TMultiGraph();
 
  const Int_t n = 100;  
   Double_t x[n], y[n], y2[n], y3[n];
 
  for (Int_t i=0;i<n;i++) {
     x[i] = i*0.1;
     y[i] =  5*sin(x[i]+0.2);
     y2[i] = 10*sin(1.5*x[i]+0.2)*exp(-0.3*x[i]);
     y3[i] = 0.5*cos(2.4*x[i]+0.2)*exp(0.3*x[i]);
     // printf(" i %i %f %f \n",i,x[i],y[i]);
   }
   TGraph *Agr1 = new TGraph(n,x,y);
   TGraph *Agr2 = new TGraph(n,x,y2);
   TGraph *Agr3 = new TGraph(n,x,y3);
   
   ThreeMGr->Add(Agr1);
   ThreeMGr->Add(Agr2);
   ThreeMGr->Add(Agr3);
   
   Agr1->SetLineColor(6);
   Agr1->SetLineWidth(1);
   Agr2->SetLineColor(49);
   Agr2->SetLineWidth(4);
   Agr3->SetLineColor(49);
   Agr3->SetLineWidth(2);
   
   ThreeMGr->Draw("ACP");

   xlabel( ThreeMGr, "xxx"); //-------------------------------------------
   //ylabel( ThreeMGr, "yyy"); //-------------------------------------------

   cthr->Update();
   cthr->SetGridx();
   cthr->GetFrame()->SetBorderSize(12);
   cthr->Modified();
}

