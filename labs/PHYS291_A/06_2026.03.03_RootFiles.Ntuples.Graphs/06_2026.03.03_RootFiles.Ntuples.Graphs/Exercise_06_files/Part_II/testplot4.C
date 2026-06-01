{  //  This is testplot3.C from  testplot2.C
  TFile *ff = new TFile("graphsdata.root");
  ff->ls();
  TNtuple *ntp  = (TNtuple*) ff->Get("ntuple1"); 

  ntp->Draw("y:x","","l");    // do the same for plotting the second and third curv

  TGraph *tempgraph;
  tempgraph=(TGraph*)gPad->GetPrimitive("Graph");
  //  clone the graph
  //  TGraph *mygraph = (TGraph*)tempgraph->Clone("mygraph");
  TCanvas *c2= new TCanvas("c2","Canv 2",500,30,600,400);
  tempgraph->Draw("ALC");
  //   mygraph->Draw("ALC");  
}
/////////////////////   end  testplot3.C

