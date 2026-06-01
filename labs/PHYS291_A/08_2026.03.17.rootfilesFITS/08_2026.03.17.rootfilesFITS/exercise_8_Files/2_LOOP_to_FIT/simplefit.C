{
//  THIS IS A SINGLE fit version, only k=4 is done

	TFile * ggg=new TFile("six_hist.root"); // file six_hist.root with histos
    
	TString Names[6]={"both", "asym", "single", "close", "far", "flat"};
	TString HiNm;
	TH1F * h2p[10];
	TF1 * plfun[10]; 
	TF1 * tryfun[10]; 

    TCanvas *canvF;
    TCanvas *canv;
//
//   ADD  functions into strings
//  
    TString fun1 = "[0]-[1]*x";                            //  a -  b * x
    TString fun2 = "+[2] * exp(- (x-[4])*(x-[4]) * [3] )"; //+c* exp(-d*(x-e)*(x-e))
    TString fun3 = "+[5] * exp(- (x-[7])*(x-[7]) * [6] )";
    TString fun4 = fun1  + fun2 + fun3;

	TF1 *dgaus=new TF1("dgaus",fun4,-5.0,10.0);  // see dgaus->SetRange()

	TString pfun="plfun";
	TString tfun="tryfun";
	TString shist="Hist ";  TString sfunc="Func ";

	double lty ;
	double rty ;
	double ltx ;
	double rtx;
	int  NBINS;
	double pars[8];

   int k=4;     // {
	HiNm="LL_"+Names[k];
	cout << HiNm << endl;
	
	h2p[k]=(TH1F*) ggg->Get(HiNm);
	
	canv   = new TCanvas(Names[k],shist+char(49+k)+" "+Names[k],30+k*150,30+k*20,600,400);
	canvF= new TCanvas("f"+Names[k],sfunc+char(49+k),30+k*150,300+k*20,600,400);
		canv->cd();
        h2p[k]->SetTitle(Names[k]);
		h2p[k]->Draw();

		NBINS=h2p[k]->GetNbinsX();
		lty = h2p[k]->GetBinContent(1);
		rty = h2p[k]->GetBinContent(NBINS-1); 
		ltx = h2p[k]->GetBinCenter(1);
		rtx = h2p[k]->GetBinCenter(NBINS-1);

		pars[0]= lty;    //  lt  end value
		pars[1]=-( rty - lty ) / ( rtx - ltx );

		pars[2]=h2p[k]->GetMaximum() - (lty + rty )/2.0;
		pars[5]= pars[2];

		pars[7]= rtx - (rtx-ltx)/4.0;
		pars[4]= ltx + (rtx-ltx)/4.0;

		pars[3]= 10.0/(rtx-ltx);
		pars[6] = pars[3];

		dgaus->SetParameters(pars);
		dgaus->SetRange(ltx,rtx);
		tryfun[k]=(TF1 * )dgaus->Clone(tfun+char(48+k));
		h2p[k]->SetMinimum(0);   // to start plot from y=0
		canv->Modified();        
		h2p[k]->Fit("dgaus");
			plfun[k]=(TF1 * )dgaus->Clone(pfun+char(48+k));
        canv->Print(Names[k]+".png");
        
		canvF->cd();
		plfun[k]->SetLineWidth(6);
		plfun[k]->Draw();   plfun[k]->SetMinimum(0);    canvF->Modified();
		tryfun[k]->SetLineColor(kGray);
        tryfun[k]->Draw("same");
		cout << HiNm << "   " << shist+char(48+k)+" "+Names[k] << endl;        
        canvF->Print(Names[k]+"_fit_funct.png");
	//   loop over k removed }
}
