/*
** i_behavior.h for LoveBrains in /home/robin_f/Programming/Git/CPP/LoveBrains
** 
** Made by Guillaume ROBIN
** Login   <robin_f@epitech.eu>
** 
** Started on  Wed Jul 22 14:29:54 2015 Guillaume ROBIN
** Last update Thu Jul 30 18:37:43 2015 Guillaume ROBIN
*/

#ifndef I_BEHAVIOR_H_
# define I_BEHAVIOR_H_

# include "Graphics/i_object.h"

namespace Graphics
{
  class IBehavior
  {
  public:
    virtual ~IBehavior(void) { }

    virtual void	Update(IObject *obj) = 0;
  };
}

#endif /* !I_BEHAVIOR_H_ */
