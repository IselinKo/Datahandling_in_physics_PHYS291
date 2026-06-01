{   

  TString OurTString;
  char EntryNames[100][50];  //  Max 100 options!

TGMainFrame         * OurFrame;
TGListBox           *fListBox;
TGCheckButton       *fCheckMulti;
TList               *fSelected;

void DoExit();
void HandleCheckButton();
void PrintSelected();

int n=0;    // how many selected

  TF1 *plotFun;                                                // Tr
  TString Sfun;                                                // Tr
  TString funcs[15];                                           // Tr
  void assign_funcs();  // These are the function TStrings     // Tr
  int toplot[15];       // which functions to plot             // Tr
  //                                                           // Tr
 // This must be moved     assign_funcs();                      // Tr

// main frame
   OurFrame = new TGMainFrame(gClient->GetRoot(),10,10,kMainFrame | kVerticalFrame);
   OurFrame->SetLayoutBroken(kTRUE);
//    embedded canvas
   TRootEmbeddedCanvas *OurCanvas = new TRootEmbeddedCanvas(0,OurFrame,624,425,kSunkenFrame);
   Int_t Cnum = OurCanvas->GetCanvasWindowId();
   TCanvas *Canv = new TCanvas("Canv", 10, 10, Cnum);
   OurCanvas->AdoptCanvas(Canv);
      OurFrame->AddFrame(OurCanvas);
//   Text Label defined
   TGLabel *OurLabel = new TGLabel(OurFrame,"OurLabel");      
   OurLabel->SetTextJustify(kTextLeft);
   OurLabel->SetText("Enter Text Below");
      OurFrame->AddFrame(OurLabel);
//  Text entry defined   
   TGTextBuffer *Buf=new TGTextBuffer(228);
   TGTextEntry *OurText=new TGTextEntry(OurFrame,Buf,-1);
   OurText->SetAlignment(kTextLeft);
   OurText->SetText("Here ...");
      OurFrame->AddFrame(OurText);                                   
//        Buttons  defined  and placed 
   ReadButton = new TGTextButton(OurFrame, "Read Text", "Do_Get_Text()");
       OurFrame->AddFrame(ReadButton);
   ExitButton = new TGTextButton(OurFrame, "EXIT", "Do_Exit()");
       OurFrame->AddFrame(ExitButton);
//  Adding the listbox
  fListBox = new TGListBox(OurFrame, 89);
   fSelected = new TList;

   assign_funcs();                                                      // Tr
   // The entry names must be changed
   for (int i = 0; i < 15; ++i) {                             // changed Number
      // sprintf(EntryNames[i], "Function Call %i", i);
      sprintf(EntryNames[i],"%2d %s",i,funcs[i].Data());      // The functions
      fListBox->AddEntry(EntryNames[i], i);
   }
   fListBox->Resize(220,100);

   OurFrame->AddFrame(fListBox);
//  Adding the listbox   ended

//   check button   
 
  fCheckMulti = new TGCheckButton(OurFrame, "Mutliple selection", "HandleCheckButton()");

   OurFrame->AddFrame(fCheckMulti);
 
  
  TGTextButton *showBut = new TGTextButton(OurFrame, "Show Selection", "PrintSelected()");
   
  OurFrame->AddFrame(showBut);
 //  ended button 



//   Housekeeping

   OurFrame->MapSubwindows();
                                    OurLabel->MoveResize  ( 24,453,260, 28);      
                                    OurText->MoveResize   ( 24,483,480, 28);
                                    OurCanvas->MoveResize ( 24, 16,704,425);
                                    ReadButton->MoveResize(544,446,184, 32);  
                                    ExitButton->MoveResize(544,483,184, 32);
                                    showBut->MoveResize ( 770, 350,150,25);
                                    fCheckMulti->MoveResize ( 770, 300,150,25);

                                    fListBox->MoveResize( 770, 30, 220,200);
   OurFrame->MapWindow();           OurFrame->Resize      (1000,531);
//              Canvas - THIS IS AN EXAMPLE ONLY    
   Canv->cd();
   Sfun=funcs[0].Data();
   plotFun0=new TF1(Sfun,Sfun,0.0,12.0);       // Tr
   plotFun0->Draw();  
   //  TH1F * hist=new TH1F("a","--------",100,0,4);
   //  hist->Draw();
}  

