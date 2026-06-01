{

  TString Filename;
  cout << "enter the name of the root file\n";
  cin >> 	Filename;
  TFile *fff = new TFile(Filename);

TString ObjName;         TString A_ObjNames[100];
TString ObjTitle;        TString A_ObjTitles[100];
TString ObjClass;        TString A_ObjClasses[100];
  
TList *LKEYS=fff->GetListOfKeys();   // TList - list of objects - from a directory
int N_of_keys= LKEYS->GetEntries();  // we have full control over the amount
                                     // can repeat any number times, up or down..
ObjTitle = LKEYS->At(0)->GetTitle();
ObjName  = LKEYS->At(0)->GetName();
//  But we need TKey to use GetClassName()  

TKey * mykey;

for (int k=0; k < N_of_keys; k++ ) {
   mykey = (TKey*) LKEYS->At(k) ;
   ObjClass=mykey->GetClassName();   A_ObjClasses[k]= ObjClass;
   ObjName=mykey->GetName();         A_ObjNames[k]  = ObjName;
   ObjTitle=mykey->GetTitle();       A_ObjTitles[k] = ObjTitle;
   cout << "Class string  " << ObjClass << endl;
   cout << "Object Name   " << ObjName << endl;
   cout << "Title         " << ObjTitle << endl;
      if (   ObjClass=="TH1F"  ) cout << "\t\t ******* TH1F - is a histograms \n";
   cout << "----------------------------------------\n";
   }
cout << "-----------\nProcessing all content\n-----------\n";
for (int k=0; k < N_of_keys; k++ ) {
   cout << k+1<<".   "  << A_ObjClasses[k] << "\t  " << A_ObjNames[k]  <<  endl;
   }
}