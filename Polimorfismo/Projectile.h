#ifndef PROJECTILE_H
#define PROJECTILE_H

#include "GameObject.h"


class Projectile : public GameObject
{
   public:
      Projectile(std::string);
      void draw();

   protected:

   private:
};

#endif // PROJECTILE_H
