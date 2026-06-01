{
   //  make_charTree.C  the same as  make_TTree.C
   //  Some of the branches can be C-strings   char aName[ ]
   //  NOTE:   Names  does not need &Names, 
   //          it is already an address (pointer)
   
   TTree *tch = new TTree("tch","Tree with char");
//         PPx, Names, EEv 
//         are "the interface" to the branches
   Float_t PPx;
   char Names[50]; 
   int EEv;

   tch->Branch("px",&PPx,"px/F");      // Branch defined through
   tch->Branch("str",Names,"str/C");   // its "outer" interface
   tch->Branch("ev",&EEv,"ev/I");      // F I  C  type 
                       // F float   D double  I int    C char
                       
   //  Data are placed to next level of the tree by TTree::Fill()
   //  as many times as needed                      tch->Fill()
   // fill the tree
   for (Int_t i=0; i<10000; i++) {
      cout << "enter 1 numbers and a single word string \n";
      cin >> PPx >> Names;
      EEv = i;
      tch->Fill();
      cout << "Fill more? Stop=0 ... ";
      cin >> quest;
      if (!quest) break;
   }
   TFile *f = new TFile("tree1.root","UPDATE");
   f->ls();   
   tch->Write();
// f->Close();
}

