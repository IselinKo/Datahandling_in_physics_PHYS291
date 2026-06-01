{
//  To be run after the  p2_hist_fit.C 
//
// extra 4 plot  - adding the  FWHM  demonstration
// using the  Peak position, Peak Width (FWHM) 
// and the Peak Value - half   (Full Width at Half Maximum)

//chist2->cd();                           //   Make sure to plot in TCanvas chist2
double xa[2]; double ya[2];	
xa[0]=peakPos-width/2.0;  xa[1]=xa[0]; //    peakPos-width/2.0
ya[0]=0;  ya[1]=peakVal/2.0;           //    vertical

TGraph *gr1=new TGraph(2,xa,ya);
chist2->cd();        // assuring that we plot in the right TCanvas

gr1->Draw("same");

double xb[2]; 
xb[0]=peakPos+width/2.0;  xb[1]=xb[0];  //    peakPos+width/2.0
TGraph *gr2=new TGraph(2,xb,ya);        //    vertical
gr2->Draw("same");

double xc[2]; double yc[2];	             //        horizontal
xc[0]=peakPos-width/2.0;  xc[1]=peakPos+width/2.0;
yc[0]=peakVal/2.0;  yc[1]=peakVal/2.0;   //        peakVal/2.0

TGraph *gr3=new TGraph(2,xc,yc);
gr3->Draw("same");

double xm[2]; double ym[2];	
xm[0]=peakPos;  xm[1]=xm[0];   //    peakPosition, peakValue
ym[0]=0;  ym[1]=peakVal;       //    vertical

TGraph *gr4=new TGraph(2,xm,ym);
gr4->Draw("same");

}
