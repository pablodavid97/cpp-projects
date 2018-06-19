#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <string>

class GameObject
{
   public:
      GameObject(std::string);
      void draw();

   protected:
      std::string name;

   private:

};

#endif // GAMEOBJECT_H
