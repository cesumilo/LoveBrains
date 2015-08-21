//
// ann_generator.cc<2> for GANNEngine in /home/robin_f/Programming/Git/CPP/GANNEngine
// 
// Made by Guillaume ROBIN
// Login   <robin_f@epitech.eu>
// 
// Started on  Tue Jul 21 16:42:33 2015 Guillaume ROBIN
// Last update Thu Aug 20 12:52:52 2015 Guillaume ROBIN
//

#include <cstdlib>

#include "ANN/ann_generator.h"
#include "ANN/tools.h"
#include "GANN/gann_const.h"
#include "GANN/gann.h"

namespace GANN
{
  /*
  ** Constructor & Destructor.
  */
  ANNGenerator::ANNGenerator(void) throw(): _rand_min(-5), _rand_max(5),
				    _activation(&Sigmoid), _output_function(&Sigmoid),
				    _out_ftype(ANN::ActivationType::SIGMOID),
				    _layer_ftype(ANN::ActivationType::SIGMOID)
  {
  }

  ANNGenerator::ANNGenerator(std::vector<unsigned int> const& infos, double crossing_rate) throw():
    ANNGenerator()
  {
    _infos = infos;
    _crossing_rate = crossing_rate;
  }

  ANNGenerator::~ANNGenerator(void) throw()
  {
  }

  /*
  ** Setters.
  */
  void	ANNGenerator::init(std::vector<unsigned int> const& infos, double crossing_rate) throw()
  {
    _infos = infos;
    _crossing_rate = crossing_rate;
  }

  void	ANNGenerator::setRandomize(double min, double max) throw()
  {
    _rand_min = min;
    _rand_max = max;
  }

  void	ANNGenerator::setActivationFunction(ANNLayer::FActivate function,
					    ANN::ActivationType type) throw()
  {
    _activation = function;
    _layer_ftype = type;
  }

  void	ANNGenerator::setOutputsActivation(ANNLayer::FActivate function,
					   ANN::ActivationType type) throw()
  {
    _output_function = function;
    _out_ftype = type;
  }

  /*
  ** Getters.
  */
  std::vector<unsigned int> const&	ANNGenerator::getInfos(void) const throw()
  {
    return (_infos);
  }

  double	ANNGenerator::getCrossingRate(void) const throw()
  {
    return (_crossing_rate);
  }

  double	ANNGenerator::getRandomMin(void) const throw()
  {
    return (_rand_min);
  }

  double	ANNGenerator::getRandomMax(void) const throw()
  {
    return (_rand_max);
  }

  ANNLayer::FActivate	ANNGenerator::getActivation(void) const throw()
  {
    return (_activation);
  }

  ANNLayer::FActivate	ANNGenerator::getOutputsActivation(void) const throw()
  {
    return (_output_function);
  }

  ANN::ActivationType	ANNGenerator::getOutputType(void) const throw()
  {
    return (_out_ftype);
  }

  ANN::ActivationType	ANNGenerator::getLayerType(void) const throw()
  {
    return (_layer_ftype);
  }

  /*
  ** Overload.
  */
  ANNGenerator&	ANNGenerator::operator=(ANNGenerator const& gen) throw()
  {
    _infos = gen.getInfos();
    _crossing_rate = gen.getCrossingRate();
    _rand_min = gen.getRandomMin();
    _rand_max = gen.getRandomMax();
    _activation = gen.getActivation();
    _output_function = gen.getOutputsActivation();
    _out_ftype = gen.getOutputType();
    _layer_ftype = gen.getLayerType();
    return (*this);
  }

  /*
  ** Methods.
  */
  GA::IDNA	*ANNGenerator::Generate(void) const throw()
  {
    GA::IDNA   	*ptr = NULL;
    ANN    	ann;

    ann.setRandom(_rand_min, _rand_max);
    ann.setCrossingRate(_crossing_rate);
    try
      {
	ann.setActivationFunction(_activation, _layer_ftype);
	ann.setOutputsActivation(_output_function, _out_ftype);
	ann.Create(_infos);
      }
    catch (ANNException const& e)
      {
	std::cerr << e.what() << std::endl;
	return (NULL);
      }
    if (!(ptr = new GANN(ann)))
      std::cerr << ERR_ANN_GENERATOR << std::endl;
    return (ptr);
  }
}
