{
//   This version of the program draws really all of the histograms
//   It has been modified to draw and fit all 6 in file in 6 different windows
//   It should plot also the fitting functions after the fit in 6 windows
//   All the windows should be saved as PNG files
//
//
TFile * ggg=new TFile("six_hist.root");  // root file with histograms

TString Names[6]={"both", "asym", "single", "close", "far", "flat"};
TString HistName;    // Modified to LL_both, LL_asym .... needs only one, not array
TCanvas *canvas[6];     //  Must be made to an array  [6]  (could be [10] or [100])
TCanvas *canvfunc[6];    //  Must be made to an array  [6], or [10] ... for this file
int k=0;              // for the looping over histograms  set to 4 in test
TH1F *his2peak[6];      //Histograms  must be made [6] make it to his2peak[k]
TF1 * plotfun[6];   //  also this - function(s) for each name - done here
TF1 * tryfun[6];       //  also this - function(s) for each name - done here
TF1 * twogaus[6];    //  as well as here  (the fit functions)
TString twogausname="twogaus";  TString Num;   // for esy passing of name, see below
char buffer[100];  //  for printing   - special feature, sprintf(buffer + i*len
//
//   ADD  functions into strings (2 peaks and one )
//  
    TString fun1 = "[0]-[1]*x";                     //  a -  b * x
    TString fun2 = "+[2] * exp(- [3]*(x-[4])**2 )"; // +c * exp(-d*(x-e)**2)
    TString fun3 = "+[5] * exp(- [6]*(x-[7])**2 )";
    TString fun4 = fun1  + fun2 + fun3;

	TString pfun="plotfun";
	TString shist="Histogram ";  TString sfunc="Function ";

	//    The names of histograms stored in the file

	double lefty ;
	double righty ;
	double leftx ;
	double rightx;
	int  NBINS;
	double nparams[6][8];     //   could be just nparams[8]; for setting
                                  //   extended to nparams[6][8]; FOR GETTING
        k=4;    // use when testing the look, try k=0, or k=5 etc
  for(int k=0;k<6;k++) {
	HistName="LL_"+Names[k];  // k=4 in this test
	cout << HistName << endl;

       Num=(char)(48+k); twogausname="twogaus"+Num;   // this added 2025 See fit
       twogaus[k]=new TF1(twogausname,fun4,-10,10);  // see twogaus[ ]->SetRange()
	
       his2peak[k]=(TH1F*) ggg->Get(HistName);   //  make it to his2peak[k]
	
       canvas[k] = new TCanvas(Names[k],shist+char(49+k)+" "+Names[k],30+k*150,30+k*20,600,400);
       canvfunc[k] = new TCanvas("f"+Names[k],sfunc+char(49+k),30+k*150,300+k*20,600,400);

        canvas[k]->cd();
        his2peak[k]->SetTitle(Names[k]);
	    his2peak[k]->Draw();

		NBINS=his2peak[k]->GetNbinsX();
		lefty = his2peak[k]->GetBinContent(1);
		righty = his2peak[k]->GetBinContent(NBINS-1); 
		leftx = his2peak[k]->GetBinCenter(1);
		rightx = his2peak[k]->GetBinCenter(NBINS-1);

		nparams[k][0]= lefty;    //  Left  end value
		nparams[k][1]=-( righty - lefty ) / ( rightx - leftx );

		nparams[k][2]=his2peak[k]->GetMaximum() - (lefty + righty )/2.0;
		nparams[k][5]= nparams[k][2];

		nparams[k][7]= rightx - (rightx-leftx)/4.0;
		nparams[k][4]= leftx + (rightx-leftx)/4.0;

		nparams[k][3]= 10.0/(rightx-leftx);
		nparams[k][6] = nparams[k][3];

		twogaus[k]->SetParameters(nparams[k]); // note: nparams[k] used as pointer
		twogaus[k]->SetRange(leftx,rightx);
		his2peak[k]->SetMinimum(0);   // to start plot from y=0
		canvas[k]->Modified();        
            //     Monitor fitting - changing nparams     NOTE THE buffer+8*i trick
                for(int i=0;i<8;i++) sprintf(buffer+8*i,"%7.1f ",nparams[k][i]); 
                tryfun[k] = (TF1 * )twogaus[k]->Clone("tryfun[k]");
		his2peak[k]->Fit(twogausname);  // passing func to fit avoiding "twogaus[k]"
                            //  but use the pointers  twogaus[k] for GETTING
            for(int i=0;i<8;i++) nparams[k][i]=twogaus[k]->GetParameter(i);
            cout << "Monitor fitting - changing nparams\n"; // buffer filled above
            cout << buffer << endl;  
            for(int i=0;i<8;i++) printf("%7.1f ",nparams[k][i]);printf("\n");
		plotfun[k]=(TF1 * )twogaus[k]->Clone("plotfun[k]");
        canvas[k]->Print(Names[k]+".png");
        
	canvfunc[k]->cd();
                plotfun[k]->SetLineWidth(4);
		plotfun[k]->Draw();   plotfun[k]->SetMinimum(0);    canvfunc[k]->Modified();
                tryfun[k]->SetLineColor(kGray);
                tryfun[k]->Draw("same");
		cout << HistName << "   " << shist+char(48+k)+" "+Names[k] << endl;        
        canvfunc[k]->Print(Names[k]+"_fit_funct.png");
   } // Ending the k-loop here when all 6 done  

   //   The following  four lines are added to do  the the reporting  
   for(int row=0;row<6;row++){
       for(int I=0;I<8;I++) printf(" %7.2f ",nparams[row][I]);
       cout << "   LL_"<< Names[row] << endl;
    }
}

