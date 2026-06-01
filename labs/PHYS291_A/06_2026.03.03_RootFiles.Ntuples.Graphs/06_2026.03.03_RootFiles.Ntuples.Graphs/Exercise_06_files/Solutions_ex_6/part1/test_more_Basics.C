{
//another  test   
//
//      file      test_more_Basics.C   (this file runs - study it)
//
// =========================  New file, new test - many file-pointers
//
// Better approach   have lots of file pointers;
// Keep file opened
//                basicX.root will be modified - use "UPDATE"

   TFile *fil1 = new TFile("basicN.root");  // fil1  ntuple
   fil1->ls();
   fil2 = new TFile("basicX.root","UPDATE");  // fil2 hist hx
   fil2->ls();
   TCanvas * aplot = new TCanvas("aplot","aplot");

   TFile *fil3 = new TFile("basicY.root");
   fil3->ls();
   TFile *fil4 = new TFile("basicZ.root");
   fil4->ls();

   fil1->ls();

   TH1F * H1 = (TH1F*) fil3->Get("hy");
   H1->Draw();

   TCanvas * cplot = new TCanvas("cplot","cplot");
   cplot->cd();
   TH1F * H2 = (TH1F*) H1->Clone("H2");
//
//  fil2  is opened with "UPDATE"  - can be modified
// 
   fil2->cd();
   H2->Write();
//
//  write to fil2  using   fil2->WriteTObject()  
//  can change name of the object
// 
   TNtuple *ntp  = (TNtuple*) fil1->Get("ntuple");
   fil2->WriteTObject(ntp,"mytuple");

   fil2 = new TFile("basicX.root");  // open again for check
   fil2->ls();
   fil2->Close();

   fil4->cd();
   cplot->cd();    // plot into canvas aplot
   H2->Draw();
   H2->Fill(-0.3,165);
   H2->Fill(3.5,265);
   H2->Fill(-3,165); 
   H2->Draw("hist");
   fil2 = new TFile("basicX.root","UPDATE"); // open again to modify
   fil2->WriteTObject(cplot,"A_canvas");
   fil2->ls();

//   only do this when finished with all file objects
//   fil1->Close();   fil2->Close();   fil3->Close();   fil4->Close();

}
//================  end of  test_more_Basics.C
    
