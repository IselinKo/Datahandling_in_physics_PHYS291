void one_step();  void go_steps(); void go_fast(); void do_step(); void new_walk();
void quit_root(); 
 
   TCanvas * CONTROLS;    TMarker *m;
   TCanvas * WALKS; TLine *AA;  TCanvas * STEPS; TH1F * Steps;
   TButton		*step_button; TButton		*go_button;
   TButton		*fast_button; TButton		*quit_button; 
   TTimer *timer;    //  The timer is a device to make autonomous processes
 
   double Lim; int isteps; double L1;double L2;
   double xold, yold, xnew, ynew;
   int no_of_walks; double oldangle;

void wmarker()
{
   gRandom->SetSeed();
   L1=1.0; L2=1.0;             //  Step Length parmeters
   no_of_walks=0; isteps=0;
   xold = 0.0;  Lim=12.0;
   yold = 0.0;    
   WALKS=new TCanvas("WALKS","WALKS",200,30,500,500);   
   WALKS->Range(-Lim,-Lim,Lim,Lim);
   m = new TMarker(0.0, 0.0, 31);
   m->SetMarkerSize(2); m->SetMarkerColor(kBlue);
   m->Draw();
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
void do_step(){        //    single step; draw the path line
   double dx,dy;
   WALKS->cd();           //    Will Draw to the walk-canvas 
   isteps++;
    double lenn=L1+L2*gRandom->Rndm();      // step parameters
    // double angl=2.0*3.14159*gRandom->Rndm();
    double angl=oldangle+gRandom->Gaus(1.5,1.0);
    dy = lenn*sin(angl);                    // step coordinates
    dx = lenn*cos(angl);
    oldangle=angl;
    xnew=xold+dx; ynew=yold+dy;
    AA=new TLine(xold, yold, xnew, ynew);   // The line made by new
    AA->Draw() ;   
    m->SetX(xnew); m->SetY(ynew);                         
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
	xold=xnew; yold=ynew; m->Draw();
	printf(" walk %d.  tok  %d random steps to  escape\n",no_of_walks,isteps);
	Steps->Fill((Float_t) isteps);
	STEPS->cd();
	Steps->Draw();  
	STEPS->Modified();
	STEPS->Update();	
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
          step_walk();
}
void go_steps(){                // timer on; each step drawn
	  timer->SetCommand("step_walk()");
	  timer->SetTime(4);
      timer->TurnOn();
}        
void go_fast(){                 // timer on, only each whole walk drawn
	  timer->SetCommand("many_steps_walk()");
	  timer->SetTime(0);
      timer->TurnOn();
}       	  	
void quit_root() { gROOT->ProcessLine(".q"); }  
