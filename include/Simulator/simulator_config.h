/*
** simulatior_config.h for LoveBrains in /home/robin_f/Programming/Git/CPP/LoveBrains
** 
** Made by Guillaume ROBIN
** Login   <robin_f@epitech.eu>
** 
** Started on  Thu Jul 23 13:51:41 2015 Guillaume ROBIN
** Last update Wed Sep  2 12:47:17 2015 Guillaume ROBIN
*/

#ifndef SIMULATOR_CONFIG_H_
# define SIMULATOR_CONFIG_H_

# include <vector>
# include <string>

# include "Simulator/simulator_exception.h"
# include "ANN/neural_net.h"

namespace Simulator
{
  /*!
   * \class SConfig
   * \brief Manage the configuration of the simulator.
   */
  class SConfig
  {
  public:
    /*!
     * \brief Contains several display options.
     */
    enum class DisplayMode { NONE, ENVIRONMENT_2D };
    /*!
     * \brief Constructor.
     */
    SConfig(void) throw();
    /*!
     * \brief Destructor.
     */
    ~SConfig(void) throw();

    /*
    ** Setters.
    */

    /*!
     * \brief Set the crossing rate that will be used by the GAEngine.
     * \param rate : Contains the new crossing rate.
     * \return error : SimulatorException
     */
    void	setCrossingRate(double rate);
    /*!
     * \brief Set the mutation rate that will be used by the GAEngine.
     * \param rate : Contains the new mutation rate.
     * \return error : SimulatorException
     */
    void	setMutationRate(double rate);
    /*!
     * \brief Set the selection rate that will be used by the GAEngine.
     * \param rate : Contains the new selection rate.
     * \return error : SimulatorException
     */
    void	setSelectionRate(double rate);
    /*!
     * \brief Set the expected fitness that will be used by the GAEngine.
     * \param rate : Contains the new expected fitness.
     */
    void	setExpectedFitness(double rate) throw();
    /*!
     * \brief Set the pool size for the tournament in the GAEngine.
     * \param size : Contains the pool size.
     * \return error : SimulatorException
     */
    void	setPoolSize(unsigned int size);
    /*!
     * \brief Set the maximum epochs for the GAEngine.
     * \param max : Contains the maximum epochs.
     */
    void	setMaxEpochs(int max) throw();
    /*!
     * \brief Set the report interval for the GAEngine.
     * \param interval : Contains the new interval between each report.
     */
    void	setReportInterval(unsigned int interval) throw();
    /*!
     * \brief Set the population size of the GAEngine.
     * \param size : Contains the new population size.
     * \return error : SimulatorException
     */
    void	setPopulationSize(unsigned int size);
    /*!
     * \brief Set the topology of the neural network used by the AI objects.
     * \param infos : Contains a string that describe the topology.
     * \return error : SimulatorException
     */
    void	setANNInfos(std::string infos);
    /*!
     * \brief Set the activation function for the intern layers of the neural network.
     * \param function : Contains the function pointer of the new activation function.
     * \param type : Contains the type of the function pointer.
     * \return error : SimulatorException
     */
    void	setActivation(GANN::ANNLayer::FActivate function, GANN::ANN::ActivationType type);
    /*!
     * \brief Set the activation function for the output layer of the neural network.
     * \param function : Contains the function pointer of the new activation function.
     * \param type : Contains the type of the function pointer.
     * \return error : SimulatorException
     */
    void	setOutputsActivation(GANN::ANNLayer::FActivate function,
				     GANN::ANN::ActivationType type);
    /*!
     * \brief Set the environment size (window size).
     * \param width : Window's width.
     * \param height : Window's height.
     * \return error : SimulatorException
     */
    void	setEnvironmentSize(unsigned int width, unsigned int height);
    /*!
     * \brief Set if it's a tournament or not.
     * \param isTournament : (true) if it's a tournament, (false) is it's not.
     */
    void	setIsTournament(bool isTournament) throw();
    /*!
     * \brief Set the display mode of the environment.
     * \param display : Contains the display mode.
     */
    void	setDisplayMode(DisplayMode display) throw();
    /*!
     * \brief Set the log path.
     * \param path : Contains the path of the log file.
     */
    void	setLogPath(std::string const& path) throw();

    /*
    ** Getters.
    */

