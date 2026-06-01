{       //  Declare Histogram (using pointer)
  TH1D *Myhist=new TH1D("Myhist","Histogram of values",20,0.5,20.5); 
  int values[]={6, 4, 7, 1, 3, 5, 8,12, 5, 4, 1, 6, 4, 6, 5,10, 6, 3, 3, 8, 3, 2, 6, 1, 
    3, 4, 8, 9, 5, 4, 1, 6, 4, 6, 5,10, 6, 3, 3, 8, 7, 4, 7, 1, 3, 5, 8, 7, 5, 4, 1, 6, 
    4, 6, 5,10, 6, 3, 3, 8, 6, 1, 2, 3, 4, 5, 6, 7, 8, 9,10,11,12, 9,11, 6, 5, 7, 7, 5, 
    8, 12,13,14,15,16,17,18, 19,20,12,13,14,15,16,17,18,19,20,13,11, 5};
  int k;  int N;   N=sizeof(values)/sizeof(int);   // This is handy!
                   //  Histogram is filled in a LOOP !! 
  for(k=0;k<N;k++) Myhist->Fill(values[k]);
  Myhist->Draw();
                  //  Histogram is made

  TFile*  MyFile = new TFile("first_histo.root","RECREATE");
       MyFile->cd();
       Myhist->Write();
       MyFile->ls();    // Simple, standard way, only Tree, Histogram, saved ....

  TFile*  YourFile = new TFile("histFile.root","RECREATE");
       YourFile->cd();
       YourFile->WriteObject(Myhist,"Histogram_of_values");
                      // More general way, Most objects can be saved ....
    TString  Explain ="\n\nThe Histogram_of_values same as Myhist\n";
    Explain=Explain + "the name changed in WriteObject(Myhist,\"Histogram_of_values\")\n";
       YourFile->WriteObject(&Explain,"explanation");
       YourFile->ls();   
}      

