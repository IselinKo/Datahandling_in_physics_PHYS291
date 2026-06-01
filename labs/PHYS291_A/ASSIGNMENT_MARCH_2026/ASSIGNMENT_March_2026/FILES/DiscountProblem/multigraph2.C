{  
   //    Nameless script / macro   multiGR.C 
   //
   //    Draw two simple graphs
   //
   //    Using   TMultiGraph    
   //
   //    Author: L. Kocbach modifying R. Brun
   
   TCanvas *c1 = new TCanvas("c1","Two Simple Graphs",200,10,800,600);

   TMultiGraph *TwoGr = new TMultiGraph();
 
  const Int_t n = 20;
  
   Double_t x[n], y[n], y2[n], y3[n];
 
  for (Int_t i=0;i<n;i++) {
     x[i] = i*0.1;
     y[i] =  3+3.5*(x[i]+0.2);
     y2[i] = 10-(x[i]+0.2)*(x[i]+0.2);
     printf(" i %i %f %f %f \n",i,x[i],y[i],y2[i]);
   }
   TGraph *gr1 = new TGraph(n,x,y);
   TGraph *gr2 = new TGraph(n,x,y2);
   
   gr2->SetMinimum(0);

   TwoGr->Add(gr1);
   TwoGr->Add(gr2);
   
   gr1->SetLineColor(6);
   gr1->SetLineWidth(3);

   gr2->GetXaxis()->SetTitle("X title");
   gr2->GetYaxis()->SetTitle("Y title");

   gr2->SetLineColor(49);
   gr2->SetLineWidth(3);

   TwoGr->SetMinimum(0);          // start from zero 
   TwoGr->Draw("ACP");
   TwoGr->GetXaxis()->SetNdivisions(525);  // note this, the axis

   // TCanvas::Update() draws the frame, after which one can change it
   c1->Update();
   c1->SetGrid();                        //  Draw Grid
   c1->GetFrame()->SetBorderSize(12);
   c1->Modified();
}

