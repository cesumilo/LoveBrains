//
// main.cc for LoveBrains in /home/robin_f/Programming/Git/CPP/LoveBrains
// 
// Made by Guillaume ROBIN
// Login   <robin_f@epitech.eu>
// 
// Started on  Wed Jul 22 14:07:01 2015 Guillaume ROBIN
// Last update Thu Jul 30 19:38:15 2015 Guillaume ROBIN
//

#include <iostream>

#include "Simulator/simulator.h"
#include "Plugin/plugin_manager.h"
#include "Graphics/i_object.h"
#include "ANN/tools.h"

int			main(void)
{
  Simulator::SConfig	config;
  Simulator::Simulator	*simulator = new Simulator::Simulator();
  Plugin::PluginManager	pl_manager;

  if (simulator)
    {
      try
	{
	  pl_manager.LoadPlugins();
	  pl_manager.LoadObjects();
	}
      catch (Plugin::PluginException const& e)
	{
	  std::cerr << e.what() << std::endl;
	}
      try
	{
	  config.setANNInfos("10-2-1");
	  simulator->Init(config, "environment.conf");
	  Simulator::Simulator::Evaluate(simulator->getEngine().getGAEngine().getPopulation().get());
	}
      catch (Simulator::SimulatorException const& e)
	{
	  std::cerr << e.what() << std::endl;
	}
      delete(simulator);
      try
	{
	  pl_manager.ClosePlugins();
	}
      catch (Plugin::PluginException const& e)
	{
	  std::cerr << e.what() << std::endl;
	}
    }
  return (0);
}
