void mingraph()
{
   const int n = 20;  int i;
   double x[n], y[n];

   for (i=0;i<n;i++) {
     x[i] = i*0.2;
     y[i] = 10.0*sin(3.0*x[i]+0.2)*exp(-0.5*x[i]);
   }
   
   TCanvas *cgr = new TCanvas("cgr","Graph");
   TGraph  *gr = new TGraph(n,x,y);     //  x[i], y[i]
   gr->Draw("ACP");
}
