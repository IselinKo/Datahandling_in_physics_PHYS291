class Student {
     private: 
            string name;
            string course;
            char mark;
     public:     
             Student(){  name="---";   };  // create Just empty
             Student(string N)           {   name=N;  };  // create w. name
             Student(string N, string C ){ name=N; course=C; };
             Student(string N, string C, char M){ 
              if (N.length() > 4)name=N; else  cout<<"wrong name\n";
              course=C; mark=M;};
             void SetName(string N){
                   if(N.length() > 4) name=N; else  cout<<"wrong name\n"; };
             void SetCourse(string C){
                   course=C;        };
             string GetName(){  
                       return name;        };
      };
/*        Examples:
Student AA;
AA.SetName("Ann Aas");
Student BB("Jan jansen","PHYS291",'C');
cout << BB.GetName() << endl;

Missing functions:   SetMark(char m)   string GetCourse()  char GetMark()

*/
