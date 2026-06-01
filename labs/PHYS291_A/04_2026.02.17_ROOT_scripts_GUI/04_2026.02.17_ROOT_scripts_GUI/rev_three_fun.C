{    //  Brace needed only when used as a script/macro
 // This is copy of the "figure solution"
 // Filename three_fun.C
 // Run by     root rev_three_fun.C or .x rev_three_fun.C in root
 // and ,  item Editor on the Graphics Window
 // Change graphically Line colors, Line thickness etc
 //
 TF1 fcos("fcos","cos(3*x)*exp(-0.3*x)",0,10);   // all need semicolon                
 TF1 fsin("fsin","sin(x)*exp(-0.2*x)",0,10);
 TF1 fup("fup","0.3*cos(2*x)*exp(0.15*x)",0,10);
 
 fup.Draw(); 
 fsin.Draw("SAME");
 fcos.Draw("SAME");            // if interactive, enter line

 fsin.SetLineColor(kOrange); // and click on the Canvas
 fsin.SetLineWidth(4);       // and click on the Canvas
 fcos.SetLineColor(kBlue); 
 fup.SetLineColor(kBlack);  
  
 fcos.SetTitle("  ");         // still a wrong title
 fup.SetTitle("  ");          // fup defines the "SAME"   
 } // Add this brace if saving in a file to be run by .x 

