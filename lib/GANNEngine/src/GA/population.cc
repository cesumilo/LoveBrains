//
// population.cc for GAEngine in /home/robin_f/Programming/Git/CPP/GAEngine
// 
// Made by Guillaume ROBIN
// Login   <robin_f@epitech.eu>
// 
// Started on  Fri Jul 17 16:15:09 2015 Guillaume ROBIN
// Last update Tue Jul 28 18:17:13 2015 Guillaume ROBIN
//

# include <thread>
# include <stdlib.h>
# include <time.h>
# include <random>

#include "GA/population.h"
#include "GA/ga_const.h"

namespace GA
{
  /*
  ** Constructor & Destructor.
  */
  Population::Population(void) throw(): _size(0), _pool_size(DEF_POOL_SIZE),
					_mutation_rate(DEF_MUT_RATE),
					_selection_rate(DEF_SEL_RATE), _best_fitness(0),
					_avg_fitness(0)
  {
    srand(time(NULL));
  }

  Population::Population(GAConfig const& config, unsigned int size): Population()
  {
    if (!config.isValid())
      throw (PopulationException(ERR_GA_NOCONF));
    _config = config;
    if (size < DEF_MIN_SIZE)
      throw (PopulationException(ERR_POP_SIZE));
    _size = size;
  }

  Population::~Population(void) throw()
  {
    for (std::list<IDNA *>::iterator it = _samples.begin(); it != _samples.end(); ++it)
      delete(*it);
  }

  /*
  ** Overlaod.
  */
  Population&		Population::operator=(Population const& pop) throw()
  {
    std::list<IDNA *>	samples = pop.get();

    _size = pop.getSize();
    _pool_size = pop.getPoolSize();
    _mutation_rate = pop.getMutationRate();
    _selection_rate = pop.getSelectionRate();
    _best_fitness = 0;
    _avg_fitness = 0;
    _config = pop.getConfig();
    for (std::list<IDNA *>::iterator it=samples.begin(); it != samples.end(); ++it)
      _samples.push_back(*it);
    return (*this);
  }

  /*
  ** Initializer.
  */
  void		Population::Generate(void)
  {
    IDNA	*sample;

    for (unsigned int i = 0; i < _size; i++)
      {
	if (!(sample = _config.getGenerator()->Generate()))
	  throw (PopulationException(ERR_POP_GEN));
	else
	  _samples.push_back(sample);
      }
  }

  /*
  ** Getters.
  */
  unsigned int	Population::getSize(void) const throw()
  {
    return (_size);
  }

  unsigned int	Population::getPoolSize(void) const throw()
  {
    return (_pool_size);
  }

  double	Population::getMutationRate(void) const throw()
  {
    return (_mutation_rate);
  }

  double	Population::getSelectionRate(void) const throw()
  {
    return (_selection_rate);
  }

  double	Population::getBestFitness(void) const throw()
  {
    return (_best_fitness);
  }

  double	Population::getAverageFitness(void) const throw()
  {
    return (_avg_fitness);
  }

  GAConfig const&	Population::getConfig(void) const throw()
  {
    return (_config);
  }

  std::list<IDNA *> const&	Population::get(void) const throw()
  {
    return (_samples);
  }

  std::list<IDNA *>&	Population::get(void) throw()
  {
    return (_samples);
  }

  /*
  ** Setters.
  */
  void	Population::setSize(unsigned int size)
  {
    if (size < DEF_MIN_SIZE)
      throw (PopulationException(ERR_POP_SIZE));
    _size = size;
  }

  void	Population::setPoolSize(unsigned int size)
  {
    if (size < DEF_MIN_SIZE)
      throw (PopulationException(ERR_POP_PSIZE));
    _pool_size = size;
  }

  void	Population::setMutationRate(double rate)
  {
    if (rate < 0 || rate > 1)
      throw (PopulationException(ERR_POP_MUT));
    _mutation_rate = rate;
  }

  void	Population::setSelectionRate(double rate)
  {
    if (rate < 0 || rate > 1)
      throw (PopulationException(ERR_POP_SELT));
    _selection_rate = rate;
  }

  void	Population::setConfig(GAConfig const& config)
  {
    if (!config.isValid())
      throw (PopulationException(ERR_GA_NOCONF));
    _config = config;
  }

  /*
  ** Genetic : Evaluate.
  */
  void				Population::Evaluate(unsigned int nbThread)
  {
    double			sum_fitness = 0;
    double			*tmp = new double[nbThread];
    double			temp;
    unsigned int		rest_size;
    unsigned int		size_per_thread;
    std::thread			*threads = new std::thread[nbThread];
    std::list<IDNA *>::iterator	it = _samples.begin();

    if (!tmp || !threads || !_config.isValid())
      throw (PopulationException(ERR_POP_EVAL));
    if (nbThread >= DEF_MIN_SIZE)
      {
	rest_size = _size % nbThread;
	size_per_thread = _size / nbThread;
      }
    else
      {
	rest_size = _size;
	size_per_thread = 0;
      }
    _best_fitness = 0;
    while (size_per_thread > 0)
      {
	for (unsigned int i = 0; i < nbThread; i++)
	  {
	    threads[i] = std::thread(_config.getDNAFitness(), *it, &(tmp[i]));
	    it++;
	  }
	for (unsigned int i = 0; i < nbThread; i++)
	  threads[i].join();
	for (unsigned int i = 0; i < nbThread; i++)
	  {
	    if (tmp[i] > _best_fitness)
	      _best_fitness = tmp[i];
	    sum_fitness += tmp[i];
	  }
	size_per_thread--;
      }
    while (rest_size > 0)
      {
	(_config.getDNAFitness())(*it, &temp);
	if (temp > _best_fitness)
	  _best_fitness = temp;
	sum_fitness += temp;
	it++;
	rest_size--;
      }
    _avg_fitness = sum_fitness / (double)_size;
    delete[](threads);
    delete[](tmp);
  }

