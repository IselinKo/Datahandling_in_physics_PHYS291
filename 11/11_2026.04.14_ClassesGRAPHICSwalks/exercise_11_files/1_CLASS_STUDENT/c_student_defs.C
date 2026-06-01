class Student {              //  The methods are declared in the class
     private:                //  But defined outside 
            string name;
            string course;
            char mark;
     public:
             Student();
             Student(string Name);
             Student(string Name, string course);
             void SetName(string Name);
             void SetCourse(string Name);
             void SetMark(char M);
             string GetName();
             string GetCourse();
             char GetMark();
             };                  // class definition finished
Student::Student(){    
    name="---";       }
Student::Student(string Name){
    name=Name;        }
void Student::SetName(string inputname){
    name=inputname;        }
void Student::SetCourse(string inputname){
    course=inputname;        }
string Student::GetName(){  
     return name;        }
//   The same examples as in the other files
