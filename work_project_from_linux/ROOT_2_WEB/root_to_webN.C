
{

TCanvas* c500 = new TCanvas("c500","Drawing to the WEB",10,10,600,600);

   char * fnames[50];      //  we could have 50 images, this takes little space
   for(int k=0;k<50;k++) fnames[k]=new char[14];
   for(int k=0;k<50;k++) sprintf(fnames[k],"pict%d.png",k);

///////////////

FILE *outfil;
outfil=fopen("index.html","w");   //   opening   index.html   
   fprintf(outfil,"<html>\n");       //    starting HTML  printout    
   fprintf(outfil,"<head>\n");       //    head and title
   fprintf(outfil,"<title>\n");
   fprintf(outfil,"PHYS291 Project Spring 2026");
   fprintf(outfil,"</title>\n");

fclose(outfil);                             // close - to insert mathJax

system("cat mathjax.fil >>  index.html");

outfil=fopen("index.html","a");      //  reopen index.html
   fprintf(outfil,"</head>\n");

   fprintf(outfil,"<body style=");  //  specify the font and colors

   fprintf(outfil,"\"font-family:monospace; font-size: 14pt; "); 
   fprintf(outfil," color:#000000; background-color:#cbddf5\"> \n");

fprintf(outfil,"<br><b><big>Project PHYS291 - Iselin Kongsmark</big></b> \n");

// Text width fixed by a TABLE TRICK 

   fprintf(outfil,"<br><table width=1100><tr><td style=");
   fprintf(outfil,"\"font-family:monospace; font-size: 14pt\"> \n");

   fprintf(outfil,"<br>This porpose of this project is to visualize fMRI data representing brain activity in the Default Mode Network (DMN). In this report two main visualizations are presented: first one where time is constant while varying spatial coordinates, and another one with constant spatial coordinates while varying time.\n");
   fprintf(outfil, "<br><br>\n");

   fprintf(outfil,"<br><b>Brief theory </b> \n");
   fprintf(outfil,"<br><br>\n");

   fprintf(outfil,"Magnetic Resonance Imaging (MRI) is a medical imaging technuiqe that utilizes strong electromagntic fields to produce detalied images of the body's internal stucture. It generates high-resolution images with excellent contrast between different tissue types [1]. In functional magnetic ressonance imaging (fMRI), a series of MRI scans are collected over time. This measures the changes in blood flow and oxygenation levels realted to neural activity [1], called the BOLD signal. \n");
   fprintf(outfil,"<br><br>\n");

   fprintf(outfil," From fMRI distinct networks of brain regions can be identified.These networks are active during different kinds of activity. The discovery of one of particular network revolutionized our understanding of the human brain, namly the Defaul Mode Network (DMN). The DMN is active e.g. during rest, daydreaming or mind wandering. Research on DMN have revealed a lot about how large-scale functional brain networks behave, enabeling mapping of brain orginization [2]. \n");
   fprintf(outfil,"<br><br>\n");

   fprintf(outfil,"In this project, some simple visualizations of DMN fMRI data are presented.The visualization will examplify both how magnetic ressonance create images of the brain's internal stuckture, and how the BOLD signal changes over time for the DMN network. \n");

   fprintf(outfil,"<br><br>\n");

   fprintf(outfil,"<br><b>Preprocessing steps </b> \n");
   fprintf(outfil,"<br><br>\n");

   fprintf(outfil,"The raw fMRI data is stored in a NIfTI (.nii) file, with dimensions x, y, z, and t, forming voxels enlisting the activity levels over time. The voxels represent a brain volume of 2 mm$\^2$ and there are 0.72 seconds between each scan. \n");
   fprintf(outfil, "<br><br>\n");
   
   fprintf(outfil,"Using the Python package NiBabel, the data was sampled and converted to a text file (CSV). If one were to include all of the data, the resulting text file would have a size of multiple GB, which would be excessive for this project. Systematic sampling was therefore performed to reduce computational time and processing requirements, while still retaining sufficient data quality for visualization purposes. The sampling interval was set to 2 for the data point in x, y, and z axis, and the time axis was reduced to the first 42 time stamps. This results in about 30 seconds worth of scans.\n");
   fprintf(outfil, "<br><br>\n");

   fprintf(outfil,"The text file was next converted into a ROOT file, using the TTree structure which is efficient for plotting in ROOT. \n");
   fprintf(outfil, "<br><br>\n");

   fprintf(outfil, "<br><b> Histograms at constant time </b> \n");
   fprintf(outfil, "<br><br>\n");

   fprintf(outfil,"This section presents two-dimensional histograms of brain slices generated in ROOT, where color represents activity level. First we will take a look at some examples for different values of z, before a scrolling animation is displayed. In these plots the x, y, and t coordinates remains constant. The program plot_2Dhist.C is designed to let the user plug in a z-value of their choice. However, for the Root_to_webN.C producing this html report, that feature had to be enabled. \n");
   fprintf(outfil, "<br><br>\n");

//                           Making the graphics

   int I=0;
   TF1 *func;  TString FUNC;
   
//////// from plot_2Dhist.C

TFile *f = new TFile("fmri_val1_t42.root");
TTree *tree = (TTree*)f->Get("brain");
tree->Draw("intensity>>htemp", "", "goff");
TH1F *htemp = (TH1F*)gDirectory->Get("htemp");
Double_t mean = htemp->GetMean();

// call the function plot_2Dhist defined at bottom of script
plot_2Dhist(c500, tree, mean, 20, 0);
c500->Print(fnames[I]); 

plot_2Dhist(c500, tree, mean, 40, 0);
c500->Print(fnames[I+1]);

plot_2Dhist(c500, tree, mean, 60,0);
c500->Print(fnames[I+2]);

   fprintf(outfil, "<div style=\"display:flex; gap:10px;\">\n");
   fprintf(outfil, "<img src=\"%s\" style=\"width:32%%\">\n", fnames[I]);
   fprintf(outfil, "<img src=\"%s\" style=\"width:32%%\">\n", fnames[I+1]);
   fprintf(outfil, "<img src=\"%s\" style=\"width:32%%\">\n", fnames[I+2]);
   fprintf(outfil, "</div>\n");
I += 3;

   fprintf(outfil,"<br><k> Figure 1: Brain slices at different z-values, t=0.</k> \n");
   fprintf(outfil,"<br><br>\n");

   fprintf(outfil,"Figure 1 shows brain cross sections at z = 20, 40 and 60 for time t=0. The colorbar indicates the absolute relative deviation from the mean activity level in the brain. Yellow zones are therefore either a much more active or much less active than the average voxel intensity. This is calculated using the following formula: \n");
   fprintf(outfil,"<br><br>\n");

   
   fprintf(outfil," $$ \\bar{I} = |\\frac{ I - \\text{Global mean}} {\\text{Global mean}} | \\cdot 100 $$\n");
   fprintf(outfil,"<br><br>\n");

   fprintf(outfil,"where Global mean is the mean of all voxel intensities at all time instances. \n");
   fprintf(outfil,"<br><br>\n");

   fprintf(outfil,"To counteract sparse voxel density caused by sampling and to create smoother plots, the intensity was averaged for nearby slices and ROOT's build in smooting function was utilized. \n");
   fprintf(outfil,"<br><br>\n");

   fprintf(outfil,"<br><b>Scrolling through all brain slices</b><br>\n");
   fprintf(outfil,"<br><br>\n");

   fprintf(outfil,"In the animation in Figure 2, the z coordinate increases for each new plot. This creates the effect of scrolling through the brain volume, similar to the visualization used in CT imaging. The animation was created by looping over the same function that produced the plots over. \n");
   fprintf(outfil,"<br><br>\n");

// --- scroll through slices, save frames, make GIF ---
int frameCount = 0;
for (int slice = 0; slice < 78; slice += 2)
{
    plot_2Dhist(c500, tree, mean, slice, 0);
    c500->Print(Form("frame_%02d.png", frameCount));
    frameCount++;
}

system("convert -delay 20 -loop 0 frame_*.png scroll_animation.gif");
system("rm frame_*.png");  // clean up frames after GIF is made

   fprintf(outfil, "<br><br>\n");
   fprintf(outfil, "<img src=\"scroll_animation.gif\"><br>\n");
   fprintf(outfil,"<br><k>Figure 2: Scrolling animation of brain slices at t=0.</k><br>\n");
   fprintf(outfil, "<br><br>\n");

   fprintf(outfil,"<br><b>Histograms with time evolution </b> \n");
   fprintf(outfil,"<br><br>\n");

   fprintf(outfil,"In the following animations, time evolution will be incorporated to display how activity changes over time. In the original script the user is able to choose which slice (z-value) to plot. For the purpose of making this report, the z-values 20, 40 and 60 was chosen, as for in Figure 1. \n");
   fprintf(outfil,"<br><br>\n");
// --- time evolution of slice, save frames, make GIF ---
int frameCount2 = 0;
for (int t = 0; t < 42; t++)
{
    plot_2Dhist(c500, tree, mean, 20, t);
    c500->Print(Form("frameA_%02d.png", t));

    plot_2Dhist(c500, tree, mean, 40, t);
    c500->Print(Form("frameB_%02d.png", t));

    plot_2Dhist(c500, tree, mean, 60, t);
    c500->Print(Form("frameC_%02d.png", t));

    // stitch the three side by side into one combined frame
    system(Form("convert frameA_%02d.png frameB_%02d.png frameC_%02d.png +append combined_%02d.png", t, t, t, t));
}
system("convert -delay 72 -loop 0 combined_*.png timeev_animation.gif");
system("rm frameA_*.png frameB_*.png frameC_*.png combined_*.png");

   fprintf(outfil, "<img src=\"timeev_animation.gif\" style=\"width:98%%\"><br>\n");
   fprintf(outfil, "<br><k>Figure 3: Time evolution of brain slices z=20, 40, 60:</k><br>\n");
   fprintf(outfil, "<br><br>\n");

   fprintf(outfil,"In the animation above in Fugure 3, some areas are lit up more than the surrounding tissue. Looking at the relative deviation will highlight the areas with the most notable intensities. One would expect these areas to somewhat correlate with the brain regions which are active during DMN. For future projects, it would be interesting to explore wether these areas match the regions one expects to be active during DMN.\n");
   fprintf(outfil,"<br><br>\n");
   fprintf(outfil,"If there was more time for this project, it would also be interesting to do a more thourough normalization of data. The method used now uses the global mean intensity. However, to attain a proper BOLD signal, one should normalize each voxel by it self. When normalizing using the global mean, important data could be lost. \n");

//// ----------

   
   fprintf(outfil,"</td></tr></table><br>\n");
 

  //  fprintf(outfil,"</body>\n");     // should be there
  //  fprintf(outfil,"</html>\n");      // but browsers are forgiving


   fclose(outfil);
   
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

void plot_2Dhist(TCanvas* c, TTree* tree, Double_t mean, int slice = 40, int t = 0)
{
gStyle->SetPadLeftMargin(0.15);
c-> SetRightMargin(0.18);

// create histogram
tree->Draw(
    "y:x >> h(32,-10,100,32,-5,120)",
    Form("abs((intensity-%f)/%f) *(abs(z-%d)<2 && t==%d)", mean, mean, slice, t),
    "colz"
);

TH2F *h = (TH2F*)gDirectory->Get("h");

h->SetTitle(Form("Brain Slice z=%d   t=%d   (%.2f sec)", slice, t, t*0.72));
h->SetMinimum(0);
h->SetMaximum(1);

h->GetXaxis()->SetTitle("x");
h->GetYaxis()->SetTitle("y");
h->GetZaxis()->SetTitle("Intensity - Absolute Relative Deviation");

h->Smooth();
h->SetStats(0);
h->Draw("colz");

}

