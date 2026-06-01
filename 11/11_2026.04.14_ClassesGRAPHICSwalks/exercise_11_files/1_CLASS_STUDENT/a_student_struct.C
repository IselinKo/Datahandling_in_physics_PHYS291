struct student { 
            string name;
            string course;
            char mark;
};    
//   The above defines the structure; We can construct some help functions
//   Only the above is strictly needed;

    void SetName(student *S, string N){
                   if(N.length() > 4) S->name=N; else  cout<<"wrong name\n";};
    void SetCourse(student *S, string C){
                   S->course=C;        };
    string GetName(student S){  
                       return S.name;        };
/*   Examples:  
student A1;
A1.name="Donald Duck";   // easy; But e.g. you can not implement checks
A1.name="AB";            // Invalid name - we think
student BB;
SetName(&BB,"A B")       //  returns wrong name
*/
