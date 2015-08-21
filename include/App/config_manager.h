/*
** config_manager.h for LoveBrains in /home/robin_f/Programming/Git/CPP/LoveBrains
** 
** Made by Guillaume ROBIN
** Login   <robin_f@epitech.eu>
** 
** Started on  Fri Jul 31 11:39:48 2015 Guillaume ROBIN
** Last update Fri Aug 21 05:39:15 2015 Guillaume ROBIN
*/

#ifndef CONFIG_MANAGER_H_
# define CONFIG_MANAGER_H_

# include "Simulator/simulator_config.h"

namespace App
{
  /*!
   * \brief Manage the configuration of the simulator and the engines.
   */
  class ConfigManager
  {
  public:
    /*!
     * \brief Constructor.
     */
    ConfigManager(void);
    /*!
     * \brief Destructor.
     */
    ~ConfigManager(void);

    /*
    ** Getters.
    */

    /*!
     * \brief Get the configuration object of class "SConfig".
     * \return Simulator::SConfig const&
     */
    Simulator::SConfig const&	getConfiguration(void) const;

    /*
    ** Methods.
    */

    /*!
     * \brief Get the configuration of the simulator from a file.
     * \param path : the path to the configuration file.
     */
    void	getConfigFromFile(const char *path);

  private:
    Simulator::SConfig	_config; /*!< Contains the simulator's configuration */
  };
}

#endif /* !CONFIG_MANAGER_H_ */
