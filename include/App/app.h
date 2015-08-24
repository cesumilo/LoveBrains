/*
** app.h for LoveBrains in /home/robin_f/Programming/Git/CPP/LoveBrains
** 
** Made by Guillaume ROBIN
** Login   <robin_f@epitech.eu>
** 
** Started on  Fri Jul 31 11:35:32 2015 Guillaume ROBIN
** Last update Mon Aug 24 13:42:36 2015 Guillaume ROBIN
*/

#ifndef APP_H_
# define APP_H_

/*!
 * \file app.h
 * \brief this file define the application called LoveBrains.
 * \author Guillaume ROBIN
 * \date Thursday, 20 August
 * \version 1.0.0
 */

# include "App/app_exception.h"
# include "App/config_manager.h"
# include "Simulator/simulator.h"
# include "Plugin/plugin_manager.h"

namespace App
{
  /*!
   * \namespace App
   * \brief Contains all the tools which compose the application.
   */

  /*!
   * \brief Manage all the stuff in order to run the simulation.
   */
  class App
  {
  public:
    /*!
     * \brief Constructor
     */
    App(void) throw();
    /*!
     * \brief Destructor
     */
    ~App(void) throw();

    /*
    ** Getters.
    */

    /*!
     * \brief Get the configuration manager.
     */
    ConfigManager const&	getConfigManager(void) const throw();
    /*!
     * \brief Get the simulator object.
     */
    const Simulator::Simulator	*getSimulator(void) const throw();

    /*
    ** Methods.
    */
    /*!
     * \brief Initialize the application.
     * \param simulator_file : the simulation file's path.
     * \param environment_file : the environment file's path.
     * \return error : AppException
     */
    void	Init(const char *simulator_file, const char *environment_file);
    /*!
     * \brief Run the application and launch the simulation.
     * \param output_file : the output file's path.
     * \return error : AppException
     */
    void	Run(const char *output_file);

  private:
    ConfigManager		_manager; /*!< Manage the simulator configuration */
    Plugin::PluginManager	_plugins; /*!< Manage the plugin part of the software */
    Simulator::Simulator	*_simulator; /*!< Manage the simulation of the environment */
  };
}

#endif /* !APP_H_ */
