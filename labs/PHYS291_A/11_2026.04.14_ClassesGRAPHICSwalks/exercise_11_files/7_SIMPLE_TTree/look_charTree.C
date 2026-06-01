{ 
   //       look_charTree.C      modification of  look_TTree.C   
   //    reeds a tree  constructed by 
   //       make_charTree.C 

   TFile *f = new TFile("tree1.root");
   TTree *tch = (TTree*)f->Get("tch");
   //         Ux, Texts, EEv 
   //         are "the interface" to the branches
   Float_t Ux;
   Int_t Eev;
   char Texts[300];    //  Texts is a pointer, thus NOT &Texts
   
   tch->SetBranchAddress("px",&Ppx);
   tch->SetBranchAddress("str",Texts);  //  Texts is a pointer
   tch->SetBranchAddress("ev",&Eev);    //  thus NOT &Texts


   int nentries = (int) tch->GetEntries();
   for (int i=0; i<nentries; i++) {
      tch->GetEntry(i);    // copy i-th level to the interface 
                           // including the string in Texts[] 
      printf(" %4d %10.4f %s \n", Eev, Ux, Texts);
   }
}
