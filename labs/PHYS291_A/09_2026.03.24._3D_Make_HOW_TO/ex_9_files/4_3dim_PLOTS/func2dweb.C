{
TString peak_1="1.0/((x-2)*(x-2) + (y+2)*(y+2)+1.0)";
TString peak_2="0.5/((x+2)*(x+2) + (y-2)*(y-2)+0.5)";
cout << peak_1 <<endl;   // to check
cout << peak_1+"+"+peak_2 << endl;

TF2 * fpeaks=new TF2("fpeaks",peak_1+ "+" +peak_2,-4,4,-4,4);
//fpeaks->SetNpx(350);
//fpeaks->SetNpy(350);
   char * fnames[50]; 
   for(int k=0;k<50;k++) fnames[k]=new char[10];
   for(int k=0;k<50;k++) sprintf(fnames[k],"pict%d.png",k);

   FILE *outfil;
   outfil=fopen("index.html","w");
   fprintf(outfil,"<html><body>\n");

TCanvas* c2d = new TCanvas("c2d","Function f2(x,y)",10,10,600,600);
   int I=0;

 //  LOOP  
 fpeaks->Draw(); 
      fprintf(outfil,"<br><img src=\"%s\"><br>\n",fnames[I]);
      c2d->Print(fnames[I]); I = I+1;
 fpeaks->Draw("lego");
      fprintf(outfil,"<br><img src=\"%s\"><br>\n",fnames[I]);
      c2d->Print(fnames[I]); I = I+1;
 fpeaks->Draw("lego2");
      fprintf(outfil,"<br><img src=\"%s\"><br>\n",fnames[I]);
      c2d->Print(fnames[I]); I = I+1;
  fpeaks->Draw("surf2");
  gPad->SetTheta(20);   //     30 is default
  gPad->SetPhi(250);    //     default is 30
      fprintf(outfil,"<br><img src=\"%s\"><br>\n",fnames[I]);
      c2d->Print(fnames[I]); I = I+1;
  gPad->SetTheta(0);   //     30 is default
      fprintf(outfil,"<br><img src=\"%s\"><br>\n",fnames[I]);
      c2d->Print(fnames[I]); I = I+1;
  gPad->SetTheta(145);   //     30 is default
  gPad->SetPhi(30);    //     default is 30
      fprintf(outfil,"<br><img src=\"%s\"><br>\n",fnames[I]);
      c2d->Print(fnames[I]); I = I+1;
  fpeaks->Draw("surf3");
      fprintf(outfil,"<br><img src=\"%s\"><br>\n",fnames[I]);
      c2d->Print(fnames[I]); I = I+1;
  gPad->SetTheta(20);   //     30 is default
  gPad->SetPhi(250);    //     default is 30
      fprintf(outfil,"<br><img src=\"%s\"><br>\n",fnames[I]);
      c2d->Print(fnames[I]); I = I+1;
  fpeaks->Draw("surf4");
      fprintf(outfil,"<br><img src=\"%s\"><br>\n",fnames[I]);
      c2d->Print(fnames[I]); I = I+1;
  gPad->SetTheta(55);   //     30 is default
  gPad->SetPhi(45);    //     default is 30
      fprintf(outfil,"<br><img src=\"%s\"><br>\n",fnames[I]);
      c2d->Print(fnames[I]); I = I+1;


   fclose(outfil);
   printf("LAST:\n<br><img src=\"%s\"><br>\n",fnames[I-1]);
   printf("\n\n   %d  graphs entered into index.html\n", I);
//fpeaks->SetNpx(350);
//fpeaks->SetNpy(350);
}

