/*
 * Seth Cram
 * sec #02
 * 12/09/19
 * Prog Assign #13:
 *   command line C programming calc
 * All of the objectives should be completed.
 * extra work (EW): 
*/
#include<cstdlib> // for atoi(): ascii to integer
#include<cstdio>  // for printf()
#include<string.h>   // for strcmp()

int main(int argc, char *argv[]){ // main for calc
  if(argc != 4){  // check if there are the right number of inputs
    printf("Error calculations should be of the form string, number, operand, number\n");
    return 0;
  }
  double answer =  0; // changed to double to do division well
  int operand1, operand2;
  operand1 = atoi(argv[1]); // change the arguments from ascii to ints
  operand2 = atoi(argv[3]);

  if(strcmp("%",argv[2]) == 0){
    if(operand2 == 0){
      printf("Can't take the modulus of zero my dude/dudette \n");
      return 0;
    }
    else
      answer = (operand1 % operand2) * 1.0;
    printf("%i %s %i = %g \n",operand1, argv[2], operand2, answer);
  }

  if(strcmp("/",argv[2]) == 0){
    if(operand2 == 0){
      printf("Can't divide by zero my dude/dudette \n");
      return 0;
    }
    else
      answer =  ((double)operand1) / ((double)operand2);
    printf("%i %s %i = %g \n",operand1, argv[2], operand2, answer);
  }

  if(strcmp("x",argv[2]) == 0){
    answer = (operand1 * operand2) * 1.0;
    printf("%i %s %i = %g \n",operand1, argv[2], operand2, answer);
  }

  if(strcmp("-",argv[2]) == 0){
    answer = (operand1 - operand2) * 1.0;
    printf("%i %s %i = %g \n",operand1, argv[2], operand2, answer);
  }

  if(strcmp("+",argv[2]) == 0){   
    answer = (operand1 + operand2) * 1.0;
    printf("%i %s %i = %g \n",operand1, argv[2], operand2, answer);
  }
}


