#ifndef BUILDING_H
#define BUILDING_H

#include "GameObject.h"


class Building : public GameObject
{
   public:
      Building(std::string name);
      void draw();

   protected:

   private:
};

#endif // BUILDING_H
