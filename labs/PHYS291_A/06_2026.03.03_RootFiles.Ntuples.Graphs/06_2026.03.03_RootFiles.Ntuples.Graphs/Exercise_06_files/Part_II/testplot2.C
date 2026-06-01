//     save as testplot2.C
void testplot2()
{
  TFile *ff = new TFile("graphsdata.root");
  ff->ls();
  TNtuple *ntp  = (TNtuple*) ff->Get("ntuple1"); 

  ntp->Draw("y:x","","l");    // do the same for plotting the second and third curv

}

