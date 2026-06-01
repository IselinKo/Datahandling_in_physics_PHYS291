{
// #include "clicks_func.C"
gROOT->ProcessLine(".L clicks_func.C");	

  // Shows all types of events, prints the code of the event
  // and the data of the event
  // for mouse movement, the coordinates
  // for keyboard events the code
  //
  // Taken from Tutorials:
  //generate small triangles randomly in the canvas.
  //Each triangle has a unique id and a random color in the color palette
  //
  //then click on any triangle. A message showing the triangle number
  //and its color will be printed.
  //
  const Int_t ntriangles=10;  
  TCanvas *c1 = new TCanvas("c1","triangles",10,10,700,700);
  TRandom *r; r=gRandom;
  Double_t dx = 0.2; Double_t dy = 0.2;
  //Int_t ncolors = gStyle->GetNumberOfColors();
  ncolors = 20;
  Double_t x[4],y[4];
  TColor *c;
  Int_t ci;
  for (Int_t i=0;i<10;i++) {
     x[0] = r->Uniform(.05,.95); y[0] = r->Uniform(.05,.95);
     x[1] = x[0] + dx*r->Rndm(); y[1] = y[0] + dy*r->Rndm();
     x[2] = x[1] - dx*r->Rndm(); y[2] = y[1] - dy*r->Rndm();
     x[3] = x[0];               y[3] = y[0];
     TPolyLine *pl = new TPolyLine(4,x,y);
     pl->SetUniqueID(i);
     ci = r->Integer(ncolors);
     c  = gROOT->GetColor(ci);
     c->SetAlpha(r->Rndm());
     pl->SetFillColor(ci);
     pl->Draw("f");
  }
  c1->AddExec("ex","clicks_func()");
}

