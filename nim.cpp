  /*
 * Seth Cram
 * Sec #02
 * 9/18/2019
 * Assignment #3
 * The game of NIM
 * Extra Credit (EC): N/A
 * Extra Work (EW): added an if block that specifies a situation where both players win
 * Note: commented out chapter 3, exercise 6 as I implimented a more complex way to make the computer lose less often with user inputed values
 */
 #include<iostream>     // include two libraries
 #include<cstdlib>
 using namespace std;
 int main()             // main() starts the actual program 
 {
    // ---------------- Variable declarations ---------------------
    int num_objects = 0; 
    int current_player = 1; 
    int move;
    int take_away_min;
    int take_away_max;
    char cont; // continue playing?
    // ----------- Beginning of the main game loop ----------------
     cout << "Welcome to Seth's adaption of the game of nim! It's a player vs computer based game that tests your prediction skills." << endl;
     cout << "It's turn based and gives both you and the computer a chance to take a number of objects from the total. Good luck!" << endl;
     // beginner messages ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
do{
   do {
     if(num_objects == 0 ){ // grabs user input
    	cout << "How many objects would you like to play with as your total? (Enter whole numbers only) " << endl;
     	cin >> num_objects;
     	cout << "What's the minimum number of objects someone can take in a single turn? (1 is recommended)" << endl;
     	cin >> take_away_min;
     	cout << "What's the maximum number of objects someone can take in a single turn?" << endl;
     	cin >> take_away_max;
	if(take_away_min > take_away_max){
		cout << "The minimum can't be bigger than the maximum" << endl;
		return 0;
	}
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
/*		if(num_objects == 2){ 
*			move = num_objects - 1;
*               	} else {
*			if(num_objects == 3){
*				move = num_objects -2;
*			} else {
*				if(num_objects == 4){
*					move = num_objects -1;
*				} else {
*             			 move =  1+ rand() % take_away_max;    // random computer move
*				}
*			}
		} */
             } while (move < take_away_min || move > take_away_max || move > num_objects);
            cout << "Computer removed " << move << endl;
       }
       num_objects = num_objects - move;  // implement the move
       cout << "This many objects remain: " << endl;
       for(int i = 1; i <= num_objects; i++){	    // number of objects remaining loop
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
   cout << "Player " << current_player << " wins!!! They deserve a cookie.\n";
   if(current_player == 1){                                                      // losing and winning messages
     cout << "Player 0 loses!!! Give Player 1 a cookie this instant." << endl; 
   } else {
     cout << "Player 1 loses!!! Give Player 0 a cookie this instant." << endl; 
   }
   cout << "Would you like to continue playing Seth's adaption of nim? (y for yes)" << endl;
   cin >> cont;
}
while(cont == 'y');
cout << "Bye bye ^.^" << endl;
return 0;
   }
