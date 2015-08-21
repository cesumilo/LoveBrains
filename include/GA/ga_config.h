/*
** i_config.h for GAEngine in /home/robin_f/Programming/Git/CPP/GAEngine
** 
** Made by Guillaume ROBIN
** Login   <robin_f@epitech.eu>
** 
** Started on  Tue Jul 21 13:02:43 2015 Guillaume ROBIN
** Last update Fri Aug 21 16:55:48 2015 Guillaume ROBIN
*/

#ifndef GA_CONFIG_H_
# define GA_CONFIG_H_

# include <list>

# include "GA/i_generator.h"

namespace GA
{
  /*!
   * \class GAConfig
   * \brief Define the configuration of the GAEngine.
   */
  class GAConfig
  {
  public:
    /*
    ** Typedef.
    */

    /*!
     * \brief Function pointer to evaluate the population.
     */
    typedef void	(*FEvaluate)(std::list<IDNA *>&);
    /*!
     * \brief Function pointer that define the evaluation of an AI.
     */
    typedef void	(*DNAFitness)(IDNA *, double *);
    /*!
     * \brief Function pointer that define how to compare two IDNA.
     */
    typedef bool	(*DNACompare)(const IDNA *, const IDNA *);
    /*!
     * \brief Function pointer that define how to cross two IDNA.
     */
    typedef IDNA	*(*DNACrossover)(const IDNA *, const IDNA *);
    /*!
     * \brief Function pointer that define how to mutate a IDNA.
     */
    typedef void	(*DNAMutate)(IDNA *);

    /*!
     * \brief Constructor.
     */
    GAConfig(void);
    /*!
     * \brief Destructor.
     */
    ~GAConfig(void);

    GAConfig&	operator=(GAConfig const& config);

    /*!
     * \brief Return if the function pointer, setted in order to evaluate the population, is not NULL.
     * \return true : if the function pointer is not null.
     * \return false : if the function pointer is null.
     */
    bool	isEvaluated(void) const;
    /*!
     * \brief Return if the configuration is valid.
     * \return true : if the configuration is valid.
     * \return false : if the configuration is not valid.
     */
    bool	isValid(void) const;

    /*!
     * \brief Set the evaluation function pointer.
     * \param function : Contains the function pointer for the evaluation of the population.
     */
    void	setEvaluation(FEvaluate function);
    /*!
     * \brief Set the generator.
     * \param generator : Contains the generator object.
     */
    void	setGenerator(IGenerator *generator);
    /*!
     * \brief Set the fitness function pointer.
     * \param function : Contains the function pointer for the evaluation of the fitness.
     */
    void	setDNAFitness(DNAFitness function);
    /*!
     * \brief Set the function pointer to compare two IDNA.
     * \param function : Contains the function pointer.
     */
    void	setDNACompare(DNACompare function);
    /*!
     * \brief Set the crossover function pointer.
     * \param function : Contains the function pointer for the crossover of the population.
     */
    void	setDNACrossover(DNACrossover function);
    /*!
     * \brief Set the mutation function pointer.
     * \param function : Contains the function pointer for the mutation of the population.
     */
    void	setDNAMutate(DNAMutate function);

    /*!
     * \brief Get the evaluation function pointer.
     * \return GA::GAConfig::FEvaluate
     */
    FEvaluate		getEvaluation(void) const;
    /*!
     * \brief Get the generator member.
     * \return GA::IGenerator *
     */
    IGenerator		*getGenerator(void) const;
    /*!
     * \brief Get the function pointer to evaluate the fitness.
     * \return GA::GAConfig::DNAFitness
     */
    DNAFitness		getDNAFitness(void) const;
    /*!
     * \brief Get the function pointer to compare two IDNA.
     * \return GA::GAConfig::DNACompare
     */
    DNACompare		getDNACompare(void) const;
    /*!
     * \brief Get the function pointer to cross two IDNA.
     * \return GA::GAConfig::DNACrossover
     */
    DNACrossover	getDNACrossover(void) const;
    /*!
     * \brief Get the function pointer to mutate an IDNA object.
     * \return GA::GAConfig::DNAMutate
     */
    DNAMutate		getDNAMutate(void) const;

  private:
    FEvaluate		_evaluate; /*!< Contains the function pointer to evaluate the population. */
    IGenerator		*_generator; /*!< Contains the generator. */
    DNAFitness		_fitness; /*!< Contains the function pointer to evaluate the fitness of an IDNA. */
    DNACompare		_compare; /*!< Contains the function pointer to compare two IDNA. */
    DNACrossover	_crossover; /*!< Contains the function pointer to cross two IDNA. */
    DNAMutate		_mutate; /*!< Contains the function pointer to mutate an IDNA. */
  };
}

#endif /* !GA_CONFIG_H_ */
