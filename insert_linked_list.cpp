/*
 * Seth Cram
 * sec #02
 * 12/03/19
 * Prog Lab #12:
 *   Updated Linked List with insert funct
 * All of the objectives should be completed.
 * extra work (EW): can add a node anywhere, even at the end.
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
  void insert(node *); 
  int get_addy();
};

int node::get_addy(){ //getter function used to retrieve ID number to use in main
  return player_ID;
}
void node::insert(node *n){ //insert funct
  if(next != NULL){      
    if(player_ID <= n->player_ID && next->player_ID >= n->player_ID){ 
      n->next = next;
      next = n;
    }
    else{
      next -> insert(n);
    }
  }
  else{
    next = n;
    n -> next = NULL;
  }                     
}
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
  int bobs, carl_ID;
  string pause;

  temp = new node();  // create a new node object
  temp -> setdata("Sally",8,"whip"); // add data
  temp -> setnext(NULL);  // make the next object Null
  head = temp;// make head point to the beginning of the list

 temp = new node();    // repeat
  temp -> setdata("Anne",6,"leaf");
  temp -> setnext(head);
  head = temp;         

  cout << "How many Bob's do you want to add to the list? \n";
  cin >>  bobs;
  for(int i = 0; i < bobs; i++){
    temp = new node();
    temp -> setdata("Bob",4,"turkey");
    temp -> setnext(head);
    head = temp;
  }
  cout << "List of Members: \n";
  head->print();
  head = temp;            
 
  temp = new node(); //START OF LAB 12 IMPORTANT CODE
  cout << "Add another member?" << endl;
  cin >> pause;
  cout << "What's their ID number? " << endl;
  cin >> carl_ID;
  if(pause == "y"){  
    temp -> setdata("Carl",carl_ID,"strap"); // add data
    if(head == NULL || head->get_addy() > temp->get_addy()){
      temp -> setnext(head);
      head = temp;
    }else{
      head -> insert(temp);
    }
  }                   //END
  cout << "List of Members: \n";
  head->print();
}

