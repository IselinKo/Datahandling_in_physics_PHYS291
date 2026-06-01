void axigraph()
{
   const int n = 20;  int i;
   double x[n], y[n];

   for (i=0;i<n;i++) {
     x[i] = i*0.2;
     y[i] = 10.0*sin(3.0*x[i]+0.2)*exp(-0.5*x[i]);
     printf("%10.3f %10.6f \n",x[i],y[i]);
   }
   
   TCanvas *cgrax = new TCanvas("cgrax","Graph",400,180,700,500);
   TGraph  *gra = new TGraph(n,x,y);     //  x[i], y[i]
   gra->Draw("ACP");

// Add line at y=0 to show the zero level
   
   double xax[2], yax[2];       // This extra for y=0 line
   xax[0]=x[0];  xax[1]=x[n-1]; // first and last of x
   yax[0]=0.0;   yax[1]=0.0;    // This extra for y=0 line
   TGraph  *graxis = new TGraph(2,xax,yax); 
   graxis->Draw("SAME");
   
   cgrax->Print("axigraph.png");
   cgrax->Print("axigraph.pdf");
}
