{
   // Show 3-D polylines 
   //   Based on root tutorials basic3d.C; L. Kocbach 2020

   TCanvas *c1 = new TCanvas("c1","PolyLine3D  Window",200,10,700,500);
   int Npt=200; double Phi; double R=8.0;
   double x,y,z, xmin,xmax,ymin,ymax,zmin,zmax;
   xmin=5; xmax=25;  ymin=5; ymax=25;  zmin=5; zmax=25;

   // create a view
   view = TView::CreateView(1);
   view->SetRange(xmin,ymin,zmin,xmax,ymax,zmax);

   // create a  PolyLine3D
     TPolyLine3D *pl3d1 = new TPolyLine3D(Npt);
     for (int k=0; k<Npt; k++){
       Phi=(double)k*0.3;
       R=R-8.0/(double)Npt;
       x=15+R*cos(Phi);y=10+R*sin(Phi);z=5.0+(double)k*20/(double)Npt;
       pl3d1->SetPoint(k, x,y,z);      // set points
      }
   pl3d1->SetLineWidth(5);
   pl3d1->SetLineColor(kOrange);
   pl3d1->Draw();
     R=9.0;
   // create a  PolyLine3D
     TPolyLine3D *pl3d2 = new TPolyLine3D(Npt);
     for (int k=0; k<Npt; k++){
       Phi=(double)k*0.3;
       R=R-8.0/(double)Npt;
       x=10+R*cos(Phi);y=15-R*sin(Phi);z=5.0+(double)k*15/(double)Npt;
       pl3d2->SetPoint(k, x,y,z);       // set points
      }
   pl3d2->SetLineWidth(3);
   pl3d2->SetLineColor(kBlue);

   pl3d2->Draw();   
}
