 {TF1 fcos("fcos","cos(3*x)*exp(-0.3*x)",0,10); // Do not repeat if you continue
 TF1 fsin("fsin","sin(x)*exp(-0.2*x)",0,10);
 fcos.Draw();                  // Do not repeat if ...
 fsin.Draw("SAME"); // You can also try
 TF1 fup("fup","0.3*cos(2*x)*exp(0.15*x)",0,10)
 fup.Draw("SAME");   //   or "SAME" ?? can you combine 3
 fsin.SetLineColor(kOrange); // and click on the Canvas
 fcos.SetLineColor(kBlue);}
