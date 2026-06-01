{
class stud { public: char NAM[100]; char COURSE[100]; int POINTS=0;};
//
  stud group[4];
  cout << "sizeof(group[0]) " << sizeof(group[0]) << endl;
  strcpy(group[0].NAM,"John Smith");
  strcpy(group[0].COURSE,"PHYS291");
  group[0].POINTS=55;
  strcpy(group[1].NAM,"Eve Taylor");
  strcpy(group[1].COURSE,"I100");
  group[1].POINTS=85;
  cout << group[0].NAM << "  " <<  group[0].COURSE << endl;
  cout << group[1].NAM << "  " <<  group[1].COURSE << endl;
}
