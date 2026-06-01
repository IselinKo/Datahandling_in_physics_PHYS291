void surf_Demo(){  
   //  Demonstration of TGraph2d
   
   double x[10000]; double y[10000]; double z[10000];
   double xx,yy;
   int kx,ky, kt;
   int Nx,Ny;  // Number of points in x and y direction
   
   // The ( x,y) matrix is not used explicitely
   // instead the points are set linearly into  x[ ] y[ ] z[ ] 
   // unlike in other systems, there is no  x[ ] y[ ] z[ ][ ]

   Nx=80; Ny=80;    
   kt=0;
   for (kx=0;kx<Nx;kx++) {
      xx=-4+0.1*kx; 
      for (ky=0;ky<Ny;ky++) {
           yy=-4+0.1*ky; x[kt]=xx; y[kt]=yy;
           z[kt]=3.0*exp(-(xx-0.9)*(xx-0.9)-1.5*(yy+0.7)*(yy+0.7));
           z[kt]=z[kt]+2.5*exp(-0.8*(xx+0.9)*(xx+0.9)-0.4*(yy-0.9)*(yy-0.9));
           kt++;
      }
   }
   TGraph2D *dt2 = new TGraph2D(Nx*Ny,x,y,z);
   dt2->SetTitle("Demo of surface graph2D; X axis title; Y axis title; Z axis title");
   dt2->GetHistogram()->GetXaxis()->SetTitleOffset(2) ;
   dt2->GetHistogram()->GetXaxis()->CenterTitle(true);
   dt2->GetHistogram()->GetYaxis()->SetTitleOffset(2.); 
   dt2->GetHistogram()->GetZaxis()->CenterTitle(false); 
   dt2->GetHistogram()->GetYaxis()->CenterTitle(true);
   dt2->GetHistogram()->GetZaxis()->SetTitleOffset(+1.3);

   TCanvas *c2d = new TCanvas("c2d","Graph2D example",30,30,600,400);
   gStyle->SetPalette(53);
   dt2->Draw("surf2");   
   //  Rotate the viewpoint to Theta, Phi
   gPad->SetTheta(60);   //     30 is default
   gPad->SetPhi(60);    //     30 is default 
   
   TCanvas *d2d = new TCanvas("d2d","Graph2D example",500,30,600,400);
   gStyle->SetPalette(87);
   dt2->Draw("surf3");   
   //  Rotate the viewpoint to Theta, Phi
   gPad->SetTheta(45);   //     30 is default
   gPad->SetPhi(145);    //     30 is default 

   TCanvas *e2d = new TCanvas("e2d","Graph2D example",30,400,600,400);
   // no colorgStyle->SetPalette(53);
   dt2->Draw("surf6");   
   //  Rotate the viewpoint to Theta, Phi
   gPad->SetTheta(45);   //     30 is default
   gPad->SetPhi(245);    //     30 is default       

   TCanvas *f2d = new TCanvas("f2d","Graph2D example",500,400,600,400);
   gStyle->SetPalette(95);
   dt2->Draw("surf7");   
   //  Rotate the viewpoint to Theta, Phi
   gPad->SetTheta(45);   //     30 is default
   gPad->SetPhi(45);    //     30 is default 
}
