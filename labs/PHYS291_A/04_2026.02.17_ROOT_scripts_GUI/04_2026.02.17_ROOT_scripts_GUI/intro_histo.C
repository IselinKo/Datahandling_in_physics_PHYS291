{    // only needed if used as nameless script

int values[]={6,
 4, 7, 1, 3, 5, 8,12, 5, 4, 1, 6, 4, 6, 5,10, 6, 3, 3, 8, 3,
 2, 6, 1, 3, 4, 8, 9, 5, 4, 1, 6, 4, 6, 5,10, 6, 3, 3, 8, 7,
 4, 7, 1, 3, 5, 8, 7, 5, 4, 1, 6, 4, 6, 5,10, 6, 3, 3, 8, 6,
 1, 2, 3, 4, 5, 6, 7, 8, 9,10,11,12, 9,11, 6, 5, 7, 7, 5, 8,
12,13,14,15,16,17,18,19,20,12,13,14,15,16,17,18,19,20,13,11,
5};

int k;  int N;
N=sizeof(values)/sizeof(int);   // This is handy!
TH1D *myHist=new TH1D("myHist","Histogram of values",20,0.5,20.5); 
//  Histogram is filled in a LOOP !! 
  for(k=0;k<N;k++) myHist->Fill(values[k]);
//
TCanvas *c2=new TCanvas("c2","Example Histogram",400,50,700,500);
//
  myHist->SetMinimum(0);    //   Try without this - it starts with nonzero
    myHist->SetTitle("Example Histogram");
    myHist->GetXaxis()->SetTitle("Value");
    myHist->GetXaxis()->CenterTitle(true);
    myHist->GetYaxis()->SetTitle("Count");
    myHist->GetYaxis()->CenterTitle(true);
   myHist->Draw();
   /*       these are commented out
     myHist->SetFillColor(kOrange);  // or kBlue, kRed
     myHist->SetBarWidth(0.5); h3st->SetBarOffset(0.5);
    myHist->Draw("bar");
    run them  line by line anyway
  */

}      // only needed if used as nameless script

//  0.5 1.5 2.5 ....   20.5
