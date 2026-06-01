//
// usage:  xlabel( MyGraph, "label x");  //-----------------------------------
//         ylabel( MyGraph, "label y");  //-----------------------------------
//
//         MyGraph can be both simple TGraph  or TMultiGraph object
//
void ylabel( TGraph* GRAF, TString  Text ){
   GRAF->GetYaxis()->SetTitle(Text);
   GRAF->GetYaxis()->CenterTitle(true);          //  Axis label in the center
}
void xlabel( TGraph* GRAF, TString  Text ){
   GRAF->GetXaxis()->SetTitle(Text);
   GRAF->GetXaxis()->CenterTitle(true);          //  Axis label in the center
}

//  TMultiGraph *

void ylabel( TMultiGraph * GRAF, TString  Text ){
   GRAF->GetYaxis()->SetTitle(Text);
   GRAF->GetYaxis()->CenterTitle(true);          //  Axis label in the center
}
void xlabel( TMultiGraph * GRAF, TString  Text ){
   GRAF->GetXaxis()->SetTitle(Text);
   GRAF->GetXaxis()->CenterTitle(true);          //  Axis label in the center
}

