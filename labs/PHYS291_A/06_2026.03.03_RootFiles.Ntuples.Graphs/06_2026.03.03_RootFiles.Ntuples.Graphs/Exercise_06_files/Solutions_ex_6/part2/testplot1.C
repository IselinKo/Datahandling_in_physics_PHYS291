//     save as testplot2.C
{
  TFile *ff = new TFile("graphsdata.root");
  ff->ls();
  TNtuple *ntp  = (TNtuple*) ff->Get("ntuple1"); 

  ntp->Draw("x:y","","l");    // do the same for plotting the second and third curv

}

