/*
** ai_vision_field.h for Basic survival plugin in /home/robin_f/Programming/Git/CPP/LoveBrains/mods/basic_survival
** 
** Made by ROBIN Guillaume
** Login   <robin_f@epitech.eu>
** 
** Started on  Mon Aug 17 14:08:08 2015 ROBIN Guillaume
** Last update Tue Aug 18 14:35:42 2015 Guillaume ROBIN
*/

#ifndef AI_VISION_FIELD_H_
# define AI_VISION_FIELD_H_

#include "Graphics/i_object.h"
#include "Graphics/i_sensor.h"

# define DEF_NB_VFDIST	(float)200
# define DEF_NB_VFANGLE	(double)20
# define DEF_MAX_DIST	(double)5000
# define DEF_MIN_DIST	(double)-5000

class AIVisionField : public Graphics::ISensor
{
 public:
  AIVisionField(void);
  ~AIVisionField(void);

  /*
  ** Getters.
  */
  bool	isValid(Graphics::IObject *obj);

  /*
  ** Methods.
  */
  void	Update(Graphics::IObject *obj, std::list<Graphics::IObject *>& env);
};

#endif /* !AI_VISION_FIELD_H_ */
