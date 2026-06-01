{
int global=7;
void v(int y);

  int x=8;
  v(x);

}
void v(int y)
{
cout << "v(int y): parameter y: "<< y << endl;
cout << "global variable called global: "<<global<<endl;
}

