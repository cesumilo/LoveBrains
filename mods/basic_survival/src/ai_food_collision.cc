//
// ai_food_collision.cc for Basic survival plugin in /home/robin_f/Programming/Git/CPP/LoveBrains/mods/basic_survival
// 
// Made by Guillaume ROBIN
// Login   <robin_f@epitech.eu>
// 
// Started on  Sat Aug  1 14:39:38 2015 Guillaume ROBIN
// Last update Sat Aug  1 14:46:34 2015 Guillaume ROBIN
//

#include <iostream>

#include "ai_food_collision.h"

/*
** Constructor & Destructor.
*/
AIAndFoodCollision::AIAndFoodCollision(void)
{
}

AIAndFoodCollision::~AIAndFoodCollision(void)
{
}

/*
** Methods.
*/
void	AIAndFoodCollision::Update(Graphics::IObject *obj)
{
  std::cerr << "Collision: " << obj->getType() << std::endl;
}
