{
//   
//       root      *.root     AllRoot_Form.c
//
TList *LKEYS; TKey *mykey;

TString Fname[1000];
TString hnames[1000];

TString canv[1000];

TCanvas * Ncanv[1000];     
TH1F * Nhist[1000];
   TF1 *funcs[1000];
   TF1 *Clonfuncs[1000];
   
TFile *FFF[1000];

TString Formula="[0]-x*[1]+[2]*exp(-(x-[4])*(x-[4])*[3])";

int i=2;
int Nrf=gROOT->GetListOfFiles()->GetEntries();
for(i=0;i<Nrf;i++){  FFF[i]=(TFile*)gROOT->GetListOfFiles()->At(i);}


for(i=0;i<Nrf;i++)Fname[i] = FFF[i]->GetName(); // Tested


for( i=0; i<Nrf; i++){
  LKEYS=FFF[i]->GetListOfKeys() ;
  mykey = (TKey*) LKEYS->At(0) ;  // Assuming only one histogram

  hnames[i]=mykey->GetName() ;      }



for( i=0; i<Nrf; i++){
//  Ncanv[i] = new TCanvas(canv[i],hnames[i],30+i*200,30+i*100,700,500);
    Ncanv[i] = new TCanvas("Can"+hnames[i],hnames[i],30+i*100,30+i*100,600,400);
    Nhist[i] =  (TH1F*) FFF[i]->Get(hnames[i]); 
    Nhist[i] ->Draw();
   
   funcs[i]=new TF1( hnames[i]+"FF", Formula, -100.0, 100.0); 
   funcs[i]->SetParameters(0,0,0,0,0);
   funcs[i]->SetParameter(2,(Nhist[i] ->GetMaximum())/2.5);
  
   Nhist[i] ->Fit(funcs[i]);
   
   Clonfuncs[i]=(TF1*) funcs[i]->Clone("Clonfuncs[i]");
   Clonfuncs[i]->SetParameter(0,0);
   Clonfuncs[i]->SetParameter(1,0);
   Clonfuncs[i]->Draw("SAME");

   
    // FFF[i]->Close();  // THIS WAS THE BAD THING   DO NOT CLOSE
   }
}


   
   