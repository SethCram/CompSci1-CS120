/*
 * Seth Cram
 * sec #02
 * 10/12/19
 * Prog Assignment #6
 *   Modified Pet Class -
 * All of the objectives should be completed.
 * extra credit (EW): Added a conditional for if the new private variable(loyalty) reaches too low
 */

#include<iostream>
#include<string>
#include<cstdlib> // included new library for random number generator
using namespace std;
// declaration of the pet class
class pet{
   private:
      int hunger;           // private data member
      string name;          // private data member
      int happy;            // private data member
      int loyalty;          // private data member (new)
   public:
      pet();                // constructor
      void play();          // public member function
      void feed();          // public member function
      void print();         // public member function
      void talk();          // public member function (new)
      int check_health();   // public member function
};
int main()
{
   pet pet1;
   int choice;
   int health_check;
   do{
       pet1.print();
       cout << "What would you like to do with your pet?\n";
       cout << "Leave Pet (0) \nPlay (1) \nFeed (2)\nTalk (3)\n";
       cin >> choice;
       switch(choice){
       case 0:
	 cout << "Youre pet looks sad, but you leave anyways.\n";
	 break;
       case 1:
           pet1.play();
           break;
       case 2:
           pet1.feed();
           break;
       case 3:
	   pet1.talk();
	   break;
      }
      health_check = pet1.check_health();
   }while(choice != 0 && health_check != 1);
   cin.ignore();
   cout << "Press enter to exit." << endl;
   cin.ignore();
   return 0;
}

/* Constructor, creates a new pet with starting values. */
pet::pet(){
     hunger = 50;
     happy = 50;
     loyalty = 50;
     cout << "Pet's name? (One word)\n";
     cin >> name;
}
/* Member function play(), allows playing with a pet. */
void pet::play(){
    int choice = 0;
    
    cout << "What should we play?\n";
    cout << "Fetch (1) \nRoll over (2) \n";
    cin >> choice;
    switch(choice){
    case(1):
         happy -= 7;
         hunger += 5;
	 loyalty += 2;
         break;
    case(2):
         happy += 4;
         hunger += 1;
	 loyalty -= 5;
         break;
    default:
         cout << "Not a valid choice." << endl;
   }
}

/* Member function feed(), allows the user to feed a pet. */
void pet::feed(){
    int rando;
    rando = rand() % 100; // random number
    if(rando < 10){ // random messages
      cout << "You spill the food on the floor, but your pet doesn't seem to care\n";
    }
    if((rando <= 40) && (rando >= 10)){
      cout << "You balance the food bowl on your head. Your pet just looks at you expectantly\n";
    }
    if((rando > 40) && (rando <= 70)){
      cout << "Your pet starts jumping around in excitement\n";
    }
    if((rando > 70) && (rando < 100)){
      cout << "You throw some of the food to your pet, and it catches the food with ease\n";
    }
    cout << "MMM, Yummy!\n";
    hunger -= 5;
    loyalty += 5;
}
/* Member function talk(), allows user to talk to a pet. */
void pet::talk(){
  cout << "\nYou sit your pet down and have a deep talk.\n";
  hunger += 5;
  loyalty += 10;
  happy += 10;
}

/* Member function print(), prints information about a pet. */
void pet::print(){
    cout << "\nYour pet " << name << " is " << endl;
    cout << "Happy: " << happy << endl;
    if(happy < 30){ // informative messsages
      cout << "Your pet seems depressed\n";
    }
    if(happy > 70){
      cout << "Your pet's eyes light up when it sees you, and it starts getting excited\n";
    }

    cout << "Hungry: " << hunger << endl;
    if(hunger > 70){
      cout << "Your pet looks really hungry\n";
    }
    if(hunger < 30){
      cout << "Your pet appears well-fed!\n";
    }

    cout << "Loyalty: " << loyalty << endl;
    if(loyalty < 30){
      cout << "Your pet keeps its distance, and doesn't always come when called\n";
    }
    if(loyalty > 70){
      cout << "Your pet stays close to you, and looks as if it wouldn't leave your side for the world\n";
    }

}

/* Member function check_health(), checks the health of a pet. */
int pet::check_health(){
    if(hunger >= 100){
         cout << "\nYour pet has starved.\n";
         return 1;
    }
    if(happy <= 0){
         cout << "\nYour pet has died of a broken heart.\n";
         return 1;
    }
    if(loyalty <= 0){ // (EW) 
         cout << "\nYour pet ran away.\n";
	 return 1;
    }
    return 0;
}
