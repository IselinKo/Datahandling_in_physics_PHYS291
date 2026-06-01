class Student {
     private: 
            string name;                   //  same as struct
            string course;
            char mark;
     public:
             Student();                    //  creates Student
             Student(string Name);         //  creates Student with given name
             Student(string Name, string course);
             void SetName(string Name);
             void SetCourse(string Name);
             void SetMark(char M);
             string GetName();
             string GetCourse();
             char GetMark();
             };                            // Class Student declared, not methods
             //   Here follow the methods
Student::Student(){         //  example   Student S1;
    name="---";       }
Student::Student(string Name){  //  example   Student S2("Jan Jansen");
    name=Name;        }
void Student::SetName(string inputname){  //  example  S1.SetName("Anne Aas");
    name=inputname;        }
void Student::SetCourse(string inputname){
    course=inputname;        }
string Student::GetName(){         // example   cout << S2.GetName << endl;
     return name;        }

