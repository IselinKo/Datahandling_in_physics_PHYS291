{
/////////////////////////////////////////////////////////
TFile *fff = new TFile("six_hist.root");

TString ObjName;
TString ObjTitle;
TString ObjClass;
  
TList *LKEYS=fff->GetListOfKeys();   // TList - list of objects - from a directory
int N_of_keys= LKEYS->GetEntries();  // we have full control over the amount
                                     // can repeat any number times, up or down..
ObjTitle = LKEYS->At(0)->GetTitle();
ObjName  = LKEYS->At(0)->GetName();
//  But we need TKey to use GetClassName()  

TKey * mykey;

for (int k=0; k < N_of_keys; k++ ) {
   mykey = (TKey*) LKEYS->At(k) ;
   ObjClass=mykey->GetClassName();
   ObjName=mykey->GetName();
   ObjTitle=mykey->GetTitle();
   cout << "Class string  " << ObjClass << endl;
   cout << "Object Name   " << ObjName << endl;
   cout << "Title         " << ObjTitle << endl;
       if (   ObjClass=="TH1F"  ) cout << "\t\t ******* TH1F - is a histograms \n";
   cout << "----------------------------------------\n";
   }
}

