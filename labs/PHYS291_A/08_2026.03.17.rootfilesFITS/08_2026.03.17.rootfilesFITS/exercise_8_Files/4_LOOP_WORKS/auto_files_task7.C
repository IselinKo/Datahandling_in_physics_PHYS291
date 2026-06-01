
{  
   TString filname[1000];
   TString canvname[1000];
   TString Histname[1000];
   TFile *rfile[1000];
   TCanvas * Ncanv[1000];  
   TH1F * Nhist[1000];
   TList *LKEYS;        // only one list is needed      
   ifstream instr;      // only one input list is needed  
   
   system("ls *.root > rootfileslist.txt");
   instr.open("rootfileslist.txt");
   int nfiles = 0;  int i=0;
/*   while (1) {
      instr >> filname[i]; 
      if (!instr.good()) break;  
      nfiles++; i++;
    } */
while (1){ instr >> filname[i]; if (!instr.good()) break;nfiles++; i++;}

   for (i=0;i<nfiles;i++) {    //  i=0;
   cout <<  filname[i] << endl;  
   canvname[i] = "C_" +filname[i];
   
   
   rfile [i] = new TFile (filname[i]);    rfile[i]->ls();  


   LKEYS = (TList*) rfile[i]->GetListOfKeys();
   Histname[i]=LKEYS->At(0)->GetName();

   Nhist[i] = (TH1F*) rfile[i]->Get(Histname[i]); 
   Ncanv[i] = new TCanvas(canvname[i],filname[i],30+i*50,30+i*50,700,500);

   Nhist[i] ->Draw();

   }
   /*
   canvname[1]
   Ncanv[1]->cd()
   TLine *L = new TLine(0,0,8,1000)
   L->Draw()
   L->SetLineWidth(8)
   L->SetLineColor(kBlue)
   */
}



   



