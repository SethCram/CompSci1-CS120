/*
* Seth Cram
* sec #02
* 9/3/19
* Prog Assignment #1
 * The fortune Teller -
    * a simple program introducing some
    * fundimental programming concepts.
    * All of the objectives should be completed.
    * extra credit (EC): added the enter your age question and self variable, also added self variable into luck calculation
    */
#include<iostream> // include a library
using namespace std;
int main()  // main() starts the program
{
	// -------------- Variable Declarations ------------------
 	int favorite;  // create a variable to store the favorite number
        int disliked;  // create a variable to store the disliked number
	int lucky;     // create a variable to store the lucky number
	int idealbff;  // new var to store ideal age of best friend
	int self;      // new var to store own age (EC)
	// ------------- Get user input -------------------------
	cout << "Enter your favorite number (no decimals): ";  // output
    	cin >> favorite;
	cout << "Enter your ideal best friend's age (no decimals): "; //output
	cin >> idealbff;  		// user input
	cout << "Enter your own age (no decimals): "; //output (extra credit)
	cin >> self;
	cout << "Enter a number you don't like (no decimals): "; //output
	cin >> disliked;
	lucky = (favorite*disliked*idealbff*self) % 10; // (self=EC)
	cout << endl << "Your secret, lucky number is: " << lucky << endl;
	if(lucky < 0){  // conditional, calues less than 0
		cout << "Try to be less negative." << endl;
	}
	if(lucky >= 0 && lucky < 3){ // 0 to 2 inclusive
		cout << "Think bigger!" << endl;
	}
	if(lucky >= 4 && lucky < 9){ // 4 to 8 inclusive
		cout << "Today you should embrace technology." << endl;
	}
	if(lucky == 9){ // exactly 9
		cout << "Today is your lucky day!" << endl;
	}
        if(lucky == 3){ // exactly 3
	cout << "You shall have a bountiful harvest!" << endl;
	}
	// ---------- Code to help the program exit "gracefully" -----
	cin.ignore();
 	cout << "Press enter to quit." << endl;
	cin.ignore();
	return 0;
}