  /*
  ** Genetic : Selection.
  */
  static IDNA		*getDNAByIdx(std::list<IDNA *> samples, unsigned int index)
  {
    unsigned int	i = 0;

    for (std::list<IDNA *>::iterator it = samples.begin(); it != samples.end(); it++)
      {
	if (i == index)
	  return (*it);
	i++;
      }
    return (NULL);
  }

  static int	RandomInt(int min, int max)
  {
    return (rand() % (max - min) + min);
  }

  void			Population::Selection(void) throw()
  {
    unsigned int     	nbSelected = 0;
    unsigned int     	nbChild = _size * _selection_rate;
    std::list<IDNA *>	list;

    if (_samples.size() > 0)
      {
	_parents.clear();
	while (nbSelected < nbChild)
	  {
	    for (unsigned int i = 0; i < 2; i++)
	      {
		for (unsigned int i = 0; i < _pool_size; i++)
		  list.push_back(getDNAByIdx(_samples, RandomInt(0, _size)));
		list.sort(_config.getDNACompare());
		_parents.push_back(list.front());
		list.clear();
	      }
	    nbSelected++;
	  }
      }
  }

  /*
  ** Genetic : Crossover.
  */
  static void		PreparePopulation(std::vector<IDNA *>& keep, std::vector<IDNA *>& rm,
					  std::list<IDNA *>& samples, unsigned int keep_size)
  {
    unsigned int	count = 0;

    for (std::list<IDNA *>::iterator it = samples.begin(); it != samples.end(); it++)
      {
	if (count < keep_size)
	  keep.push_back(*it);
	else
	  rm.push_back(*it);
      }
    samples.clear();
  }

  void			Population::Crossover(void)
  {
    std::vector<IDNA *>	keep;
    std::vector<IDNA *>	rm;
    IDNA	       	*s1;
    IDNA	       	*s2;
    unsigned int       	keep_size = _size - (_size * _selection_rate);

    _samples.sort(_config.getDNACompare());
    PreparePopulation(keep, rm, _samples, keep_size);
    for (unsigned int i = 0; i < _parents.size() - 1; i++)
      {
	s1 = (_config.getDNACrossover())(_parents[i], _parents[i + 1]);
	s2 = (_config.getDNACrossover())(_parents[i + 1], _parents[i]);
	if (!s1 && s2)
	  delete(s2);
	else if (s1 && !s2)
	  delete(s1);
	if (!s1 || !s2)
	  {
	    for (unsigned int i = 0; i < rm.size(); i++)
	      delete(rm[i]);
	    for (unsigned int i = 0; i < keep.size(); i++)
	      delete(keep[i]);
	    throw (PopulationException(ERR_POP_CROSS));
	  }
	if (RandomInt(0, 2) == 0)
	  {
	    _samples.push_back(s1);
	    delete(s2);
	  }
	else
	  {
	    _samples.push_back(s2);
	    delete(s1);
	  }
      }
    for (unsigned int i = 0; i < keep.size(); i++)
      _samples.push_back(keep[i]);
    for (unsigned int i = 0; i < rm.size(); i++)
      delete(rm[i]);
  }

  /*
  ** Genetic : Mutation.
  */
  void						Population::Mutation(void) throw()
  {
    std::default_random_engine			gen;
    std::uniform_real_distribution<double>	distrib(0, 1);

    for (std::list<IDNA *>::iterator it = _samples.begin(); it != _samples.end(); it++)
      {
	if (distrib(gen) <= _mutation_rate)
	  (_config.getDNAMutate())(*it);
      }
  }

  /*
  ** Overload.
  */
  std::ostream&			operator<<(std::ostream& flux, Population const& p)
  {
    std::list<IDNA *>		list;
    std::list<IDNA *>::iterator	it;

    flux << STR_POP_SIZE << p.getSize() << std::endl;
    flux << STR_POP_MUT << p.getMutationRate() << std::endl;
    flux << STR_POP_SELT << p.getSelectionRate() << std::endl;
    flux << STR_POP_BFIT << p.getBestFitness() << std::endl;
    flux << STR_POP_AFIT << p.getAverageFitness() << std::endl;
    list = p.get();
    it = list.begin();
    while (it != list.end() && *it && (*it)->getFitness() != p.getBestFitness())
      ++it;
    flux << STR_POP_GENES;
    if (it != list.end())
      (*it)->Print();
    return (flux);
  }
}
