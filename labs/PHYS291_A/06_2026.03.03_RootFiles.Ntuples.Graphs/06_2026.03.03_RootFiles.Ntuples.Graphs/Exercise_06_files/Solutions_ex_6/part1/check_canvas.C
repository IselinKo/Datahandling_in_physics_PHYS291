{

   fil2 = new TFile("basicX.root","UPDATE"); // open - to read or modify
   TCanvas * QQQ = (TCanvas *) fil2->Get("A_canvas");
   QQQ->Draw();
}
