//
// ann_layer.cc for GANNEngine in /home/robin_f/Programming/Git/CPP/GANNEngine
// 
// Made by Guillaume ROBIN
// Login   <robin_f@epitech.eu>
// 
// Started on  Wed Jul  8 14:23:00 2015 Guillaume ROBIN
// Last update Mon Aug 24 15:34:13 2015 Guillaume ROBIN
//

#include <cmath>
#include <stdlib.h>
#include <time.h>

#include "ANN/ann_layer.h"
#include "ANN/tools.h"
#include "ANN/ann_const.h"

namespace GANN
{
  /*
  ** Constructor & Destructor.
  */
  ANNLayer::ANNLayer(void)
  {
    _activate = NULL;
  }

  ANNLayer::ANNLayer(unsigned int num_inputs, unsigned int num_neurons, double min, double max,
		     FActivate f_activate): ANNLayer()
  {
    _weights = Matrix<double>(num_neurons, num_inputs, 0);
    _outputs = Matrix<double>(num_neurons, 1, 0);
    _bias = Matrix<double>(num_neurons, 1, 0);
    _activate = f_activate;

    for (unsigned int i = 0; i < _weights.rows() * _weights.cols(); i++)
      _weights[i] = RandomDouble(min, max);
    for (unsigned int i = 0; i < _bias.rows() * _bias.cols(); i++)
      _bias[i] = RandomDouble(min, max);
  }

  ANNLayer::ANNLayer(ANNLayer const& copy)
  {
    _weights = copy.getWeights();
    _outputs = copy.getOutputs();
    _bias = copy.getBias();
    _activate = copy.getActivationFunction();
  }

  ANNLayer::~ANNLayer(void)
  {
  }

  /*
  ** Getters.
  */
  Matrix<double> const&	ANNLayer::getWeights(void) const
  {
    return (_weights);
  }

  Matrix<double>&	ANNLayer::getWeights(void)
  {
    return (_weights);
  }

  Matrix<double> const&	ANNLayer::getOutputs(void) const
  {
    return (_outputs);
  }

  Matrix<double> const&	ANNLayer::getBias(void) const
  {
    return (_bias);
  }

  Matrix<double>&	ANNLayer::getBias(void)
  {
    return (_bias);
  }

  ANNLayer::FActivate		ANNLayer::getActivationFunction(void) const
  {
    return (_activate);
  }

  /*
  ** Setters.
  */
  void	ANNLayer::setWeights(Matrix<double> const& weights)
  {
    _weights = weights;
  }

  void	ANNLayer::setBias(Matrix<double> const& bias)
  {
    _bias = bias;
  }

  void	ANNLayer::setOutputs(Matrix<double> const& outputs)
  {
    _outputs = outputs;
  }

  void	ANNLayer::setActivationFunction(FActivate f)
  {
    _activate = f;
  }

  /*
  ** Overlaod.
  */
  ANNLayer&	ANNLayer::operator=(ANNLayer const& layer)
  {
    _weights = layer.getWeights();
    _outputs = layer.getOutputs();
    _bias = layer.getBias();
    return (*this);
  }

  /*
  ** Methods.
  */
  void	ANNLayer::Activate(Matrix<double> const& inputs)
  {
    _outputs = _weights * inputs - _bias;
    for (unsigned int i = 0; i < _outputs.rows() * _outputs.cols(); i++)
      {
	if (_activate)
	  _outputs[i] = _activate(_outputs[i]);
	else
	  {
	    std::cerr << ERR_ANN_NULLACTIVATION << std::endl;
	    _outputs[i] = 0;
	  }
      }
  }
}
