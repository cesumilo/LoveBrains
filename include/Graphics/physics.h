/*
** physics.h for LoveBrains in /home/robin_f/Programming/Git/CPP/LoveBrains
** 
** Made by Guillaume ROBIN
** Login   <robin_f@epitech.eu>
** 
** Started on  Wed Jul 22 14:41:22 2015 Guillaume ROBIN
** Last update Thu Jul 30 17:09:59 2015 Guillaume ROBIN
*/

#ifndef PHYSICS_H_
# define PHYSICS_H_

# include <vector>
# include <map>

# include "Graphics/factory_object.h"
# include "Graphics/i_collider.h"
# include "Graphics/i_sensor.h"

namespace Graphics
{
  class Physics
  {
  public:
    Physics(void);
    ~Physics(void);

    /*
    ** Getters.
    */
    std::vector<ICollider *> const&	getColliders(void) const;
    std::vector<ISensor *> const&	getSensors(void) const;
    /* TODO: maybe optimize those 3 maps */
    std::map<std::string, int> const&	getEnvironmentSettings(void) const;
    std::map<std::string, int> const&	getCurrentEnvironment(void) const;
    std::map<std::string, bool> const&	getGenerationSettings(void) const;

    /*
    ** Setters.
    */
    void	addCollider(ICollider *collider);
    void	addSensor(ISensor *sensor);
    void	addGenerationSetting(std::string type, bool generate);

    /*
    ** Methods.
    */
    void	LoadEnvironmentSettings(std::list<IObject *>& env);
    void	UpdateEnvironment(std::list<IObject *>& env);
    void	UpdateColliders(std::list<IObject *>& env) const;
    void	UpdateSensors(std::list<IObject *>& env) const;

    /*
    ** Overload.
    */
    Physics&	operator=(Physics const& physics);

  private:
    FactoryObjects		_factory;
    std::vector<ICollider *>	_colls;
    std::vector<ISensor *>	_sensors;
    std::map<std::string, int>	_env_settings;
    std::map<std::string, bool>	_gen_settings;
    std::map<std::string, int>	_cur_settings;
  };
}

#endif /* !PHYSICS_H_ */
