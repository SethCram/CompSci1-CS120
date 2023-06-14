const int HEIGHT = 30; // the new height = 30
const int WIDTH = 30;  // the new width = 30

class world{
   private:
      int terrain[WIDTH][HEIGHT]; // 2D array of terrain
      robot *bots[WIDTH][HEIGHT]; // 2D array of pointers pointing to robots
      // can theoretically add something like sunny or cloudy day array
   public:
      void set_up();
      void draw();
      void update();
};


void world::set_up(){
     for(int y = 0; y < HEIGHT; y++){
           for(int x = 0; x < WIDTH; x++){
	     bots[x][y] = NULL; // not storing a valid value yet, not pointing anywhere
                terrain[x][y] = rand()%2; // 1 or 0 randomly
            }
     }
     bots[2][2] = new robot(1);
     bots[7][7] = new robot(2);
     bots[15][15] = new robot(3); // adds another robot 
     bots[20][5] = new robot(4); // adds another robot
}

void world::draw(){
    for(int y = 0; y < HEIGHT; y++){
          for(int x = 0; x < WIDTH; x++){
	    if(bots[x][y] == NULL){
	      if(x < WIDTH/2 && y < HEIGHT/2){
		cout << (char)(terrain[x][y] + 77); // M or N
	      }else{
	      cout << (char)(terrain[x][y]%1 + 124); // 124, then set to char by ascii
	      }
	    }else{
	      bots[x][y] -> draw(); // draws a # (found in robot.h)
	    }
          }
          cout << endl;
    }

    for(int y = 0; y < HEIGHT; y++)
          for(int x = 0; x < WIDTH; x++)
	    if(bots[x][y] != NULL){ // if see a robot ask to print + refresh itself
	      bots[x][y]->print(); // (found in robot.cpp) 
	      bots[x][y]->refresh(); // 	
                     cout << "\n";
               }

}

void world::update(){ // updates world for next move 
    int tempx,tempy;
    robot *temp;
    for(int y = 0; y < HEIGHT; y++){
          for(int x = 0; x < WIDTH; x++){
               if(bots[x][y] != NULL){
                     tempx = x;
                     tempy = y;
                     bots[x][y] -> move(tempx,tempy);
		     // 3 if statements to check robot doesn't go out of bounds
                     if(tempx < 0 || tempx >= WIDTH)
                           tempx = x;
                     if(tempy < 0 || tempy >= HEIGHT)
                           tempy = y;
                     if(bots[tempx][tempy] == NULL){
                           temp = bots[x][y];
                           bots[x][y] = NULL; // old location to NULL
                           bots[tempx][tempy] = temp; // new location 
                     }  
               }
          }
    }
}
