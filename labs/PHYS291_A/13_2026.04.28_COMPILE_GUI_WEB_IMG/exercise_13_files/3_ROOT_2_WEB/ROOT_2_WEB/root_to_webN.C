{
// New ROOT SESSION

TCanvas* c500 = new TCanvas("c500","Drawing to the WEB",10,10,600,600);

   char * fnames[50];      //  we could have 50 images, this takes little space
   for(int k=0;k<50;k++) fnames[k]=new char[14];
   for(int k=0;k<50;k++) sprintf(fnames[k],"pict%d.png",k);

 
//     Preparing LATEX  - used below in the text part

TString latx="Coding the polynomial $f(x)$ into the TF1 and similar objects in ROOT\n";
latx=latx+"<br><br>\n";

latx=latx+"   $$  f(x) = p_0 + p_1 x + p_2 e^ {-p_3 ( x - p_4) ^2 }  $$ \n";
latx=latx+"<br><br>\n";

latx=latx+"   $$    [0]+[1] * x + [2] * \exp (-[3] * (x-[4]) *(x-[4]) )  $$   \n";
latx=latx+"<br><br>\n";


latx=latx+"Coding $f(x)$ into the TF1 and similar objects  in ROOT  - a simple fraction in $x$  \n";                                                    
latx=latx+"<br><br>\n";

latx=latx+"$$    f(x) = \\frac{p_6} { p_7+(x-p_8)^2 }     $$   \n";

latx=latx+"<br><br>\n";

latx=latx+"$$       [6]/([7]+(x-[8])*(x-[8]) )       $$   \n";

latx=latx+"<br><br>\n";

latx=latx+"Quantum Mechanics Notation \n";
latx=latx+"<br><br>\n ";

TString LANGL="\\langle"; TString RANGL="\\rangle";

TString latx2 = "$$" + LANGL + "\\psi^*_f | \\ T \\   | \\psi_i "+ RANGL +" \\ =\\  0 $$   \n";
latx2=latx2+"<br><br>\n";
latx2=latx2+"$$     \\int \\psi^*_f (r,\\theta,\\phi) \\ T \\ \\psi_i (r,\\theta,\\phi)\\ ";
latx2=latx2+" r^2 dr  sin\\theta d\\theta d\\phi \\ =\\  0 $$ \n ";

latx2=latx2+"<br><br>\n";
TString latx3="Hydrogen Atom Quantum Mechanics Description etc  \n";  
latx3=latx3+"<br><br>\n";

//   done up to here
latx3=latx3+"$$     \\psi^* (r,\\theta,\\phi) \\  \\ =\\  R_{nl}(r) \\ Y_{lm}( \\theta,\\phi ) $$   \n";
latx3=latx3+"<br><br>\n";
 
latx3=latx3+"$$      \\int  R_{n_f l_f}(r) R_{n_i l_i}(r)\\  T(r) \\  r^2 \\ dr \\  \n";
latx3=latx3+"\\int  Y_{l_fm_f}(\\theta,\\phi) Y_{l_Tm_T}(\\theta,\\phi) Y_{l_im_i}";
latx3=latx3+"(\\theta,\\phi)\\sin\\theta d\\theta d\\phi $$   \n"; 

latx3=latx3+"<br><br>\n";

latx = latx + latx2 + latx3;

//     latex part end

   FILE *outfil;
   outfil=fopen("index.html","w");   //   opening   index.html   
   fprintf(outfil,"<html>\n");       //    starting HTML  printout    
   fprintf(outfil,"<head>\n");       //    head and title
   fprintf(outfil,"<title>\n");
       fprintf(outfil,"The title - ROOT to WEB");
   fprintf(outfil,"</title>\n");

 fclose(outfil);                             // close - to insert mathJax

	 system("cat mathjax.fil >>  index.html");


  outfil=fopen("index.html","a");      //  reopen index.html
  fprintf(outfil,"</head>\n");





   fprintf(outfil,"<body style=");  //  specify the font and colors
   
   fprintf(outfil,"\"font-family:monospace; font-size: 14pt; "); 
   fprintf(outfil," color:#0000AA; background-color:#FFFFAA\"> \n");

   
   fprintf(outfil,"<br><b><big>LINKS:</big></b> \n");

   fprintf(outfil,"<br><a href=\"about_html_2.txt.html\">Description:  about_html_2.txt.html</a>\n");
   fprintf(outfil,"<br><a href=\"animate.html\" target=\"nnn\">Demo of page animation using refresh (new Tab)</a>\n");
   fprintf(outfil,"<br>View also this index.html in the tab to left, <b>without the webserver</b>");
   fprintf(outfil,"<br><a href=\"https://folk.uib.no/nfylk/web2022/\">");
   fprintf(outfil,"folk.uib.no/nfylk/web2022/</a> - a WEB version of graphics part of this(2022)<br>\n");
  
   //    To printf "  inside of "   "   you use    \"
   //       printf(" \"  \" --")    prints   "  " --

  // Text width fixed by a TABLE TRICK 

  fprintf(outfil,"<br><table width=1100><tr><td style=");
  fprintf(outfil,"\"font-family:monospace; font-size: 16pt\"> \n");

  fprintf(outfil,"This is the text part, also showing the use of latex. The text finds \n");
  fprintf(outfil,"the correct width itself because it is adjusted by the Table. \n");
  fprintf(outfil," Also the font size is adjusted by the < td > tag, as you \n");
  fprintf(outfil,"will find studying the source, both of root script which \n");
  fprintf(outfil,"produced (this one!) and the source index.html BELOW in the textbox <br><br> \n");

   fprintf(outfil,"<br>testing LaTeX $$f_a(x)=\\frac{x}{1+x^2}$$<br><br>\n");
fprintf(outfil,"and here can come lots of more text, no limitations, the width will be adjusted. \n");
fprintf(outfil,"<b><br><a href=\"#latexF\"><big>More Latex examples</a></big> </b> below the graphics<br>");
////////////////////
 //     fprintf(outfil,"%s\n", latx.Data());  // was originally here - moved to name="larexF"
////////////////////
//                           Making the graphics

   int I=0;
   TF1 *func;  TString FUNC;


 //  LOOP BY HAND
  FUNC="cos(2*x)*exp(-0.3*x)"; func=new TF1("func",FUNC,0,10);
  func->Draw(); 
      fprintf(outfil,"<hr><br>This image: function  %s \n<br>\n" ,FUNC.Data());
      fprintf(outfil,"&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;");
      fprintf(outfil,"&nbsp;<img src=\"%s\"><br>\n",fnames[I]);
      c500->Print(fnames[I]); I = I+1;

  FUNC="sin(4*x)*exp(-0.5*x)"; func=new TF1("func",FUNC,0,10);
  func->Draw(); 
      fprintf(outfil,"<hr><br>This image: function  %s \n<br>\n" ,FUNC.Data());
      fprintf(outfil,"<img src=\"%s\"><br>\n",fnames[I]);
      c500->Print(fnames[I]); I = I+1;

  FUNC="cos(2*x)*exp(0.3*x)"; func=new TF1("func",FUNC,0,10);
  func->Draw(); 
      fprintf(outfil,"<hr><br>This image: function  %s \n<br>\n" ,FUNC.Data());
      fprintf(outfil,"&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;");
      fprintf(outfil,"&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;");
      fprintf(outfil,"&nbsp;<img src=\"%s\"><br>\n",fnames[I]);
      c500->Print(fnames[I]); I = I+1;

    fprintf(outfil,"<a name=\"latexF\"> <br><hr><br> \n");

   fprintf(outfil,"  <b> More Latex examples </b> <br>");


     fprintf(outfil,"%s\n", latx.Data()); 


  fprintf(outfil,"</td></tr></table><br>\n");
 
 

  //  fprintf(outfil,"</body>\n");     // should be there
  //  fprintf(outfil,"</html>\n");      // but browsers are forgiving


   fclose(outfil);
   system("txtbox_blue index.html");
   system("echo \"<br><br><b>Source of this file (before adding it)</b>\" >> index.html");
   system("cat index.html.html >> index.html");
   system("echo \"<br><br><b>The root macro root_to_webN.C producing all this </b>\" >> index.html");
   system("txtbox_white root_to_webN.C");
   system("cat root_to_webN.C.html >> index.html");
   system("txtbox_white about_html_2.txt");
   system("firefox  index.html  &");
   system("cp nswap swap");
   system("cp animate.fil animate.html");
   system("python3 -m http.server 8000 &");
   system("./swap &");
   sleep(1);
   system("firefox  http://127.0.0.1:8000/  &");
}

