{
  int Idec; char Cdec;
  TF1 f1("f1","4/(4+x**2)",-5,5);
  TF1 f2("f2","1/(2+2*x**2)",-5,5);
  TF1 f3("f3","exp(-0.2*x**2)",-5,5);

  f1.SetMinimum(0);  f1.Draw();

cout << "    Shown is function 1/(4+x**2) - which of the 2 following is closest?\n";
cout << "    enter 2 for 1/(2+2*x**2)     or       enter 3 for  exp(-2*x**2)    : ";
cin >> Idec;

if(Idec<2 || Idec>3 ) {
	cout << "you entered a wrong number == " << Idec << "  I set it to 2 \n";
	Idec=2;          }
if(Idec==2) f2.Draw("same"); else f3.Draw("same");
   cout << "Do you want to see the other comparison? - enter y or n  :  ";cin >> Cdec;
if (Cdec=='y'){TCanvas*c7=new TCanvas("c7","comp",600,100,600,400);c7->cd();f1.Draw();
if(Idec==3) f2.Draw("same"); else f3.Draw("same");}
}
