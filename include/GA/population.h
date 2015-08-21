/*
** population.h for GAEngine in /home/robin_f/Programming/Git/CPP/GANNEngine/include/GA
** 
** Made by Guillaume ROBIN
** Login   <robin_f@epitech.eu>
** 
** Started on  Wed Jul  8 14:00:38 2015 Guillaume ROBIN
** Last update Fri Aug 21 22:41:24 2015 Guillaume ROBIN
*/

#ifndef POPULATION_H_
# define POPULATION_H_

# include <vector>
# include <iostream>

# include "GA/ga_config.h"
# include "GA/population_exception.h"

namespace GA
{
  /*!
   * \class Population
   * \brief Define what is a population for the GAEngine.
   */
  class Population
  {
  public:
    /*
    ** Constructor & Destructor.
    */
    /*!
     * \brief Constructor.
     */
    Population(void) throw();
    /*!
     * \brief Constructor.
     * \param config : Contains the configuration of the population.
     * \param size : Contains the population size.
     * \return error : PopulationException
     */
    Population(GAConfig const& config, unsigned int size);
    /*!
     * \brief Destructor.
     */
    ~Population(void) throw();

    /*
    ** Overload.
    */
    Population&	operator=(Population const& pop) throw();

    /*
    ** Initializer.
    */

    /*!
     * \brief Generator the entire population.
     * \return error : PopulationException
     */
    void	Generate(void);

    /*
    ** Getters.
    */

    /*!
     * \brief Get the population size member.
     * \return unsigned int
     */
    unsigned int	       	getSize(void) const throw();
    /*!
     * \brief Get the pool size member.
     * \return unsigned int
     */
    unsigned int	       	getPoolSize(void) const throw();
    /*!
     * \brief Get the mutation rate member.
     * \return double
     */
    double		       	getMutationRate(void) const throw();
    /*!
     * \brief Get the selection rate member.
     * \return double
     */
    double		       	getSelectionRate(void) const throw();
    /*!
     * \brief Get the best fitness contained in the population.
     * \return double
     */
    double		       	getBestFitness(void) const throw();
    /*!
     * \brief Get the average fitness of the population.
     * \return double
     */
    double		       	getAverageFitness(void) const throw();
    /*!
     * \brief Get the configuration of the GAEngine.
     * \return GAConfig const&
     */
    GAConfig const&		getConfig(void) const throw();
    /*!
     * \brief Get the list of the IDNA.
     * \return std::list<IDNA *> const&
     */
    std::list<IDNA *> const&	get(void) const throw();
    /*!
     * \brief Get the list of the IDNA.
     * \return std::list<IDNA *> &
     */
    std::list<IDNA *> &		get(void) throw();

    /*
    ** Setters.
    */

    /*!
     * \brief Set the population size.
     * \return error : PopulationException
     */
    void	setSize(unsigned int size);
    /*!
     * \brief Set the pool size.
     * \return error : PopulationException
     */
    void	setPoolSize(unsigned int size);
    /*!
     * \brief Set the mutation rate.
     * \return error : PopulationException
     */
    void	setMutationRate(double rate);
    /*!
     * \brief Set the selection rate.
     * \return error : PopulationException
     */
    void	setSelectionRate(double rate);
    /*!
     * \brief Set the GAEngine's configuration.
     * \return error : PopulationException
     */
    void	setConfig(GAConfig const& config);

    /*
    ** Genetic.
    */

    /*!
     * \brief Evaluate the population.
     * \param nbThread : Contains the number of threads used to evaluate the population.
     * \return error : PopulationException
     */
    void	Evaluate(unsigned int nbThread);
    /*!
     * \brief Do the selection of the population in order to generate the next population.
     */
    void	Selection(void) throw();
    /*!
     * \brief Do te crossover of the population.
     * \return error : PopulationException
     */
    void	Crossover(void);
    /*!
     * \brief Do the mutation of the population.
     * \return error : PopulationException
     */
    void	Mutation(void) throw();

  private:
    unsigned int		_size; /*!< Contains the population size. */
    unsigned int		_pool_size; /*!< Contains the pool size for the tournament. */
    double			_mutation_rate; /*!< Contains the mutation rate. */
    double			_selection_rate; /*!< Contains the selection rate. */
    double			_best_fitness; /*!< Contains the best fitness contained in the population. */
    double			_avg_fitness; /*!< Contains the average fitness of the population. */
    GAConfig			_config; /*!< Contains the population's configuration. */
    std::list<IDNA *>       	_samples; /*!< Contains all the IDNAs of the population. */
    std::vector<IDNA *>		_parents; /*!< Contains temporarily all the parents of the next population. */
  };

  std::ostream&	operator<<(std::ostream& flux, Population const& p);
}

#endif /* !POPULATION_H_ */