void Do_Get_Text(){                //  For the Read Button
    OurTString=  OurText->GetText();
    cout << "\n\n\t\t\t " << OurTString << "\n\t\t\t TString OurTString set as title of the histogram \n";
    plotFun0->SetTitle(OurTString);   Canv->Update();  Canv->Modified();
    //  was hist changed to plotfun0
    
}
void Do_Exit(){                   //  For the Exit Button
    gROOT->ProcessLine(".q");
}
void HandleCheckButton()
{  
      fListBox->SetMultipleSelections(fCheckMulti->GetState());
}

void assign_funcs(){                                                  // Tr
  funcs[0] ="sin(x)*exp(-0.3*x)      ";                             // Tr
  funcs[1] ="cos(x)*exp(-0.3*x)      ";                             // Tr
  funcs[2] ="0.7*cos(x)*exp(-0.01*x) ";                             // Tr
  funcs[3] ="0.9*cos(x*x)            ";                             // Tr
  funcs[4] ="exp(-0.7*x)             ";                             // Tr
  funcs[5] ="exp(-0.1*x*x)           ";                             // Tr
  funcs[6] ="0.95/(1.0+x*x)          ";                             // Tr
  funcs[7] ="0.95/(1.0+x*x)*cos(x)   ";                             // Tr
  funcs[8] ="cos(0.5*x)*exp(-0.2*x)  ";                             // Tr
  funcs[9] ="cos(2*x)*exp(-0.5*x)    ";                             // Tr
  funcs[10]="exp(-0.1*x*x)*cos(x*x)  ";                             // Tr
  funcs[11]="0.2*cos(x)*exp(0.3*x)   ";                             // Tr
  funcs[12]="0.08*x                  ";                             // Tr
  funcs[13]="0.05*x*x                ";                             // Tr
  funcs[14]="0.2+0.05*x-0.005*x*x    ";                             // Tr
                                                                      // Tr  
}                                                                     // Tr      

void PrintSelected()
{
   //   Handles properly the selected items
   //   Gets their number vi TList if multiselection.

   fSelected->Clear();   //  TList fSelected;

   Canv->cd();
   // if (fListBox->GetMultipleSelections()) {
       printf("==================================\n");
      int N=fListBox->GetNumberOfEntries();
      fListBox->GetSelectedEntries(fSelected);
      //int n=fSelected->GetSize();
      //printf("There are %d selected entries:\n", n);
      n=0;
      for(int i=0; i<N; i++){
         if(fListBox->GetSelection(i)) {
          printf("%d  is selected -> %s\n",i,EntryNames[i]);
          toplot[n]=i;   
          n++;
          }
        }
          cout << "selected " << n << endl;

      //   }  NO if  MultipleSelections
    // THIS IS THE ACTUAL FUNCTIONALITY                              // Tr   
        //  it needs the selected function indices toplot[i]         // Tr
        for (int i=0;i<n;i++){                                       // Tr
             Sfun=funcs[toplot[i]].Data();                           // Tr
                // funcs from assign_funcs(); Sfun a local TString   // Tr
             cout <<"IN LOOP" << Sfun << endl;                                   // Tr
             if(i==0) {  plotFun0=new TF1(Sfun,Sfun,0.0,12.0);       // Tr
                         plotFun0->Draw();                           // Tr 
                      }                                              // Tr                      
             else  {   plotFun=new TF1(Sfun,Sfun,0.0,12.0);          // Tr
                       plotFun->Draw("SAME"); 
                   }                                                 // Tr
 
            }                                                        // Tr
       plotFun0->SetTitle("Combined Plot of selected");
    // THE PART ABOVE ONLY IS THE ACTUAL FUNCTIONALITY               // Tr
      Canv->Modified(); Canv->Update();                      // Tr

} 
