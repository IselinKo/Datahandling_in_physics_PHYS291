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


