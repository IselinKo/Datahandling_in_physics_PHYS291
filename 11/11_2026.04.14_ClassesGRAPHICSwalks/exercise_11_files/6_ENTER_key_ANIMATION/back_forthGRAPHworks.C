{
TCanvas *Displ=new TCanvas("Displ","Drawing");
TF1 f1("f1","exp(-x)",0,5);
TF1 f2("f2","1-exp(-x)",0,5);
TF1 f3("f3","0.5-0.01*x",0,5);f3.SetMaximum(1.0);f3.SetMinimum(0.0);
string lin; 
for(;;){  f1.Draw();Displ->Modified(); Displ->Update(); 
	           gSystem->ProcessEvents();
               getline(cin,lin);
          f3.Draw();Displ->Modified(); Displ->Update();
	           gSystem->ProcessEvents();
               getline(cin,lin);
          f2.Draw();Displ->Modified(); Displ->Update();
	           gSystem->ProcessEvents();
               getline(cin,lin);
          f3.Draw();Displ->Modified(); Displ->Update();
	           gSystem->ProcessEvents();
               getline(cin,lin);
       } 
}
