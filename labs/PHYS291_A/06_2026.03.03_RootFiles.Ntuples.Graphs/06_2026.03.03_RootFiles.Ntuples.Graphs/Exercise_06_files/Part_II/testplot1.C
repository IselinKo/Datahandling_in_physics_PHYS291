//     save as testplot1.C
void testplot1()
{
  TFile *ff = new TFile("graphsdata.root");
  ff->ls();
  TNtuple *ntp  = (TNtuple*) ff->Get("ntuple1"); 

  ntp->Draw("x:y","","l");    // do the same for plotting the second and third curv

}

