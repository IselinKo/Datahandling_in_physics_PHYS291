//  With SetTime(3000)  the timer waits 3 sec = 3000 millisec
//  With SetTime(1)     the program runs fast(1 millisec per step)
//  Change to  1 or 10 or 10000
//
//  Push STOP - then you can .g in the command
//
TTimer *timer;    
TCanvas  * Canv_Control;
TButton	*stop_button; 
TButton	*go_button; 
int tot=0;  


void Timer_controller() {

Canv_Control=new TCanvas("Canv_Control","Timer Controls",30,230,200,200);
stop_button = new TButton("STOP", "timer->TurnOff()",0.1,0.1,0.8,0.3);
    stop_button->Draw(); 
go_button = new TButton("GO", "timer->TurnOn()",0.1,0.5,0.8,0.7);
   go_button->Draw();
timer = new TTimer(1); 
   timer->SetCommand("do_the_work()");
   timer->SetTime(1);  //  SetTime(1);   SetTime(3000); 
   timer->TurnOn(); 	  
}

void do_the_work(){
 tot++;
 cout << "one_more step  " << tot << endl;
}