    /*!
     * \brief Get the crossing rate member.
     * \return double
     */
    double				getCrossingRate(void) const throw();
    /*!
     * \brief Get the mutation rate member.
     * \return double
     */
    double				getMutationRate(void) const throw();
    /*!
     * \brief Get the selection rate member.
     * \return double
     */
    double				getSelectionRate(void) const throw();
    /*!
     * \brief Get the expected fitness member.
     * \return double
     */
    double				getExpectedFitness(void) const throw();
    /*!
     * \brief Get the pool size member.
     * \return unsigned int
     */
    unsigned int			getPoolSize(void) const throw();
    /*!
     * \brief Get the maximum epochs member.
     * \return int
     */
    int					getMaxEpochs(void) const throw();
    /*!
     * \brief Get the report interval member.
     * \return unsigned int
     */
    unsigned int			getReportInterval(void) const throw();
    /*!
     * \brief Get the population size member.
     * \return unsigned int
     */
    unsigned int			getPopulationSize(void) const throw();
    /*!
     * \brief Get the neural network topology member.
     * \return std::vector<unsigned int> const&
     */
    std::vector<unsigned int> const&	getANNInfos(void) const throw();
    /*!
     * \brief Get the activation function pointer of the intern layers.
     * \return GANN::ANNLayer::FActivate
     */
    GANN::ANNLayer::FActivate		getActivation(void) const throw();
    /*!
     * \brief Get the activation function pointer of the output layer.
     * \return GANN::ANNLayer::FActivate
     */
    GANN::ANNLayer::FActivate		getOutputsActivation(void) const throw();
    /*!
     * \brief Get the window's width.
     * \return unsigned int
     */
    unsigned int			getEnvironmentWidth(void) const throw();
    /*!
     * \brief Get the window's height.
     * \return unsigned int
     */
    unsigned int			getEnvironmentHeight(void) const throw();
    /*!
     * \brief Get the type of the activation function pointer inside an intern layer.
     * \return GANN::ANN::ActivationType
     */
    GANN::ANN::ActivationType		getLayerActivationType(void) const throw();
    /*!
     * \brief Get the type of the activation function pointer inside the output layer.
     * \return GANN::ANN::ActivationType
     */
    GANN::ANN::ActivationType		getOutputActivationType(void) const throw();
    /*!
     * \brief Get the boolean that says if it's a tournament.
     * \return bool
     */
    bool	isTournament(void) const throw();
    /*!
     * \brief Get the current display mode of the environment.
     * \return SConfig::DisplayMode
     */
    DisplayMode	getDisplayMode(void) const throw();
    /*!
     * \brief Get the log file path.
     * \return std::string const&
     */
    std::string const&	getLogPath(void) const throw();

    /*
    ** Overlaod.
    */
    SConfig&	operator=(SConfig const& config);

  private:
    DisplayMode			_display; /*!< Contains the current display mode of the environment. */
    bool			_isTournament; /*!< Contains the boolean that says if it's a tournament. */
    double			_crossing_rate; /*!< Contains the crossing rate. */
    double			_mutation_rate; /*!< Contains the mutation rate. */
    double			_selection_rate; /*!< Contains the selection rate. */
    double			_expected_fitness; /*!< Contains the expected fitness. */
    unsigned int		_pool_size; /*!< Contains the pool size of the tournament. */
    int				_max_epochs; /*!< Contains the maximum epochs. */
    unsigned int		_report_interval; /*!< Contains the interval between each report. */
    unsigned int		_pop_size; /*!< Contains the population size. */
    unsigned int		_env_width; /*!< Contains the window's width. */
    unsigned int		_env_height; /*!< Contains the window's height. */
    GANN::ANNLayer::FActivate	_activation; /*!< Contains the activation function pointer for the intern layers. */
    GANN::ANNLayer::FActivate	_output_activation; /*!< Contains the activation function pointer for the output layer. */
    std::vector<unsigned int>	_infos; /*!< Contains the topology of the neural network. */
    GANN::ANN::ActivationType	_layer_ftype; /*!< Contains the activation function type for the intern layers. */
    GANN::ANN::ActivationType	_out_ftype; /*!< Contains the activation function type for the output layer. */
    std::string			_log_path; /*!< Contains the log file path. */
  };
}

#endif /* !SIMULATOR_CONFIG_H_ */
