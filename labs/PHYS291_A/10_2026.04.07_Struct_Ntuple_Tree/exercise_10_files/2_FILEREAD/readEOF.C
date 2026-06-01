{
  //  fgets enters a whole line
  //  that can be treated by read from string 
  //  fgets  ->  sscanf
  
   // automatic stop on end of file
   // using both fscanf()
   // and fgets()  - get a whole line
   
   FILE *fil_in;
   fil_in=fopen("datain.txt","r");
   double x,y;
   int n=0;
   while (fscanf(fil_in," %lf %lf", &x, &y) !=EOF ){
       n=n+1;
       printf(" %lf   %lf \n", x,y);
   }
   printf(" %d lines from datain.txt\n", n);
   fclose(fil_in);
   
   char LINE[256];
   n=0;
   fil_in=fopen("datain.txt","r");
   
   while ( fgets( LINE, 255, fil_in) ){
      // note: without this if it does
      // not stop on empty last line
      if(strlen(LINE)>1) {  
         sscanf(LINE, " %lf %lf", &x, &y);
         n=n+1;
         printf(" %lf   %lf \n", x,y);
       }
   }
   printf(" %d lines from datain.txt\n", n);
   fclose(fil_in);
}

