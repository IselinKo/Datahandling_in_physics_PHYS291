{
// Reuse this for various other distributions

TH1F* hi1;     // we define the pointer, so that we can write
               // many times for various cases ..... h1=new TH1F......

h1=new TH1F("A","b",100,0.0,1.0);
for(int i=0;i<10000000;i++){   h1->Fill(  gRandom->Rndm()  ) ;}
h1->Draw();
//  But you must remember:  
h1->SetMinimum(0);   
//  otherwise it is confusing - does not "look uniform" at all
}

