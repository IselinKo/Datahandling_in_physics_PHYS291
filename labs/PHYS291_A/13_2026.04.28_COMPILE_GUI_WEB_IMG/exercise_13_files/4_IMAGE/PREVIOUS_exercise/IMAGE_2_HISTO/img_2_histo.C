// Create a 2-D histogram from an image.
// Author of Tutorial version : Olivier Couet
// Author of this version :  Ladislav Kocbach 2020
//
//    Needed - a small image   small.png
{
   TASImage image("small.png");
   UInt_t yPixels = image.GetHeight();    // Unsigned integer
   UInt_t xPixels = image.GetWidth();
   UInt_t *argb   = image.GetArgbArray(); // Image data Linear array
   UInt_t A;    float grey;

   TH2D* h1 = new TH2D("h1","neg Image values",xPixels,-1,1,yPixels,-1,1);
   TH2D* h2 = new TH2D("h2","pos Image values",xPixels,-1,1,yPixels,-1,1);
//    red   0xffff0000    4 bytes in UInt_t, only 3 used in png
//    green 0xff00ff00    This is true for our images
//    blue  0xff0000ff    Might be different generally

   for (int row=0; row<xPixels; ++row) {
      for (int col=0; col<yPixels; ++col) {
         int index = col*xPixels+row;
         A=argb[index];
         A=A&(0x00ffffff);  // keep only the last thre bytes
         grey = 0.50*float((A&0xff0000)/float(0xff0000));
         grey = grey+0.40*float((A&0xff00)/float(0xff00));
         grey = grey+0.30*float((A&0xff)/float(0xff));
         h2->SetBinContent(row+1,yPixels-col,grey);
         grey=-grey;
         h1->SetBinContent(row+1,yPixels-col,grey);
      }
   }
   TCanvas *C1=new TCanvas("C1","Image",-50,50,4*xPixels+4,4*yPixels+4);  
   image.Draw();
   TCanvas *C2=new TCanvas("C2","Lego Hist.",-350,50,600,600);
   h1->Draw("lego");    // h->Draw("surf2");
   TCanvas *C3=new TCanvas("C3","surf4 Hist.",-650,50,600,600);
   h2->Draw("surf4");
}
