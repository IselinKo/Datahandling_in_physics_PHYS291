//================ file script_two.C =========================
void printnnNN()
{
//  This is  script -  macro - containing a function
//  it contains a function of type void  (i.e. returns nothing)
//
//  IT CAN NOT BE RUN as named script; file name is different
//     root
//     .L script_two.C
//     printnnNN();
//
//  The variables defined here are PRIVATE, NOT KNOWN to the other
//  programs
    int nn=20;  int NN=40;
    printf("\n\nSimple program doing not much\n");
    printf("\n\n   nn is %d  and  NN is %d \n\n", nn, NN);
}

