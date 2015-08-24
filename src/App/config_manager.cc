//
// config_manager.cc for LoveBrains in /home/robin_f/Programming/Git/CPP/LoveBrains
// 
// Made by Guillaume ROBIN
// Login   <robin_f@epitech.eu>
// 
// Started on  Fri Jul 31 11:43:33 2015 Guillaume ROBIN
// Last update Mon Aug 24 14:32:00 2015 Guillaume ROBIN
//

#include <fstream>
#include <iostream>
#include <string>

#include "App/config_manager.h"
#include "App/app_const.h"
#include "App/config_getter.h"

namespace App
{
  static t_config_getter	g_getters[DEF_MAX_GETTERS] =
  {
    {std::string(DEF_GET_CROSSING_RATE), &config_getCrossingRate},
    {std::string(DEF_GET_MUTATION_RATE), &config_getMutationRate},
    {std::string(DEF_GET_SELECTION_RATE), &config_getSelectionRate},
    {std::string(DEF_GET_EXPECTED_FIT), &config_getExpectedFitness},
    {std::string(DEF_GET_POOL_SIZE), &config_getPoolSize},
    {std::string(DEF_GET_MAX_EPOCHS), &config_getMaxEpochs},
    {std::string(DEF_GET_REPORT_INTER), &config_getReportInterval},
    {std::string(DEF_GET_POPULATION_SIZ), &config_getPopulationSize},
    {std::string(DEF_GET_ANNINFOS), &config_getANNInfos},
    {std::string(DEF_GET_ACTIVATION), &config_getActivation},
    {std::string(DEF_GET_OACTIVATION), config_getOutputsActivation},
    {std::string(DEF_GET_ENVIRONMENT_S), &config_getEnvironmentSize},
    {std::string(DEF_GET_TOURNAMENT), &config_getIsTournament}
  };

  /*
  ** Constructor & Destructor.
  */
  ConfigManager::ConfigManager(void)
  {
  }

  ConfigManager::~ConfigManager(void)
  {
  }

  /*
  ** Getters.
  */
  Simulator::SConfig const&	ConfigManager::getConfiguration(void) const
  {
    return (_config);
  }

  /*
  ** Methods.
  */
  static bool	isValidLine(std::string const& line)
  {
    for (unsigned int i = 0; i < line.size(); ++i)
      {
	if ((line[i] < DEF_CONST_MINCHAR || line[i] > DEF_CONST_MAXCHAR)
	    && line[i] != DEF_CONST_DELIMCHAR && line[i] != DEF_CONST_SPCHAR
	    && line[i] != DEF_CONST_UNDERSCHAR && line[i] != DEF_CONST_DASHCHAR
	    && (line[i] < DEF_CONST_MINNUMCHAR || line[i] > DEF_CONST_MAXNUMCHAR))
	  return (false);
      }
    return (true);
  }

  static void	getConfig(Simulator::SConfig& config, std::string& line)
  {
    unsigned int	pos = line.find(DEF_CONST_DELIMSTR);
    std::string		token = line.substr(0, pos);
    unsigned int	index = 0;

    line.erase(0, pos + 1);
    while (index < DEF_MAX_GETTERS && token != g_getters[index].token)
      ++index;
    if (index < DEF_MAX_GETTERS)
      g_getters[index].get(config, line);
    else
      std::cerr << ERR_APP_UNEXPECTED_TOK << token << std::endl;
  }

  void			ConfigManager::getConfigFromFile(const char *path)
  {
    std::ifstream	file(path);
    std::string		line;

    if (file)
      {
	while (std::getline(file, line))
	  {
	    if (!isValidLine(line))
	      continue ;
	    getConfig(_config, line);
	  }
      }
    else
      std::cerr << ERR_APP_INVALIDCONF << std::endl;
  }
}
