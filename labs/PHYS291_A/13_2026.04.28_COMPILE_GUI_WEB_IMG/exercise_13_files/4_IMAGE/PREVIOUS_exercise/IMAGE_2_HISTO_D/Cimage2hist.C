// \ingroup tutorial_image
// Create a 2-D histogram from an image.
//
// \author Olivier Couet; Modified / corrected by Ladislav Kocbach

void Cimage2hist()
{
   TASImage image("$ROOTSYS/tutorials/image/rose512.jpg");
   UInt_t yPixels = image.GetHeight();
   UInt_t xPixels = image.GetWidth();
   UInt_t *argb   = image.GetArgbArray();
   float R, G, B;

   TH2D* h = new TH2D("h","Rose histogram",xPixels,-1,1,yPixels,-1,1);

   for (int y=0; y<yPixels; ++y) {
      for (int x=0; x<xPixels; ++x) {
         int index = y*xPixels+x;
         R= float(argb[index]&0xff0000)/(0xff0000);
         G= float(argb[index]&0xff00)/(0xff00);
         B= float(argb[index]&0xff)/(0xff);
         float grey = (R+G+B)/3.0;
         h->SetBinContent(x,yPixels-y,grey);
      }
   }

   gStyle->SetPalette(kSunset);
   gStyle->SetPalette(kCandy);
   h->Draw("colz");
}
