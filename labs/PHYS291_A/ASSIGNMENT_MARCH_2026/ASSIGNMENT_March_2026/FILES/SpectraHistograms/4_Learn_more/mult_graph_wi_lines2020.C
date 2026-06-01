{  
   //    Nameless script / macro   mult_graph_wi_lines2019.C 
   //
   //    Draw three simple graphs   (splitting one in 2 parts)
   //
   //    Using   TMultiGraph        (  adding lines for marking things )
   //
   //    Author: L. Kocbach modifying R. Brun    
   
   TCanvas *c1 = new TCanvas("c1","Three Simple Graphs",200,10,800,600);

   TMultiGraph *ThreeGr = new TMultiGraph();
 
  const Int_t n = 100;
  
   Double_t x[n], y[n], y2[n], y3[n];
 
  for (Int_t i=0;i<n;i++) {
     x[i] = i*0.1;
     y[i] =  5*sin(x[i]+0.2);
     y2[i] = 10*sin(1.5*x[i]+0.2)*exp(-0.3*x[i]);
     y3[i] = 0.5*cos(2.4*x[i]+0.2)*exp(0.3*x[i]);
     printf(" i %i %f %f \n",i,x[i],y[i]);
   }
   Double_t * newx; Double_t * newy2;         // Splitting graph2 in 2 using pointers
   newx=x+n/2-10;   newy2=y2+n/2-10;        // Splitting graph2 in 2 using pointers
   
   TGraph *gr1 = new TGraph(n,x,y);
   TGraph *gr2 = new TGraph(n/2,x,y2);         // Splitting graph2
   TGraph *gr3 = new TGraph(n,x,y3);
   TGraph *gr4 = new TGraph(n/2+9,newx,newy2); //  second part of graph2  
   
   gr1->SetLineColor(6);
   gr1->SetLineWidth(1);

//   gr2->GetXaxis()->SetTitle("X title");
//   gr2->GetYaxis()->SetTitle("Y title");

   gr2->SetLineColor(49);
   gr2->SetLineWidth(4);

   gr3->SetLineColor(49);
   gr3->SetLineWidth(2);
   
    gr4->SetLineColor(6);
      
   ThreeGr->Add(gr1,"lp");
   ThreeGr->Add(gr2,"AB");
   ThreeGr->Add(gr3,"ACP");
   ThreeGr->Add(gr4,"ACP");
     gr2->SetFillColor(6);
    // hist->SetBarWidth(0.1); //hist->SetBarOffset(0.0);   
     gStyle->SetBarWidth(0.1);   
   ThreeGr->Draw("A");

   c1->Update();
   c1->SetGridx();
   c1->GetFrame()->SetBorderSize(12);
   
   ThreeGr->GetXaxis()->SetTitle("Dimensionless X");
   ThreeGr->GetYaxis()->SetTitle("Functions");
   ThreeGr->GetXaxis()->CenterTitle(true);          //  Axis label in the center
   ThreeGr->GetYaxis()->CenterTitle(true);          //  Axis label in the center

   float xold, xnew, yold, ynew;
   xold=0.35;yold=-7.33; xnew=9.35; ynew=8;          //   ADDING single LINES
   TLine * AA=new TLine(xold, yold, xnew, ynew);
   AA->Draw();
   xold=0;yold=0; xnew=10; ynew=0;        //  horizontal line through zero
   AA=new TLine(xold, yold, xnew, ynew);
   AA->Draw();
   float X1,Y1,X2,Y2;
   X1=5.3; X2=5.3; Y1=-6.3; Y2=2.5;      //  vertical line
   TLine * BB=new TLine(X1,Y1,X2,Y2);
   BB->Draw();
   BB->SetLineWidth(5);                      
    X1=0.35; X2=9.75; Y1=-6.3; Y2=-6.3;  //  horizontal line
   BB=new TLine(X1,Y1,X2,Y2);
   BB->Draw();
   BB->SetLineWidth(2);

   c1->Modified();
   c1->Print("mult_graph_wi_lines.png");
}

