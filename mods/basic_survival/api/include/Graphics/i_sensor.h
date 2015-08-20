
/*
** i_sensor.h for LoveBrains in /home/robin_f/Programming/Git/CPP/LoveBrains
** 
** Made by Guillaume ROBIN
** Login   <robin_f@epitech.eu>
** 
** Started on  Wed Jul 22 14:39:45 2015 Guillaume ROBIN
** Last update Tue Aug 18 13:40:40 2015 Guillaume ROBIN
*/

#ifndef I_SENSOR_H_
# define I_SENSOR_H_

# include <list>

# include "Graphics/i_object.h"

namespace Graphics
{
  class ISensor
  {
  public:
    virtual ~ISensor() { }

    virtual void	Update(IObject *obj, std::list<IObject *>& env) = 0;
    virtual bool	isValid(IObject *obj) = 0;
  };
}

#endif /* !I_SENSOR_H_ */
