{  
   //    Nameless script / macro   multigraph.C 
   //
   //    Draw three simple graphs
   //
   //    Using   TMultiGraph    
   //
   //    Author: L. Kocbach modifying R. Brun
   
   TCanvas *c1 = new TCanvas("c1","Three Simple Graphs",200,10,800,600);

   TMultiGraph *ThreeGr = new TMultiGraph();
 
  const Int_t n = 100;
  
   Double_t x[n], y[n], y2[n], y3[n];
 
  for (Int_t i=0;i<n;i++) {
     x[i] = i*0.1;
     y[i] =  5*sin(x[i]+0.2);
     y2[i] = 10*sin(1.5*x[i]+0.2)*exp(-0.3*x[i]);
     y3[i] = 0.5*cos(2.4*x[i]+0.2)*exp(0.3*x[i]);
     printf(" i %i %f %f \n",i,x[i],y[i]);
   }
   TGraph *gr1 = new TGraph(n,x,y);
   TGraph *gr2 = new TGraph(n,x,y2);
   TGraph *gr3 = new TGraph(n,x,y3);
   
   ThreeGr->Add(gr1);
   ThreeGr->Add(gr2);
   ThreeGr->Add(gr3);
   
   gr1->SetLineColor(6);
   gr1->SetLineWidth(1);

   gr2->GetXaxis()->SetTitle("X title");
   gr2->GetYaxis()->SetTitle("Y title");

   gr2->SetLineColor(49);
   gr2->SetLineWidth(4);

   gr3->SetLineColor(49);
   gr3->SetLineWidth(2);
   
   ThreeGr->Draw("ACP");

   // TCanvas::Update() draws the frame, after which one can change it
   c1->Update();
   c1->SetGridx();
   c1->GetFrame()->SetBorderSize(12);
   c1->Modified();
}

