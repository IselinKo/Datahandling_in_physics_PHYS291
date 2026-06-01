{
//   The program draws the fits in 5 different windows
//   It plots the fitting functions before the fit in 5 windows
//   All the windows are saved as PNG files
//

	TFile * ggg=new TFile("six_hist.root"); // root file with histograms
    
	TString Names[6]={"both", "asym", "single", "close", "far", "flat"};
	TString HistName;
	TH1F *his2peak[10];
	TF1 * plotfun[10]; 
	TF1 * tryfun[10]; 

    TCanvas *canvasFun[10];
    TCanvas *canvas[10];
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

for(int k=0;k<6;k++) {
	HistName="LL_"+Names[k];
	cout << HistName << endl;
	
	his2peak[k]=(TH1F*) ggg->Get(HistName);
	
	canvas[k]=new TCanvas(Names[k],shist+char(49+k)+" "+Names[k],30+k*150,30+k*20,600,400);
	canvasFun[k]=new TCanvas("f"+Names[k],sfunc+char(49+k),30+k*150,300+k*20,600,400);
		canvas[k]->cd();
        his2peak[k]->SetTitle(Names[k]);
		his2peak[k]->Draw();

		NBINS=his2peak[k]->GetNbinsX();
		lefty = his2peak[k]->GetBinContent(1);
		righty = his2peak[k]->GetBinContent(NBINS-1); 
		leftx = his2peak[k]->GetBinCenter(1);
		rightx = his2peak[k]->GetBinCenter(NBINS-1);

		nparams[0]= lefty;    //  Left  end value
		nparams[1]=-( righty - lefty ) / ( rightx - leftx );

		nparams[2]=his2peak[k]->GetMaximum() - (lefty + righty )/2.0;
		nparams[5]= nparams[2];

		nparams[7]= rightx - (rightx-leftx)/4.0;
		nparams[4]= leftx + (rightx-leftx)/4.0;

		nparams[3]= 10.0/(rightx-leftx);
		nparams[6] = nparams[3];

		twogaus->SetParameters(nparams);
		twogaus->SetRange(leftx,rightx);
		tryfun[k]=(TF1 * )twogaus->Clone(tfun+char(48+k));
		his2peak[k]->SetMinimum(0);   // to start plot from y=0
		canvas[k]->Modified();        
		his2peak[k]->Fit("twogaus");
			plotfun[k]=(TF1 * )twogaus->Clone(pfun+char(48+k));
        canvas[k]->Print(Names[k]+".png");
        
		canvasFun[k]->cd();
		plotfun[k]->SetLineWidth(6);
		plotfun[k]->Draw();   plotfun[k]->SetMinimum(0);    canvasFun[k]->Modified();
		tryfun[k]->SetLineColor(kGray);
        tryfun[k]->Draw("same");
		cout << HistName << "   " << shist+char(48+k)+" "+Names[k] << endl;        
        canvasFun[k]->Print(Names[k]+"_fit_funct.png");
	}
}
