/*
 * Seth Cram
 * Sec #02
 * 10/01/2019
 * Assignment #5:
 *   adventure game 2.0 
 */
#include<iostream>
#include<cstdlib>  // include a 2nd library used in nim
using namespace std;

// prototypes
int door();
int kitchen();
int closet();
int down_hall();
int bedroom();
int living_room();
int menu(int,int); // new menu function for valid choice
int nim(); // new function that ports nim over from previous assignment
int p_stats(); // displays player loud stat and items collected

// global variables
int loud = 0;     // how loud the user is being
int choice = 0;
int f_light = 0;   // flashlight variable
int batt = 0;      // battery variable 
int b_charger = 0; // battery charger variable

int main()
{
  int current_room = 1; // starts in front of the door
  cout << "\nYou feel the lock finally give under your pick." << endl;
  cout << "Haunted house here you come!" << endl;  
  do
  {
	switch(current_room)
	{
		p_stats();
		case 1:
                        current_room = door();
                        break;
                case 2:
                        current_room = kitchen();
                        break;
                case 3:
                        current_room = closet();
                        break;
                case 4:
                        current_room = down_hall();
                        break;
                case 5:
                        current_room = bedroom();
                        break;
                case 6:
                        current_room = living_room();
                        break;

                default:
			cout << "You can't go there" << endl;
			break;
	}
  } while(current_room != 0);
}

