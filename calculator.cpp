/*
* Seth Cram
* sec #02
* 9/12/19
* Prog Assignment #2
 * The Calculator -
    * All of the objectives should be completed.
    * extra credit (EC): Added a check for division by zero through an embedded if statement
    * extra work (EW): Made sure the user chose one of the 4 operations through an overarching if-else statement 
    * extra work pt.2 (EW): made the operation variable a short to save memory
    */
#include<iostream> // include a library
using namespace std;
int main()  // main() starts the program
{
        // -------------- Variable Declarations ------------------
	double x,y; // the variables for the 2 numbers chosen by user
	double ans; // variable to store the answer to the operation
	short int op; // variable to store user's choice of operation (EW)
	 // ------------- Get user input -------------------------
        cout << "Enter your first number: ";  // output
        cin >> x;
        cout << "Enter your second number: ";  // output
        cin >> y;
        cout << "What operation would you like to perform?" << endl; 
        cout << "Type 1 to multiply, 2 to divide, 3 to add and 4 to subtract: "; // output
	cin >> op;
	// -------------- Perform Operations ----------------------
	if((op>0) && (op<5)){ // (EW)

		if(op==1){ // multiply
		ans = x*y;
		}
                if(op==2){ // divide
			if(y==0){
			cout << "Warning: You can't divide by zero in this program bruv" << endl;
			return 0;
			}
		ans = x/y;
                }
                if(op==3){ // add
		ans = x+y;
                }
                if(op==4){ // subtract
		ans = x-y;
                }
	cout << "Your answer is: " << ans << endl;
	}
	else {
		cout << "Please, select one of the 4 operations or leave." << endl; // (EW)
		return 0;
	}
}
	

