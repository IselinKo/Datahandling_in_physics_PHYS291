{   
    //     grow_TTree.C   
    //        use parts of make_TTree.C and look_TTree.C
    //  Adding extra ENTRIES an eisting tree with simple-variable branches

   TFile *f = new TFile("tree1.root","UPDATE");
   //   TTree *t1 = new TTree("t1","TTree with simple variables");
   //        instead fetch the existing
   TTree *t1 = (TTree*)f->Get("t1");
   
//         PPx, PPy, PPz,     EEv 
//         are "the interface" to the branches
//         The names are arbitrary; the type is important

   float PPx, PPy, PPz;     int EEv;

   t1->Branch("px",&PPx,"px/F");    // Branch defined through
   t1->Branch("py",&PPy,"py/F");    // its "outer" interface
   t1->Branch("pz",&PPz,"pz/F");    // F,I,D type specification
   t1->Branch("ev",&EEv,"ev/I");
   int quest=1;
   //  Data are placed to next level of the tree by TTree::Fill()
   //  as many times as needed                      t1->Fill()
   for (Int_t i=0; i<10000; i++) {
      cout << "enter 3 numbers: \n";
      cin >> PPx >> PPy >> PPz;     // Data are placed in 
      EEv = i;                      // the "interface"
      t1->Fill();                   // Data copied to the tree
                                    // to all branches
      cout << "Fill more? Stop=0 ... ";
      cin >> quest;
      if (!quest) break;            // This only for demo
   }
   // Here: when the tree is MODIFIED it can be stored
   // You should change  the title
   t1->SetTitle("Extended Previous TTree "); 
   cout << "File content before t1->Write() \n";
   f->ls();   // before the TTree Write

   t1->Write();        // or use f->WriteTObject(t1); 
   cout << "list after  t1->Write() \n";
   f->ls();    // after the TTree Write
}

