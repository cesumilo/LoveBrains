
/*
** i_sensor.h for LoveBrains in /home/robin_f/Programming/Git/CPP/LoveBrains
** 
** Made by Guillaume ROBIN
** Login   <robin_f@epitech.eu>
** 
** Started on  Wed Jul 22 14:39:45 2015 Guillaume ROBIN
** Last update Fri Aug 21 15:23:35 2015 Guillaume ROBIN
*/

#ifndef I_SENSOR_H_
# define I_SENSOR_H_

# include <list>

# include "Graphics/i_object.h"

namespace Graphics
{
  /*!
   * \class ISensor
   * \brief Define the interface of a sensor.
   */
  class ISensor
  {
  public:
    /*!
     * \brief Destructor.
     */
    virtual ~ISensor() { }

    /*!
     * \brief Update the object in terms of the environment.
     * \param obj : Contains the object that is involved by the sensor.
     * \param env : Contains all the objects in the environment.
     */
    virtual void	Update(IObject *obj, std::list<IObject *>& env) = 0;
    /*!
     * \brief Verify if the sensor support the current object.
     * \param obj : Contains the current object.
     * \return true : if the object is supported.
     * \return false : if the object is not supported.
     */
    virtual bool	isValid(IObject *obj) = 0;
  };
}

#endif /* !I_SENSOR_H_ */
