//    First try line by line - then 
//    save this block as noname.C
{
TCanvas *Cnon = new TCanvas("Cnon","hallo",50,20,700,500);
double xx1[20],yy1[20],xx2[20],yy2[20];
  xx1[0]=1.0; yy1[0]=3.0;
  xx1[1]=4.0; yy1[1]=1.0;
  xx2[0]=1.0; yy2[0]=1.0;
  xx2[1]=3.0; yy2[1]=2.0;
  xx2[2]=5.0; yy2[2]=5.0;
TGraph * graf1=new TGraph(2,xx1,yy1);
TGraph * graf2=new TGraph(3,xx2,yy2);
graf1->Draw("ACP");
graf2->Draw("same");
Cnon->Modified();
}

