{
TFile * AFile=new TFile("first_histo.root");
AFile->ls();
TString HistName="Myhist";
TH1F *histo=(TH1F*) AFile->Get(HistName);
histo->Draw();
}

