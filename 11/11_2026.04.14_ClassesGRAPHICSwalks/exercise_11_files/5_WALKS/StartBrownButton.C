
// Demonstration of fast point redrawing in root 
// 400 points drawn 2000 times 
void more_walk();   void StartBrownButton();
TButton		*stop_button; TButton		*go_button;
TCanvas * CONT;

  TCanvas  *CC;;   

  TLine * AA;  

   double Lim=12.0; int i=0;
   double xold, yold;
   TTimer *timer; 


void StartBrownButton()
{

  {
   timer = new TTimer(0);  
   CC=new TCanvas("CC","CC",700,50,500,500);
   CONT=new TCanvas("CONT","Controls",10,50,100,100);
	 
	CC->cd();  
   TAttLine (45, 6, 6);
   AA= new TLine(0,0,0,0);
   CC->Range(-12,-12,12,12);
   xold=0; yold=0;
   AA=new TLine(xold, yold, xold+0.1, yold+0.1);
   AA->SetLineWidth(0);
   AA->Draw();
	  
	  CONT->cd();     //   Little canvas for buttons
	  stop_button = new TButton("STOP", "timer->TurnOff()",0.1,0.1,0.85,0.45);
      go_button = new TButton("GO", "timer->TurnOn()",0.1,0.55,0.85,0.85);	  
	  
	  stop_button->Draw();       go_button->Draw();
   }   
	timer->SetCommand("more_walk()");
	timer->SetTime(0);
	timer->TurnOn(); 	 


  }
void more_walk(){   
   
 CC->Clear();
 CC->cd();
   i=0;
   xold=0; yold=0;
  while (  i<400 )
  { i++;
   double xold=-12+24*gRandom->Rndm();
   double yold=-12+24*gRandom->Rndm();
 
   AA=new TLine(xold, yold, xold+0.35, yold);
   AA->SetLineWidth(10);
   AA->Draw() ; 
  }
   CC->Modified();
   CC->Update(); 
 
}


