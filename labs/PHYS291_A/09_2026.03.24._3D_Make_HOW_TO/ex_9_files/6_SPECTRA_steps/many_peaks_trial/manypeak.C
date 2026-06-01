{
np=6;
TString BigFun;
TString Lin="[0]+[1]*x";
TString pl="+";
TString Gausses[100];
char temp[50];
int i; int v;
for(i=0;i<np;i++)  {  v=2+3*i;
     sprintf(temp,"[%d]*exp(-[%d]*(x-[%d])*(x-[%d]))",v,v+1,v+2,v+2);
     cout << temp<<endl;
     Gausses[i]=temp;
}
BigFun=Lin;
for(i=0;i<np;i++)  { BigFun=BigFun+pl+Gausses[i];}
cout << BigFun << endl;
     
TF1 *bf= new TF1("bf",BigFun,0,20);
bf->SetParameter(0,3);
bf->SetParameter(1,0.07);
for(i=0;i<np;i++) { v=2+3*i; bf->SetParameter(v,3);
bf->SetParameter(v+1,2);   bf->SetParameter(v+2,2+i*2.9); 
}
TCanvas * Tc=new TCanvas("Tc","Tc");
TH1F * his=new TH1F("his","manypeaks",100,0,20);
Tc->Divide(1,2);
Tc->cd(1);
bf->Draw();
for(i=0;i<100000;i++) his->Fill(bf->GetRandom());
Tc->cd(2);
his->Draw();
his->SetMinimum(0);
cout << "\n\n    Run\n    .x manyfit.C\n";
}






