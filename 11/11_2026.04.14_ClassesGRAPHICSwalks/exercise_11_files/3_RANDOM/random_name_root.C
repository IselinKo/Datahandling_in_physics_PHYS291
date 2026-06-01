{
TString nam="fnam";
gRandom->SetSeed();
nam=nam+char(65+gRandom->Integer(26))+char(65+gRandom->Integer(26));
nam=nam+char(65+gRandom->Integer(26))+char(65+gRandom->Integer(26));
nam=nam+".root";
TFile * ff=new TFile(nam,"UPDATE");
gROOT->ProcessLine(".q");
}

