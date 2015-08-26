/*
** i_collider.h for LoveBrains in /home/robin_f/Programming/Git/CPP/LoveBrains
** 
** Made by Guillaume ROBIN
** Login   <robin_f@epitech.eu>
** 
** Started on  Wed Jul 22 14:31:32 2015 Guillaume ROBIN
** Last update Thu Jul 30 17:08:21 2015 Guillaume ROBIN
*/

#ifndef I_COLLIDER_H_
# define I_COLLIDER_H_

# include "Graphics/i_behavior.h"

namespace Graphics
{
  class ICollider
  {
  public:
    virtual ~ICollider() { }

    virtual bool	isValid(std::string const& obj_1, std::string const& obj_2) = 0;
    virtual bool	isCollision(IObject *obj_1, IObject *obj_2) = 0;

    virtual IBehavior	*getAction(void) const = 0;
  };
}

#endif /* !A_COLLIDER_H_ */
