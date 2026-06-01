void clicks_func() {
   //this action function is called whenever you move the mouse
   //it  prints the event tpe code
   //you can add graphics actions instead
   
   int event = gPad->GetEvent();     // EVENT 
   
   cout << event<< endl; 
   
	int px = gPad->GetEventX();      //  event data
    int py = gPad->GetEventY();  

	cout << px << "  " << py << endl;

	if (event == 11){     //   if event 11
	TObject *select = gPad->GetSelected();
     if (!select) return;
     if (select->InheritsFrom(TPolyLine::Class())) {
        TPolyLine *pl = (TPolyLine*)select;
        printf("You have clicked triangle %d, color=%d\n",
        pl->GetUniqueID(),pl->GetFillColor());
        }
	}//           if event 11

}

