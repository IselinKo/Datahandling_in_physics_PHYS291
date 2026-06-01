//    as twolines.C
//    named macro; the file and the function the same name
void twolines()  {
TCanvas *Ctwo = new TCanvas("Ctwo","hallo",50,20,700,500);
double xx1[20],yy1[20],xx2[20],yy2[20];
  xx1[0]=1.0; yy1[0]=3.0;
  xx1[1]=4.0; yy1[1]=1.0;
  xx2[0]=1.0; yy2[0]=1.0;
  xx2[1]=3.0; yy2[1]=2.0;
  xx2[2]=5.0; yy2[2]=5.0;
TGraph * Ggr1=new TGraph(2,xx1,yy1);
TGraph * Ggr2=new TGraph(3,xx2,yy2);
Ggr1->Draw("ACP");
Ggr2->Draw("same");
Ctwo->Modified();
}

