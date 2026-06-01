/// author Olivier Couet; Modified / corrected by Ladislav Kocbach

{
   TASImage roseimage("LK256.jpg");
   UInt_t yPixels = roseimage.GetHeight();
   UInt_t xPixels = roseimage.GetWidth();
   UInt_t *argb   = roseimage.GetArgbArray();
   float R, G, B;

   TH2D* hi = new TH2D("h","Rose histogram",xPixels,-1,1,yPixels,-1,1);

   for (int y=0; y<yPixels; ++y) {
      for (int x=0; x<xPixels; ++x) {
         int index = y*xPixels+x;
         R= float(argb[index]&0xff0000)/(0xff0000);
         G= float(argb[index]&0xff00)/(0xff00);
         B= float(argb[index]&0xff)/(0xff);
         float grey = (R+G+B)/3.0;
         hi->SetBinContent(x,yPixels-y,grey);
      }
   }

   TCanvas *canv1 = new TCanvas("canv1","Image.Draw()",100,100,500,600);
   TCanvas *canv2 = new TCanvas("canv2","L.K._colz",300,150,500,600);
   TCanvas *canv3 = new TCanvas("canv3","L.K.surf6",500,200,500,600);
   TCanvas *canv4 = new TCanvas("canv4","L.K._surf6_rotate",700,250,500,600);
  
   canv1->cd();  roseimage.Draw();

   canv2->cd();  
   gStyle->SetPalette(kCandy);     // TRY  gStyle->SetPalette(kSunset);
   hi->Draw("colz");
   canv3->cd();
   hi->Draw("surf6");
   canv4->cd();
   hi->Draw("surf6"); gPad->SetTheta(90); gPad->SetPhi(0);
}
