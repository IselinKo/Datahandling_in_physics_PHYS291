{
    double params[8]={4.0, 0.35, 3.0, 5.0,   -2.0, 5.0, 4.0,  1.5};
//                a    b     c  inv_width pos  c  inv.w. pos
//
//     Note:2025 versions - the colors changed kOrange, kBlue 
//
//     work with parts, single peak, double peak
//
//   ADD long functions into strings
//   
    TString fun1 = "[0]-[1]*x";                // lin. background
    TString fun2 = "[2] * exp(- [3]*(x-[4])**2  )";
    TString fun3 = fun1 + "+" + fun2;
    TF1 *backgaus=new TF1("backgaus",fun3,-4.0,4.0);

    backgaus->SetParameter(0,3);
    backgaus->SetParameter(1,0.1);
    backgaus->SetParameter(2,3);
    backgaus->SetParameter(3,3.0);    
    backgaus->SetParameter(4,-2.0);
    
    //   backgaus->GetRandom()
    cout <<  backgaus->GetRandom() << "  \n";
    for(int k=0;k<50;k++)  {   
                    cout <<  backgaus->GetRandom() << "  "; }
    cout <<  backgaus->GetRandom() << "  \n";

//
TH1F *dh1 = new TH1F("dh1","x distribution",100,-4,4);

TCanvas *cfunB = new TCanvas("cfunB","Function",50,150,550,400);
TCanvas *chistB = new TCanvas("chistB","Histogram",50,550,550,400);
TCanvas *cfunO = new TCanvas("cfunO","Function",550,150,550,400);
TCanvas *chistO = new TCanvas("chistO","Histogram",550,550,550,400);

cfunB->cd();
backgaus->Draw();
backgaus->SetMinimum(0);   // to start plot from y=0
cfunB->Modified();

chistB->cd();
dh1->FillRandom("backgaus",10000); 
dh1->Draw();
dh1->FillRandom("backgaus",10000);
dh1->Draw();
dh1->SetMinimum(0);   // to start plot from y=0

// Attempt first fit - might fail
dh1->Fit(backgaus);
//  Clone the first fit to fit1gTRY, DRAW kORANGE
TF1 *fit1gTRY = (TF1*) backgaus->Clone("fit1gTRY");

fit1gTRY->SetLineColor(kOrange); fit1gTRY->Draw("same");
chistB->Modified();

//  Attempt second fit, guess better function parameters

backgaus->SetParameters(params);
backgaus->SetParameters(params);
backgaus->SetParameter(0,100);  // guess start
backgaus->SetParameter(1,-10);   // guess sloap
backgaus->SetParameter(2,100);   // guess height   
backgaus->SetParameter(4,2);     // guess pos.  

cfunB->cd();
backgaus->SetLineColorAlpha(kBlue,0.5);
backgaus->SetLineWidth(4);
backgaus->Draw();
backgaus->SetMinimum(0);   // to start plot from y=0
cfunB->Modified();

TF1 *fitbackgaus = (TF1*) backgaus->Clone("fitbackgaus");

chistB->cd();
dh1->Fit(fitbackgaus);
//
//   ADD long functions into strings
//   
    fun1 = "[0]-[1]*x";
    fun2 = "+[2] * exp(-[3]*(x-[4])**2  )";
    fun3 = "+[5] * exp(- [6]*(x-[7])**2  )";
    TString fun4 = fun1  + fun2 + fun3;
    TF1 *twogaus=new TF1("twogaus",fun4,-4.0,4.0);


    twogaus->SetParameters(params);
    //  cfunO->cd();
    //  twogaus->Draw();
    twogaus->SetMinimum(0);   // to start plot from y=0
cfunB->Modified();

chistO->cd();    
    TH1F *htwo = new TH1F("htwo","x distribution",100,-4,4);
htwo->FillRandom("twogaus",100000);
htwo->Draw();
htwo->Fit(twogaus);
htwo->SetMinimum(0);   // to start plot from y=0

TF1 *fit2gTRY = (TF1*) twogaus->Clone("fit2gTRY");
fit2gTRY->SetLineColor(kOrange); fit2gTRY->Draw("same");

twogaus->SetParameters(params);
twogaus->SetParameters(params);
twogaus->SetParameter(0,1000);  // guess start
twogaus->SetParameter(1,-50);   // guess sloap
twogaus->SetParameter(2,100);   // guess height   1
twogaus->SetParameter(4,-3);  // guess pos.  1
twogaus->SetParameter(5,250);   // guess height 2
twogaus->SetParameter(7,3);   // guess pos.  2

cfunO->cd();
    twogaus->SetLineColor(kBlue);
    twogaus->Draw();
cfunO->Modified();

TF1 *fit2gaus = (TF1*) twogaus->Clone("fit2gaus");
//fit2gaus->SetLineColor(kYellow);
fit2gaus->SetLineColorAlpha(kBlue,0.5);
fit2gaus->SetLineWidth(4);
chistO->cd(); 
htwo->Fit(fit2gaus);
chistO->Modified();
cout << "Functions plotted: have parameters passed as start to the fit calls\n";
cout << "In histgrams: Orange are the unsuccesful fits with original parameters\n";
cout << "The proper fits are obtained with the blue functions\n";
//

}
