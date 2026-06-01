{
// New ROOT SESSION

TCanvas* c2d = new TCanvas("c2d","Random rannor",10,10,600,600);
TH2F *hpxpy  = new TH2F("hpxpy","py vs px",40,-4,4,40,-4,4);
   hpxpy->SetStats(0);
   Double_t px,py;
   for (Int_t i = 0; i < 90000; i++) {
      gRandom->Rannor(px,py);
      hpxpy->Fill(px+1,py+1);
   }
   for (Int_t i = 0; i < 75000; i++) {
      gRandom->Rannor(px,py);
      hpxpy->Fill(px-2,py-2);
   }


   char * fnames[50]; 
   for(int k=0;k<50;k++) fnames[k]=new char[10];
   for(int k=0;k<50;k++) sprintf(fnames[k],"pict%d.png",k);

   FILE *outfil;
   outfil=fopen("index.html","w");
   fprintf(outfil,"<html><body>\n");

   int I=0;

 //  LOOP  
 hpxpy->Draw(""); 
      fprintf(outfil,"<br><img src=\"%s\"><br>\n",fnames[I]);
      c2d->Print(fnames[I]); I = I+1;
 hpxpy->Draw("lego");
      fprintf(outfil,"<br><img src=\"%s\"><br>\n",fnames[I]);
      c2d->Print(fnames[I]); I = I+1;
 hpxpy->Draw("lego2");
      fprintf(outfil,"<br><img src=\"%s\"><br>\n",fnames[I]);
      c2d->Print(fnames[I]); I = I+1;
  hpxpy->Draw("surf2");
  gPad->SetTheta(20);   //     30 is default
  gPad->SetPhi(250);    //     default is 30
      fprintf(outfil,"<br><img src=\"%s\"><br>\n",fnames[I]);
      c2d->Print(fnames[I]); I = I+1;
  gPad->SetTheta(0);   //     30 is default
      fprintf(outfil,"<br><img src=\"%s\"><br>\n",fnames[I]);
      c2d->Print(fnames[I]); I = I+1;
   fclose(outfil)

}

