//
// neural_net.cc for GANNEngine in /home/robin_f/Programming/Git/CPP/GANNEngine
// 
// Made by Guillaume ROBIN
// Login   <robin_f@epitech.eu>
// 
// Started on  Wed Jul  8 15:52:17 2015 Guillaume ROBIN
// Last update Wed Jul 29 10:23:13 2015 Guillaume ROBIN
//

#include <stdlib.h>
#include <time.h>

#include "ANN/neural_net.h"
#include "ANN/tools.h"

#include <iostream>

namespace GANN
{
  /*
  ** Constructor & Destructor.
  */
  ANN::ANN(void): _rand_min(-10), _rand_max(10)
  {
    _layer_activation = &Sigmoid;
    _out_activation = &Sigmoid;
  }

  ANN::ANN(std::vector<unsigned int> const& infos): ANN()
  {
    ANNLayer	*ptr;

    _infos = infos;
    for (unsigned int i = 1; i < infos.size(); i++)
      {
	if (i < infos.size() - 1)
	  ptr = new ANNLayer(infos[i - 1], infos[i], _rand_min, _rand_max, _layer_activation);
	else
	  ptr = new ANNLayer(infos[i - 1], infos[i], _rand_min, _rand_max, _out_activation);
	if (ptr)
	  _layers.push_back(ptr);
	else
	  std::cerr << ERR_ANN_NLAYER << std::endl;
      }
  }

  ANN::~ANN(void)
  {
    unsigned int size = _layers.size();

    for (unsigned int i = 0; i < size; i++)
      delete(_layers[i]);
  }

  /*
  ** Getters.
  */
  Matrix<double> const&	ANN::getOutputs(void) const
  {
    return (_layers[_layers.size() - 1]->getOutputs());
  }

  double	ANN::getMinRandom(void) const
  {
    return (_rand_min);
  }

  double	ANN::getMaxRandom(void) const
  {
    return (_rand_max);
  }

  std::vector<ANNLayer *> const&	ANN::getLayers(void) const
  {
    return (_layers);
  }

  std::vector<unsigned int> const&	ANN::getInfos(void) const
  {
    return (_infos);
  }

  double	ANN::getCrossingRate(void) const
  {
    return (_cross_rate);
  }

  ANNLayer::FActivate	ANN::getActivationFunction(void) const
  {
    return (_layer_activation);
  }

  ANNLayer::FActivate	ANN::getOutputsActivation(void) const
  {
    return (_out_activation);
  }

  /*
  ** Setters.
  */
  void	ANN::setRandom(double min, double max)
  {
    _rand_min = min;
    _rand_max = max;
  }

  void	ANN::setLayers(std::vector<ANNLayer *> const& layers)
  {
    for (unsigned int i = 0; i < _layers.size(); i++)
      delete(_layers[i]);
    _layers.clear();
    for (unsigned int i = 0; i < layers.size(); i++)
      _layers.push_back(layers[i]);
  }

  void	ANN::setCrossingRate(double rate)
  {
    if (rate >= 0 && rate <= 1)
      _cross_rate = rate;
    else
      {
	_cross_rate = DEF_CROSS_RATE;
	std::cerr << ERR_ANN_INVCROSSRATE << std::endl;
      }
  }

  void	ANN::setActivationFunction(ANNLayer::FActivate f)
  {
    _layer_activation = f;
  }

  void	ANN::setOutputsActivation(ANNLayer::FActivate f)
  {
    _out_activation = f;
  }

  /*
  ** Overload.
  */
  ANN&				ANN::operator=(ANN const& b)
  {
    std::vector<ANNLayer *>	layers;
    unsigned int		size = _layers.size();

    _rand_min = b.getMinRandom();
    _rand_max = b.getMaxRandom();
    _out_activation = b.getOutputsActivation();
    _layer_activation = b.getActivationFunction();
    _cross_rate = b.getCrossingRate();
    layers = b.getLayers();
    for (unsigned int i = 0; i < size; i++)
      delete(_layers[i]);
    _layers.clear();
    for (unsigned int i = 0; i < layers.size(); i++)
      _layers.push_back(new ANNLayer(*(layers[i])));
    return (*this);
  }

  /*
  ** Methods.
  */
  void			ANN::Activate(Matrix<double> const& inputs)
  {
    Matrix<double>	current(inputs);

    for (unsigned int i = 0; i < _layers.size(); i++)
      {
	if (_layers[i])
	  {
	    _layers[i]->Activate(current);
	    current = Matrix<double>(_layers[i]->getOutputs());
	  }
	else
	  {
	    std::cerr << ERR_ANN_ERRACTIVATE << std::endl;
	    i = _layers.size();
	  }
      }
  }

  void	       	ANN::Create(std::vector<unsigned int> const& infos)
  {
    ANNLayer	*ptr;

    _infos = infos;
    for (unsigned int i = 1; i < infos.size(); i++)
      {
	if (i < infos.size() - 1)
	  ptr = new ANNLayer(infos[i - 1], infos[i], _rand_min, _rand_max, _layer_activation);
	else
	  ptr = new ANNLayer(infos[i - 1], infos[i], _rand_min, _rand_max, _out_activation);
	if (ptr)
	  _layers.push_back(ptr);
	else
	  {
	    std::cerr << ERR_ANN_NLAYER << std::endl;
	    i = infos.size();
	  }
      }
  }
}
