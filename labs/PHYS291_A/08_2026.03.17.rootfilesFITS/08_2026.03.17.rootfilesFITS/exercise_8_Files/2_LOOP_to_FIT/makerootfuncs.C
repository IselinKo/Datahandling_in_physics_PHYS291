{
//    write_twopeak.C   changed to 
//    makerootfuncs.C
//   
//   TF1 *twogaus=new TF1("twogaus",fun4,0,8);
//
//   cout <<  twogaus->GetRandom() << "  \n";
//

  TFile * fff= new TFile("N_six_hist.root","RECREATE");
// TFile * fff= new TFile("exerc_8_2019.root","UPDATE");

int nhi=6;

TCanvas * Ncanv[100]; 
TH1F * Nhist[100];
TString hnames[]={"both", "asym", "single", "close", "far", "flat"};


int Npoints[] = {50000,20000,200000,80000,50000,50000};
int Nbins[]={150, 100, 125, 150, 100, 50};
double Amin=  0.0;
double Amax=  8.0;

TString OBJNAME;
//
//   ADD long functions into strings
//  
    TString fun1 = "[0]-[1]*x";
    TString fun2 = "+[2] * exp(- (x-[4])*(x-[4]) * [3] )";
    TString fun3 = "+[5] * exp(- (x-[7])*(x-[7]) * [6] )";
    TString fun4 = fun1  + fun2 + fun3;

    TF1 *twogaus=new TF1("twogaus",fun4,Amin,Amax);


double *params[100];
double vec0[]={2.0, -0.095,   4.0, 1.0,   2.0,    3.0, 1.0,  5.5};
double vec1[]={3.0, 0.095,   2.0, 3.0,   3.0,    4.0, 3.0,  4.5};
double vec2[]={2.0, -0.055,   3.0, 2.0,   4.0,    0.0, 0.0,  0.0};
double vec3[]={4.0, 0.015,   3.0, 1.6,   2.0,    4.0, 1.0,  4.5};
double vec4[]={4.0, -0.012,   4.0, 4.0,   2.0,    6.0, 4.0,  3.5};
double vec5[]={4.0, 0.005,   6.0, 0.7,   3.0,    4.0, 0.5,  6.5};
params[0]=vec0; params[1]=vec1; params[2]=vec2; params[3]=vec3;
params[4]=vec4; params[5]=vec5;


//                a    b       inv_width pos  c  inv.w. pos
//
int i;
for (i=0;i<nhi;i++)   {

    Ncanv[i] = new TCanvas("Can"+hnames[i],hnames[i],30+i*100,30+i*50,600,400);

    Ncanv[i]->cd();    
    Nhist[i] = new TH1F(hnames[i],hnames[i]+" distribution",Nbins[i],Amin,Amax);
    twogaus->SetParameters(params[i]);
    Nhist[i]->FillRandom("twogaus",Npoints[i]);
    Nhist[i]->SetMinimum(0); 
    Nhist[i]->Draw();
    OBJNAME="LL_"+hnames[i];

    fff->WriteTObject(Nhist[i],OBJNAME);
    fff->ls();
   }
    for(int row=0;row<6;row++){
       for(int I=0;I<8;I++) printf(" %7.3f ",params[row][I]); 
       cout << "    LL_"<<hnames[row] << endl;
    }
}
