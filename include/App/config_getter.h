/*
** config_getter.h for LoveBrains in /home/robin_f/Programming/Git/CPP/LoveBrains
** 
** Made by Guillaume ROBIN
** Login   <robin_f@epitech.eu>
** 
** Started on  Fri Jul 31 12:05:11 2015 Guillaume ROBIN
** Last update Fri Jul 31 13:06:04 2015 Guillaume ROBIN
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
  typedef struct	s_config_getter
  {
    std::string		token;
    ConfigGetter	get;
  }			t_config_getter;

  /*
  ** Methods.
  */
  void	config_getCrossingRate(Simulator::SConfig& config, std::string const& value);
  void	config_getMutationRate(Simulator::SConfig& config, std::string const& value);
  void	config_getSelectionRate(Simulator::SConfig& config, std::string const& value);
  void	config_getExpectedFitness(Simulator::SConfig& config, std::string const& value);
  void	config_getPoolSize(Simulator::SConfig& config, std::string const& value);
  void	config_getMaxEpochs(Simulator::SConfig& config, std::string const& value);
  void	config_getReportInterval(Simulator::SConfig& config, std::string const& value);
  void	config_getPopulationSize(Simulator::SConfig& config, std::string const& value);
  void	config_getANNInfos(Simulator::SConfig& config, std::string const& value);
  void	config_getActivation(Simulator::SConfig& config, std::string const& value);
  void	config_getOutputsActivation(Simulator::SConfig& config, std::string const& value);
  void	config_getEnvironmentSize(Simulator::SConfig& config, std::string const& value);
}

#endif /* !CONFIG_GETTER_H_ */
