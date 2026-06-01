
TCanvas  * Canv_Cons;
TButton	*stop_butt; 
TButton	*go_butt; 
int totalus=0;  
void do_the_job();

void controller() {

Canv_Cons=new TCanvas("Canv_Cons","Controls",30,30,200,200);
stop_butt = new TButton("QUIT", "exit_here()",0.1,0.1,0.8,0.3);
    stop_butt->Draw(); 
go_butt = new TButton("STEP", "do_the_job()",0.1,0.5,0.8,0.7);
   go_butt->Draw();
}

void exit_here() {
        cout << "exiting root by running\ngROOT->ProcessLine(\".q\")\n";
        gROOT->ProcessLine(".q");
}

void do_the_job(){
 totalus++;
 cout << "===============================Cone_more step  " << totalus << endl;
}


