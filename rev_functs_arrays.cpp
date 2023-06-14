/*
 * Seth Cram
 * sec #02
 * 12/10/19
 * Prog Lab #13:
 *   review of functs + arrays
 * All of the objectives should be completed.
 * extra work (EW):
 */
#include<iostream>
#include<cstdlib>
using namespace std;

// put prototypes here
void print(int [],int);
double average(int [],int);
void summation(int [],int,int &);

int main(){
  int array[10];
  int len = 10;
  for(int i = 0; i < len; i++){  
    array[i] = rand()%100;  // fill the array with random elements
  }
  cout << "The array values are:\n";
  print(array,len); // this function should print each element of the array
   
  double avg;
  // Here the program should call a function called average()
  avg= average(array,len);
  // that calculates the average and stores the result in avg to be printed
  cout << "The average value is: " << avg << endl;

  int sum= 0;
  summation(array,len,sum); // this should calculate the sum of the values and 
  // store the answer in sum to be printed.
  cout << "The sum of the values is: " << sum << endl;
}

// put the function code here
void print(int a[], int len){
  for(int i = 0; i < len; i++){
    cout << a[i] << " ";
  }
  cout << endl;
}
double average(int a[], int len){
  double sum = 0;
  for(int i = 0; i < len; i++){
    sum = sum + a[i];
  }
  return sum/((double)len);
}
void summation(int a[], int len, int &sum){
  for(int i = 0; i < len; i++){
    sum = sum + a[i];
  }
}
