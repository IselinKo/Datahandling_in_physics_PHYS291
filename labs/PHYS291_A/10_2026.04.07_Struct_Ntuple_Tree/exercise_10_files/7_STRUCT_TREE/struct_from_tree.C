{
struct tstst {int  i; int k; char nam[20]; char addr[30];};

tstst A;

  TFile *f = new TFile("treestruc.root","UPDATE");
   f->ls();

   TTree *tch = (TTree*) f->Get("tch");

  cout <<" tch->GetNbranches() is "<< tch->GetNbranches() << endl;

  cout <<" length   tch->GetEntries()  is " <<  tch->GetEntries() << endl;
//  tch->SetBranchAddress("stru1",&A); 
//            Wrong; pointer to pointer
// Error in <TTree::SetBranchAddress>: 
// The address for "stru1" should be the address of a pointer!!!
  //O.K. but it was  tch->Branch("stru1", &A);

tstst * Apointer;
Apointer=&A;
tch->SetBranchAddress("stru1", &Apointer);  // pointertopointer
  
  tch->GetEntry(0);    
     cout << A.i  <<"  "<< A.k << endl;
     cout << A.nam <<"  "<< A.addr << endl;
                      
  tch->GetEntry(1);    
     cout << A.i  <<"  "<< A.k << endl;
     cout << A.nam <<"  "<< A.addr << endl;

  tch->GetEntry(2);    
     cout << A.i  <<"  "<< A.k << endl;
     cout << A.nam <<"  "<< A.addr << endl;

 //  This is nothing, but returns the last correct

  tch->GetEntry(3);    
     cout << A.i  <<"  "<< A.k << endl;
     cout << A.nam <<"  "<< A.addr << endl;

  tch->GetEntry(333);     // Nonsense, but does not complain 
     cout << A.i  <<"  "<< A.k << endl;
     cout << A.nam <<"  "<< A.addr << endl;
 }
