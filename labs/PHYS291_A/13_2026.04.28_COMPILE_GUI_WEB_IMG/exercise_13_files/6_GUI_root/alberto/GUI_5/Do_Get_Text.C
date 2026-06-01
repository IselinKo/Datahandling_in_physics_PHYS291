void Do_Get_Text(){                //  For the Read Button
    OurTString=  OurText->GetText();
    cout << "\n\n\t\t\t " << OurTString << "\n\t\t\t TString OurTString set as title of the histogram \n";
    plotFun0->SetTitle(OurTString);   Canv->Update();  Canv->Modified();
    //  was hist changed to plotfun0
    
}