// function definitions
int door()
{
  cout << "You're in front of the door, the entire house only illuminated by the light of the moon" << endl;
  do
  { 
	p_stats();
  	cout << "You see a kitchen(1) to your east, a closet(2) to your west, and a set of stairs(3) before you, with a hallway(4) going past them." << endl;
	cout << "Outside(5) is just a couple steps away\n";   
	cout << "Which way do you go?" << endl;
  	cin >> choice;
	choice = menu(1,5);
  	if(choice == 1)
        {
                return 2; // go kitchen
        }
        if(choice == 2)
        {
                return 3; // go closet
        }
	if(choice == 3)
	{
		cout << "You approach the stairs and get a strangely eerie feeling as the hairs on the back of your neck stand straight up." << endl;
		cout << "You decide to save the stairs for later." << endl;
	}
        if(choice == 4)
        {
                return 4; // go down the hallway
        }
        if(choice == 5)
        {
                cout << "You try the handle, but the door won't budge\n";
		cout << "You get frustrated and slam your fist against the door\n";
		loud += 1;
        }

  }while(choice < 6 && choice > 0);
}
int kitchen()
{
	static int doll = 1;
	cout << "You enter the room, look around, and see an array of knives as you enter the old, victorianesque kitchen" << endl;
        cout << "You also see dead flowers on the window sill" << endl;
  do{
	p_stats();
	cout << "What will you do?\n";
	cout << "Take a knife(1)" << endl;
        cout << "Pick a dead flower(2)" << endl;	
	cout << "Go to the front door(3)\n";
	cout << "Head to the bedroom(4)\n";
	cout << "Peer out the window(5)\n";
	cin >> choice;
	choice = menu(1,5);
           switch(choice){
		case 1:
                	cout << "Why would you need a knife right now?" << endl;
			break;
        	case 2:
			if(doll == 1){
				cout << "On your walk over you slip on a black doll and slam on your bum\n";
				cout << "ouch.....\n";
				cout << "You decide the flower isn't worth the pain for now.\n";
				doll = 0;
				loud += 1;
			}else{
				cout << "You make it too the flowers without stepping on another god forsaken toy\n";
				cout << "It smells like........dried blood...\n";
			}
			break;
		case 3:
			return 1; //  go back to the door
			break;
		case 4:
			return 5;
			break;
		case 5:
	                cout << "You stare out the window towards the stone path you previously walked down...wait, where'd the path go?" << endl;
			break;
	  }
  cout << "You decide to keep looking around.\n";
  }while(choice > 0 && choice < 6);
}
int closet()
{
        static int vase = 1;
        cout << "The moonlight doesn't reach in here\n";
        cout << "Everything is pitch black\n";
  do{
	p_stats();
        cout << "Search the room anyways(1)" << endl;
	cout << "Go back to the front door(2)" << endl;
	cout << "Look better(3)" << endl;
        cin >> choice;
	choice = menu(1,3);
	switch(choice){
		case 1:
        		if(vase == 0)
        		{
                		cout << "You find a light switch, but it doesn't work\n";
        		}
        		if(vase == 1)
        		{
                		cout << "You run your hands along the wall looking for a light switch and accidently knock a vase over\n";
				loud += 1;
				vase = 0;
        		}
			break;
		case 2:
	                return 1; // go door
               		break;
		case 3:
                        if(batt == 1)
                        {
                                cout << "You squint your eyes, but see nothing\n";
                        }
                        if(batt == 0)
                        {
                              cout << "You squint your eyes and are just able to make out the glimmer of aluminum\n";
                              cout << "You reach out and find a double A batttery!\n";
                              batt = 1;
                        }
			break;
	}
  }while(choice > 0 && choice < 4);
}
int down_hall()
{
        
        cout << "It feels almost as if your being watched.\n";
	do
        {
		p_stats();
        	cout << "Enter the bedroom(1), living room(2), or go to the front door(3)?\n";
        	cin >> choice;
		choice = menu(1,3);  
        	if(choice == 1)
        	{
        	        return 5; // go bedroom
        	}
        	if(choice == 2)
        	{
                	return 6; // go living room
        	}
                if(choice == 3)
                {
                        return 1; // go door
                }
        }while(choice != 1); 
}
int bedroom()
{
        cout << "A big king sized bed with black curtains greats your eyes as you enter\n";
	do{
		p_stats();
		cout << "What will you do?\n";
		cout << "Investigate the nightstand(1)\n";
		cout << "Look in the dresser(2)\n";
		cout << "Take a peak out the window(3)\n";
		cout << "Climb in bed(4)\n";
		cout << "Go to the hallway(5)\n";
		cout << "Enter the kitchen(6)\n";
        	cin >> choice;
		choice = menu(1,6);
		switch(choice)
		{
			case 1:
				if(f_light == 0){
					cout << "You find a flashlight!\n";
					f_light = 1;
				}else{
					cout << "You drag your hand around in the drawer, but find nothing.\n";
				}
				break;
			case 2:
				cout << "You see multiple sets of all black clothing\n";
				cout << "They look brand new, but nobody's lived in this house for as long as you've been alive...\n";
				break;
			case 3: 
				cout << "You peer out the window to find the tall silhouette of a man in the distance\n";
				cout << "You can't make out any of his features, but you feel like he's looking right at you\n";
				break;
			case 4: 
				cout << "Who knows the last time that bed was cleaned?\n";
				break;
			case 5: 
				return 4;
				break;
			case 6: 
				return 2;
				break;
		}   
        }while(choice > 0 && choice < 7);
}
int living_room()
{
	
        cout << "This room seems much darker than the rest, despite the windows in the room.\n";
	cout << "It's almost as if the light doesn't dare touch this part of the house...\n";
	do{
		p_stats();
		cout << "What do you do?\n";
        	cout << "Investigate the fireplace(1)\n";
		cout << "Search the couch(2)\n";
		cout << "Take a sword off the wall(3)\n";
		cout << "Go back into the hallway(4)\n";
                cin >> choice;
		choice = menu(1,4);
		switch(choice)
		{
			case 1: 
				cout << "The thing is covered in soot and nearly no light reaches here\n";
				if(f_light == 0 && batt == 0 && b_charger == 0){
					cout << "You don't dare investigate more without a proper light source\n";
				}
				if(f_light == 1 && batt == 0 && b_charger == 0){
					cout << "You flip on the flashlight but it doesn't have any batteries in it...\n";
				}
				if(f_light == 1 && batt == 1 && b_charger == 0){
					cout << "You put your battery into the flashlight but it looks like the battery is dead.\n";
				}
				if(f_light == 1 && batt == 1 && b_charger == 1){
					cout << "You charge the battery and pop it into the flashlight\n";
					cout << "\nYou flip on your flashlight and begin investigating\n";
					cout << "After some poking around you decide to move the stand the firewood goes on and see a latch!\n";
					cout << "You heave up on the latch as you hear an ungodly scream come from the top floor.\n";
					cout << "You start panicking as your heart begins thundering in your chest\n";
					cout << "You're in danger\n";
					cout << "You decide not to stick around and find out what made that noise\n";
					cout << "You jump down the open trapdoor and find tunnels beneath the house\n";
					cout << "You crawl for what seems like miles but finally end up above ground, directly in front of the old house.\n";
					cout << "You turn on your heels and decide to take up a new hobby that doesn't involve screeching monsters\n";
					cout << "\n\n\n\nYOU ESCAPED\n\n\n\n";
					return 0;				
				}
				break;
			case 2:
				if(b_charger == 0){
					cout <<"You start sifting between the cushions and find an old handheld gaming unit.\n";
					cout <<"You feel nostalgic as the sytem boots up and a game comes on the screen...\n\n\n\n\n";
					nim();
					cout <<"\n\n\n\n\nThat was fun, but probably not the best use of your time...so you keep going through the couch.\n";
					cout << "You throw the last cushion to the ground and find a battery charger!\n";
					b_charger = 1;
				} else{
					cout << "The pick up one of the cushions you threw and try and balance it on your head.\n";
					cout << "Probably not the best use of your time...\n";
				}
				break;
			case 3: 
				cout << "It's way heavier than you thought!\n";
				cout << "You do a few practice swings with the thing and it flies out of your hands making a loud crashing noise\n";
				cout << "You decide the way of the sword isn't for you.\n";
				loud += 1;
				break;
			case 4: 
				return 4; //  go back to the hallway
				break;
		}
	}while(choice > 0 && choice < 5);  
}
int menu(int min,int max){
	while(choice < min || choice > max){
                cout << "As you stand there contemplating the meaning of life, you suddenly feel off balance and slam into the wall\n"; // punishes user
                loud += 1;
		cout << "Please pick a number from (" << min << ")-(" << max << ")" << endl;
		cin >> choice;
	}
	return choice;
}
int nim()             // nim() starts the game
 {
    // ---------------- Variable declarations ---------------------
    int num_objects = 0;
    int current_player = 1;
    int move;
    int take_away_min;
    int take_away_max;
    // ----------- Beginning of the main game loop ----------------
     cout << "Welcome to Seth's adaption of the game of nim! It's a player vs computer based game that tests your prediction skills." << endl;
     cout << "It's turn based and gives both you and the computer a chance to take a number of objects from the total. Good luck!" << endl;
     // beginner messages ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
do{
   do {
     if(num_objects == 0 ){ // grabs user input
        cout << "How many objects would you like to play with as your total? (Enter whole numbers only) " << endl;
        cin >> num_objects;
	do{
        	cout << "What's the minimum number of objects someone can take in a single turn? (1 is recommended)" << endl;
        	cin >> take_away_min;
        	cout << "What's the maximum number of objects someone can take in a single turn?" << endl;
        	cin >> take_away_max;
	        if(take_away_min > take_away_max){
                	cout << "The minimum can't be bigger than the maximum" << endl;
		}
        }while(take_away_min > take_away_max);
        cout << "There are " << num_objects << " objects total, don't be the person who takes the last one..." << endl;
     }
       if (current_player == 1) {    // conditional: if
            if(num_objects < take_away_min){                     // an if loop that lets both players win (EW)
                cout << "Y'all both win, nobody took the last cookie. Congratulations player 1 and player 0!" << endl;
                return 0;
            }
            cout << "Player 1 enter your move (" << take_away_min << "-" << take_away_max << ")" << endl ;  // output
            cin >> move;                 // input
               while (move < take_away_min || move > take_away_max || move > num_objects){
               cout << "Illegal move. \nEnter a new move (" << take_away_min << "-" << take_away_max << "): ";
               cin >> move;
                }
       } else {                          // else part of conditional
            do {                         // make sure move is legal
                if(num_objects < take_away_min){                // a method for both players to win (EW)
                         cout << "Y'all both win! Nobody took the last object. Congratulations player 1 and player 0!" << endl;
                         return 0;
                }

                if( (num_objects <= take_away_max) && (num_objects >= take_away_min) && (num_objects - 1 > 0) ){      // doesn't lose if it doesn't have to
                                move = num_objects - 1;
                } else {
                        if(num_objects <= (take_away_max * 2) && num_objects >= (take_away_min * 2) &&  ( (num_objects - take_away_max) - 2 > 0)  ){
                            move = (num_objects - take_away_max) - 2;
                        } else {
                                move = 1 + rand() % take_away_max;
                        }
                }
             } while (move < take_away_min || move > take_away_max || move > num_objects);
            cout << "Computer removed " << move << endl;
       }
       num_objects = num_objects - move;  // implement the move
       cout << "This many objects remain: " << endl;
       for(int i = 1; i <= num_objects; i++){       // number of objects remaining loop
                cout << "*";
                if( (i % 10) == 0){
                        cout << "\n";
                }
       }
       cout << "\n";
       current_player = (current_player + 1) % 2;  // switch players
       if ((num_objects > 20) && (num_objects < 30)){               // game commentary
            cout << "With so many objects left, it's anyone's game!" << endl;
       }
       if ((num_objects > 1) && (num_objects < 10)){                // game commentary
            cout << "With so few objects left, our victor shall emerge soon!" << endl;
       }
   } while (num_objects > 0);
   // ------------  end of the game loop --------------------------
   if(current_player == 1){                                                      // losing and winning messages
     cout << "Computer loses." << endl;
     cout << "Congratulations Player 1!\n";
     return 0;
   } else {
     cout << "Player 1 loses." << endl;
     cout << "Congratulations Computer!\n";
   }
   
}
while(1 == 1);
}
int p_stats(){  // displays player loud stat and items collected
        cout << "You're loudness meter is at: " << loud << endl;
        if(batt == 1){
                cout << "You have a battery.\n";
        }
        if(b_charger == 1){
                cout << "You have a battery charger.\n";
        }
        if(f_light == 1){
                cout << "You have a flashlight.\n";
        }
        if (loud >= 3)
        {
                cout << "............\n";
                cout << "............\n";
                cout << "You hear something slam into the walls above you.\n";
                cout << "It sounds enormous and you can already hear it panting in a frenzy\n";
                cout << "It sounds like it's headed for the stairs and you don't want to find out what it is so you try and break a window.\n";
                cout << "You feel a sharp pain in your legs as you slam to the ground and are dragged upstairs by your ankle...............\n";
                cout << "\n\n\nYOU DIED\n\n\n";
                return 0;
        }
}
