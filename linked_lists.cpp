/*
 * Seth Cram
 * sec #02
 * 11/12/19
 * Prog Lab #11:
 *   Linked List with Recursion
 * All of the objectives should be completed.
 * extra work (EW): N/A
 */
#include<iostream>
#include<string>
using namespace std;

class node{
private:
  node *next;
  string name;
public:
  void setnext(node *n){next = n;} // inline function
  void setdata(string n){name = n;}  // inline function
  void print(); // defined below
  void reverse_print(); // defined below
};

void node::print(){
  cout << name << endl;
  if(next != NULL)      // if next == NULL, ends recursion
    next -> print(); // puts next addy into print() + calls the funct to run again
}

void node::reverse_print(){
  /* if(next == NULL){
    cout << name << endl;
    return;                // why does this funct keep looping after a return statement?
  }
  next -> reverse_print(); // loops until the final next 
  cout << name << endl; // prints final next's data (why does the funct still loop after displaying 1st name?)
  */
  if(next != NULL)
    next -> reverse_print();
  cout << name << endl;
}

int main(){
  node *head, *temp;  // pointers to a node object
  int bobs;
  temp = new node();  // create a new node object
  temp -> setdata("Sally"); // add data
  temp -> setnext(NULL);  // make the next object Null
  head = temp;           // make head point to the beginning of the list

  temp = new node();  // create another new node object
  temp -> setdata("Fred"); // add data
  temp -> setnext(head); // 'point' the new object to the beginning of the list
  head = temp;          // make head point to the new beginning of the list

  temp = new node();    // repeat
  temp -> setdata("Anne");
  temp -> setnext(head);
  head = temp;          // make head point to the new beginning of the list

  temp = new node();    // repeat
  temp -> setdata("Alan");
  temp -> setnext(head);
  head = temp;          // make head point to the new beginning of the list
  cout << "Regular List: \n";
  head->print();       // print the list
  cout << "Reverse List: \n";
  head->reverse_print(); // print lsit in reverse order

  cout << "How many additonal Bob's do you want to add to the list? \n";
  cin >>  bobs;
  for(int i = 0; i < bobs; i++){
    temp = new node();
    temp -> setdata("Bob");
    temp -> setnext(head);
    head = temp;
  }
  cout << "Regular List: \n";
  head->print();       // print the list
  cout << "Reverse List: \n";
  head->reverse_print(); // print lsit in reverse order

}
