
class student {   public:   string Name; string Course; int Points=0;

       //  constructors
            student();
            student( string nam, string cour, int p );

       // methods
            void show();
            void defs(string nam , string cour , int p);
            };

void studgr(){
   student group[4];

   group[0].defs("John Smith", "PHYS291", 55);
   group[1].defs( "Eva Taylor" , "INF100", 44);
   group[2].defs( "Petra Bush" , "INF100", 30);

   group[0].show();
   group[1].show();
   group[2].show();

   student Guest( "Peter Hansson" , "INF100", 44);
   student Coming;
   Coming.defs( "Gina Cassini" , "INF100", 44);

    Guest.show();
    Coming.show();
    group[3] =  Coming;

    group[3].show();

}

void student::show(){  
  cout << Name << " " << Course << " " << Points << endl;
}
void student::defs( string nam, string cour, int p ){   
    Name=nam; Course=cour; Points=p;
}
student::student( ){   
    Name="nobody"; Course="none"; Points=-100;
}
student::student( string nam, string cour, int p ){   
    Name=nam; Course=cour; Points=p;
}


