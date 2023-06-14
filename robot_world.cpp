/*
 * Seth Cram
 * sec #02
 * 11/13/19
 * Prog Assignment #11:
 *           Robot Game
 * All of the objectives should be completed.
 * extra work (EW): N/A
 */
// imported libs
#include<iostream>
#include<cstdlib>
#include<ctime>      // using < > = look elsewhere to find lib
using namespace std;
// header files (they include other .cpp progs)
#include"robot.h"    // using " " = look in current directory to find file
#include"world.h"
int main(){
  world a_world;     // creates a_world obj of class world (defined in world.h)
  srand(time(NULL));
  a_world.set_up();  // fills in terrain randomly
  do{                // inf loop
    a_world.update();
    a_world.draw();
    cin.ignore();
  }while(1);
  return 0;
}
