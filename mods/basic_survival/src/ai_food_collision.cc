//
// ai_food_collision.cc for Basic survival plugin in /home/robin_f/Programming/Git/CPP/LoveBrains/mods/basic_survival
// 
// Made by Guillaume ROBIN
// Login   <robin_f@epitech.eu>
// 
// Started on  Sat Aug  1 14:39:38 2015 Guillaume ROBIN
// Last update Mon Aug 17 13:59:29 2015 ROBIN Guillaume
//

#include <iostream>

#include "ai_food_collision.h"
#include "basic_ia.h"

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
void		AIAndFoodCollision::Update(Graphics::IObject *obj)
{
  BasicAI	*ptr;

  if (obj->getType().compare("basic_food") == 0)
    obj->setIsDead(true);
  else if (obj->getType().compare("basic_survival_ai") == 0)
    {
      ptr = (BasicAI *)obj;
      ptr->increaseLife();
      ptr->setFitness(ptr->getFitness() + FOOD_SCORE);
    }
}
