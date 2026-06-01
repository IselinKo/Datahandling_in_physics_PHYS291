{
TImage *img1 = TImage::Open("H.jpg");
TCanvas *C01=new TCanvas("C01","Image One H.jpg",40,40,450,450);
img1->Draw();
UInt_t yP1 = img1->GetHeight();       //  file  H.jpg
UInt_t xP1 = img1->GetWidth();        //  C01 img1      xP1      yP1     Orgb1
UInt_t *Orgb1   = img1->GetArgbArray();  
 
TImage *img2 = TImage::Open("R.jpg");
TCanvas *C02=new TCanvas("C02","Image Two R.jpg",540,40,450,450);
img2->Draw();
UInt_t yP2 = img2->GetHeight();       //   file  R.jpg
UInt_t xP2 = img2->GetWidth();        //  C02 img2      xP2      yP2     Orgb2
UInt_t *Orgb2   = img2->GetArgbArray();    img2->Draw();


TImage *image1 = TImage::Open("H.jpg");
UInt_t yPixels1 = image1->GetHeight();   //  file  H.jpg
UInt_t xPixels1 = image1->GetWidth();    //  C1 image1 xPixels1 yPixels1 argb1
UInt_t *argb1   = image1->GetArgbArray(); 
TCanvas *C1=new TCanvas("C1","Image One",40,350,450,450);     image1->Draw();

TImage *image2 = TImage::Open("R.jpg");
UInt_t yPixels2 = image2->GetHeight();    //  file  R.jpg
UInt_t xPixels2 = image2->GetWidth();    //  C2 image2 xPixels2 yPixels2 argb2
UInt_t *argb2  = image2->GetArgbArray();
TCanvas *C2=new TCanvas("C2","Image Two",540,350,450,450);     image2->Draw();

UInt_t A;  UInt_t B;   float grey;
int K, col, row; 
//   
//   This is how the pixels run in rows and columns in linear argb[index]
//
//   for (int row=0; row<xPixels; ++row) {
//      for (int col=0; col<yPixels; ++col) {
//         int index = col*xPixels+row;
//         A=argb[index];
//
int i;
for( i=0;i< yPixels1*xPixels1; i++){ 

	     if( i <yPixels1*xPixels1/2) argb1[i]=Orgb1[i] & Orgb2[i];    
	     if (i >  yPixels1*xPixels1*0.75 ) argb1[i]=(argb1[i] | 0x0000ff00 );
         
	     argb2[i]=( Orgb1[i] & ~Orgb2[i] ) + 0xff000000 ;  //  bitwise negate ~  and first byte ff
	     //argb2[i]=( Orgb1[i] ^ Orgb2[i] ) + 0xff000000 ;  //  XOR   and first byte ff
         if (i >  yPixels1*xPixels1*0.5 )  argb2[i]=(argb2[i] | 0x000000ff );

}

cout << "image1->Draw();   \n";

C1->cd();
image1->Draw();
image1->WriteImage("manip_IMG_1.jpg");
C2->cd();
image2->Draw();
image2->WriteImage("differ_figs.jpg");
}

