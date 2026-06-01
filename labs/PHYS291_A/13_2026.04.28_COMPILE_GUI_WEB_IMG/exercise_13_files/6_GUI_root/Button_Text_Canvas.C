{   TString OurTString;
// main frame
   TGMainFrame *OurFrame = new TGMainFrame(gClient->GetRoot(),10,10,kMainFrame | kVerticalFrame);
   OurFrame->SetName("OurFrame");
   OurFrame->SetLayoutBroken(kTRUE);
// embedded canvas
   TRootEmbeddedCanvas *OurCanvas = new TRootEmbeddedCanvas(0,OurFrame,624,425,kSunkenFrame);
   OurCanvas->SetName("OurCanvas");
   Int_t Cnum = OurCanvas->GetCanvasWindowId();
   TCanvas *Canv = new TCanvas("Canv", 10, 10, Cnum);
   OurCanvas->AdoptCanvas(Canv);
   OurFrame->AddFrame(OurCanvas, new TGLayoutHints(kLHintsLeft | kLHintsTop,2,2,2,2));
//  FONT 
   TGFont *Fnt;         // will reflect user font changes
   Fnt = gClient->GetFont("-*-helvetica-medium-r-*-*-24-*-*-*-*-*-iso8859-1");

   TGGC   *uGC;           // will reflect user GC changes
   GCValues_t ourGC;
   ourGC.fMask = kGCForeground | kGCBackground | kGCFillStyle | kGCFont | kGCGraphicsExposures;
       gClient->GetColorByName("#ff0000",ourGC.fForeground);
       gClient->GetColorByName("#ffffd0",ourGC.fBackground);    // Backgroud color of the frame
   ourGC.fFillStyle = kFillSolid;
   ourGC.fFont = Fnt->GetFontHandle();
   ourGC.fGraphicsExposures = kFALSE;
   uGC = gClient->GetGC(&ourGC, kTRUE);
//   Text Label defined
   TGLabel *OurLabel = new TGLabel(OurFrame,"OurLabel");      
   OurLabel->SetTextJustify(kTextLeft);
   OurLabel->SetTextFont(Fnt->GetFontStruct());
   OurFrame->AddFrame(OurLabel, new TGLayoutHints(kLHintsLeft | kLHintsTop,2,2,2,2));
//  Text entry defined   
   TGTextBuffer *Buf=new TGTextBuffer(228);
   TGTextEntry *OurText=new TGTextEntry(OurFrame,Buf,-1,uGC->GetGC(),Fnt->GetFontStruct(),kSunkenFrame);
//  Text entry properties
   OurText->SetMaxLength(4096);
   OurText->SetAlignment(kTextLeft);
                          OurLabel->SetText("Enter Text Below");
                           OurText->SetText("Here");
   OurFrame->AddFrame(OurText, new TGLayoutHints(kLHintsLeft | kLHintsTop,2,2,2,2));
//          Buttons  defined   
   ReadButton = new TGTextButton(OurFrame, "Read Text", "Do_Get_Text()");
   ExitButton= new TGTextButton(OurFrame, "EXIT", "Do_Exit()");
//         Buttons Changing Font and colors
   gClient->GetColorByName("#0000ff",ourGC.fForeground);  // Changed color
   ExitButton->SetTextColor(ourGC.fForeground);  ExitButton->SetFont(Fnt->GetFontStruct());
   gClient->GetColorByName("#ff0000",ourGC.fForeground);  // Changed color 
   ReadButton->SetTextColor(ourGC.fForeground);  ReadButton->SetFont(Fnt->GetFontStruct());
//       Place the buttons         
   OurFrame->AddFrame(ReadButton, new TGLayoutHints(kLHintsLeft | kLHintsTop,2,2,2,2));
   OurFrame->AddFrame(ExitButton, new TGLayoutHints(kLHintsLeft | kLHintsTop,2,2,2,2));
//   Housekeeping
   OurFrame->SetMWMHints(kMWMDecorAll,kMWMFuncAll, kMWMInputModeless);
   OurFrame->MapSubwindows();
   OurFrame->SetBackgroundColor(ourGC.fBackground);
   OurLabel->SetBackgroundColor(ourGC.fBackground);
                                    OurLabel->MoveResize  ( 24,453,260, 28);      
                                    OurText->MoveResize   ( 24,483,480, 28);
                                    OurCanvas->MoveResize ( 24, 16,704,425);
                                    ReadButton->MoveResize(544,446,184, 32);  
                                    ExitButton->MoveResize(544,483,184, 32);
   OurFrame->MapWindow();           OurFrame->Resize      (776,531);
//              Canvas - THIS IS AN EXAMPLE ONLY    
   Canv->cd();
   TH1F * hist=new TH1F("a","b",100,0,4);
   hist->Draw();
}  
void Do_Get_Text(){                //  For the Read Button
    OurTString=  OurText->GetText();
    cout << "\n\n\t\t\t " << OurTString << "\n\t\t\t TString OurTString set as title of the histogram \n";
    hist->SetTitle(OurTString);   Canv->Update();  Canv->Modified();
    
}
void Do_Exit(){                   //  For the Exit Button
    gROOT->ProcessLine(".q");
}

