int global=7;
void v(int y);

void declare_funcs_gen()
{
   global=7;

  int x=8;
  v(x);

}
void v(int y)
{
cout << "v(int y): parameter y: "<< y << endl;
cout << "global variable called global: "<<global<<endl;
}

