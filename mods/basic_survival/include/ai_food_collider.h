/*
** ai_food_collider.h for Basic survival plugin in /home/robin_f/Programming/Git/CPP/LoveBrains/mods/basic_survival
** 
** Made by Guillaume ROBIN
** Login   <robin_f@epitech.eu>
** 
** Started on  Sat Aug  1 14:11:27 2015 Guillaume ROBIN
** Last update Sat Aug  1 14:43:42 2015 Guillaume ROBIN
*/

#ifndef AI_FOOD_COLLIDER_H_
# define AI_FOOD_COLLIDER_H_

# include "Graphics/i_collider.h"

class ColliderAIAndFood : public Graphics::ICollider
{
 public:
  ColliderAIAndFood(void);
  ~ColliderAIAndFood(void);

  /*
  ** Methods.
  */
  bool			isValid(std::string const& obj_1, std::string const& obj_2);
  bool			isCollision(Graphics::IObject *obj_1, Graphics::IObject *obj_2);
  Graphics::IBehavior	*getAction(void) const;
};

#endif /* !AI_FOOD_COLLIDER_H_ */
