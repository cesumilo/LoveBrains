/*
** config_getter.h for LoveBrains in /home/robin_f/Programming/Git/CPP/LoveBrains
** 
** Made by Guillaume ROBIN
** Login   <robin_f@epitech.eu>
** 
** Started on  Fri Jul 31 12:05:11 2015 Guillaume ROBIN
** Last update Tue Aug 25 12:05:17 2015 Guillaume ROBIN
*/

#ifndef CONFIG_GETTER_H_
# define CONFIG_GETTER_H_

# include <string>

# include "Simulator/simulator_config.h"

namespace App
{
  /*
  ** Typedef.
  */
  typedef void	(*ConfigGetter)(Simulator::SConfig&, std::string const&);

  /*
  ** Struct.
  */

  /*!
   * \brief Object which manage parsing of the configuration file.
   */
  typedef struct	s_config_getter
  {
    std::string		token;
    ConfigGetter	get;
  }			t_config_getter;

  /*
  ** Methods.
  */

  /*!
   * \brief Get the crossing rate from the configuration file.
   */
  void	config_getCrossingRate(Simulator::SConfig& config, std::string const& value);
  /*!
   * \brief Get the mutation rate from the configuration file.
   */
  void	config_getMutationRate(Simulator::SConfig& config, std::string const& value);
  /*!
   * \brief Get the selection rate from the configuration file.
   */
  void	config_getSelectionRate(Simulator::SConfig& config, std::string const& value);
  /*!
   * \brief Get the expected fitness from the configuration file.
   */
  void	config_getExpectedFitness(Simulator::SConfig& config, std::string const& value);
  /*!
   * \brief Get the pool size for the tournament from the configuration file.
   */
  void	config_getPoolSize(Simulator::SConfig& config, std::string const& value);
  /*!
   * \brief Get the maximum epochs from the configuration file.
   */
  void	config_getMaxEpochs(Simulator::SConfig& config, std::string const& value);
  /*!
   * \brief Get the report interval from the configuration file.
   */
  void	config_getReportInterval(Simulator::SConfig& config, std::string const& value);
  /*!
   * \brief Get the population size from the configuration file.
   */
  void	config_getPopulationSize(Simulator::SConfig& config, std::string const& value);
  /*!
   * \brief Get the neural network informations from the configuration file.
   */
  void	config_getANNInfos(Simulator::SConfig& config, std::string const& value);
  /*!
   * \brief Get the activation function for the intern layers, from the configuration file.
   */
  void	config_getActivation(Simulator::SConfig& config, std::string const& value);
  /*!
   * \brief Get the activation function for the output layer, from the configuration file.
   */
  void	config_getOutputsActivation(Simulator::SConfig& config, std::string const& value);
  /*!
   * \brief Get the environment size (window size) from the configuration file.
   */
  void	config_getEnvironmentSize(Simulator::SConfig& config, std::string const& value);
  /*!
   * \brief Get if it's a tournament from the configuration file.
   */
  void	config_getIsTournament(Simulator::SConfig& config, std::string const& value);
  /*!
   * \brief Get the display mode of the environment.
   */
  void	config_getDisplayMode(Simulator::SConfig& config, std::string const& value);
}

#endif /* !CONFIG_GETTER_H_ */
