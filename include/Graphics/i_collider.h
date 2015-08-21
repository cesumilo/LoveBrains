/*
** i_collider.h for LoveBrains in /home/robin_f/Programming/Git/CPP/LoveBrains
** 
** Made by Guillaume ROBIN
** Login   <robin_f@epitech.eu>
** 
** Started on  Wed Jul 22 14:31:32 2015 Guillaume ROBIN
** Last update Fri Aug 21 15:03:38 2015 Guillaume ROBIN
*/

#ifndef I_COLLIDER_H_
# define I_COLLIDER_H_

# include "Graphics/i_behavior.h"

namespace Graphics
{
  /*!
   * \class ICollider
   * \brief Define the interface for the collider object.
   */
  class ICollider
  {
  public:
    /*!
     * \brief Destructor.
     */
    virtual ~ICollider() { }

    /*!
     * \brief Verify if the couple of objects is supported by the collider.
     * \param obj_1 : Contains the key of the first object.
     * \param obj_2 : Contains the key of the second object.
     * \return true : if the collider support the couple of objects.
     * \return false : if the collider doesn't support the couple of objects.
     */
    virtual bool	isValid(std::string const& obj_1, std::string const& obj_2) = 0;
    /*!
     * \brief Compute if the couple of objects is colliding.
     * \param obj_1 : Contains the first object.
     * \param obj_2 : Contains the second object.
     * \return true : if the couple of objects is colliding.
     * \return false : if they don't collide.
     */
    virtual bool	isCollision(IObject *obj_1, IObject *obj_2) = 0;

    /*!
     * \brief Get the action that the collider will execute.
     * \return IBehavior *
     */
    virtual IBehavior	*getAction(void) const = 0;
  };
}

#endif /* !A_COLLIDER_H_ */
