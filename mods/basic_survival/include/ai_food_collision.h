/*
** ai_food_collision.h for Basic survival plugin in /home/robin_f/Programming/Git/CPP/LoveBrains/mods/basic_survival
** 
** Made by Guillaume ROBIN
** Login   <robin_f@epitech.eu>
** 
** Started on  Sat Aug  1 14:37:05 2015 Guillaume ROBIN
** Last update Sat Aug  1 14:39:18 2015 Guillaume ROBIN
*/

#ifndef AI_FOOD_COLLISION_H_
# define AI_FOOD_COLLISION_H_

# include "Graphics/i_behavior.h"

class AIAndFoodCollision : public Graphics::IBehavior
{
 public:
  AIAndFoodCollision(void);
  ~AIAndFoodCollision(void);

  /*
  ** Methods.
  */
  void	Update(Graphics::IObject *obj);
};

#endif /* !AI_FOOD_COLLISION_H_ */
