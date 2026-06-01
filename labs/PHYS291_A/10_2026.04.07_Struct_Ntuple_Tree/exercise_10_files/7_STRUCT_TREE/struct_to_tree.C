{
//  Just a tree
TTree *tch = new TTree("tch","Tree with char");
struct tstst {int  i; int k; char nam[20]; char addr[30];};
tstst A;
A.i=5; A.k=25; strcpy(A.nam,"IFT UiB");
strcpy(A.addr,"PostOffice Number N-5009");
tstst B;
B=A;
strcpy(A.addr,"Allegaten 55 5009 Bergen");
A.i=255; A.k=(-10); strcpy(A.nam,"Course PHYS281");
cout << "Testing if different: A.i - B.i " <<  A.i - B.i  <<endl;
//  the interface branch address is the address of tstst A 
tch->Branch("stru1", &A);  
tch->Fill();      // -------------------  First fill
A=B;
tch->Fill();      // -------------------  Second fill
strcpy(A.nam,"Third entry");
strcpy(A.addr,"This is another one");
tch->Fill();      // -------------------  Third fill
  TFile *f = new TFile("treestruc.root","UPDATE");
tch->Write();      // write this little tree to the rootfile
}
