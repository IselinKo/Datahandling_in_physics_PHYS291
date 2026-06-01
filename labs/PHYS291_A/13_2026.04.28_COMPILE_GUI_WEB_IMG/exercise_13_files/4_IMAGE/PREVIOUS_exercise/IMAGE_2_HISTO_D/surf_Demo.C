//===========================
//    surf1.C
// ===========================      starts on the next line
{
   //    Restart root;     run by     .x surf1.C
   //    first removing
   int  first_removing=1;
   //TCanvas *canv = new TCanvas("canv","Graph2D example",0,0,600,400);
   Double_t x, y, z, P = 6.;
   Int_t np = 1000;
   TGraph2D *gr0 = new TGraph2D();
   gr0->SetTitle("Graph title; X axis; Y axis; Z axis");
   TRandom *r = new TRandom();
   for (Int_t N=0; N<np; N++) {
      x = 2*P*(r->Rndm(N))-P;
      y = 2*P*(r->Rndm(N))-P;
      z = (sin(x)/x)*(sin(y)/y);
      gr0->SetPoint(N,x,y,z);
   }
   gStyle->SetPalette(81);    // setting palette for colormap
   TCanvas *canv1 = new TCanvas("canv1","Graph2D surf",-50,50,600,400);
   TGraph2D *gr1=(TGraph2D*) gr0->Clone("gr1");
   gr1->SetTitle("surf; X axis; Y axis; Z axis");
   gr1->Draw("surf");  // option
   canv1->Modified(); canv1->Update(); gSystem->ProcessEvents();
   sleep(1);

   TCanvas *canv2 = new TCanvas("canv2","Graph2D surf1",-100,100,600,400);
   TGraph2D *gr2=(TGraph2D*) gr0->Clone("gr2");   
   gr2->SetTitle("surf1; X axis; Y axis; Z axis");
   gStyle->SetPalette(81);
   gr2->Draw("surf1");  // option
   canv2->Modified(); canv2->Update(); gSystem->ProcessEvents();
   sleep(1);

   TCanvas *canv3 = new TCanvas("canv3","Graph2D surf2",-150,150,600,400);
   TGraph2D *gr3=(TGraph2D*) gr0->Clone("gr3");
   gr3->SetTitle("surf2; X axis; Y axis; Z axis");
   gr3->Draw("surf2");  // option
   canv3->Modified(); canv3->Update(); gSystem->ProcessEvents();
   sleep(1);

   TCanvas *canv4 = new TCanvas("canv4","Graph2D surf3",-200,200,600,400);
   TGraph2D *gr4=(TGraph2D*) gr0->Clone("gr4");
   gr4->SetTitle("surf3; X axis; Y axis; Z axis");
   gr4->Draw("surf3");  // option
   canv4->Modified(); canv4->Update(); gSystem->ProcessEvents();
   sleep(1);

   TCanvas *canv5 = new TCanvas("canv5","Graph2D surf4",-250,250,600,400);
   TGraph2D *gr5=(TGraph2D*) gr0->Clone("gr5");
   gr5->SetTitle("surf4; X axis; Y axis; Z axis");
   gr5->Draw("surf4");  // option
   canv5->Modified(); canv5->Update(); gSystem->ProcessEvents();
   sleep(1);

   TCanvas *canv6 = new TCanvas("canv6","Graph2D lego",-300,300,600,400);
   TGraph2D *gr6=(TGraph2D*) gr0->Clone("gr6");
   gr6->SetTitle("lego; X axis; Y axis; Z axis");
   gr6->Draw("lego");  // option
   canv6->Modified(); canv6->Update(); gSystem->ProcessEvents();
   sleep(1);

   TCanvas *canv7 = new TCanvas("canv7","Graph2D lego2",-350,350,600,400);
   TGraph2D *gr7=(TGraph2D*) gr0->Clone("gr7");
   gr7->SetTitle("lego2; X axis; Y axis; Z axis");
   gr7->Draw("lego2");  // option
   canv7->Modified(); canv7->Update(); gSystem->ProcessEvents();
   sleep(1);

   TCanvas *canv8 = new TCanvas("canv8","Graph2D cont",-600,200,600,600);
   TGraph2D *gr8=(TGraph2D*) gr0->Clone("gr8");
   gr8->SetTitle("cont; X axis; Y axis; Z axis");
   gr8->Draw("cont");  // option
   canv8->Modified(); canv8->Update(); gSystem->ProcessEvents();
   sleep(1);

   TCanvas *canv9 = new TCanvas("canv9","Graph2D cont1",-650,200,600,600);
   TGraph2D *gr=(TGraph2D*) gr0->Clone("gr9");
   gr9->SetTitle("cont1; X axis; Y axis; Z axis");
   gr9->Draw("cont1");  // option
   canv9->Modified(); canv9->Update(); gSystem->ProcessEvents();
   sleep(1);

   TCanvas *canv10 = new TCanvas("canv10","Graph2D cont2",-670,150,600,600);
   TGraph2D *gr10=(TGraph2D*) gr0->Clone("gr10");
   gr10->SetTitle("cont2; X axis; Y axis; Z axis");
   gr10->Draw("cont2");  // option
   canv10->Modified(); canv10->Update(); gSystem->ProcessEvents();
   sleep(1);

   TCanvas *canv11 = new TCanvas("canv11","Graph2D cont3",-700,100,600,600);
   TGraph2D *gr11=(TGraph2D*) gr0->Clone("gr11");
   gr11->SetTitle("cont3; X axis; Y axis; Z axis");
   gr11->Draw("cont3");  // option
   canv11->Modified(); canv11->Update(); gSystem->ProcessEvents();
   sleep(1);

   TCanvas *canv12 = new TCanvas("canv12","Graph2D surf6",-550,50,700,500);
   TGraph2D *gr12=(TGraph2D*) gr0->Clone("gr12");
   gr11->SetTitle("surf6; X axis; Y axis; Z axis");
   gr11->Draw("surf6");  // option
   canv12->Modified(); canv12->Update(); gSystem->ProcessEvents();
   sleep(1);

         gSystem->ProcessEvents();

//   Demonstration  - suitable for Linux with gnome problems

    int WinWidths[50]; int WinHeights[50]; //  storing the window sizes
    
      // To produce the picture uncomment the next line or enter it into root
      // canv->Print("Graph2d.png");        
      //  Or to get a little gallery, copy and paste the long next line
      // gr2->Draw("lego2");canv->Print("lego2.png");  
      // gr2->Draw("surf");canv->Print("surf.png"); 
      //gr2->Draw("surf4");canv->Print("surf4.png"); 
   sleep(1);
   hide_all();
   show_each();
   show_end();
}
void hide_all(){
int i, Ncanv; TCanvas * Canv12345678; 
Ncanv= gROOT->GetListOfCanvases()->GetEntries();  
   for(i=0;i<Ncanv;i++) {    
       Canv12345678=(TCanvas*) gROOT->GetListOfCanvases()->At(i);
       if(first_removing) {
           WinWidths[i] = Canv12345678->GetWindowWidth();
           WinHeights[i] = Canv12345678->GetWindowHeight();
         }
       Canv12345678->SetWindowSize(50,50);
       Canv12345678->SetWindowPosition(800,40);
       Canv12345678->Modified(); Canv12345678->Update(); gSystem->ProcessEvents();
     } 
     first_removing=0;
}
void show_each(){
int i, Ncanv; TCanvas * Canv12345678; char Nam[100]; TString S;
string line;
Ncanv= gROOT->GetListOfCanvases()->GetEntries();

  while(1){   
   for(i=0;i<Ncanv;i++) {    
       //  cout << WinWidths[i] << " " <<  WinHeights[i] << endl;
       Canv12345678=(TCanvas*) gROOT->GetListOfCanvases()->At(i);
       Canv12345678->SetWindowPosition(40,40);
       Canv12345678->SetWindowSize(WinWidths[i],WinHeights[i]);
       Canv12345678->Modified(); Canv12345678->Update(); gSystem->ProcessEvents();
       gSystem->ProcessEvents();
       // Canv12345678->WaitPrimitive();     
       // getline(cin,line); if(line=="q") break;
       sleep(1);
       Canv12345678->SetWindowSize(50,50);
        gSystem->ProcessEvents();
       }
     Canv12345678->SetWindowSize(WinWidths[Ncanv-1],WinHeights[Ncanv-1]);  // The last one
     Canv12345678->Modified(); Canv12345678->Update(); gSystem->ProcessEvents();
     cout <<"If you want repeat, hit enter;  To exit, type q and enter\n";

     getline(cin,line);  if(line=="q") break;
     Canv12345678->SetWindowSize(50,50);                         // The last one
     Canv12345678->Modified(); Canv12345678->Update(); gSystem->ProcessEvents();
    
  } 
}

