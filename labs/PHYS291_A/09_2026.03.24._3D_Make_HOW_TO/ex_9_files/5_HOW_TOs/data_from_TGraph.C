{
//  Here we get data from a TGragh
//  First we put data into a TGraph  
//  Using gr1->GetN(); gr1->GetPoint(m,x,y);
//  Also note  TString Onam= gr1->GetTitle();
//             gr1->SetTitle(  Onam + " new part here" );
//
   double X[1000], Y[1000]; 
   double x,y;
   int nlines=10;
   for(int m=0; m<nlines; m++){ 
       x=m*0.15;
       y=sin(2*x)*exp(-0.3*x);
        X[m]=x;  Y[m]=y;  
      cout << m << " " << x << " " << y << endl;
     }
   
   TGraph * gr1 = new TGraph( nlines, X, Y);
   gr1->Draw();
//        If I have the graph   Get the arrays
//        TString Yname=gr1->GetName()

int Npoints = gr1->GetN();
   for(int m=0; m<Npoints; m++){ 
       gr1->GetPoint(m,x,y);
       cout << m << " " << x << " " << y << endl;
  }

}


