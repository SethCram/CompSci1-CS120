/*
 * Seth Cram
 * sec #02
 * 10/23/19
 * Prog Assign #8:
 *   random doubles array with functions
 * All of the objectives should be completed.
 * extra work (EC): The standard deviation program is included below
 */
#include<iostream>
#include<cstdlib>
#include<cmath>
using namespace std;
// prototypes
void generate(double [],int,double,double);
void print(double [],int);
double avg(double [],int);
double min(double [],int);
double max(double [],int);
void addX(double [],int,double);
int num_less(double [],int);
int num_more(double [],int);
int num_less(double [],int,double);
double range(double [],int);
double std_dev(double [],int); // (EC)

int main(){
  //variable declarations to test the functions, arbitrary values contained
  int cap = 100; // size of each array
  double array[cap]; // creates an empty array with 100 empty memory locations called array
  double low = -10.0;
  double high = 10.0;
  double added = 3.7;
  double threshold = 5;

  generate(array,cap,low,high); //section testing fuctions
  print(array,cap);
  cout << "Average of the array values: " << avg(array,cap) << endl;
  cout << "Minimum of the array values: " << min(array,cap) << endl;
  cout << "Maximum of the array values: " << max(array,cap) << endl;
  cout << "Number of values lower than the average number of the array values: " << num_less(array,cap) << endl;
  cout << "Number of values bigger than the average number of the array values: " << num_more(array,cap) << endl;
  cout << "Number of values below the threshold: " << num_less(array,cap,threshold) << endl;
  cout << "The range of values in the array: " << range(array,cap) << endl;
  cout << "The standard deviation of values in the array: " << std_dev(array,cap) << endl; // (EC)

  addX(array,cap,added); // section adding values to a filled array
  print(array,cap);
  cout << "Added " << added << " to the above array\n"; 
  cout << "Average of the array values: " << avg(array,cap) << endl;
  cout << "Minimum of the array values: " << min(array,cap) << endl;
  cout << "Maximum of the array values: " << max(array,cap) << endl;
  cout << "Number of values lower than the average number of the array values: " << num_less(array,cap) << endl;
  cout << "Number of values bigger than the average number of the array values: " << num_more(array,cap) << endl;
  cout << "Number of values below the threshold: " << num_less(array,cap,threshold) << endl;
  cout << "The range of values in the array: " << range(array,cap) << endl;
  cout << "The standard deviation of values in the array: " << std_dev(array,cap) << endl; // (EC)

  low = 5; // section testing if lower bound > upper bound what happens
  high = 2;
  threshold = 3;
  generate(array,cap,low,high);
  print(array,cap);
  cout << "Average of the array values: " << avg(array,cap) << endl;
  cout << "Minimum of the array values: " << min(array,cap) << endl;
  cout << "Maximum of the array values: " << max(array,cap) << endl;
  cout << "Number of values lower than the average number of the array values: " << num_less(array,cap) << endl;
  cout << "Number of values bigger than the average number of the array values: " << num_more(array,cap) << endl;
  cout << "Number of values below the threshold: " << num_less(array,cap,threshold) << endl;
  cout << "The range of values in the array: " << range(array,cap) << endl;
  cout << "The standard deviation of values in the array: " << std_dev(array,cap) << endl; // (EC)

  low = 5; // section testing if lower bound = upper bound and you add 0 to each array value what happens
  high = 5;
  added = 0;
  threshold = 1.1;
  generate(array,cap,low,high);
  addX(array,cap,added);
  print(array,cap);
  cout << "Average of the array values: " << avg(array,cap) << endl;
  cout << "Minimum of the array values: " << min(array,cap) << endl;
  cout << "Maximum of the array values: " << max(array,cap) << endl;
  cout << "Number of values lower than the average number of the array values: " << num_less(array,cap) << endl;
  cout << "Number of values bigger than the average number of the array values: " << num_more(array,cap) << endl;
  cout << "Number of values below the threshold: " << num_less(array,cap,threshold) << endl;
  cout << "The range of values in the array: " << range(array,cap) << endl;
  cout << "The standard deviation of values in the array: " << std_dev(array,cap) << endl; // (EC)

  low = -10; // section testing if lower bound and upper bound negative and add a negative to each array value what happens
  high = -5;
  added = -2.1;
  threshold = -9.9;
  generate(array,cap,low,high);
  addX(array,cap,added);
  print(array,cap);
  cout << "Average of the array values: " << avg(array,cap) << endl;
  cout << "Minimum of the array values: " << min(array,cap) << endl;
  cout << "Maximum of the array values: " << max(array,cap) << endl;
  cout << "Number of values lower than the average number of the array values: " << num_less(array,cap) << endl;
  cout << "Number of values bigger than the average number of the array values: " << num_more(array,cap) << endl;
  cout << "Number of values below the threshold: " << num_less(array,cap,threshold) << endl;
  cout << "The range of values in the array: " << range(array,cap) << endl;
  cout << "The standard deviation of values in the array: " << std_dev(array,cap) << endl; // (EC)

}

void generate(double a[], int bulk, double lower, double upper){ // form random array
    for(int i = 0; i < bulk; i++){
      a[i] = (rand() / (RAND_MAX / (upper - lower))) + lower;
    }
}
void print(double a[], int bulk){ // print funct
  for(int i = 0; i < bulk; i++){
    if(0 == i % 5 && i != 0){  // formatting for readability
      cout << "\n";
    }
    cout << i + 1 << " " << a[i] << "\t";
  }
  cout << "\n"; // more formatting
}
double avg(double a[], int bulk){ // average function
  double array_tot = 0;
  double array_avg;
  for(int i = 0; i < bulk; i++){
    array_tot = array_tot + a[i];
  }    
  return array_avg = array_tot / bulk;
}
double min(double a[], int bulk){ // calculates min in array
  for(int i = 0; i < bulk; i++){
    double smallest;
    if(i == 0){
      smallest = a[i];
    }
    if(a[i] < smallest){
      smallest = a[i];
    }
    if(i + 1 == bulk){
      return smallest;
    }
  }
}
double max(double a[], int bulk){ // calculates max in array
  for(int i = 0; i < bulk; i++){
    double largest;
    if(i == 0){
      largest = a[i];
    }
    if(a[i] > largest){
      largest = a[i];
    }
    if(i + 1 == bulk){
      return largest;
    }
  }
}
void addX(double a[],int bulk, double x){ // add to each array value
  for(int i = 0; i < bulk; i++){
    a[i] = a[i] + x;
  }
}
int num_less(double a[], int bulk){ // lower than avg
  double avg_compare = avg(a,bulk);
  int counter = 0;
  for(int i = 0; i < bulk; i++){
    if(avg_compare > a[i]){
      counter++;
    } 
  }
  return counter;
}
int num_more(double a[], int bulk){ // higher than avg
  double avg_compare = avg(a,bulk);
  int counter = 0;
  for(int i = 0; i < bulk; i++){
    if(avg_compare < a[i]){
      counter++;
    }
  }
  return counter;
}
int num_less(double a[], int bulk, double thold){ // lower than threshold
  int counter = 0;
  for(int i = 0; i < bulk; i++){
    if(thold > a[i]){
      counter++;
    }
  }
  return counter;
}
double range(double a[], int bulk){ // range funct
  return max(a,bulk) - min(a,bulk);
}
double std_dev(double a[], int bulk){ // standard deviation funct (EW)
  double average;
  double squared_ph = 0;
  average = avg(a,bulk);
  for(int i = 0; i < bulk; i++){
    squared_ph = squared_ph + (pow(a[i] - average, 2));
  }
  return sqrt(squared_ph / bulk);
}
