//
// simulator.cc for LoveBrains in /home/robin_f/Programming/Git/CPP/LoveBrains
// 
// Made by Guillaume ROBIN
// Login   <robin_f@epitech.eu>
// 
// Started on  Thu Jul 23 12:19:26 2015 Guillaume ROBIN
// Last update Thu Jul 30 19:45:37 2015 Guillaume ROBIN
//

#include <iostream>

#include "Simulator/simulator.h"
#include "Simulator/simulator_const.h"

namespace Simulator
{
  /*
  ** Static values.
  */
  Graphics::Environment	*Simulator::_env;

  /*
  ** Constructor & Destructor.
  */
  Simulator::Simulator(void) throw()
  {
  }

  Simulator::~Simulator(void) throw()
  {
    delete(_env);
    Graphics::FactoryObjects::DeleteAll();
  }

  /*
  ** Getters.
  */
  GANN::GANNEngine const&	Simulator::getEngine(void) const throw()
  {
    return (_engine);
  }

  GANN::GANNEngine&	Simulator::getEngine(void) throw()
  {
    return (_engine);
  }

  GANN::ANNGenerator const&	Simulator::getGenerator(void) const throw()
  {
    return (_generator);
  }

  GA::GAConfig const&	Simulator::getConfig(void) const throw()
  {
    return (_config);
  }

  /*
  ** Overload.
  */
  Simulator&	Simulator::operator=(Simulator const& simulator)
  {
    _engine = simulator.getEngine();
    _generator = simulator.getGenerator();
    _config = simulator.getConfig();
    return (*this);
  }

  /*
  ** Methods.
  */
  void	Simulator::Init(SConfig const& config, const char *file)
  {
    _env = new Graphics::Environment(config.getEnvironmentWidth(), config.getEnvironmentHeight());
    if (!_env)
      throw (SimulatorException(ERR_SIMULATOR_ENV));
    _env->LoadFromFile(file);
    _config = _engine.getGAConfig();
    _generator.init(config.getANNInfos(), config.getCrossingRate());
    _generator.setActivationFunction(config.getActivation());
    _generator.setOutputsActivation(config.getOutputsActivation());
    _config.setGenerator(&_generator);
    _config.setEvaluation(&Simulator::Evaluate);
    try
      {
	_engine.getGAEngine().setMutationRate(config.getMutationRate());
	_engine.getGAEngine().setSelectionRate(config.getSelectionRate());
	_engine.getGAEngine().setPoolSize(config.getPoolSize());
	_engine.getGAEngine().setReportInterval(config.getReportInterval());
	_engine.getGAEngine().setExpectedFitness(config.getExpectedFitness());
      }
    catch (GA::GAEngineException const& e)
      {
	throw (SimulatorException(e.what()));
      }
    try
      {
	_engine.Init(_config, config.getPopulationSize());
      }
    catch (GANN::GANNException const& e)
      {
	throw (SimulatorException(e.what()));
      }
  }

  void	Simulator::Evaluate(std::list<GA::IDNA *>& brains)
  {
    std::cout << "Size: " << brains.size() << std::endl;
    _env->Run();
  }
}
