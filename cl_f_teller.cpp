/*
 * Seth Cram
 * sec #02
 * 12/09/19
 * Prog Assign #13:
 *   command line C programming fortune teller
 * All of the objectives should be completed.
 * extra work (EW): included the time() command to calc fortune
 */
#include<cstdlib> // for atoi(): ascii to integer
#include<cstdio>  // for printf()
#include<string.h>   // for strcmp()
#include<time.h>  // for time() and rand() (EW)

int main(int argc, char *argv[])  // main for fortune teller
{
  // -------------- Variable Declarations ------------------
  int favorite;  // create a variable to store the favorite number
  int disliked;  // create a variable to store the disliked number
  int lucky;     // create a variable to store the lucky number
  int idealbff;  // new var to store ideal age of best friend
  int self;      // new var to store own age (EC)
  // ------------- Get user input -------------------------
  srand(time(NULL)); // (EW)
  if(argc != 5){  // check if there are the right number of inputs
    printf("Error calculations should be of the form string, number, number,\
 number, number\n");
    return 0;
  }
  // ascii to ints
  favorite = atoi(argv[1]);
  disliked = atoi(argv[2]);
  idealbff = atoi(argv[3]);
  self = atoi(argv[4]);
  lucky = (favorite*disliked*idealbff*self*rand()) % 10; // (self=EC) (EW)

  printf("Your secret, lucky number is %i \n", lucky);
  if(lucky < 0){  // conditional, calues less than 0
    printf("Try to be less negative. \n");
  }
  if(lucky >= 0 && lucky < 3){ // 0 to 2 inclusive
    printf("Think bigger! \n");
  }
  if(lucky >= 4 && lucky < 9){ // 4 to 8 inclusive
    printf("Today you should embrace technology. \n");
  }
  if(lucky == 9){ // exactly 9
    printf("Today is your lucky day! \n");
  }
  if(lucky == 3){ // exactly 3
    printf("You shall have a bountiful harvest! \n");
  }
  // ---------- Code to help the program exit "gracefully" -----
  return 0;
}
