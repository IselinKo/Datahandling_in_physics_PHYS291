//
//    Example from a book:   Learn C++ in 21  !!!!!!    Modified by us
//
//    compile       g++ -o  virt  mammal_virt.cpp 
//
//    run in root        root  mammal_virt.cpp 
//    or:         in root    .L mammal_virt.cpp
//                           mammal_virt();
//

#include <iostream>
using namespace std;

    class Mammal
    {
    public:
       Mammal():itsAge(1) { cout << "Mammal constructor...\n"; }
       ~Mammal() { cout << "Mammal destructor...\n"; }
       Mammal (const Mammal & rhs);
       virtual void Speak() const { cout << "------\n"; }
       virtual Mammal* Clone() { return new Mammal(*this); }
       int GetAge()const { return itsAge; }
    protected:
       int itsAge;
    
    friend void SetAge( Mammal & Org, int age){
         Org.itsAge=age;
         }
    };

    Mammal::Mammal (const Mammal & rhs):itsAge(rhs.GetAge())
    {
       cout << "Mammal Copy Constructor...\n";
    }

    class Dog : public Mammal
    {
    public:
       Dog() { cout << "Dog constructor...\n"; }
       ~Dog() { cout << "Dog destructor...\n"; }
       Dog (const Dog & rhs);
       void Speak()const { cout << "Woof!\n"; }
       virtual Mammal* Clone() { return new Dog(*this); }
    };

    Dog::Dog(const Dog & rhs):
    Mammal(rhs)
    {
       cout << "Dog copy constructor...\n";
    }

    class Cat : public Mammal
    {
    public:
       Cat() { cout << "Cat constructor...\n"; }
       ~Cat() { cout << "Cat destructor...\n"; }
       Cat (const Cat &);
       void Speak()const { cout << "Meow!\n"; }
       virtual Mammal* Clone() { return new Cat(*this); }
    };

    Cat::Cat(const Cat & rhs):
    Mammal(rhs)
    {
       cout << "Cat copy constructor...\n";
    }

    enum ANIMALS { MAMMAL, DOG, CAT};
    const int NumAnimalTypes = 3;



                     #if defined(__CLING__)
int mammal_virt()  
		             #else
int main ()
                     #endif


{  //  Testing the "protected itsAge"
   //   Spot is "born" as a regular dog
     Mammal *Spot=new Dog();
     cout << "Spot's age: " << Spot->GetAge() << endl;
     SetAge( *Spot , 7);
//  Clone Spot  - to Fido ; Fido is a regular dog
     Dog*  Fido= (Dog*)Spot->Clone();
     cout << "Fido's age: " << Fido->GetAge() << endl;

     Mammal Hero = *Spot;   
     cout << "Hero's age: " << Hero.GetAge() << endl;
     SetAge( *Fido , 9);
     SetAge( Hero , 5);
     cout << "Hero's age: " << Hero.GetAge() << endl;  

     cout << "Spot sounds: "; Spot->Speak(); 
     cout << "Fido sounds: "; Fido->Speak();
     cout << "Hero sounds: "; Hero.Speak();

     
     Cat Tara;  
     cout << "Tara sounds: "; Tara.Speak();

     return 0;
}

