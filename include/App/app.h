/*
** app.h for LoveBrains in /home/robin_f/Programming/Git/CPP/LoveBrains
** 
** Made by Guillaume ROBIN
** Login   <robin_f@epitech.eu>
** 
** Started on  Fri Jul 31 11:35:32 2015 Guillaume ROBIN
** Last update Thu Aug 20 13:37:55 2015 Guillaume ROBIN
*/

#ifndef APP_H_
# define APP_H_

# include "App/app_exception.h"
# include "App/config_manager.h"
# include "Simulator/simulator.h"
# include "Plugin/plugin_manager.h"

namespace App
{
  class App
  {
  public:
    App(void) throw();
    ~App(void) throw();

    /*
    ** Getters.
    */
    ConfigManager const&	getConfigManager(void) const throw();
    const Simulator::Simulator	*getSimulator(void) const throw();

    /*
    ** Methods.
    */
    void	Run(const char *simulator_file, const char *environment_file,
		    const char *output_file);

  private:
    ConfigManager		_manager;
    Plugin::PluginManager	_plugins;
    Simulator::Simulator	*_simulator;
  };
}

#endif /* !APP_H_ */
