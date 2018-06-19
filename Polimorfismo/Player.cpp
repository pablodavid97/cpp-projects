#include <iostream>
#include "Player.h"

using namespace std;

Player::Player(std::string name)
   : GameObject(name)
{
   cout << "Player(" << name << ")" << endl;
}

void Player::draw()
{
   cout << "\\o/ Player::draw(" << name << ")" << endl;
}
