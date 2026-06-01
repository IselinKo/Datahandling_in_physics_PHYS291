//================
//      file             testBasics.C   (this file runs - study it)
//
//    Testing basicN.root  basicX.root basicY.root basicZ.root
//================ 
//The following is a sequence testing the new root files
//  save it as  testBasics.C
// study it, it also contains " cloning" of a plot
// that will be used later today
//  you will see that 
{
   TFile *ff;
   ff = new TFile("basicN.root");
   ff->ls();
   ff->Close();
   ff = new TFile("basicX.root");
   ff->ls();
   ff->Close();
   ff = new TFile("basicY.root");
   ff->ls();
   ff->Close();
   ff = new TFile("basicZ.root");
   ff->ls();
//  Get the histogram from file  
   TH1F * H1 = (TH1F*) ff->Get("hz");
   H1->Draw();

   TCanvas * cplot = new TCanvas("cplot","cplot",400,50,600,400);
   cplot->cd();
   //   clone H1 to H2
   TH1F * H2 = (TH1F*) H1->Clone("H2");   // cloning 2 versions

   H2->Fill(3,150);   //   modify i one point
   H2->Draw("hist");

  TCanvas *c4=new TCanvas("c4","Canv 4",300,300,600,400);
   
   TH1F * H3 = (TH1F*) H2->Clone("H3"); 

   H3->Fill(1,100); 
   H3->Fill(0.0,100); 
   H3->Draw("hist");

//   ff->Close();  kills both H1, H2 plots
}
///////////////////////////////  end of test_basic.C  work  //////////

