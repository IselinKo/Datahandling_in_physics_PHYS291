{
//   The program draws the fits in 6 different windows
//   It plots the fitting functions before the fit in 6 windows
//   All the windows are saved as PNG files
//

	TFile * ggg=new TFile("six_hist.root"); // root file with histograms
    
	TString Names[6]={"both", "asym", "single", "close", "far", "flat"};
	TString HistName;
	TH1F *his2peak;
	TF1 * plotfun; 
	TF1 * tryfun; 

    TCanvas *canvasFun;
    TCanvas *canvas;
//
//   ADD  functions into strings
//  
    TString fun1 = "[0]-[1]*x";                            //  a -  b * x
    TString fun2 = "+[2] * exp(- (x-[4])*(x-[4]) * [3] )"; //+c* exp(-d*(x-e)*(x-e))
    TString fun3 = "+[5] * exp(- (x-[7])*(x-[7]) * [6] )";
    TString fun4 = fun1  + fun2 + fun3;

	TF1 *twogaus=new TF1("twogaus",fun4,-5.0,10.0);  // see twogaus->SetRange()

	TString pfun="plotfun";
	TString tfun="tryfun";
	TString shist="Histogram ";  TString sfunc="Function ";

	//    The names of histograms stored in the file

	double lefty ;
	double righty ;
	double leftx ;
	double rightx;
	int  NBINS;
	double nparams[8];

k=4;    //  for( k=0;k<6;k++) {
	HistName="LL_"+Names[k];
	cout << HistName << endl;
	
	his2peak=(TH1F*) ggg->Get(HistName);
	
	canvas=new TCanvas(Names[k],shist+char(49+k)+" "+Names[k],30+k*150,30+k*20,600,400);
	canvasFun=new TCanvas("f"+Names[k],sfunc+char(49+k),30+k*150,300+k*20,600,400);
		canvas->cd();
        his2peak->SetTitle(Names[k]);
		his2peak->Draw();

		NBINS=his2peak->GetNbinsX();
		lefty = his2peak->GetBinContent(1);
		righty = his2peak->GetBinContent(NBINS-1); 
		leftx = his2peak->GetBinCenter(1);
		rightx = his2peak->GetBinCenter(NBINS-1);

		nparams[0]= lefty;    //  Left  end value
		nparams[1]=-( righty - lefty ) / ( rightx - leftx );

		nparams[2]=his2peak->GetMaximum() - (lefty + righty )/2.0;
		nparams[5]= nparams[2];

		nparams[7]= rightx - (rightx-leftx)/4.0;
		nparams[4]= leftx + (rightx-leftx)/4.0;

		nparams[3]= 10.0/(rightx-leftx);
		nparams[6] = nparams[3];

		twogaus->SetParameters(nparams);
		twogaus->SetRange(leftx,rightx);
		tryfun=(TF1 * )twogaus->Clone(tfun+char(48+k));
		his2peak->SetMinimum(0);   // to start plot from y=0
		canvas->Modified();        
		his2peak->Fit("twogaus");
			plotfun=(TF1 * )twogaus->Clone(pfun+char(48+k));
        canvas->Print(Names[k]+".png");
        
		canvasFun->cd();
		plotfun->SetLineWidth(6);
		plotfun->Draw();   plotfun->SetMinimum(0);    canvasFun->Modified();
		tryfun->SetLineColor(kGray);
        tryfun->Draw("same");
		cout << HistName << "   " << shist+char(48+k)+" "+Names[k] << endl;        
        canvasFun->Print(Names[k]+"_fit_funct.png");
	//   no   loop over k }
}
