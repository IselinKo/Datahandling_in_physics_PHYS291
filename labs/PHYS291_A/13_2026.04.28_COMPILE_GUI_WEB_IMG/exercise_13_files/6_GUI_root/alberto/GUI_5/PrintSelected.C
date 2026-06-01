void PrintSelected()
{
   //   Handles properly the selected items
   //   Gets their number vi TList if multiselection.

   fSelected->Clear();   //  TList fSelected;

   Canv->cd();
   // if (fListBox->GetMultipleSelections()) {
       printf("==================================\n");
      int N=fListBox->GetNumberOfEntries();
      fListBox->GetSelectedEntries(fSelected);
      //int n=fSelected->GetSize();
      //printf("There are %d selected entries:\n", n);
      n=0;
      for(int i=0; i<N; i++){
         if(fListBox->GetSelection(i)) {
          printf("%d  is selected -> %s\n",i,EntryNames[i]);
          toplot[n]=i;   
          n++;
          }
        }
          cout << "selected " << n << endl;

      //   }  NO if  MultipleSelections
    // THIS IS THE ACTUAL FUNCTIONALITY                              // Tr   
        //  it needs the selected function indices toplot[i]         // Tr
        for (int i=0;i<n;i++){                                       // Tr
             Sfun=funcs[toplot[i]].Data();                           // Tr
                // funcs from assign_funcs(); Sfun a local TString   // Tr
             cout <<"IN LOOP" << Sfun << endl;                                   // Tr
             if(i==0) {  plotFun0=new TF1(Sfun,Sfun,0.0,12.0);       // Tr
                         plotFun0->Draw();                           // Tr 
                      }                                              // Tr                      
             else  {   plotFun=new TF1(Sfun,Sfun,0.0,12.0);          // Tr
                       plotFun->Draw("SAME"); 
                   }                                                 // Tr
 
            }                                                        // Tr
       plotFun0->SetTitle("Combined Plot of selected");
    // THE PART ABOVE ONLY IS THE ACTUAL FUNCTIONALITY               // Tr
      Canv->Modified(); Canv->Update();                      // Tr

} 

