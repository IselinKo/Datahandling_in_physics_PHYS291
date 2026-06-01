{  
   //    Nameless script / macro   multigraph3MOD.C 
   //
   //    Using   TMultiGraph    
   //
   
   TCanvas *Cmulti = new TCanvas("Cmulti","Three Simple Graphs with 0",200,10,800,600);

   TMultiGraph *ThreeGrZERO = new TMultiGraph();

// add the constants for the beer drinking problem 
   const int  n = 15;
  
   double x[n], week_cost[n], friday_cost[n], diff[n]; 
   double xzer[2], zeros[2];        // for the zero-line 
   
   week_cost[0] = 0;
   friday_cost[0] = 220;
 
  for (Int_t i=0;i<n;i++) {
     x[i] = i;
     week_cost[i] = x[i]*50;
     friday_cost[i] = x[i]*20 + friday_cost[0];
     diff[i] = week_cost[i] - friday_cost[i];
     //     printf(" i %i %f %f \n",i,x[i],y[i]);
   }
   xzer[0]=0.0; xzer[1]=x[n-1]; zeros[0]=0.0; zeros[1]=0.0; //  zero-line 
   
   TGraph *gr1 = new TGraph(n,x,week_cost);
   TGraph *gr2 = new TGraph(n,x,friday_cost);
   TGraph *gr3 = new TGraph(n,x,diff);
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

   gr3->SetLineColor(kBlue);
   gr3->SetLineWidth(2);

   gzero->SetLineColor(kRed);    //  zero-line 
   gzero->SetLineWidth(3);    //  zero-line 

   ThreeGrZERO->Draw("ACP");
   
   TLegend *leg = new TLegend(0.7, 0.7, 0.9, 0.9); // (x1,y1,x2,y2) in NDC

	leg->AddEntry(gr1, "Week cost", "l");
	leg->AddEntry(gr2, "Friday cost", "l");
	leg->AddEntry(gr3, "Difference", "l");
	leg->AddEntry(gzero, "Zero line", "l");

	leg->Draw();

   Cmulti->SetGridx();

  // These axes titles work for all graphs
   ThreeGrZERO->GetXaxis()->SetTitle("X number of beers");
   ThreeGrZERO->GetYaxis()->SetTitle("Price [kr]");
   ThreeGrZERO->GetXaxis()->CenterTitle(true);          //  Axis label in the center
   ThreeGrZERO->GetYaxis()->CenterTitle(true);          //  Axis label in the center
   //   Somewhat special for multigraph
   ThreeGrZERO->GetHistogram()->SetTitle("Expence of bar experience, weekdays vs friday");

   Cmulti->Print("discount.png");
}

