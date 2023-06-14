/*
 * Seth Cram
 * Sec #02
 * 10/01/2019
 * Lab #5:
 *   flip function
 */

//  prototype
void flip(int &,int &); 
#include<iostream>
using namespace std;

int main(){

	int x = 7;
	int y = 20;
	flip(x,y); // this is a function call
	cout << x << " " << y << endl; // should print 20 7
}

void flip(int &f,int &s){
	int p = f;
	int q = s;
	f = q; 
	s = p;
}
	
