//===========================
//    surf1.C
// ===========================      starts on the next line
{
   //    Restart root;     run by     .x surf1.C

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
   TCanvas *canv1 = new TCanvas("canv1","Graph2D surf",50,50,600,400);
   TGraph2D *gr1=(TGraph2D*) gr0->Clone("gr1");
   gr1->SetTitle("surf; X axis; Y axis; Z axis");
   gr1->Draw("surf");  // option

   TCanvas *canv2 = new TCanvas("canv2","Graph2D surf1",100,100,600,400);
   TGraph2D *gr2=(TGraph2D*) gr0->Clone("gr2");   
   gr2->SetTitle("surf1; X axis; Y axis; Z axis");
   gStyle->SetPalette(81);
   gr2->Draw("surf1");  // option

   TCanvas *canv3 = new TCanvas("canv3","Graph2D surf2",150,150,600,400);
   TGraph2D *gr3=(TGraph2D*) gr0->Clone("gr3");
   gr3->SetTitle("surf2; X axis; Y axis; Z axis");
   gr3->Draw("surf2");  // option

   TCanvas *canv4 = new TCanvas("canv4","Graph2D surf3",200,200,600,400);
   TGraph2D *gr4=(TGraph2D*) gr0->Clone("gr4");
   gr4->SetTitle("surf3; X axis; Y axis; Z axis");
   gr4->Draw("surf3");  // option

   TCanvas *canv5 = new TCanvas("canv5","Graph2D surf4",250,250,600,400);
   TGraph2D *gr5=(TGraph2D*) gr0->Clone("gr5");
   gr5->SetTitle("surf4; X axis; Y axis; Z axis");
   gr5->Draw("surf4");  // option

   TCanvas *canv6 = new TCanvas("canv6","Graph2D lego",300,300,600,400);
   TGraph2D *gr6=(TGraph2D*) gr0->Clone("gr6");
   gr6->SetTitle("lego; X axis; Y axis; Z axis");
   gr6->Draw("lego");  // option

   TCanvas *canv7 = new TCanvas("canv7","Graph2D lego2",350,350,600,400);
   TGraph2D *gr7=(TGraph2D*) gr0->Clone("gr7");
   gr7->SetTitle("lego2; X axis; Y axis; Z axis");
   gr7->Draw("lego2");  // option

   TCanvas *canv8 = new TCanvas("canv8","Graph2D cont",600,200,600,600);
   TGraph2D *gr8=(TGraph2D*) gr0->Clone("gr8");
   gr8->SetTitle("cont; X axis; Y axis; Z axis");
   gr8->Draw("cont");  // option

   TCanvas *canv9 = new TCanvas("canv9","Graph2D cont1",600,200,600,600);
   TGraph2D *gr=(TGraph2D*) gr0->Clone("gr9");
   gr9->SetTitle("cont1; X axis; Y axis; Z axis");
   gr9->Draw("cont1");  // option

   TCanvas *canv10 = new TCanvas("canv10","Graph2D cont2",650,150,600,600);
   TGraph2D *gr10=(TGraph2D*) gr0->Clone("gr10");
   gr10->SetTitle("cont2; X axis; Y axis; Z axis");
   gr10->Draw("cont2");  // option

   TCanvas *canv11 = new TCanvas("canv11","Graph2D cont3",700,100,600,600);
   TGraph2D *gr11=(TGraph2D*) gr0->Clone("gr11");
   gr11->SetTitle("cont3; X axis; Y axis; Z axis");
   gr11->Draw("cont3");  // option

   TCanvas *canv12 = new TCanvas("canv12","Graph2D surf6",-550,50,700,500);
   TGraph2D *gr12=(TGraph2D*) gr0->Clone("gr12");
   gr11->SetTitle("surf6; X axis; Y axis; Z axis");
   gr11->Draw("surf6");  // option
   
      // To produce the picture uncomment the next line or enter it into root
      // canv->Print("Graph2d.png");        
      //  Or to get a little gallery, copy and paste the long next line
      // gr2->Draw("lego2");canv->Print("lego2.png");  
      // gr2->Draw("surf");canv->Print("surf.png"); 
      //gr2->Draw("surf4");canv->Print("surf4.png"); 

}

