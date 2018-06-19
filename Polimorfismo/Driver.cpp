#include <iostream>
#include "GameObject.h"
#include "Building.h"
#include "Player.h"
#include "Projectile.h"
#include <cstdlib>
#include <unistd.h>

using namespace std;

void drawAll(GameObject **, int);

int main(void)
{
   const int numObj = 5;
   int frame = 0;
   GameObject *objToDraw[numObj] = {0};

   objToDraw[0] = new GameObject("World");
   objToDraw[1] = new Building("Asylum");
   objToDraw[2] = new Projectile("Arrow");
   objToDraw[3] = new Player("Aldo");

   while(true)
   {
      sleep(3);
      cout << "\n*****Drawing all objects, frame " << frame++ << endl;
      drawAll(objToDraw, numObj);
   }
}

void drawAll(GameObject *a[], int size)
{
   for(int i = 0; i < size; i++)
      if(a[i] != 0)
         a[i]->draw();
}
