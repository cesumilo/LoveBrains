//
// i_config.cc for GAEngine in /home/robin_f/Programming/Git/CPP/GAEngine
// 
// Made by Guillaume ROBIN
// Login   <robin_f@epitech.eu>
// 
// Started on  Tue Jul 21 13:28:58 2015 Guillaume ROBIN
// Last update Tue Jul 28 19:07:21 2015 Guillaume ROBIN
//

#include <cstdlib>

#include "GA/ga_config.h"

namespace GA
{
  /*
  ** Constructor & Destructor.
  */
  GAConfig::GAConfig(void): _evaluate(NULL), _generator(NULL), _fitness(NULL), _compare(NULL),
			    _crossover(NULL), _mutate(NULL)
  {
  }

  GAConfig::~GAConfig(void)
  {
  }

  /*
  ** Overload.
  */
  GAConfig&	GAConfig::operator=(GAConfig const& config)
  {
    _evaluate = config.getEvaluation();
    _generator = config.getGenerator();
    _fitness = config.getDNAFitness();
    _compare = config.getDNACompare();
    _crossover = config.getDNACrossover();
    _mutate = config.getDNAMutate();
    return (*this);
  }

  /*
  ** Methods.
  */
  bool	GAConfig::isEvaluated(void) const
  {
    return (_evaluate != NULL);
  }

  bool	GAConfig::isValid(void) const
  {
    if (!_generator)
      return (false);
    if (!_fitness && !_evaluate)
      return (false);
    if (!_compare)
      return (false);
    if (!_crossover)
      return (false);
    if (!_mutate)
      return (false);
    return (true);
  }

  /*
  ** Setters.
  */
  void	GAConfig::setEvaluation(GAConfig::FEvaluate function)
  {
    _evaluate = function;
  }

  void	GAConfig::setGenerator(IGenerator *generator)
  {
    _generator = generator;
  }

  void	GAConfig::setDNAFitness(GAConfig::DNAFitness function)
  {
    _fitness = function;
  }

  void	GAConfig::setDNACompare(GAConfig::DNACompare function)
  {
    _compare = function;
  }

  void	GAConfig::setDNACrossover(GAConfig::DNACrossover function)
  {
    _crossover = function;
  }

  void	GAConfig::setDNAMutate(GAConfig::DNAMutate function)
  {
    _mutate = function;
  }

  /*
  ** Getters.
  */
  GAConfig::FEvaluate	GAConfig::getEvaluation(void) const
  {
    return (_evaluate);
  }

  IGenerator	*GAConfig::getGenerator(void) const
  {
    return (_generator);
  }

  GAConfig::DNAFitness	GAConfig::getDNAFitness(void) const
  {
    return (_fitness);
  }

  GAConfig::DNACompare	GAConfig::getDNACompare(void) const
  {
    return (_compare);
  }

  GAConfig::DNACrossover	GAConfig::getDNACrossover(void) const
  {
    return (_crossover);
  }

  GAConfig::DNAMutate	GAConfig::getDNAMutate(void) const
  {
    return (_mutate);
  }
}
