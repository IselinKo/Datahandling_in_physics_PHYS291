{
struct btripple {
              int a; 
              int b; 
              char str[100];} ; 
btripple s;
s.a=8; s.b=4; 
strcpy(s.str,"Long String Entry");

btripple t22;
sprintf(t22.str,"Number %d",34);
t22.a=64; t22.b=16;

//  Access the elements of the structure with .

cout << "s.b " << s.b << endl;

btripple * sss = new btripple;
sss->a=11; sss->b=11;
sprintf( sss->str, "%s -> %s", "alpha", "beta");

//    what about arrays?
//    Task: try out   btripple Arr[10]
//          and       btripple *BArr[10] (must use new or e.g. &Arr)
}
