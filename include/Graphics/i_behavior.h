/*
** i_behavior.h for LoveBrains in /home/robin_f/Programming/Git/CPP/LoveBrains
** 
** Made by Guillaume ROBIN
** Login   <robin_f@epitech.eu>
** 
** Started on  Wed Jul 22 14:29:54 2015 Guillaume ROBIN
** Last update Fri Aug 21 14:47:17 2015 Guillaume ROBIN
*/

#ifndef I_BEHAVIOR_H_
# define I_BEHAVIOR_H_

# include "Graphics/i_object.h"

namespace Graphics
{
  /*!
   * \class IBehavior
   * \brief Define a behavior for a collider.
   */
  class IBehavior
  {
  public:
    /*!
     * \brief Destructor.
     */
    virtual ~IBehavior(void) { }

    /*!
     * \brief Update the object that have been affected the collider.
     * \param obj : Contains the object that is affected by the collider.
     */
    virtual void	Update(IObject *obj) = 0;
  };
}

#endif /* !I_BEHAVIOR_H_ */
