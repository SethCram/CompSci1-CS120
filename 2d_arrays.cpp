/*
 * Seth Cram
 * sec #02
 * 11/05/19
 * Prog Lab #10:
 *   2D array with pointers
 * All of the objectives should be completed.
 * extra work (EW): N/A

 Expected output:
   99, 3, 4, 5, 44, 6,
   77, 5, 7, 9, 10, 12,
   55, 66, 10, 13, 15, 18,
 */
#include<iostream>
using namespace std;

void fill(int a[][6], int, int);
void increment(int a[][6], int, int);

int main(){
  int a[3][6];
  fill(a,3,6); // fills array with multiples of 1 for row 1, 2 for row 2, and 3 for row 3
  increment(a,3,4); // adds 1 to the first 4 columns in the array
  int *p; 
  p = (int *)a; // typecast array to int + store addy in p
  *p = 99; // store 99's addy in first element of array
  p[6] = 77; // has the 6th int in the array (a[1][0]) point to 77
  p = &a[2][2]; // sets p to addy of a[2][2]
  p--; // subtracts 1 from a[2][2] addy so now a[2][1]
  *p = 66; // store 66's addy in a[2][1]
  p = (int *)(a[0]+4); // sets p to addy of a[0][4] bc calling the index of an array counts by column (same as p = (int *)(a[0][0]+4)?) no, segmentation fault.
  *p = 44; // store 44's addy in a[0][4]
  p = (int *)(a+2); // sets p to addy of a[2][0] bc calling just the array location counts by row
  *p = 55;
  for(int r = 0; r < 3; r++){ // prints all values of the array
    for(int c = 0; c < 6; c++){
      cout << a[r][c] << ", ";
    }
    cout << endl;  // to display in columns of 6
  }
}


void fill(int data[][6], int rows, int columns){
  for(int r = 0; r < rows; r++){
    for(int c = 0; c < columns; c++){
      data[r][c] = (r+1)*(c+1);
    }
  }
}

void increment(int data[][6], int rows, int columns){
  for(int r = 0; r < rows; r++){
    for(int c = 0; c < columns; c++){
      data[r][c] += 1;
    }
  }
}
/*
  actual output:
   99, 3, 4, 5, 44, 6,
   77, 5, 7, 9, 10, 12,
   55, 66, 10, 13, 15, 18,
 */

