void clicks_func() {
   //   this action function is called whenever you move the mouse
   //   it  prints the event or keybord event code
   //   you can add graphics actions instead
   
   int event = gPad->GetEvent();     // EVENT 
   
   cout << event<< endl; 
   
	 int px = gPad->GetEventX();      //  event data
   int py = gPad->GetEventY();  

	cout << px << "  " << py << endl;

	if (event == 1){     //   if event 
         cout << "==============  MOUSE CLICKED ===========================\n";
   }
   if (event == 11){     //   if event 
         cout << "==============  MOUSE RELEASED ===========================\n";
   }
	
}

