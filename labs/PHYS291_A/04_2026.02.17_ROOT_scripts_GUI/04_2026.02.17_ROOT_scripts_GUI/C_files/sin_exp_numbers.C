void sin_exp_numbers()
{
   const int n = 20;  int i;    //   Const and integer
   double x[n], y[n];           //   x and y(x) storage

   for (i=0;i<n;i++) {       // i= 0,1,... 19, since n=20
     x[i] = i*0.2;        
     y[i] = 10.0*sin(3.0*x[i]+0.2)*exp(-0.5*x[i]);
     printf("     %10.6f     %10.6f \n",x[i],y[i]);   }
}
