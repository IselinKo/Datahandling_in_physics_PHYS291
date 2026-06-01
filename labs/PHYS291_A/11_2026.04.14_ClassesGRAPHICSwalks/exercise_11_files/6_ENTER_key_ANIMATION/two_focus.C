{
  // This version is heavily edited from the original
  // in order to assure visible expected motion (the if's added to assure jump)
  //       The marker is prevented from leaving the 
string SS; double xx,yy,dx,dy; TCanvas * WALKS; 
WALKS=new TCanvas("WALKS","WALKS",200,30,500,500); WALKS->Range(-12,-12,12,12); 
TMarker *mk = new TMarker(1.0, 1.5, 29); mk->SetMarkerSize(9); mk->Draw();
gRandom->SetSeed();
xx=0;yy=0;
//          single random move   
xx=xx-2+4*gRandom->Rndm(); yy=yy-2+4*gRandom->Rndm();
mk->SetX(xx);mk->SetY(yy); 
WALKS->Update();WALKS->Modified(); gSystem->ProcessEvents(); 

for(;;){  
// This is keyboard steered animation   FOCUS on TCanvas WINDOW    5 steps
system("clear");
cout <<"\n\n\n\nMake sure focus is on the Graphics Canvas for 5 steps\n\n";
cout <<"           click in the graphics canvas to focus on it\n\n";
 for(int k=0;k<5;k++) { 
      // WALKS->WaitPrimitive();    // Waits for keyboard
       dx=-2+4*gRandom->Rndm(); if(abs(dx)<0.2) dx=dx*5;  // to assure jump
       dy=-2+4*gRandom->Rndm(); if(abs(dy)<0.2) dy=dy*5;  // to assure jump
       xx=xx+dx; yy=yy+dy; 
       if(abs(xx)>11) xx=11*xx/abs(xx); if(abs(yy)>11) yy=11*yy/abs(yy);
       mk->SetX(xx);mk->SetY(yy); 
       WALKS->Update();WALKS->Modified();
       WALKS->Update();WALKS->Modified();
       gSystem->ProcessEvents();    // Does ALL THE GRAPHICS 
       cout << k+1 << ".  waiting for ENTER when graphics active\n";
       WALKS->WaitPrimitive();    // Waits for keyboard
   }
  WALKS->WaitPrimitive();      // Waits for keyboard
  mk->SetMarkerSize(5);        // Changing color and size
  mk->SetMarkerColor(kBlue); WALKS->Update();WALKS->Modified();
  gSystem->ProcessEvents();       // Does ALL THE GRAPHICS

system("clear");
cout << "\n\n**************************************************\n";      
cout <<"\n\n\n\nNow focus must be on this Terminal for 5 steps\n\n";
cout <<"           click in this terminal window to focus on it\n\n";
xx=0;yy=0;
// This is keyboard steered animation   FOCUS on TERMINAL WINDOW 5  steps
for(int k=0;k<5;k++) { 
       cout << k+1 << ".  waiting for ENTER when this terminal active\n";
       getline(cin,SS);        // Waits for keyboard
       dx=-2+4*gRandom->Rndm(); if(abs(dx)<0.2) dx=dx*5;  // to assure jump
       dy=-2+4*gRandom->Rndm(); if(abs(dy)<0.2) dy=dy*5;  // to assure jump
       if(abs(xx)>11.8) xx=11.8*xx/abs(xx); if(abs(yy)>11.8) yy=11.8*yy/abs(yy);
       xx=xx+dx; yy=yy+dy;
       mk->SetX(xx);mk->SetY(yy); 
       WALKS->Update();WALKS->Modified(); 
       gSystem->ProcessEvents();        // Does ALL THE GRAPHICS
     }
  mk->SetMarkerSize(9);        // Changing color and size
  mk->SetMarkerColor(kBlack); WALKS->Update();WALKS->Modified();
  gSystem->ProcessEvents();            // Does ALL THE GRAPHICS
}


}
