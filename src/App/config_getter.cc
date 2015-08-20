//
// config_getter.cc for LoveBrains in /home/robin_f/Programming/Git/CPP/LoveBrains
// 
// Made by Guillaume ROBIN
// Login   <robin_f@epitech.eu>
// 
// Started on  Fri Jul 31 12:09:39 2015 Guillaume ROBIN
// Last update Thu Aug 20 13:31:29 2015 Guillaume ROBIN
//

#include <stdexcept>
#include <iostream>

#include "App/config_getter.h"
#include "App/app_const.h"
#include "Simulator/simulator_const.h"
#include "Simulator/simulator_exception.h"
#include "Graphics/graphics_const.h"
#include "ANN/tools.h"

namespace App
{
  void		config_getCrossingRate(Simulator::SConfig& config, std::string const& value)
  {
    double	rate;

    try
      {
	rate = std::stof(value);
      }
    catch (std::invalid_argument const& e)
      {
	rate = DEF_CROSSING_RATE;
	std::cerr << e.what() << std::endl;
      }
    try
      {
	config.setCrossingRate(rate);
      }
    catch (Simulator::SimulatorException const& e)
      {
	rate = DEF_CROSSING_RATE;
	config.setCrossingRate(rate);
	std::cerr << e.what() << std::endl;
      }
  }

  void		config_getMutationRate(Simulator::SConfig& config, std::string const& value)
  {
    double	rate;

    try
      {
	rate = std::stof(value);
      }
    catch (std::invalid_argument const& e)
      {
	rate = DEF_MUTATION_RATE;
	std::cerr << e.what() << std::endl;
      }
    try
      {
	config.setMutationRate(rate);
      }
    catch (Simulator::SimulatorException const& e)
      {
	rate = DEF_MUTATION_RATE;
	config.setMutationRate(rate);
	std::cerr << e.what() << std::endl;
      }
  }

  void		config_getSelectionRate(Simulator::SConfig& config, std::string const& value)
  {
    double	rate;

    try
      {
	rate = std::stof(value);
      }
    catch (std::invalid_argument const& e)
      {
	rate = DEF_SELECTION_RATE;
	std::cerr << e.what() << std::endl;
      }
    try
      {
	config.setSelectionRate(rate);
      }
    catch (Simulator::SimulatorException const& e)
      {
	rate = DEF_SELECTION_RATE;
	config.setSelectionRate(rate);
	std::cerr << e.what() << std::endl;
      }
  }

  void		config_getExpectedFitness(Simulator::SConfig& config, std::string const& value)
  {
    double	rate;

    try
      {
	rate = std::stof(value);
      }
    catch (std::invalid_argument const& e)
      {
	rate = DEF_MAX_RATE;
	std::cerr << e.what() << std::endl;
      }
    config.setExpectedFitness(rate);
  }

  void			config_getPoolSize(Simulator::SConfig& config, std::string const& value)
  {
    unsigned int	size;

    try
      {
	size = std::stoi(value);
      }
    catch (std::invalid_argument const& e)
      {
	size = DEF_POOL_SIZE;
	std::cerr << e.what() << std::endl;
      }
    try
      {
	config.setPoolSize(size);
      }
    catch (Simulator::SimulatorException const& e)
      {
	size = DEF_POOL_SIZE;
	config.setPoolSize(size);
	std::cerr << e.what() << std::endl;
      }
  }

  void 	config_getMaxEpochs(Simulator::SConfig& config, std::string const& value)
  {
    int	max_epochs;

    try
      {
	max_epochs = std::stoi(value);
      }
    catch (std::invalid_argument const& e)
      {
	max_epochs = DEF_MAX_EPOCHS;
	std::cerr << e.what() << std::endl;
      }
    config.setMaxEpochs(max_epochs);
  }

  void			config_getReportInterval(Simulator::SConfig& config,
						 std::string const& value)
  {
    unsigned int	interval;

    try
      {
	interval = std::stoi(value);
      }
    catch (std::invalid_argument const& e)
      {
	interval = DEF_REPORT_INTERVAL;
	std::cerr << e.what() << std::endl;
      }
    config.setReportInterval(interval);
  }

  void			config_getPopulationSize(Simulator::SConfig& config,
						 std::string const& value)
  {
    unsigned int	size;

    try
      {
	size = std::stoi(value);
      }
    catch (std::invalid_argument const& e)
      {
	size = DEF_POPULATION_SIZE;
	std::cerr << e.what() << std::endl;
      }
    try
      {
	config.setPopulationSize(size);
      }
    catch (Simulator::SimulatorException const& e)
      {
	size = DEF_POPULATION_SIZE;
	config.setPopulationSize(size);
	std::cerr << e.what() << std::endl;
      }
  }

  void	config_getANNInfos(Simulator::SConfig& config, std::string const& value)
  {
    unsigned int	pos = value.find(DEF_CONST_SPACESTR);
    std::string		infos = value;

    infos.erase(0, pos + 1);
    try
      {
	config.setANNInfos(infos);
      }
    catch (Simulator::SimulatorException const& e)
      {
	std::cerr << e.what() << std::endl;
      }
  }

  void	config_getActivation(Simulator::SConfig& config, std::string const& value)
  {
    try
      {
	if (value.find(DEF_FUNCTION_SIGMOID) != value.size())
	  config.setActivation(&GANN::Sigmoid, GANN::ANN::ActivationType::SIGMOID);
	else if (value.find(DEF_FUNCTION_THRESHOLD) != value.size())
	  config.setActivation(&GANN::Threshold, GANN::ANN::ActivationType::THRESHOLD);
	else
	  config.setActivation(&GANN::Sigmoid, GANN::ANN::ActivationType::SIGMOID);
      }
    catch (Simulator::SimulatorException const& e)
      {
	std::cerr << e.what() << std::endl;
      }
  }

  void	config_getOutputsActivation(Simulator::SConfig& config, std::string const& value)
  {
    try
      {
	if (value.find(DEF_FUNCTION_SIGMOID) != value.size())
	  config.setOutputsActivation(&GANN::Sigmoid, GANN::ANN::ActivationType::SIGMOID);
	else if (value.find(DEF_FUNCTION_THRESHOLD) != value.size())
	  config.setOutputsActivation(&GANN::Threshold, GANN::ANN::ActivationType::THRESHOLD);
	else
	  config.setOutputsActivation(&GANN::Sigmoid, GANN::ANN::ActivationType::SIGMOID);
      }
    catch (Simulator::SimulatorException const& e)
      {
	std::cerr << e.what() << std::endl;
      }
  }

  void			config_getEnvironmentSize(Simulator::SConfig& config,
						  std::string const& value)
  {
    unsigned int	pos = value.find(DEF_DELIMITER_SIZE);
    std::string		str_width = value.substr(0, pos);
    std::string		str_height = value;
    unsigned int	width;
    unsigned int	height;

    str_height.erase(0, pos + 1);
    try
      {
	width = std::stoi(str_width);
	height = std::stoi(str_height);
      }
    catch (std::invalid_argument const& e)
      {
	width = DEF_APP_WIDTH;
	height = DEF_APP_HEIGHT;
	std::cerr << e.what() << std::endl;
      }
    try
      {
	config.setEnvironmentSize(width, height);
      }
    catch (Simulator::SimulatorException const& e)
      {
	width = DEF_APP_WIDTH;
	height = DEF_APP_HEIGHT;
	config.setEnvironmentSize(width, height);
	std::cerr << e.what() << std::endl;
      }
  }
}
