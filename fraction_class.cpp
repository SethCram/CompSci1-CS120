/*
 * Seth Cram
 * sec #02
 * 10/18/19
 * Prog Assignment #7
 *   Fraction Class -
 * All of the objectives should be completed.
 * extra credit (EW): Added a constructor and a catch for if the mixed number didn't output a single whole number
 */
#include<iostream>
using namespace std;

class fraction{
private:
  int num;
  int denom;
public:
  fraction(); // constructor
  void set_fraction(int,int);
  void print_improp();
  void print_mixed();
  void print_decimal();
  fraction add(fraction);
  fraction subtr(fraction);
  fraction div(fraction);
  fraction mult(fraction);
};

int main(){
  fraction f1, f2, f3;
  int numeral, denomeral, print_num;
  cout << "numerator: " << endl;
  cin >> numeral;
  cout << "denominator: " << endl;
  cin >> denomeral;
  f1.set_fraction(numeral,denomeral);
  f1.print_improp();
  f1.print_mixed();
  f1.print_decimal();

  cout << "numerator: " << endl;
  cin >> numeral;
  cout << "denominator: " << endl;
  cin >> denomeral;
  f2.set_fraction(numeral,denomeral);
  f2.print_improp();
  f2.add(f1);
  f2.subtr(f1);
  f2.div(f1);
  f2.mult(f1);

  cout << "numerator: " << endl;
  cin >> numeral;
  cout << "denominator: " << endl;
  cin >> denomeral;
  f3.set_fraction(numeral,denomeral);
  f3.print_improp();
  f3.add(f1);

}

fraction::fraction(){ // (EW)
  num = 1;
  denom = 1;
}

void fraction::set_fraction(int n, int d){
  int denom_placehold;
  int num_placehold;
  if(d == 0){
    denom_placehold = d;
    num_placehold = n;
    num = denom_placehold;
    denom = num_placehold;
  }else{
    num = n;
    denom = d;
  } 
}

void fraction::print_improp(){
  cout << "Your improper fraction is: " << num << "/" << denom << endl;
}

void fraction::print_mixed(){
  int whole_num;
  fraction remain;
  remain.num  = num % denom;
  remain.denom = denom;
  whole_num = num / denom;
  if(whole_num == 0){
   cout << "Your mixed number is: " << whole_num << " " << remain.num << "/" << remain.denom << endl;  
  }else{ // (EW)
    cout << "Your mixed number is: " << remain.num << "/" << remain.denom << "since there were no whole numbers" << endl;
  }
}

void fraction::print_decimal(){
  double deci;
  deci = 1.0 * num / denom;
  cout << "Your decimal value is: " << deci  << endl;
}

fraction fraction::add(fraction an_obj){
  fraction ans;
  ans.num = (num * an_obj.denom) + (denom *an_obj.num);
  ans.denom = denom * an_obj.denom;
  cout << "Fraction addition = " << ans.num << "/" << ans.denom << endl;
}

fraction fraction::subtr(fraction an_obj){
  fraction ans;
  ans.num = (denom *an_obj.num) - (num * an_obj.denom);
  ans.denom = denom * an_obj.denom;
  cout << "Fraction division = " << ans.num << "/" << ans.denom << endl; 
}


fraction fraction::div(fraction an_obj){
  fraction ans;
  if(num == 0 || denom == 0 || an_obj.denom == 0 || an_obj.num == 0){
    ans.num == 0;
    ans.denom == 0;
  }else{
  ans.num = an_obj.num * denom; 
  ans.denom = an_obj.denom * num;
  }
  cout << "The 1st fraction divided by the second = " << ans.num << "/" << ans.denom << endl;
}

fraction fraction::mult(fraction an_obj){
  fraction ans;
  if(num == 0 || denom == 0 || an_obj.denom == 0 || an_obj.num == 0){
    ans.num == 0;
    ans.denom == 0;
  }else{
  ans.num = an_obj.num * num;
  ans.denom = an_obj.denom * denom;
  }
  cout << "The 1st fraction multiplied by the second = " << ans.num << "/" << ans.denom << endl;
}




