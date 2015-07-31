//
// app.cc for LoveBrains in /home/robin_f/Programming/Git/CPP/LoveBrains
// 
// Made by Guillaume ROBIN
// Login   <robin_f@epitech.eu>
// 
// Started on  Fri Jul 31 13:33:16 2015 Guillaume ROBIN
// Last update Fri Jul 31 16:04:17 2015 Guillaume ROBIN
//

#include "App/app.h"
#include "App/app_const.h"
#include "Graphics/graphics_const.h"

namespace App
{
  /*
  ** Constructor & Destructor.
  */
  App::App(void) throw()
  {
  }

  App::~App(void) throw()
  {
  }

  /*
  ** Getters.
  */
  ConfigManager const&	App::getConfigManager(void) const throw()
  {
    return (_manager);
  }

  const Simulator::Simulator	*App::getSimulator(void) const throw()
  {
    return (_simulator);
  }

  /*
  ** Methods.
  */
  static bool	isThereBrains(std::list<Graphics::IObject *>& env)
  {
    for (std::list<Graphics::IObject *>::iterator it = env.begin(); it != env.end(); ++it)
      {
	if ((*it)->hasBrain())
	  return (true);
      }
    return (false);
  }

  void	App::Run(const char *simulator_file, const char *environment_file)
  {
    Graphics::FactoryObjects	factory;

    if (!(_simulator = new Simulator::Simulator()))
      throw (AppException(ERR_APP_SIMULATOR));

    _manager.getConfigFromFile(simulator_file);
    try
      {
	_simulator->InitEnvironment(_manager.getConfiguration());
      }
    catch (Simulator::SimulatorException const& e)
      {
	throw (AppException(e.what()));
      }
    try
      {
	_plugins.LoadPlugins();
	_plugins.LoadObjects();
	_plugins.LoadColliders(_simulator->getPhysicsEngine());
	_plugins.LoadSensors(_simulator->getPhysicsEngine());
      }
    catch (Plugin::PluginException const& e)
      {
	throw (AppException(e.what()));
      }
    try
      {
	_simulator->Init(_manager.getConfiguration(), environment_file);
      }
    catch (Simulator::SimulatorException const& e)
      {
	throw (AppException(e.what()));
      }
    if (isThereBrains(_simulator->getObjects()))
      {
	try
	  {
	    _simulator->Run();
	  }
	catch (Simulator::SimulatorException const& e)
	  {
	    throw (AppException(e.what()));
	  }
      }
    else
      throw (AppException(ERR_APP_NEEDIA));
    delete(_simulator);
    try
      {
	_plugins.ClosePlugins();
      }
    catch (Plugin::PluginException const& e)
      {
	throw (AppException(e.what()));
      }
  }
}
