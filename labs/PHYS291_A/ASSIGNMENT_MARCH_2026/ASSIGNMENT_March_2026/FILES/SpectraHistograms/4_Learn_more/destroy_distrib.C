{
double p3=hB->GetFunction("plotFun")->GetParameter(3);
hB->GetFunction("plotFun")->SetParameter(3,4*p3);
C2->Modified();
p3=hA->GetFunction("plotFun")->GetParameter(3);
hA->GetFunction("plotFun")->SetParameter(3,0.25*p3);
C4->Modified();
cout << "These lines modified the internal clones of the Fit Function\n";
cout << "stored in the histogram objects  hA  and  hB \n";
cout << "Both are cloned from plotFun INTERNALLY! \n\n"; 
cout << "To restore the good fit, type/paste in:\n ";
cout << "  C2->cd();hB->Fit(plotFun); \n ";
cout << "  C4->cd();hA->Fit(plotFun); \n ";

//  C2->cd();hB->Fit(plotFun);
//  C4->cd();hA->Fit(plotFun); 
}

