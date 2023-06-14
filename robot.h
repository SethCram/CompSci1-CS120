class robot{
       private:
          int direction;
          int energy;
          int ID;
          int moved;  
          void turnRight();                  // a private function
          void forward(int &, int &);        // a private function
      public:
          void turnLeft();                   // a private function
int getID(){return ID;}
         robot(int);                        
         void refresh() {moved = 0;}        // an in-line function
         void draw();
         void print();
         void move(int &, int &);           // pass-by-reference arguments
   };

void robot::turnLeft(){
      energy--;
      direction = (direction + 3) % 4; // a left is 3 rights
}
void robot::turnRight(){
      energy--;
      direction = (direction + 1) % 4;
}
void robot::forward(int &x,int &y){
      energy -= 2;
      if(direction == 0)
           y--;    
      if(direction == 2)
           y++;    
      if(direction == 1)
           x++;    
      if(direction == 3)
           x--;    
}
robot::robot(int id){
     energy = 50;
     ID = id;
     moved = 0;
     direction = 0;
}
void robot::draw(){ // direction var included in class, private data mems can be accessed by 
  if(direction == 0)
    cout << "^";
  if(direction == 2)
    cout << "v";
  if(direction == 1)
    cout << ">";
  if(direction == 3)
    cout << "<";
}
void robot::print(){
     cout<<"ID" <<ID<<": Energy = "<<energy<< "   Direction = "<<direction;
}
void robot::move(int &x,int &y){
     if(moved == 1)
          return;
     switch(rand()%4){
     case 0:
          turnLeft();
          break;
     case 1:
          turnRight();
          break;
     case 2:
     case 3: 
          forward(x,y);
          break;
     default: 
          cout << "Error in robot move." << endl;
     }
     moved = 1;
}
