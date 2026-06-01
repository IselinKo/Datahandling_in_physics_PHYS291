{
TCanvas *Displ=new TCanvas("Displ","Drawing");
TF1 f1("f1","exp(-x)",0,5);
TF1 f2("f2","1-exp(-x)",0,5);
TF1 f3("f3","0.5-0.01*x",0,5);f3.SetMaximum(1.0);f3.SetMinimum(0.0);
string lin; 
for(int i=0;i<2;i++){  
          f1.Draw();
               getline(cin,lin);
          f3.Draw();
               getline(cin,lin);
          f2.Draw();
               getline(cin,lin);
          f3.Draw();
               getline(cin,lin);
       } 
}
