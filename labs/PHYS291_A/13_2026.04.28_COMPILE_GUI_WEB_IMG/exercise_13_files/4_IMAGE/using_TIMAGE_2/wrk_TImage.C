{
//   The original image is used as TImage object 4 times
//   Three images will be manipulated by using the grey scale byte
//   Then various experiments are done with changing colors

TImage *img1 = TImage::Open("H.jpg");
TCanvas *C1=new TCanvas("C1","H.jpg",40,40,450,450);
img1->Draw();
UInt_t yPixels1 = img1->GetHeight();       //  file  H.jpg
UInt_t xPixels1 = img1->GetWidth();        //  C01 img1      xP1      yP1     Orgb1
UInt_t *argb1   = img1->GetArgbArray();  
 

TImage *img2 = TImage::Open("H.jpg");
UInt_t yPixels2 = img2->GetHeight();   //  file  H.jpg
UInt_t xPixels2 = img2->GetWidth();    //  C1 image1 xPixels1 yPixels1 argb1
UInt_t *argb2   = img2->GetArgbArray(); 
TCanvas *C2=new TCanvas("C2","Image One",40,350,450,450);     
img2->Draw();


TImage *img3 = TImage::Open("H.jpg");
UInt_t yPixels3 = img3->GetHeight();   //  file  H.jpg
UInt_t xPixels3 = img3->GetWidth();    //  C1 image1 xPixels1 yPixels1 argb1
UInt_t *argb3   = img3->GetArgbArray(); 
TCanvas *C3=new TCanvas("C3","Image Two",400,40,450,450);     
img3->Draw();


TImage *img4 = TImage::Open("H.jpg");
UInt_t yPixels4 = img4->GetHeight();   //  file  H.jpg
UInt_t xPixels4 = img4->GetWidth();    //  C4 image1 xPixels4 yPixels4 argb1
UInt_t *argb4   = img4->GetArgbArray(); 
TCanvas *C4=new TCanvas("C4","Image Two",400,350,450,450);     
img4->Draw();


UInt_t grey, Ngrey;

UInt_t lim1=90; UInt_t lim2=20;  UInt_t val=255;   //  for color intervals
long i; 
UInt_t grb; UInt_t red; UInt_t green; UInt_t blue;


// lim1=160;          lim2=    80;        val=128;   // dividing 0-255 into 3 ranges 

// Image 2

for( i=0;i< yPixels1*xPixels1; i++){ 
         grb= argb2[i] & (UInt_t) 0xff000000;  //  highest byte, unused by us
         grey= argb2[i] & (UInt_t) 0xff;  // get the last byte , grey: all 3 bytes are equal

         if (grey>lim1) {green=(UInt_t)((grey-lim1)*(255/float(255-lim1)));
         	            if(green>255)green=255; 
         	            red=val; blue=val;}

         if (grey<lim1+1 && grey> lim2 ) {
         	            red=(UInt_t)((grey-lim2)*(256/float(lim1-lim2)));
         	            if(red>255)red=255; 
         	            green=val; blue=val;}

         if (grey<lim2+1) {
         	            blue=(UInt_t)((grey)*(256/float(lim2)));
         	            if(blue>255)blue=255; 
         	            green=val; red=val;}
          // cout << red  << "  " << green << " " << blue << endl;
           //usleep(10000);
           Ngrey=red*256*256+green*256+blue;
           argb2[i]=Ngrey | grb;
         }

// Image 3                        Attempted  a simple color transformation

for( i=0;i< yPixels1*xPixels1; i++){ 
         grb= argb3[i] & (UInt_t) 0xff000000;
         grey= argb3[i] & (UInt_t) 0xff;  // get the last byte , the 3 bytes are equal

           Ngrey=64*(2+grey/64); if (Ngrey>255) Ngrey=255;
          // Ngrey=64*(2+grey/64); if (Ngrey>255) Ngrey=255;
           grey=grey+256*Ngrey+256*256*Ngrey;	   // blue + green * 256 + red * 256*256        
	     argb3[i]=grey | grb;
         }

// Image 4

 lim1=160;          lim2=    80;        val=128;  // dividing 0-255 into 3 ranges 

for( i=0;i< yPixels1*xPixels1; i++){ 
         grb= argb4[i] & (UInt_t) 0xff000000;
         grey= argb4[i] & (UInt_t) 0xff;  // get the last byte , the 3 bytes are equal

         if (grey>lim1) {green=(UInt_t)((grey-lim1)*(255/float(255-lim1)));
         	            if(green>255)green=255; 
         	            red=val; blue=val;}

         if (grey<lim1+1 && grey> lim2 ) {
         	            red=(UInt_t)((grey-lim2)*(256/float(lim1-lim2)));
         	            if(red>255)red=255; 
         	            green=val; blue=val;}

         if (grey<lim2+1) {
         	            blue=(UInt_t)((grey)*(256/float(lim2)));
         	            if(blue>255)blue=255; 
         	            green=val; red=val;}
          // cout << red  << "  " << green << " " << blue << endl;
           //usleep(10000);
           Ngrey=red*256*256+green*256+blue;
           argb4[i]=Ngrey | grb;
         }

C2->cd();
img2->Draw();
img2->WriteImage("stretch_palette.jpg");
C4->cd();
img4->Draw();
img4->WriteImage("stretch_palette_darker.jpg");
C3->cd();
img3->Draw();
img3->WriteImage("transform_colors.jpg");

}

