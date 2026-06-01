//    
//    graph_cloner.C     clones pictures
//
{ 
//  This is a complete script; runs 
 
   TFile *fff = new TFile("graphsdata.root");
   TNtuple *ntup  = (TNtuple*) fff->Get("ntuple1"); 


    TCanvas *c1= new TCanvas("c1","Canv 1",30,30,600,400);
    ntup->Draw("y:x","","l");
    TCanvas *c2= new TCanvas("c2","Canv 2",500,30,600,400);
    ntup->Draw("z:x","","l");
    TCanvas *c3= new TCanvas("c3","Canv 3",50,200,600,400);
    ntup->Draw("w:x","","l");

TGraph *tempgraph;
tempgraph=(TGraph*)gPad->GetPrimitive("Graph");

TGraph *mygraph = (TGraph*)tempgraph->Clone("mygraph");

TCanvas *c4=new TCanvas("c4","Combine",500,200,600,400);
mygraph->Draw("ACL");

c2->cd();
tempgraph=(TGraph*)gPad->GetPrimitive("Graph");
TGraph *yourgraph = (TGraph*)tempgraph->Clone("yourgraph");
c4->cd();
yourgraph->Draw("same");
c1->cd();
tempgraph=(TGraph*)gPad->GetPrimitive("Graph");
TGraph *hergraph = (TGraph*)tempgraph->Clone("hergraph");
c4->cd();
hergraph->Draw("same");

}  
//    graph_cloner.C     clones pictures

