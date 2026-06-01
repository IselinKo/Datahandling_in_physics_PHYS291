{   
gROOT->ProcessLine(".L Do_Exit.C");
gROOT->ProcessLine(".L PrintSelected.C");
gROOT->ProcessLine(".L HandleCheckButton.C");
gROOT->ProcessLine(".L assign_funcs.C");
gROOT->ProcessLine(".L Do_Get_Text.C");

  TString OurTString;
  char EntryNames[100][50];  //  Max 100 options!

TGMainFrame         * OurFrame;
TGListBox           *fListBox;
TGCheckButton       *fCheckMulti;
TList               *fSelected;


int n=0;    // how many selected

  TF1 *plotFun;                                                // Tr
  TString Sfun;                                                // Tr
  TString funcs[15];                                           // Tr
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

}  


