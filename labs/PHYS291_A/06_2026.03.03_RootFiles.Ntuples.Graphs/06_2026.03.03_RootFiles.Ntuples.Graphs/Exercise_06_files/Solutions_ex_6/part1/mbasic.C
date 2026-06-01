{
   ifstream n_in;
   n_in.open("basic.dat.txt");

   TFile *fff = new TFile("basic.root","RECREATE");
//
//  if the automatic saving "fff->Write();" below should work
//  The TFile definition should be above here
//  i.e.  before the TH1F *h1 and TNtuple *ntuple definitions
//
   double x,y,z;
   int nlines = 0;
   int counter=0;

   TH1F *h1 = new TH1F("h1","x distribution",100,-4,4);
   TNtuple *ntuple = new TNtuple("ntuple","data from ascii file","x:y:z");

   while (1) {
      n_in >> x >> y >> z;
      if (!n_in.good()) break;      
      if (counter==9) printf("%dth line: x=%8f, y=%8f, z=%8f\n",nlines,x,y,z);
      h1->Fill(x);
      ntuple->Fill(x,y,z);
      nlines++; counter++;
      if (counter==10) counter=0; // prints evry 10. line
   }
   printf("==========\nThe file has %d lines\n", nlines);
   h1->Draw();
   fff->Write();
//   fff->Close();   // Theses are 3 lines for testing, close the fff, reopen as ff
//   TFile *ff = new TFile("basic.root");
//   ff->ls()

}

