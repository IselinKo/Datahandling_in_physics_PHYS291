//    
//    ntuple_graphs.C     clones pictures
//
{ 
//  This is a complete script; runs 
 
   TFile *fff = new TFile("graphsdata.root");
   TNtuple *ntup  = (TNtuple*) fff->Get("ntuple1"); 

   TGraph *tempgraph;
    
   ntup->Draw("y:x","","l");
    tempgraph=(TGraph*)gPad->GetPrimitive("Graph");
    TGraph *mygraph = (TGraph*)tempgraph->Clone("mygraph");
   ntup->Draw("z:x","","l");
    tempgraph=(TGraph*)gPad->GetPrimitive("Graph");
    TGraph *yourgraph = (TGraph*)tempgraph->Clone("yourgraph");
   ntup->Draw("w:x","","l");
    tempgraph=(TGraph*)gPad->GetPrimitive("Graph");
    TGraph *hergraph = (TGraph*)tempgraph->Clone("hergraph");

   TMultiGraph *ThreeGr = new TMultiGraph();

         ThreeGr->Add( mygraph ); 
         ThreeGr->Add( yourgraph ); 
         ThreeGr->Add( hergraph ); 
 
        ThreeGr->Draw("ACP");
}  
//    ntuple_graphs.C     clones pictures

