/*
** ga_engine.h for GAEngine in /home/robin_f/Programming/Git/CPP/GANNEngine/include/GA
** 
** Made by Guillaume ROBIN
** Login   <robin_f@epitech.eu>
** 
** Started on  Wed Jul  8 14:02:16 2015 Guillaume ROBIN
** Last update Fri Aug 21 17:13:25 2015 Guillaume ROBIN
*/

#ifndef GA_ENGINE_H_
# define GA_ENGINE_H_

# include "GA/ga_engine_exception.h"
# include "GA/population.h"
# include "GA/a_observer.h"

namespace GA
{
  /*!
   * \class GAEngine
   * \brief Manage the evolution of a population composed of IDNA objects.
   */
  class GAEngine : public AObserver
  {
  public:
    /*
    ** Constructor & Destructor.
    */

    /*!
     * \brief Constructor.
     */
    GAEngine(void) throw();
    /*!
     * \brief Destructor.
     */
    ~GAEngine(void) throw();

    /*
    ** Getters.
    */

    /*!
     * \brief Get the GA::Population member.
     * \return GA::Population const&
     */
    Population const&		getPopulation(void) const throw();
    /*!
     * \brief Get the GA::Population member.
     * \return GA::Population &
     */
    Population&			getPopulation(void) throw();
    /*!
     * \brief Get the mutation rate member.
     * \return double
     */
    double			getMutationRate(void) const throw();
    /*!
     * \brief Get the selection rate member.
     * \return double
     */
    double			getSelectionRate(void) const throw();
    /*!
     * \brief Get the pool size member.
     * \return unsigned int
     */
    unsigned int		getPoolSize(void) const throw();
    /*!
     * \brief Get the evaluation function pointer.
     * \return GA::GAConfig::FEvaluate
     */
    GA::GAConfig::FEvaluate	getEvaluation(void) const throw();
    /*!
     * \brief Get the maximum epochs member.
     * \return int
     */
    int				getMaxEpochs(void) const throw();
    /*!
     * \brief Get the interval between each report.
     * \return unsigned int
     */
    unsigned int		getReportInterval(void) const throw();
    /*!
     * \brief Get the number of threads used to evaluate the population.
     * \return unsigned int
     */
    unsigned int		getNumberOfThread(void) const throw();
    /*!
     * \brief Get the expected fitness member.
     * \return double.
     */
    double			getExpectedFitness(void) const throw();

    /*
    ** Setters.
    */

    /*!
     * \brief Set the maximum epochs.
     * \param max : Contains the maximum epochs.
     */
    void	setMaxEpochs(int max) throw();
    /*!
     * \brief Set the expected fitness.
     * \param fitness : Contains the new expected fitness.
     */
    void	setExpectedFitness(double fitness) throw();
    /*!
     * \brief Set the number of threads used to evaluate the population.
     * \param nb : Contains the number of threads.
     */
    void	setNumberOfThreads(unsigned int nb) throw();
    /*!
     * \brief Set the interval between each report.
     * \param nb : Contains the interval number.
     */
    void	setReportInterval(unsigned int nb) throw();
    /*!
     * \brief Set the mutation rate.
     * \param rate : Contains the new mutation rate.
     * \return error : GAEngineException
     */
    void	setMutationRate(double rate);
    /*!
     * \brief Set the selection rate.
     * \param rate : Contains the new selection rate.
     * \return error : GAEngineException
     */
    void	setSelectionRate(double rate);
    /*!
     * \brief Set the pool size for the tournament.
     * \param size : Contains the pool size.
     * \return error : GAEngineException
     */
    void	setPoolSize(unsigned int size);

    /*
    ** Overload.
    */
    GAEngine&	operator=(GAEngine const& engine);

    /*
    ** Methods : CreatePopulation.
    */

    /*!
     * \brief Create a new population in terms of the configuration.
     * \param config : Contains the configuration of the GAEngine.
     * \param size : Contains the size of the population.
     * \return error : GAEngineException
     */
    void		CreatePopulation(GAConfig const& config, unsigned int size);
    /*!
     * \brief Run the evolution of the population.
     * \param report : Contains the boolean that define if there is a report or not.
     * \return unsigned int : number of epochs
     * \return error : GAEngineException
     */
    unsigned int       	Evolve(bool report);

  private:
    GA::GAConfig::FEvaluate		_evaluate; /*!< Contains the evaluation function pointer. */
    int					_max_epochs; /*!< Contains the maximum epochs. */
    unsigned int			_report_interval; /*!< Contains the interval between each report. */
    unsigned int			_nb_threads; /*!< Contains the number of threads used to evaluate the population. */
    double				_expected_fitness; /*!< Contains the expected fitness. */
    Population				_pop; /*!< Contains the population of IDNA. */
  };
}

#endif /* !GA_ENGINE_H_ */
