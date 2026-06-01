
{  
   int NFound;                  //  Total count of histo
   TString filname[100];        //  Many files
   TFile   *rfile[100];
   TString canvname[1000];      //  Many more TCanvases
   TCanvas * Ncanv[1000];  
   TString Histname[1000];      //  and same number Histograms
   TH1F * Nhist[1000];          //  (pointers to them)
   double MaxVal[1000];             // At present the only value fetched from Hist

   TString ObjName;     // only one 
   TString ObjTitle;    // OBJect treated
   TString ObjClass;    // only one  ObjName, ObjTitle, ObjClass
   TList *LKEYS;        // list of KEYs in a file - only one list is needed    
   TKey * mykey;        // LKEYS  and mykey are there to handle KEY in the list  
   ifstream instr;      // only one input list is needed  
   int N_of_keys;       // The number of entries in the given file
   int N_of_hist;       // The number of entries which are histograms
   int Isleep=0;   
   int Nsecs=3;         //       if (Isleep) sleep(Nsecs);
   int hitKEY=1;  
   string line;         //       if (hitKEY) getline(cin,line);
     
             

   system("ls *.root > rootfileslist.txt");   // make the list of root files
   instr.open("rootfileslist.txt");           // open for reading
   int nfiles = 0;  int i=0; int kk=0;        // kk - histograms

   while (1)  {               // root files obtained from rootfileslist.txt
      instr >> filname[i]; if (!instr.good()) break;nfiles++; i++;}

   for (i=0;i<nfiles;i++) {    //  i=0;
      cout << "====================================================\n";
      cout << "file No. " << i << "  filename: "<< filname[i] << endl;    
      rfile [i] = new TFile (filname[i]);    //  rfile[i]->ls();  not needed
      LKEYS = (TList*) rfile[i]->GetListOfKeys();
      N_of_keys =  LKEYS->GetEntries();  N_of_hist=0;
      for (int k=0; k < N_of_keys; k++ ) {
           mykey = (TKey*) LKEYS->At(k) ;
           ObjClass=mykey->GetClassName();
           ObjName=mykey->GetName();
           ObjTitle=mykey->GetTitle();
           cout << " Class string: " << ObjClass;
           cout << " Obj Name: " << ObjName;
           cout << " Title: " << ObjTitle ;
           cout << " File: " << filname[i] << endl;
         if (   ObjClass=="TH1F"  ) {
             canvname[kk] = filname[i]+"____"+ObjName;
             Histname[kk]=ObjName;
             Nhist[kk] = (TH1F*) rfile[i]->Get(Histname[kk]);
             Nhist[kk]->SetTitle(canvname[kk]);
             Ncanv[kk] = new TCanvas(canvname[kk],canvname[kk],30+kk*80,30+kk*30,600,400);       
             MaxVal[kk]=Nhist[kk]->GetMaximum();  // Just an example value; 
                          // Replace this by the fitting and fit values
                          // Here is the place to insert ACTION from scripts 
                          // in directory 
                          //               1_fitting_example

             Nhist[kk] ->Draw();
             Ncanv[kk]->Update();Ncanv[kk]->Modified();gSystem->ProcessEvents(); 
             if (Isleep) sleep(Nsecs);  
             if (hitKEY) getline(cin,line);

             N_of_hist++; kk++;  //  yes, increase the count of histograms in this file         
           }        //  if the class  is a histogram TH1F
      }    // ends loop over  the KEYs in the file
      cout << "In No. " << i << " name: "<< filname[i]<<" found "<< N_of_hist << " histograms\n";     
 
    }   // ends loop over files   for(i=0;i<nfiles;i++) 
  NFound=kk;   //  Total number of TH1F histograms
  
  //    OUTPUT   

  cout << "\n=========================================================\n";
  cout << nfiles << " files processed  " <<  NFound << "histograms TH1F  found\n";
  cout << "=========================================================\n";

   for( int kk=0; kk<NFound; kk=kk+1) {
       printf("%4d  %30s   max:  %13.2f\n",kk+1, canvname[kk].Data(), MaxVal[kk]); 
       //  when printf  of TString use    TString.Data()  
       //  when printf  of  string use    string.c_str() 
   }
//  ABOVE IS DESCRIBED HOW TO   include here procedures  
                            // shown in  directory 
                            //                     1_fitting_example
             
}

