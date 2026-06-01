//================ file collection.C =========================
//
//    run:   .L  collection.C
//           fun_one(3);
//           mesg("Hello there");
//
//  This is a collection of functions 
//  it contains several functions of any type 
//
//
void fun_one(int nn)
{
    //
    printf("\n\nSimple program doing not much\n");
    printf("\n\n   nn is %d   \n\n", nn );
}
void mesg(const char * Ttext)
{
    printf("====================\nThe message is %s\n", Ttext);
    printf("====================\n");
}

