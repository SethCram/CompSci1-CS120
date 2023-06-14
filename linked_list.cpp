/*
 * Seth Cram
 * sec #02
 * 11/21/19
 * Prog Assign #12:
 *   Updated Linked List with Recursion
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
  int player_ID;
  string wep; 
public:
  void setnext(node *n){next = n;} // inline function
  void setdata(string,int,string);
  void print(); // defined below
  void append(node *);
  int length();
  void clear();
};

void node::append(node *n){ // doesn't work if head == NULL bc list empty, seg fault
  if(next != NULL)
    next -> append(n);
  else{
    next = n;
    n -> next = NULL;  
  }
}
void node::setdata(string title,int ident,string weapon){
  name = title;
  player_ID = ident;
  wep = weapon;
}

void node::print(){
  cout << name << " " << wep << " P" << player_ID << endl;
  if(next != NULL)
    next -> print();
}

int node::length(){ // doesn't work for no linked list, seg fault
  if(next == NULL)
    return 1;
  else
    return(next -> length() + 1);
}
void node::clear(){
  if(next != NULL)
    next -> clear();
  cout << "Lab member, realname********" << name << "********deleted" << endl;
  delete next;  
}

int main(){
  node *head, *temp;  // pointers to a node object
  int bobs;
  string pause;

  temp = new node();  // create a new node object
  temp -> setdata("Sally",04,"whip"); // add data
  temp -> setnext(NULL);  // make the next object Null
  head = temp;// make head point to the beginning of the list
 
  temp = new node();  // create another new node object
  temp -> setdata("Fred",03,"sword"); // add data
  temp -> setnext(head); // 'point' the new object to the beginning of the l\
ist
  head = temp;          // make head point to the new beginning of the list

 temp = new node();    // repeat
 temp -> setdata("Anne",02,"leaf");
 temp -> setnext(head);
 head = temp;          // make head point to the new beginning of the list

 temp = new node();    // repeat
 temp -> setdata("Alan",01,"magiccarpet");
 temp -> setnext(head);
 head = temp;          // make head point to the new beginning of the list
 cout << "List of Members: \n";
 head->print();
 cout << "Number of nodes: " << head->length() << endl;
 
 cout << "How many additonal Bob's do you want to add to the list? \n";
 cin >>  bobs;
 for(int i = 0; i < bobs; i++){
   temp = new node();
   temp -> setdata("Bob",100,"turkey");
   temp -> setnext(head);
   head = temp;
 }
 cout << "List of Members: \n";
 head->print();
 cout << "Number of nodes: " << head->length() << endl;

 temp = new node();  // create a new node object
 cout << "Add another member?" << endl;
 cin >> pause;
 if(pause == "yes"){
   head -> append(temp);
   temp -> setdata("Henry",05,"handcanon"); // add data
 }
 cout << "List of Members: \n";
 head->print();
 cout << "Number of nodes: " << head -> length() << endl;
 cout << "Delete them all?" << endl;
 cin >> pause;
 if(pause == "yes"){
   head -> clear();
   delete head;
 }
}
