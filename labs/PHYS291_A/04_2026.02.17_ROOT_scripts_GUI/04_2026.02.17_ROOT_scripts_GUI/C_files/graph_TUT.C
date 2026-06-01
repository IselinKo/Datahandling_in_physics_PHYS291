void graph_TUT() 
{
// This is slightly modified from the Tutorials
   //Draw a simple graph
   //Original Author: Rene Brun
   //  $ROOTSYS/tutorials/graphs/graph.C
// 
   TCanvas *grcanv = new TCanvas("grcanv","A Simple Graph Example",200,100,700,500);
   grcanv->SetFillColor(42);
   grcanv->SetGrid();
   const Int_t n = 20;
   Double_t x[n], y[n];
   for (Int_t i=0;i<n;i++) {
     x[i] = i*0.2;               
     y[i] = 10.0*sin(3.0*x[i]+0.2)*exp(-0.5*x[i]);
     printf(" %10.6f  %10.6f \n",x[i],y[i]);
   }
   TGraph *gr = new TGraph(n,x,y);
   gr->SetLineColor(2);             // can be removed
   gr->SetLineWidth(4);             // can be removed
   gr->SetMarkerColor(4);           // can be removed
   gr->SetMarkerStyle(21);           // can be removed
   gr->SetTitle("a simple graph");        // can be removed
   gr->GetXaxis()->SetTitle("X title");   // can be removed
   gr->GetYaxis()->SetTitle("Y title");   // can be removed
   gr->Draw("ACP");
   // TCanvas::Update() draws the frame, after which one can change it
   grcanv->Update();
   grcanv->GetFrame()->SetFillColor(21);
   grcanv->GetFrame()->SetBorderSize(12);
   grcanv->Modified();
}
