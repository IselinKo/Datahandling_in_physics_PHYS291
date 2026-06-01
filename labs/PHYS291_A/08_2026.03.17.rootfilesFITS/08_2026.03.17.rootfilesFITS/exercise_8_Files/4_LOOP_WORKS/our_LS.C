{
TFile *fff;
TString ObjName;
TString ObjTitle;
TString ObjClass;
TString   FileName;
TList *LKEYS;       // TList - list of objects - from a directory
int N_of_keys;      // The number of entries in the colloection
            
TKey * mykey;        //  LKEYS  and mykey are there to handle key in the list

cout << "Enter the name of  the root file:  > ";
cin >>  FileName;

fff       =  new TFile(FileName);
LKEYS     =  fff->GetListOfKeys();
N_of_keys =  LKEYS->GetEntries();

for (int k=0; k < N_of_keys; k++ ) {
   mykey = (TKey*) LKEYS->At(k) ;
   ObjClass=mykey->GetClassName();
   ObjName=mykey->GetName();
   ObjTitle=mykey->GetTitle();
   cout << "    Class string: " << ObjClass;
   cout << "    Object Name: " << ObjName;
   cout << "    Title: " << ObjTitle << endl;
   if (   ObjClass=="TH1F"  ) cout << "\n\n\t\t\t\tHurra!  - this is a histogram!\n\n";
   cout << "----------------------------------------\n";
   }
}



