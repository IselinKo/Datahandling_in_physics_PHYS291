void one_step();  void go_steps(); void go_fast(); void do_step(); void new_walk();
void switch_silent();  void quit_root(); 
 
   TCanvas * CONTROLS;
   TCanvas * WALKS; TLine *AA;  TCanvas * STEPS; TH1F * Steps;
   TButton		*step_button; TButton		*go_button;
   TButton		*fast_button; TButton		*quit_button;  TButton   *silent_button;
   TTimer *timer;    //  The timer is a device to make autonomous processes
 
   double Lim; int isteps; double L1;double L2;
   double xold, yold, xnew, ynew;
   int no_of_walks;     int toplot=1;  int keyDraw=1;

void ReallySilentRandom()
{
   gRandom->SetSeed();
   L1=1.4; L2=1.4;             //  Step Length parmeters
   no_of_walks=0; isteps=0;
   xold = 0.0;  Lim=12.0;
   yold = 0.0;
   WALKS=new TCanvas("WALKS","WALKS",-200,30,500,500);   
   WALKS->Range(-Lim,-Lim,Lim,Lim);
   CONTROLS=new TCanvas("CONTROLS","Controls",-30,30,150,250);	  
   STEPS=new TCanvas("STEPS","STEPS",-710,30,600,500);
   Steps=new TH1F("Steps","No of steps",120,0.0,120);
   Steps->Draw();
   timer = new TTimer(0); 
   xnew=0.0; ynew=0.0;
   xold=xnew; yold=ynew;

   CONTROLS->cd();     //   Little canvas for buttons         
   step_button = new TButton("STEPS", "one_step()",0.1,0.81,0.85,0.98);
   go_button =   new TButton("GO", "go_steps()",0.1,0.62,0.85,0.79);
   fast_button =   new TButton("FAST", "go_fast()",0.1,0.42,0.85,0.60);
   silent_button = new TButton("SILENT", "switch_silent()",0.1,0.22,0.85,0.40);
   quit_button = new TButton("QUIT", "quit_root()",0.1,0.02,0.85,0.20);
	      step_button->Draw();     go_button->Draw();
          quit_button->Draw();   fast_button->Draw(); silent_button->Draw();
   go_steps();   
  }
void do_step(){        //    single step; draw the path line
   double dx,dy;
   WALKS->cd();           //    Will Draw to the walk-canvas 
   isteps++;
    double lenn=L1+L2*gRandom->Rndm();      // step parameters
    double angl=3.14159*gRandom->Gaus(); // 2.0*3.14159*gRandom->Rndm();
    dy = lenn*sin(angl);                    // step coordinates
    dx = lenn*cos(angl);
    xnew=xold+dx; ynew=yold+dy;
   if (keyDraw) 
    {
        AA=new TLine(xold, yold, xnew, ynew);   // The line made by new
        AA->Draw() ;  }                          
    xold=xnew; yold=ynew;
}
void step_walk(){      //  series of steps; draw each step => WALKS->Modified();
     do_step();
 	 WALKS->Modified();
 	 WALKS->Update();
     if (!(( xold > -Lim && xold < Lim  ) && (  yold > -Lim && yold < Lim    )) ){
     new_walk(); }    //  if NOT inside, escaped; new walk
}
void new_walk() {   // after escape - start a new walk; and report the previous
	WALKS->Clear(); WALKS->Range(-Lim,-Lim,Lim,Lim);
    no_of_walks++;
	xnew=0.0; ynew=0.0;
	xold=xnew; yold=ynew;
	printf(" walk %d.  tok  %d random steps to  escape\n",no_of_walks,isteps);
	Steps->Fill((Float_t) isteps);
       if (toplot){
	STEPS->cd();
	Steps->Draw();  
	STEPS->Modified();
	STEPS->Update();}	
    isteps=0; 
}
void many_steps_walk(){   //   series of steps;  draw only when all steps finished
  while (( xold > -Lim && xold < Lim  ) && (  yold > -Lim && yold < Lim    )){     
    do_step();  	
    }
 	WALKS->Modified();
	WALKS->Update();
    new_walk();
}
void one_step(){                // timer repetion OFF, make one step
          timer->TurnOff(); 
          keyDraw=1; 
          toplot=1;
          step_walk();
}
void go_steps(){                // timer on; each step drawn
	  timer->SetCommand("step_walk()");
    keyDraw=1; toplot=1;
	  timer->SetTime(700);
      timer->TurnOn();
}        
void go_fast(){                 // timer on, only each whole walk drawn
	  timer->SetCommand("many_steps_walk()");
	  timer->SetTime(0);
    keyDraw=1;toplot=1;
      timer->TurnOn();
}  
void switch_silent() {                 // timer on, Nothing whole walk drawn
    timer->SetCommand("many_steps_walk()");
    timer->SetTime(0);
    toplot=0;
    keyDraw=0;
      timer->TurnOn();
}      	  	
void quit_root() { gROOT->ProcessLine(".q"); }  




