//
// simulator_config.cc for LoveBrains in /home/robin_f/Programming/Git/CPP/LoveBrains
// 
// Made by Guillaume ROBIN
// Login   <robin_f@epitech.eu>
// 
// Started on  Thu Jul 23 14:07:18 2015 Guillaume ROBIN
// Last update Mon Aug 24 14:30:30 2015 Guillaume ROBIN
//

#include <stdexcept>

#include "Simulator/simulator_config.h"
#include "Simulator/simulator_const.h"
#include "Graphics/graphics_const.h"

namespace Simulator
{
  /*
  ** Constructor & Destructor.
  */
  SConfig::SConfig(void) throw(): _isTournament(false),
				  _crossing_rate(DEF_CROSSING_RATE),
				  _mutation_rate(DEF_MUTATION_RATE),
				  _selection_rate(DEF_SELECTION_RATE),
				  _expected_fitness(DEF_EXPECTED_FITNESS),
				  _pool_size(DEF_POOL_SIZE),
				  _max_epochs(DEF_MAX_EPOCHS),
				  _report_interval(DEF_REPORT_INTERVAL),
				  _pop_size(DEF_POPULATION_SIZE),
				  _env_width(DEF_APP_WIDTH),
				  _env_height(DEF_APP_HEIGHT)
  {
  }

  SConfig::~SConfig(void) throw()
  {
  }

  /*
  ** Setters.
  */
  void	SConfig::setCrossingRate(double rate)
  {
    if (rate >= DEF_MIN_RATE && rate <= DEF_MAX_RATE)
      _crossing_rate = rate;
    else
      throw (SimulatorException(ERR_SCONFIG_CROSSRATE));
  }

  void	SConfig::setMutationRate(double rate)
  {
    if (rate >= DEF_MIN_RATE && rate <= DEF_MAX_RATE)
      _mutation_rate = rate;
    else
      throw (SimulatorException(ERR_SCONFIG_MUTERATE));
  }

  void	SConfig::setSelectionRate(double rate)
  {
    if (rate >= DEF_MIN_RATE && rate <= DEF_MAX_RATE)
      _selection_rate = rate;
    else
      throw (SimulatorException(ERR_SCONFIG_SELECTRATE));
  }

  void	SConfig::setExpectedFitness(double value) throw()
  {
    _expected_fitness = value;
  }

  void	SConfig::setPoolSize(unsigned int size)
  {
    if (size > _pop_size || size == 0)
      throw (SimulatorException(ERR_SCONFIG_POOLSIZE));
    else
      _pool_size = size;
  }

  void	SConfig::setMaxEpochs(int max) throw()
  {
    _max_epochs = max;
  }

  void	SConfig::setReportInterval(unsigned int interval) throw()
  {
    _report_interval = interval;
  }

  void	SConfig::setPopulationSize(unsigned int size)
  {
    if (size == 0)
      throw (SimulatorException(ERR_SCONFIG_POPSIZE));
    else
      _pop_size = size;
  }

  void			SConfig::setANNInfos(std::string infos)
  {
    unsigned int	i = 0;
    unsigned int	pos = 0;
    std::string		token;
    std::string		delimiter = DEF_SIM_DELIM;
    unsigned int	num;

    while (i < infos.size() && ((infos[i] >= DEF_SIM_MINNUM && infos[i] <= DEF_SIM_MAXNUM)
				|| infos[i] == DEF_SIM_DELIMCHAR))
      ++i;
    if (i != infos.size())
      throw (SimulatorException(ERR_SCONFIG_INFOS));
    while (infos.size() > 0)
      {
	pos = infos.find(delimiter);
	token = infos.substr(0, pos);
	try
	  {
	    num = std::stoi(token);
	    if (num == 0)
	      throw (SimulatorException(ERR_SCONFIG_INFOS));
	    _infos.push_back(num);
	  }
	catch (const std::invalid_argument& e)
	  {
	    throw (SimulatorException(e.what()));
	  }
	infos.erase(0, pos + delimiter.size());
      }
  }

  void	SConfig::setActivation(GANN::ANNLayer::FActivate function, GANN::ANN::ActivationType type)
  {
    if (!function)
      throw (SimulatorException(ERR_SCONFIG_FUNCTION));
    _layer_ftype = type;
    _activation = function;
  }

  void	SConfig::setOutputsActivation(GANN::ANNLayer::FActivate function,
				      GANN::ANN::ActivationType type)
  {
    if (!function)
      throw (SimulatorException(ERR_SCONFIG_FUNCTION));
    _out_ftype = type;
    _output_activation = function;
  }

  void	SConfig::setEnvironmentSize(unsigned int width, unsigned int height)
  {
    if (width <= 0 || height <= 0)
      throw (SimulatorException(ERR_SCONFIG_ENVSIZE));
    _env_width = width;
    _env_height = height;
  }

  void	SConfig::setIsTournament(bool isTournament) throw()
  {
    _isTournament = isTournament;
  }

  /*
  ** Getters.
  */
  double	SConfig::getCrossingRate(void) const throw()
  {
    return (_crossing_rate);
  }

  double	SConfig::getMutationRate(void) const throw()
  {
    return (_mutation_rate);
  }

  double	SConfig::getSelectionRate(void) const throw()
  {
    return (_selection_rate);
  }

  double	SConfig::getExpectedFitness(void) const throw()
  {
    return (_expected_fitness);
  }

  unsigned int	SConfig::getPoolSize(void) const throw()
  {
    return (_pool_size);
  }

  int		SConfig::getMaxEpochs(void) const throw()
  {
    return (_max_epochs);
  }

  unsigned int	SConfig::getReportInterval(void) const throw()
  {
    return (_report_interval);
  }

  unsigned int	SConfig::getPopulationSize(void) const throw()
  {
    return (_pop_size);
  }

  std::vector<unsigned int> const&	SConfig::getANNInfos(void) const throw()
  {
    return (_infos);
  }

  GANN::ANNLayer::FActivate	SConfig::getActivation(void) const throw()
  {
    return (_activation);
  }

  GANN::ANNLayer::FActivate	SConfig::getOutputsActivation(void) const throw()
  {
    return (_output_activation);
  }

  unsigned int	SConfig::getEnvironmentWidth(void) const throw()
  {
    return (_env_width);
  }

  unsigned int	SConfig::getEnvironmentHeight(void) const throw()
  {
    return (_env_height);
  }

  GANN::ANN::ActivationType	SConfig::getLayerActivationType(void) const throw()
  {
    return (_layer_ftype);
  }

  GANN::ANN::ActivationType	SConfig::getOutputActivationType(void) const throw()
  {
    return (_out_ftype);
  }

  bool	SConfig::isTournament(void) const throw()
  {
    return (_isTournament);
  }

  /*
  ** Overload.
  */
  SConfig&	SConfig::operator=(SConfig const& config)
  {
    _isTournament = config.isTournament();
    _crossing_rate = config.getCrossingRate();
    _mutation_rate = config.getMutationRate();
    _selection_rate = config.getSelectionRate();
    _expected_fitness = config.getExpectedFitness();
    _pool_size = config.getPoolSize();
    _max_epochs = config.getMaxEpochs();
    _report_interval = config.getReportInterval();
    _pop_size = config.getPopulationSize();
    _infos = config.getANNInfos();
    _activation = config.getActivation();
    _output_activation = config.getOutputsActivation();
    _env_width = config.getEnvironmentWidth();
    _env_height = config.getEnvironmentHeight();
    _layer_ftype = config.getLayerActivationType();
    _out_ftype = config.getOutputActivationType();
    return (*this);
  }
}
