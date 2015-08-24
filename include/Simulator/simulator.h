/*
** simulator.h for LoveBrains in /home/robin_f/Programming/Git/CPP/LoveBrains
** 
** Made by Guillaume ROBIN
** Login   <robin_f@epitech.eu>
** 
** Started on  Thu Jul 23 11:56:50 2015 Guillaume ROBIN
** Last update Mon Aug 24 14:26:18 2015 Guillaume ROBIN
*/

#ifndef SIMULATOR_H_
# define SIMULATOR_H_

# include "GANN/gann_engine.h"
# include "ANN/ann_generator.h"
# include "Graphics/environment.h"
# include "Simulator/simulator_config.h"

/*!
 * \namespace Simulator
 * \brief Contains objects that manage the simulation.
 */
namespace Simulator
{
  /*!
   * \brief Contains all the objects in order to run the simulation.
   */
  class Simulator
  {
  public:
    /*!
     * \brief Constructor.
     */
    Simulator(void) throw();
    /*!
     * \brief Destructor.
     */
    ~Simulator(void) throw();

    /*
    ** Getters.
    */

    /*!
     * \brief Get the GANN Engine member.
     * \return GANN::GANNEngine const&
     */
    GANN::GANNEngine const&	       	getEngine(void) const throw();
    /*!
     * \brief Get the GANN Engine member.
     * \return GANN::GANNEngine &
     */
    GANN::GANNEngine&		       	getEngine(void) throw();
    /*!
     * \brief Get the ANN generator member.
     * \return GANN::ANNGenerator const&
     */
    GANN::ANNGenerator const&	       	getGenerator(void) const throw();
    /*!
     * \brief Get the simulator's configuration member.
     * \return GA::GAConfig const&
     */
    GA::GAConfig const&		       	getConfig(void) const throw();
    /*!
     * \brief Get the list that contains all the environment's objects.
     * \return std::list<Graphics::IObject *>&
     */
    std::list<Graphics::IObject *>&	getObjects(void) throw();
    /*!
     * \brief Get the physics engine member.
     * \return Graphics::Physics&
     */
    Graphics::Physics&		       	getPhysicsEngine(void) throw();

    /*
    ** Overload.
    */

    /*!
     * \return error : SimulatorException
     */
    Simulator&	operator=(Simulator const& simulator);

    /*
    ** Methods.
    */

    /*!
     * \brief Initialize the environment.
     * \param config : Contains the simulator configuration.
     * \return error : SimulatorException
     */
    void	InitEnvironment(SConfig const& config);
    /*!
     * \brief Initialize the simulator.
     * \param config : Contains the simalator configuration.
     * \param file : Contains the path to the environment configuration.
     * \return error : SimulatorException
     */
    void	Init(SConfig const& config, const char *file);
    /*!
     * \brief Run the simulation.
     * \param output_file : Contains the path to the output file to save the best neural network.
     * \return error : SimulatorException
     */
    void	Run(const char *output_file);
    /*!
     * \brief This function is given to the GAEngine with the aim of evaluating the population.
     * \param brains : Contains neural networks that will be given to the AI objects.
     * \return error : SimulatorException
     */
    static void	Evaluate(std::list<GA::IDNA *>& brains);

  private:
    static Graphics::Environment	*_env; /*!< Contains the environment */
    GANN::GANNEngine			_engine; /*!< Contains the GANNEngine */
    GANN::ANNGenerator			_generator; /*!< Contains the ANN generator */
    GA::GAConfig			_config; /*!< Contains the configuration of the genetic algorithm engine */
  };
}

#endif /* !SIMULATOR_H_ */
