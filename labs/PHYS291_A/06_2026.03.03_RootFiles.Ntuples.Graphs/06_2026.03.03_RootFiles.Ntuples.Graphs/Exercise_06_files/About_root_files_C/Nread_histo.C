{
TFile * AFile=new TFile("histFile.root");
AFile->ls();
TString HistName="Histogram_of_values";
TH1F *histo=(TH1F*) AFile->Get(HistName);
histo->Draw();
TString * Str= (TString*) AFile->Get("explanation");
cout << "\nFrom root file object 'explanation': " << * Str << endl;
}

