{     
//   Compares histogram of cosine values 
//   with a normal graph of a function
//   filename:      graph_vs_histo.C   
//
int k,i; double x[80000],y[80000];  // 0 to 5 pi; 80 000 x-values
for(k=0;k<80000;k++){x[k]=3.14159*k/16000.0; y[k]=cos(x[k]); }

c1=new TCanvas("c1","Graph of cosine function",50,50,700,500);
//
//   GRAPH
//
gr = new TGraph(80000,x,y);
  gr->SetTitle("Graph of the cosine function"); 
  gr->Draw("ACP");
    //   Note that the title here should be set before gr->Draw()
//
//      Histogram  - count how often each value occurs - 50 BINS
//
TH1D *thst=new TH1D("thst","Histogram of cosine values",50,-1.0,1.0); 
   //  Histogram is filled in a LOOP !! 
  for(k=0;k<80000;k++) thst->Fill(y[k]);
   //
c2=new TCanvas("c2","Histogram of cosine values",400,50,700,500);
//
    thst->SetMinimum(0);    //   Try without this - it starts with nonzero
    thst->SetTitle("Histogram of cosine values");
    thst->Draw();
c2->Print("histogram.png");
//  Changing to another canvas - make another canvas active:  canvas->cd()
c1->cd();      
c1->Print("graph.png");     
}