void show_end(){
int i, Ncanv; TCanvas * Canv12345678; char Nam[100]; TString S;
string line;
Ncanv= gROOT->GetListOfCanvases()->GetEntries();

   hide_all();
   for(i=0;i<Ncanv;i++) {    
       //  cout << WinWidths[i] << " " <<  WinHeights[i] << endl;
       Canv12345678=(TCanvas*) gROOT->GetListOfCanvases()->At(i);
       Canv12345678->SetWindowPosition(40+(i%4)*200,40+(i/4)*200);
       Canv12345678->SetWindowSize(WinWidths[i]/2,WinHeights[i]/2);
       Canv12345678->Modified(); Canv12345678->Update(); gSystem->ProcessEvents();
         gSystem->ProcessEvents();
       }
}

void W(int I){
    int i, Ncanv; TCanvas * Canv12345678; char Nam[100]; TString S;

   Ncanv= gROOT->GetListOfCanvases()->GetEntries();
      hide_all();       
       //  cout << WinWidths[i] << " " <<  WinHeights[i] << endl;
       Canv12345678=(TCanvas*) gROOT->GetListOfCanvases()->At(I);
       Canv12345678->SetWindowPosition(40,40);
       Canv12345678->SetWindowSize(WinWidths[I]*1.5,WinHeights[I]*1.5);
       Canv12345678->Modified(); Canv12345678->Update(); gSystem->ProcessEvents();
         gSystem->ProcessEvents();
      
}

