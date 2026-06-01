{




TFile * fberg= new TFile("bergen.root");
// fberg->ls();     // only interactive remove later

// fberg->GetListOfKeys()->ls()
// TList *LKEYSb = fberg->GetListOfKeys()
// LKEYSb->At(0)->GetName()   // This works

//  fberg->ls();     // remove later
//  TH1F *hberg = (TH1F*) fberg->Get("BergenHist");

TList *LKEYSb = (TList*) fberg->GetListOfKeys();
char bname[100];
strcpy(bname,LKEYSb->At(0)->GetName());

TH1F * hberg=( TH1F*) fberg->Get(bname);
TCanvas * CanB = new TCanvas("CanB","bergen",10,10,600,400);
hberg->Draw();



TFile * foslo= new TFile("oslo.root");
TList *LKEYSo = (TList*) foslo->GetListOfKeys();
char oname[100];
strcpy(oname,LKEYSo->At(0)->GetName());
TH1F * hoslo=( TH1F*) foslo->Get(oname);
TCanvas * CanO = new TCanvas("CanO","oslo",300,10,600,400);
hoslo->Draw();



TFile * fcambr= new TFile("cambridge.root");
TList *LKEYSc = (TList*) fcambr->GetListOfKeys();
char cname[100];
strcpy(cname,LKEYSc->At(0)->GetName());
TH1F * hcambr=( TH1F*) fcambr->Get(cname);
TCanvas * CanC = new TCanvas("Can","cambridge",600,10,600,400);

hcambr->Draw();


TFile * ffit= new TFile("fitting1.root");
TList *LKEYSf = (TList*) ffit->GetListOfKeys();
char fname[100];
strcpy(fname,LKEYSf->At(0)->GetName());
TH1F * hfit=( TH1F*) ffit->Get(fname);
TCanvas * FFIT = new TCanvas("FFIT",fname,300,300,600,400);

hfit->Draw();



}
