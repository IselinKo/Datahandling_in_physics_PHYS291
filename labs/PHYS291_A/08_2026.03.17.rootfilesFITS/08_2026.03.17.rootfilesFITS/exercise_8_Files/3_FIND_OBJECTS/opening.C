{
  TString Filename;
  cout << "enter the name of the root file\n";
  cin >> 	Filename;
  TFile *fff = new TFile(Filename);
  fff->ls();
}