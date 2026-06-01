{  
   //    Nameless script / macro   multigraph3MOD.C 
   //
   //    Using   TMultiGraph    
   //
   
   TCanvas *Cmulti = new TCanvas("Cmulti","Three Simple Graphs with 0",200,10,800,600);

   TMultiGraph *ThreeGrZERO = new TMultiGraph();
 
   const int  n = 100;
  
   double x[n], y[n], y2[n], y3[n]; 
   double xzer[2], zeros[2];        // for the zero-line    
 
  for (Int_t i=0;i<n;i++) {
     x[i] = i*0.1;
     y[i] =  5*sin(x[i]+0.2);
     y2[i] = 10*sin(1.5*x[i]+0.2)*exp(-0.3*x[i]);
     y3[i] = 0.5*cos(2.4*x[i]+0.2)*exp(0.3*x[i]);
     //     printf(" i %i %f %f \n",i,x[i],y[i]);
   }
   xzer[0]=0.0; xzer[1]=x[n-1]; zeros[0]=0.0; zeros[1]=0.0; //  zero-line 
   
   TGraph *gr1 = new TGraph(n,x,y);
   TGraph *gr2 = new TGraph(n,x,y2);
   TGraph *gr3 = new TGraph(n,x,y3);
   TGraph *gzero = new TGraph(2,xzer,zeros);    //  zero-line 
   
   ThreeGrZERO->Add(gr1);
   ThreeGrZERO->Add(gr2);
   ThreeGrZERO->Add(gr3);
   ThreeGrZERO->Add(gzero);

   gr1->SetLineColor(6);
   gr1->SetLineWidth(1);

   gr2->GetXaxis()->SetTitle("X title");
   gr2->GetYaxis()->SetTitle("Y title");

   gr2->SetLineColor(49);
   gr2->SetLineWidth(4);

   gr3->SetLineColor(49);
   gr3->SetLineWidth(2);

   gzero->SetLineColor(kRed);    //  zero-line 
   gzero->SetLineWidth(3);    //  zero-line 

   ThreeGrZERO->Draw("ACP");

   Cmulti->SetGridx();

  // These axes titles work for all graphs
   ThreeGrZERO->GetXaxis()->SetTitle("Dimensionless X");
   ThreeGrZERO->GetYaxis()->SetTitle("Functions");
   ThreeGrZERO->GetXaxis()->CenterTitle(true);          //  Axis label in the center
   ThreeGrZERO->GetYaxis()->CenterTitle(true);          //  Axis label in the center
   //   Somewhat special for multigraph
   ThreeGrZERO->GetHistogram()->SetTitle("Title of the 3 Graphs with 0");

   Cmulti->Print("ThreGraphs.png");
}

