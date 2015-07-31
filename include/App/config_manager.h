/*
** config_manager.h for LoveBrains in /home/robin_f/Programming/Git/CPP/LoveBrains
** 
** Made by Guillaume ROBIN
** Login   <robin_f@epitech.eu>
** 
** Started on  Fri Jul 31 11:39:48 2015 Guillaume ROBIN
** Last update Fri Jul 31 13:17:21 2015 Guillaume ROBIN
*/

#ifndef CONFIG_MANAGER_H_
# define CONFIG_MANAGER_H_

# include "Simulator/simulator_config.h"

namespace App
{
  class ConfigManager
  {
  public:
    ConfigManager(void);
    ~ConfigManager(void);

    /*
    ** Getters.
    */
    Simulator::SConfig const&	getConfiguration(void) const;

    /*
    ** Methods.
    */
    void	getConfigFromFile(const char *path);

  private:
    Simulator::SConfig	_config;
  };
}

#endif /* !CONFIG_MANAGER_H_ */
