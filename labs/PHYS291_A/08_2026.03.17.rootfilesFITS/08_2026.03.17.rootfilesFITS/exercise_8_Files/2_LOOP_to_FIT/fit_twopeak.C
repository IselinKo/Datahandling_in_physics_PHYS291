{
//   fit_twopeak.C
//   
//   TF1 *twogaus=new TF1("twogaus",fun4,-4.0,4.0);
//
//   cout <<  twogaus->GetRandom() << "  \n";
//
TCanvas *cfunO = new TCanvas("cfunO","Function",350,50,600,400);
TCanvas *chistO = new TCanvas("chistO","Histogram",300,350,600,400);

//
//   ADD long functions into strings
//  
    TString fun1 = "[0]-[1]*x";
    TString fun2 = "+[2] * exp(- (x-[4])*(x-[4]) * [3] )";
    TString fun3 = "+[5] * exp(- (x-[7])*(x-[7]) * [6] )";
    TString fun4 = fun1  + fun2 + fun3;

    TF1 *twopeak=new TF1("twopeak",fun4,-4.0,4.0);
    TF1 *twogaus=new TF1("twogaus",fun4,-4.0,4.0); // clone in easy way

double params[8]={4.0, 0.35, 3.0, 5.0,   -2.0, 5.0, 4.0,  1.5};
//                a    b     c  inv_width pos  c  inv.w. pos
//
    twopeak->SetParameters(params);
    twogaus->SetParameters(params);    // clone in easy way
cfunO->cd();
    twopeak->Draw();
    twopeak->SetMinimum(0);   // to start plot from y=0
cfunO->Modified();

chistO->cd();    
    TH1F *htwo = new TH1F("htwo","x distribution",100,-4,4);
htwo->FillRandom("twogaus",10000);
htwo->Draw();
htwo->SetMinimum(0);   // to start plot from y=0
chistO->Modified();
twogaus->SetLineColor(kOrange);
htwo->Fit("twogaus");
       //  Preserve the fit by fetching and cloning
       TF1 *fitfun=(TF1*)htwo->GetFunction("twogaus");
       TF1 *savefun=(TF1*)fitfun->Clone("savefun");
cout << "\n\n   bad start parameters for fiting  \n";
cout <<     "   type   .x fit.C   \n\n";
}