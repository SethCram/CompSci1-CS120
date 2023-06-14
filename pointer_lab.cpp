/*
 * Seth Cram
 * sec #02
 * 10/29/19
 * Prog Lab #9:
 *   pointer test code
 * All of the objectives should be completed.
 * Expected outputs:
 * x = 99
 * y = 101
 * a[0] = 102
 * a[1] = 8
 * a[2] = 11
 * a[3] = 12
 * a[4] = 456
 */
#include<iostream>
using namespace std;

int func(int, int &);
void func2(int, int []);

int main(){
  int x = 99, y = 55;
  int a[5] = {1,2,3,4,5};
  int *p; // creates pointer
  p = a; // sets addy of pointer to top of array (address of a[0]) 
  p++; // move down 1 addy from top of array to a[1]
  *p = 8; // points from current addy of a[1] to int 8: a[1] = 8 
  p = &a[3]; // sets addy of pointer to a[3]'s addy
  *p = 12; // points from current addy of a[3] to int 12: a[3] = 12   
  p--; // move up one addy from current addy of array at a[3] to a[2]
  *p = 11; // point from current addy of a[2] to 11: a[2] = 11
  a[0] = func(x,y); // y changed in main bc & used in funct to pass the int by ref 
  func2(x,a); // a[4] changed in main bc arrays always pass by ref
  cout << "x = " << x << endl;
  cout << "y = " << y << endl;
  for(int i = 0; i < 5; i++){
    cout << "a[" << i << "] = " << a[i] << endl;
  }
}

int func(int a, int &b){
  a = 100;
  b = 101;
  return 102;
}

void func2(int a, int b[]){
  a = 123;
  b[4] = 456;
}
/*
 * actual output:
 *   x = 99
 *   y = 101
 *   a[0] = 102
 *   a[1] = 8
 *   a[2] = 11
 *   a[3] = 12
 *   a[4] = 456
 */
