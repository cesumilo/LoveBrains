/*
** physics.h for LoveBrains in /home/robin_f/Programming/Git/CPP/LoveBrains
** 
** Made by Guillaume ROBIN
** Login   <robin_f@epitech.eu>
** 
** Started on  Wed Jul 22 14:41:22 2015 Guillaume ROBIN
** Last update Fri Aug 21 15:52:58 2015 Guillaume ROBIN
*/

#ifndef PHYSICS_H_
# define PHYSICS_H_

# include <vector>
# include <map>

# include "Graphics/factory_object.h"
# include "Graphics/i_collider.h"
# include "Graphics/i_sensor.h"
# include "GA/i_dna.h"

namespace Graphics
{
  /*!
   * \class Physics
   * \brief Define the physics engine used by the environment.
   */
  class Physics
  {
  public:
    /*!
     * \brief Constructor.
     */
    Physics(void);
    /*!
     * \brief Destructor.
     */
    ~Physics(void);

    /*
    ** Getters.
    */

    /*!
     * \brief Get all the colliders that are managed by the physics engine.
     * \return std::vector<ICollider *> const&
     */
    std::vector<ICollider *> const&	getColliders(void) const;
    /*!
     * \brief Get all the sensors that are managed by the physics engine.
     * \return std::vector<ISensor *> const&
     */
    std::vector<ISensor *> const&	getSensors(void) const;
    /* TODO: maybe optimize those 3 maps */
    /*!
     * \brief Get the environment settings that are contained in a map.
     * \return std::map<std::string, int> const&
     */
    std::map<std::string, int> const&	getEnvironmentSettings(void) const;
    /*!
     * \brief Get the current state of the environment settings that are contained in a map.
     * \return std::map<std::string, int> const&
     */
    std::map<std::string, int> const&	getCurrentEnvironment(void) const;
    /*!
     * \brief Get the generation settings that are contained in a map.
     * \return std::map<std::string, bool> const&
     */
    std::map<std::string, bool> const&	getGenerationSettings(void) const;

    /*
    ** Setters.
    */

    /*!
     * \brief Add a new collider to the physics engine.
     * \param collider : Contains the new ICollider.
     */
    void	addCollider(ICollider *collider);
    /*!
     * \brief Add a new sensor to the physics engine.
     * \param sensor : Contains the new ISensor.
     */
    void	addSensor(ISensor *sensor);
    /*!
     * \brief Add a new generator setting to the physics engine.
     * \param type : Contains the key of the setting.
     * \param generate : true if it's generated on each death, or false.
     */
    void	addGenerationSetting(std::string type, bool generate);

    /*
    ** Methods.
    */

    /*!
     * \brief Load the environment settings from the environment.
     * \param env : Contains all the objects in the environment.
     */
    void	LoadEnvironmentSettings(std::list<IObject *>& env);
    /*!
     * \brief Update the environment.
     * \param env : Contains all the objects in the environment.
     */
    void	UpdateEnvironment(std::list<IObject *>& env);
    /*!
     * \brief Update all the colliders in the physics engine.
     * \param env : Contains all the objects in the environment.
     */
    void	UpdateColliders(std::list<IObject *>& env) const;
    /*!
     * \brief Update all the sensors in the physics engine.
     * \param env : Contains all the objects in the environment.
     */
    void	UpdateSensors(std::list<IObject *>& env) const;
    /*!
     * \brief Generate the environment in terms of the environment settings.
     * \param env : Contains all the objects in the environment.
     * \param brains : Contains all the neural networks.
     */
    void	GenerateEnvironment(std::list<IObject *>& env, std::list<GA::IDNA *>& brains);

    /*
    ** Overload.
    */
    Physics&	operator=(Physics const& physics);

  private:
    FactoryObjects		_factory; /*!< Contains the objects factory. */
    std::vector<ICollider *>	_colls; /*!< Contains all the colliders that are provided by plugins. */
    std::vector<ISensor *>	_sensors; /*!< Contains all the sensors that are provided by plugins. */
    std::map<std::string, int>	_env_settings; /*!< Contains the environment settings. */
    std::map<std::string, bool>	_gen_settings; /*!< Contains the generation settings. */
    std::map<std::string, int>	_cur_settings; /*!< Contains the current state of the environment. */
  };
}

#endif /* !PHYSICS_H_ */
