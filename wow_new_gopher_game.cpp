/*
 * Seth Cram
 * sec #02
 * 11/05/19
 * Prog Assign #10:
 *   ghost dodging w/ 2D arrays
 * All of the objectives should be completed.
 * extra work (EW): Added user sets how many mines, rows, and columns within the maximum of a 10x10 array
 */
#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;
// prototypes
void fill(int a[][10],int,int,int); // fills w/ 0 and 1s but not random
void fill(char a[][10],int,int);
void shuffle(int a[][10],int,int); // randomly shuffles 0 and 1s so now random array(EW)

int main(){
  int row = 10;
  int column = 10;
  int player_moves;
  int num_of_mines;
  int arr[10][10]; // stores where the mines are
  int arrnew[10][10]; // stores number of neighboring mines
  char display[10][10]; // display values shown to the user
  int row_choice = -1;
  int col_choice = 0;
  int *chosen_sq = &arrnew[0][0];
  int *current_sq = &arr[0][0];

  srand(time(NULL));
  cout << "Welcome to dodge the ghost!\n";
  cout << "You win when you've dug up every grave that doesn't contain a ghost.\n";
  cout << "Good luck!\n";
  cout << "You'll need it...\n";
  cout << "(Press enter to continue)\n";
  cin.ignore();
  do{
    cout << "How many graves wide should the graveyard be?(2-10)" << endl; // (EW)
    cin >> row;
    cout << "How many graves long should the graveyard be?(2-10)" << endl; // (EW)
    cin >> column;
    if(row > 10 || row <= 1 || column > 10 || column <= 1)
      cout << "Impossible graveyard try again\n";
  }while(row > 10 || row <= 1 || column > 10 || column <= 1); // (EW)
  do{    
    cout << "How many ghosts do you want in the graveyard?" << endl; // (EW)
    cin >> num_of_mines;
    if(num_of_mines >= (column * row)-1){ 
      cout << "You can only find ghosts in graves. Everyone knows they don't ACTUALLY haunt people.\n";
      cout << "So try again, but this time give yourself a fighting chance and atleast leave 2 or more graves unoccupied.\n";
    }
    if(num_of_mines <= 0)
      cout << "You can't have negative or zero ghosts dude/dudette.\n";
  }while(num_of_mines >= (column * row)-1 || num_of_mines <= 0); // (EW)
  fill(arr,row,column,num_of_mines); //arr of 1s and 0s
  shuffle(arr,row,column); // random shuffle of values(EW)
  cout << num_of_mines << endl;
  fill(display,row,column);
  
 do{
  for(int i = 0; i < row; i++){
    for(int j = 0; j < column; j++){

      int lower_i = i - 1;
      if(lower_i < 0)
	lower_i = 0;

      int upper_i = i + 1;
      if(upper_i > row - 1)
	upper_i = row - 1;

      int lower_j = j - 1;
      if(lower_j < 0)
	lower_j = 0;

      int upper_j = j + 1;
      if(upper_j > column - 1)
	upper_j = column - 1;

      int count = 0;
      for(int k = lower_i; k <= upper_i; k++){ // goes down a row
	for(int m = lower_j; m <= upper_j; m++){ // adds up 3 tiles left to right
	  if( !(k == i && m == j)) // doesn't count middle tile
	    count = count + arr[k][m];
	}
      }
      //      cout << i << ", " << j << ": " << count << endl;
      arrnew[i][j] = count; // stores number of neighboring mines in this array
    }
  }
  system("clear");
  for(int i = 0; i < row; i++){
    for(int j = 0; j < column; j++){
      current_sq = &arr[i][j];
      if(chosen_sq != current_sq)
	cout << display[i][j] << " "; 
      else{
	display[i][j] = arrnew[i][j] + '0'; // stores int of # of mines in a square to the char array
	/*            if(arrnew[i][j] == 0){
		      display[i-1][j-1] = arrnew[i-1][j-1];
		      display[i][j-1] = arrnew[i-1][j-1];
		      display[i+1][j-1] = arrnew[i-1][j-1];
		      display[i-1][j] = arrnew[i-1][j-1];
		      display[i][j] = arrnew[i-1][j-1];
		      display[i+1][j] = arrnew[i-1][j-1];
		      display[i-1][j+1] = arrnew[i-1][j-1];
		      display[i][j+1] = arrnew[i-1][j-1];
		      display[i+1][j+1] = arrnew[i-1][j-1];
		      }
	*/
	cout << display[i][j] << " ";
      }
    }
    cout << endl;
  }
  cout << endl;
  if((arr[row_choice][col_choice] == 1) && (row_choice != -1)){
    cout << "A ghost frightens you to death and then dies of embarrassment...\n";
    cout << "Better luck next time\n";
    return 0;
  }
  do{
    cout << "X:(0-" << column - 1 << ")\n";
    cin >> col_choice;
    cout << "Y:(0-" << row - 1 << ")\n";
    cin >> row_choice;
    if(row_choice < 0 || row_choice > row - 1 || col_choice < 0 || col_choice > column - 1)
      cout << "Enter a valid value or don't play the game.\n";
  }while(row_choice < 0 || row_choice > row - 1 || col_choice < 0 || col_choice > column - 1);
  chosen_sq = &arr[row_choice][col_choice]; 
  player_moves++;
 }while(player_moves < (row * column) - num_of_mines);
 cout << "Congratulations! You escaped the graveyard without incident." << endl;
}


void fill(int og_array[][10],int x,int y,int num_of_mines){
  int counter = 0;
  for(int i = 0; i < x; i++){
    for(int j = 0; j < y; j++){
      if(counter < num_of_mines)
	og_array[i][j] = 1;
      else
	og_array[i][j] = 0;
      counter = counter + og_array[i][j];
      //      cout << og_array[i][j] << " ";
    }
    cout << endl;
  }
  cout << endl;
  return;
}

void shuffle(int og_array[][10],int row,int col){
  for(int i = 0; i < row; i++){
    int r = i + (rand() % (row-i)); // ramaining rando row 0 to 9, subtract i so rando value within bounds 
    for(int j = 0; j < col; j++){
      int c = j + (rand() % (col-j)); // add j to get dif rando each loop
      int temp = og_array[i][j];
      og_array[i][j] = og_array[r][c];
      og_array[r][c] = temp;
      //      cout << og_array[i][j] << " "; //displays the random values array, but just to help me win a game
    }
    cout << endl;
  }
  cout << endl;
}

void fill(char symbols[][10],int row,int col){
  for(int i = 0; i < row; i++){
    for(int j = 0; j < col; j++){
      symbols[i][j] = '+';   
    }
  }
}
  
