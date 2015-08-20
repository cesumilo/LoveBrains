/*
** simulatior_config.h for LoveBrains in /home/robin_f/Programming/Git/CPP/LoveBrains
** 
** Made by Guillaume ROBIN
** Login   <robin_f@epitech.eu>
** 
** Started on  Thu Jul 23 13:51:41 2015 Guillaume ROBIN
** Last update Thu Aug 20 13:32:15 2015 Guillaume ROBIN
*/

#ifndef SIMULATOR_CONFIG_H_
# define SIMULATOR_CONFIG_H_

# include <vector>
# include <string>

# include "Simulator/simulator_exception.h"
# include "ANN/neural_net.h"

namespace Simulator
{
  class SConfig
  {
  public:
    SConfig(void) throw();
    ~SConfig(void) throw();

    /*
    ** Setters.
    */
    void	setCrossingRate(double rate);
    void	setMutationRate(double rate);
    void	setSelectionRate(double rate);
    void	setExpectedFitness(double rate) throw();
    void	setPoolSize(unsigned int size);
    void	setMaxEpochs(int max) throw();
    void	setReportInterval(unsigned int interval) throw();
    void	setPopulationSize(unsigned int size);
    void	setANNInfos(std::string infos);
    void	setActivation(GANN::ANNLayer::FActivate function, GANN::ANN::ActivationType type);
    void	setOutputsActivation(GANN::ANNLayer::FActivate function,
				     GANN::ANN::ActivationType type);
    void	setEnvironmentSize(unsigned int width, unsigned int height);

    /*
    ** Getters.
    */
    double				getCrossingRate(void) const throw();
    double				getMutationRate(void) const throw();
    double				getSelectionRate(void) const throw();
    double				getExpectedFitness(void) const throw();
    unsigned int			getPoolSize(void) const throw();
    int					getMaxEpochs(void) const throw();
    unsigned int			getReportInterval(void) const throw();
    unsigned int			getPopulationSize(void) const throw();
    std::vector<unsigned int> const&	getANNInfos(void) const throw();
    GANN::ANNLayer::FActivate		getActivation(void) const throw();
    GANN::ANNLayer::FActivate		getOutputsActivation(void) const throw();
    unsigned int			getEnvironmentWidth(void) const throw();
    unsigned int			getEnvironmentHeight(void) const throw();
    GANN::ANN::ActivationType		getLayerActivationType(void) const throw();
    GANN::ANN::ActivationType		getOutputActivationType(void) const throw();

    /*
    ** Overlaod.
    */
    SConfig&	operator=(SConfig const& config);

  private:
    double			_crossing_rate;
    double			_mutation_rate;
    double			_selection_rate;
    double			_expected_fitness;
    unsigned int		_pool_size;
    int				_max_epochs;
    unsigned int		_report_interval;
    unsigned int		_pop_size;
    unsigned int		_env_width;
    unsigned int		_env_height;
    std::vector<unsigned int>	_infos;
    GANN::ANNLayer::FActivate	_activation;
    GANN::ANNLayer::FActivate	_output_activation;
    GANN::ANN::ActivationType	_layer_ftype;
    GANN::ANN::ActivationType	_out_ftype;
  };
}

#endif /* !SIMULATOR_CONFIG_H_ */
