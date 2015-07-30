/*
** population.h for GAEngine in /home/robin_f/Programming/Git/CPP/GANNEngine/include/GA
** 
** Made by Guillaume ROBIN
** Login   <robin_f@epitech.eu>
** 
** Started on  Wed Jul  8 14:00:38 2015 Guillaume ROBIN
** Last update Tue Jul 28 16:15:26 2015 Guillaume ROBIN
*/

#ifndef POPULATION_H_
# define POPULATION_H_

# include <vector>
# include <iostream>

# include "GA/ga_config.h"
# include "GA/population_exception.h"

namespace GA
{
  class Population
  {
  public:
    /*
    ** Constructor & Destructor.
    */
    Population(void) throw();
    Population(GAConfig const& config, unsigned int size);
    ~Population(void) throw();

    /*
    ** Overload.
    */
    Population&	operator=(Population const& pop) throw();

    /*
    ** Initializer.
    */
    void	Generate(void);

    /*
    ** Getters.
    */
    unsigned int	       	getSize(void) const throw();
    unsigned int	       	getPoolSize(void) const throw();
    double		       	getMutationRate(void) const throw();
    double		       	getSelectionRate(void) const throw();
    double		       	getBestFitness(void) const throw();
    double		       	getAverageFitness(void) const throw();
    GAConfig const&		getConfig(void) const throw();
    std::list<IDNA *> const&	get(void) const throw();
    std::list<IDNA *> &		get(void) throw();

    /*
    ** Setters.
    */
    void	setSize(unsigned int size);
    void	setPoolSize(unsigned int size);
    void	setMutationRate(double rate);
    void	setSelectionRate(double rate);
    void	setConfig(GAConfig const& config);

    /*
    ** Genetic.
    */
    void	Evaluate(unsigned int nbThread);
    void	Selection(void) throw();
    void	Crossover(void);
    void	Mutation(void) throw();

  private:
    unsigned int		_size;
    unsigned int		_pool_size;
    double			_mutation_rate;
    double			_selection_rate;
    double			_best_fitness;
    double			_avg_fitness;
    GAConfig			_config;
    std::list<IDNA *>       	_samples;
    std::vector<IDNA *>		_parents;
  };

  std::ostream&	operator<<(std::ostream& flux, Population const& p);
}

#endif /* !POPULATION_H_ */
