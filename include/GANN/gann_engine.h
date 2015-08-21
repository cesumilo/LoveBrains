/*
** gann.h for GANNEngine in /home/robin_f/Programming/Git/CPP/GANNEngine
** 
** Made by Guillaume ROBIN
** Login   <robin_f@epitech.eu>
** 
** Started on  Wed Jul  8 19:53:34 2015 Guillaume ROBIN
** Last update Fri Aug 21 23:06:25 2015 Guillaume ROBIN
*/

#ifndef GANN_ENGINE_H_
# define GANN_ENGINE_H_

# include "GA/ga_engine.h"
# include "GANN/gann_exception.h"
# include "GANN/gann.h"

namespace GANN
{
  /*!
   * \class GANNEngine
   * \brief Define the engine that will manage the population of GANN and the evolution.
   */
  class GANNEngine
  {
  public:
    /*!
     * \brief Constructor.
     */
    GANNEngine(void) throw();
    /*!
     * \brief Destructor.
     * \return error : GANNException
     */
    ~GANNEngine(void);

    /*
    ** Initializer.
    */

    /*!
     * \brief Initialize the GANNEngine.
     * \param config : Contains the configuration for the GAEngine.
     * \param size : Contains the population size.
     * \return error : GANNException
     */
    void	Init(GA::GAConfig const& config, unsigned int size);

    /*
    ** Getters.
    */

    /*!
     * \brief Get the best neural network contained in the population.
     * \return ANN const&
     * \return error : GANNException
     */
    ANN const&		getBestANN(void) const;
    /*!
     * \brief Get the GA::GAEngine member.
     * \return GA::GAEngine&
     */
    GA::GAEngine&	getGAEngine(void) throw();
    /*!
     * \brief Get the GA::GAEngine member.
     * \return GA::GAEngine const&
     */
    GA::GAEngine const&	getGAEngine(void) const throw();
    /*!
     * \brief Get the GA::GAConfig member.
     * \return GA::GAConfig const&
     */
    GA::GAConfig const&	getGAConfig(void) const throw();

    /*
    ** Setters.
    */

    /*!
     * \brief Set the GA::GAEngine configuration.
     * \return error : GANNException
     */
    void		setGAConfig(GA::GAConfig const& config);

    /*
    ** Methods.
    */

    /*!
     * \brief Start the simulation with the aim of evolving the population.
     * \param report : Set if there is report or not.
     * \return error : GANNException
     */
    void	StartSimulation(bool report);

  private:
    /*
    ** GA Parameters.
    */
    unsigned int	_pool_size; /*!< Contains the pool size for the tournament. */
    double		_mutation_rate; /*!< Contains the mutation rate. */
    double		_selection_rate; /*!< Contains the selection rate. */

    GA::GAEngine       	_engine; /*!< Contains the GA::GAEngine. */
    GA::GAConfig	_config; /*!< Contains the configuration of the GA::GAEngine. */

    /*
    ** GA Functions.
    */

    /*!
     * \brief Define a method that compare two neural network.
     * \param IDNA * : Contains two objects of type IDNA.
     * \return true : if the first argument goes before the second argument.
     * \return false : if the first argument goes after the second argument.
     */
    static bool       	ANNComparator(const GA::IDNA *, const GA::IDNA *);
    /*!
     * \brief Define a method that cross two neural network.
     * \param IDNA * : Contains two objects of type IDNA.
     * \return GA::IDNA * : the child of the two objects.
     */
    static GA::IDNA	*ANNCrossover(const GA::IDNA *, const GA::IDNA *);
    /*!
     * \brief Define a method that mutate a neural network.
     * \param GA::IDNA * : an object of type IDNA.
     */
    static void       	ANNMutation(GA::IDNA *);
  };
}

#endif /* !GANN_ENGINE_H_ */
