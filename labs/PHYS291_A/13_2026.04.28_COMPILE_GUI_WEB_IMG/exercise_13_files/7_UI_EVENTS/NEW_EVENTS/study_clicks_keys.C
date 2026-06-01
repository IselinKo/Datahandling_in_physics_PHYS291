{
    //     clicks_handler_1.C
	//
gROOT->ProcessLine(".L clicks_handler_1.C");	

  // Shows all types of events, prints the code of the event
  // and the data of the event
  // for mouse movement, the coordinates
  // for keyboard events the code
  //
  
  TCanvas *c1 = new TCanvas("c1","Click-Events",-10,10,700,700);
 
  
  c1->AddExec("ex","clicks_func()");
}

