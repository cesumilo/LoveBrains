//
// gann.cc for GANNEngine in /home/robin_f/Programming/Git/CPP/GANNEngine
// 
// Made by Guillaume ROBIN
// Login   <robin_f@epitech.eu>
// 
// Started on  Thu Jul  9 11:30:01 2015 Guillaume ROBIN
// Last update Tue Jul 28 19:03:40 2015 Guillaume ROBIN
//

#include <stdlib.h>
#include <time.h>

#include "GANN/gann_engine.h"
#include "GANN/gann_const.h"
#include "GA/ga_const.h"
#include "ANN/tools.h"

namespace GANN
{
  /*
  ** Constructor & Destructor.
  */
  GANNEngine::GANNEngine(void) throw(): _pool_size(DEF_POOL_SIZE), _mutation_rate(DEF_MUT_RATE),
				_selection_rate(DEF_SEL_RATE)
  {
    srand(time(NULL));
    _config.setDNACompare(&ANNComparator);
    _config.setDNACrossover(&ANNCrossover);
    _config.setDNAMutate(&ANNMutation);
  }

  GANNEngine::~GANNEngine(void) throw()
  {
  }

  /*
  ** Initializer.
  */
  void	GANNEngine::Init(GA::GAConfig const& config, unsigned int size)
  {
    _config = config;
    if (size < DEF_GANN_SIZE)
      throw (GANNException(ERR_GANN_INVSIZE));
    try
      {
	_engine.setMutationRate(_mutation_rate);
	_engine.setSelectionRate(_selection_rate);
	_engine.setPoolSize(_pool_size);
	_engine.CreatePopulation(_config, size);
      }
    catch (GA::GAEngineException const& e)
      {
	throw (GANNException(e.what()));
      }
  }

  /*
  ** Getters.
  */
  ANN const&				GANNEngine::getBestANN(void) const
  {
    std::list<GA::IDNA *>		dna;
    std::list<GA::IDNA *>::iterator	it;
    double				tmp = 0;
    GA::IDNA				*ptr = NULL;

    dna = _engine.getPopulation().get();
    it = dna.begin();
    ptr = *it;
    while (it != dna.end())
      {
	if (*it && (*it)->getFitness() > tmp)
	  {
	    tmp = (*it)->getFitness();
	    ptr = *it;
	  }
	++it;
      }
    if (!ptr)
      throw (GANNException(ERR_GANN_GETBESTANN));
    return (((GANN *)ptr)->getGenes());
  }

  GA::GAEngine&	GANNEngine::getGAEngine(void) throw()
  {
    return (_engine);
  }

  GA::GAEngine const&	GANNEngine::getGAEngine(void) const throw()
  {
    return (_engine);
  }

  GA::GAConfig const&	GANNEngine::getGAConfig(void) const throw()
  {
    return (_config);
  }

  /*
  ** Setter.
  */
  void	GANNEngine::setGAConfig(GA::GAConfig const& config)
  {
    if (!config.isValid())
      throw (GANNException(ERR_GANN_INVCONFIG));
    _config = config;
  }

  /*
  ** GA Methods.
  */
  bool	GANNEngine::ANNComparator(const GA::IDNA *b1, const GA::IDNA *b2)
  {
    return (b1->getFitness() >= b2->getFitness());
  }

  void				GANNEngine::ANNMutation(GA::IDNA *sample)
  {
    ANN				ann;
    std::vector<ANNLayer *>	list;
    unsigned int		index;
    unsigned int		r;
    Matrix<double>		m;

    if (sample)
      {
	list = ((GANN *)sample)->getGenes().getLayers();
	index = RandomInt(0, list.size());
	if (list[index])
	  {
	    if (RandomInt(0, 2) == 0)
	      {
		m = list[index]->getWeights();
		r = RandomInt(0, m.rows() * m.cols());
		m[r] = RandomDouble(ann.getMinRandom(), ann.getMaxRandom());
		(((GANN *)sample)->getGenes().getLayers())[index]->setWeights(m);
	      }
	    else
	      {
		m = list[index]->getBias();
		r = RandomInt(0, m.rows() * m.cols());
		m[r] = RandomDouble(ann.getMinRandom(), ann.getMaxRandom());
		(((GANN *)sample)->getGenes().getLayers())[index]->setBias(m);
	      }
	  }
	else
	  throw (GANNException(ERR_GANN_MUTATION));
      }
    else
      throw (GANNException(ERR_GANN_DNA));
  }

  /*
  ** Methods.
  */
  void	GANNEngine::StartSimulation(bool report)
  {
    try
      {
	_engine.Evolve(report);
      }
    catch (GA::GAEngineException& e)
      {
	throw (GANNException(e.what()));
      }
  }
}
