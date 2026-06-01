{
//
//   ADD long functions into strings
//   
    TString fun1 = "[0]-[1]*x";
    TString fun2 = "[2] * exp(- (x-[4])*(x-[4]) * [3] )";
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

TCanvas *cfunB = new TCanvas("cfunB","Function",10,50,600,400);
TCanvas *chistB = new TCanvas("chistB","Histogram",10,300,600,400);
TCanvas *cfunO = new TCanvas("cfunO","Function",350,50,600,400);
TCanvas *chistO = new TCanvas("chistO","Histogram",300,350,600,400);

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
chistB->Modified();
//
//   ADD long functions into strings
//   
    fun1 = "[0]-[1]*x";
    fun2 = "+[2] * exp(- (x-[4])*(x-[4]) * [3] )";
    fun3 = "+[5] * exp(- (x-[7])*(x-[7]) * [6] )";
    TString fun4 = fun1  + fun2 + fun3;
    TF1 *twogaus=new TF1("twogaus",fun4,-4.0,4.0);

double params[8]={4.0, 0.35, 3.0, 5.0,   -2.0, 5.0, 4.0,  1.5};
//                a    b     c  inv_width pos  c  inv.w. pos
//
    twogaus->SetParameters(params);
cfunO->cd();
    twogaus->Draw();
    twogaus->SetMinimum(0);   // to start plot from y=0
cfunB->Modified();

chistO->cd();    
    TH1F *htwo = new TH1F("htwo","x distribution",100,-4,4);
htwo->FillRandom("twogaus",100000);
htwo->Draw();
htwo->SetMinimum(0);   // to start plot from y=0
chistO->Modified();

//

}