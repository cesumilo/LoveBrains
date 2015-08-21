//
// ga_engine.cc for GAEngine in /home/robin_f/Programming/Git/CPP/GAEngine
// 
// Made by Guillaume ROBIN
// Login   <robin_f@epitech.eu>
// 
// Started on  Fri Jul 17 16:35:52 2015 Guillaume ROBIN
// Last update Wed Jul 29 14:04:31 2015 Guillaume ROBIN
//

#include <iostream>

#include "GA/ga_engine.h"
#include "GA/ga_const.h"

namespace GA
{
  /*
  ** Constructor & Destructor.
  */
  GAEngine::GAEngine(void): _evaluate(NULL), _max_epochs(DEF_MAX_EPOCHS),
			    _report_interval(DEF_INT_REPORT), _nb_threads(DEF_NUM_THREAD),
			    _expected_fitness(DEF_EXPEC_FIT)
  {
    _state = AObserver::States::NONE;
    srand(time(NULL));
    setId();
  }

  GAEngine::~GAEngine(void)
  {
  }

  /*
  ** Getters.
  */
  Population const&	GAEngine::getPopulation(void) const throw()
  {
    return (_pop);
  }

  Population&		GAEngine::getPopulation(void) throw()
  {
    return (_pop);
  }

  double	GAEngine::getMutationRate(void) const throw()
  {
    return (_pop.getMutationRate());
  }

  double	GAEngine::getSelectionRate(void) const throw()
  {
    return (_pop.getSelectionRate());
  }

  unsigned int	GAEngine::getPoolSize(void) const throw()
  {
    return (_pop.getPoolSize());
  }

  GA::GAConfig::FEvaluate	GAEngine::getEvaluation(void) const throw()
  {
    return (_evaluate);
  }

  int	GAEngine::getMaxEpochs(void) const throw()
  {
    return (_max_epochs);
  }

  unsigned int	GAEngine::getReportInterval(void) const throw()
  {
    return (_report_interval);
  }

  unsigned int	GAEngine::getNumberOfThread(void) const throw()
  {
    return (_nb_threads);
  }

  double	GAEngine::getExpectedFitness(void) const throw()
  {
    return (_expected_fitness);
  }

  /*
  ** Setters.
  */
  void	GAEngine::setMaxEpochs(int max) throw()
  {
    _max_epochs = max;
  }

  void	GAEngine::setExpectedFitness(double fitness) throw()
  {
    _expected_fitness = ABS(fitness);
  }

  void	GAEngine::setNumberOfThreads(unsigned int num) throw()
  {
    _nb_threads = num;
  }

  void	GAEngine::setReportInterval(unsigned int num) throw()
  {
    if (num == 0)
      num = 1;
    _report_interval = num;
  }

  void	GAEngine::setMutationRate(double rate)
  {
    try
      {
	_pop.setMutationRate(rate);
      }
    catch (PopulationException& e)
      {
	throw (GAEngineException(e.what()));
      }
  }

  void	GAEngine::setSelectionRate(double rate)
  {
    try
      {
	_pop.setSelectionRate(rate);
      }
    catch (PopulationException& e)
      {
	throw (GAEngineException(e.what()));
      }
  }

  void	GAEngine::setPoolSize(unsigned int size)
  {
    try
      {
	_pop.setPoolSize(size);
      }
    catch (PopulationException& e)
      {
	throw (GAEngineException(e.what()));
      }
  }

  /*
  ** Overload.
  */
  GAEngine&	GAEngine::operator=(GAEngine const& engine)
  {
    _evaluate = engine.getEvaluation();
    _max_epochs = engine.getMaxEpochs();
    _report_interval = engine.getReportInterval();
    _nb_threads = engine.getNumberOfThread();
    _expected_fitness = engine.getExpectedFitness();
    _pop = engine.getPopulation();
    return (*this);
  }

  /*
  ** Methods.
  */
  void	GAEngine::CreatePopulation(GAConfig const& config, unsigned int size)
  {
    _evaluate = config.getEvaluation();
    if (size >= DEF_MIN_SIZE)
      {
	try
	  {
	    _pop.setSize(size);
	    _pop.setConfig(config);
	    _pop.Generate();
	  }
	catch (PopulationException const& e)
	  {
	    throw (GAEngineException(e.what()));
	  }
      }
    else
      std::cerr << ERR_GA_POPSIZE << std::endl;
  }

  unsigned int		GAEngine::Evolve(bool report)
  {
    unsigned int	epochs = 0;

    try
      {
	if (!_evaluate)
	  _pop.Evaluate(_nb_threads);
	else
	  _evaluate(_pop.get());
	while (_pop.getBestFitness() < _expected_fitness && IF_EPOCHS((int)epochs, _max_epochs)
	       && _state != AObserver::States::QUIT)
	  {
	    _pop.Selection();
	    _pop.Crossover();
	    _pop.Mutation();
	    if (!_evaluate)
	      _pop.Evaluate(_nb_threads);
	    else
	      _evaluate(_pop.get());
	    if ((report && epochs % _report_interval == 0) || _state == AObserver::States::REPORT)
	      std::cout << STR_GA_EPOCHS << epochs << std::endl << _pop << std::endl;
	    epochs++;
	  }
      }
    catch (PopulationException& e)
      {
	throw (GAEngineException(e.what()));
      }
    return (epochs);
  }
}
