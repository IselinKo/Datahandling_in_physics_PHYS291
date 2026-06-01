{

// USE LINE BY LINE
// Check syntax by    
//                 root lines_and_markers.C

TCanvas * WALKS; TLine *AA; 

  WALKS=new TCanvas("WALKS","WALKS",200,30,500,500);   
   WALKS->Range(-12,-12,12,12);
   double xold, yold, xnew, ynew;
   xold=0.0; yold=0.0; xnew=4.0; ynew=-10.0;
   AA=new TLine(xold, yold, xnew, ynew);
    AA->Draw() ; 
// leave the first line without its pointer
// AA will now point to a new one

   AA=new TLine(0,0,5,5);
    AA->Draw() ; 
// Now delete the second line
    AA->Delete();
 
////////////////    Markers //////////////////

CC=new TCanvas("CC","CC",700,50,500,500);
CC->Range(-12,-12,12,12);
TMarker *m = new TMarker(1.0, 1.5, 29);
m->Draw();
m->SetX(5);
m->SetY(5);
CC->Modified();
m->SetMarkerSize(3);
CC->Modified();
m->SetMarkerStyle(21);
CC->Modified();
m->SetMarkerStyle(31);
CC->Modified();
m->SetY(10);
CC->Modified();

CC->Range(-12,-12,12,12);
m->Draw();
m->SetMarkerSize(3);
CC->Modified();
m->SetX(5);
m->SetY(5);
CC->Modified();
m->SetX(0);m->SetY(0);
CC->Modified();
// leave the first marker without its pointer
// m will now point to a new one
m = new TMarker(1.0, 1.5, 29);
m->Draw();
m->SetMarkerSize(3);
CC->Modified();
// Now delete the second marker
m->Delete();
}
