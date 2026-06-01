void one_step();  void go_steps(); void go_fast(); void do_step(); void new_walk();
void quit_root(); 
 
   TCanvas * CONTROLS;
   TCanvas * WALKS; TLine *AA;  TCanvas * STEPS; TH1F * Steps;
   TButton		*step_button; TButton		*go_button;
   TButton		*fast_button; TButton		*quit_button; 
   TTimer *timer;    //  The timer is a device to make autonomous processes
 
   double Lim; int isteps; double L1;double L2;
   double xold, yold, xnew, ynew;
   int no_of_walks; double oldangle;

void roundwalk()
{
   gRandom->SetSeed();
   L1=1.0; L2=1.0;             //  Step Length parmeters
   no_of_walks=0; isteps=0;
   xold = 0.0;  Lim=12.0;
   yold = 0.0;    
   WALKS=new TCanvas("WALKS","WALKS",200,30,500,500);   
   WALKS->Range(-Lim,-Lim,Lim,Lim);
   CONTROLS=new TCanvas("CONTROLS","Controls",30,30,150,200);	  
   STEPS=new TCanvas("STEPS","STEPS",710,30,600,500);
   Steps=new TH1F("Steps","No of steps",100,0.0,400);
   Steps->Draw();
   timer = new TTimer(0); 
   xnew=0.0; ynew=0.0;
   xold=xnew; yold=ynew;

   CONTROLS->cd();     //   Little canvas for buttons         
   step_button = new TButton("STEPS", "one_step()",0.1,0.75,0.85,0.95);
   go_button = new TButton("GO", "go_steps()",0.1,0.50,0.85,0.70);
   fast_button = new TButton("FAST", "go_fast()",0.1,0.25,0.85,0.45);
   quit_button = new TButton("QUIT", "quit_root()",0.1,0.025,0.85,0.225);
	      step_button->Draw();     go_button->Draw();
          quit_button->Draw();    fast_button->Draw();
   go_steps();   
  }

