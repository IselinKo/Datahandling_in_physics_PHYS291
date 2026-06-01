//  File Cgraph2.C
//  run as               root graph2.C
//  or compile as        root graph2.C+
#include <iostream>
#include "TCanvas.h"
#include "TGraph.h"
#include "TMultiGraph.h"
#include "TAxis.h"
#include "TMath.h"

void graph2() {

   TCanvas *c1 = new TCanvas("c1","A Simple Graph Example",200,10,700,500);

   c1->SetGrid();
   TMultiGraph *multi = new TMultiGraph();
 
  const Int_t n = 100;
   Double_t x[n], y[n], y1[n];
 
  for (Int_t i=0;i<n;i++) {
     x[i] = i*0.1;
     y[i] = 10*sin(x[i]+0.2);
     y1[i] = 9*sin(x[i]+0.2)*exp(-0.3*x[i]);
     printf(" i %i %f %f \n",i,x[i],y[i]);
   }
   TGraph *gr = new TGraph(n,x,y);

   multi->Add(gr);
   TGraph *gr2 = new TGraph(n,x,y1);
   multi->Add(gr2);
   gr->SetLineColor(2);
   gr->SetLineWidth(2);
   gr2->SetLineColor(31);
   gr2->SetLineWidth(2);

   multi->Draw("ACP");
   multi->GetXaxis()->SetTitle("X title added here [cm]");
   multi->GetYaxis()->SetTitle("Y title [J]");
   multi->GetXaxis()->CenterTitle(true);
   multi->GetYaxis()->CenterTitle(true);  

   c1->Update();
   c1->Modified();	
}
