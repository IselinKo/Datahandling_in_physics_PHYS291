
TCanvas  * Canv_Control;
TButton	*stop_button; 
TButton	*go_button; 
int tot=0;  
void do_the_work();

void controller() {

Canv_Control=new TCanvas("Canv_Control","Controls",30,30,200,200);
stop_button = new TButton("END ROOT", "exit_here()",0.1,0.1,0.8,0.3);
    stop_button->Draw(); 
go_button = new TButton("GO", "do_the_work()",0.1,0.5,0.8,0.7);
   go_button->Draw();
}

void exit_here() {
        cout << "exiting root by running\ngROOT->ProcessLine(\".q\")\n";
        gROOT->ProcessLine(".q");
}

void do_the_work(){
 tot++;
 cout << "one_more step  " << tot << endl;
}


