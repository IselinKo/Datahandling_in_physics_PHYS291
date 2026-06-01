{
//    script   auto_param.C
//
//     Automatic assignment of parameters
//     for general two Gaus peaks with linear background 
//        "[0]-[1]*x";
//        "+[2] * exp(- (x-[4])*(x-[4]) * [3] )";
//        "+[5] * exp(- (x-[7])*(x-[7]) * [6] )";
//         TString fun4 = fun1  + fun2 + fun3;
//
//     Parameters  0   to  7
//
//     test with       fit_twopeak.C
//                        p0   p1    p2   p3     p4   p5    p6    p7
//     double params[8]={4.0, 0.35, 3.0, 5.0,   -2.0, 5.0, 4.0,  1.5};
//                        a    b     c  inv_width pos  c  inv.w. pos 
//

TF1 *twogausfit=new TF1("twogausfit",fun4,-4.0,4.0);
double nparams[8];
int NBINS=htwo->GetNbinsX();
double lefty = htwo->GetBinContent(1);
double righty = htwo->GetBinContent(NBINS-1); 
double leftx = htwo->GetBinCenter(1);
double rightx = htwo->GetBinCenter(NBINS-1);

nparams[0]= lefty;    //  Left  end value
nparams[1]=-( righty - lefty ) / ( rightx - leftx );

nparams[2]=htwo->GetMaximum() - (lefty + righty )/2.0;
nparams[5]= nparams[2];

nparams[4]= rightx - (rightx-leftx)/3.0;
nparams[7]= leftx + (rightx-leftx)/3.0;

nparams[3]= 10.0/(rightx-leftx);
nparams[6] = nparams[3];

twogaus->SetParameters(nparams);
htwo->Fit("twogausfit");

double fitparams[8];
twogausfit->GetParameters(fitparams);
                     
for (int i=0;i<8;i++) printf("        p%d  ", i);         printf("\n");
for (int i=0;i<8;i++) printf("%11.2lf ", fitparams[i]);    printf("\n");
savefun->Draw("SAME");

}
