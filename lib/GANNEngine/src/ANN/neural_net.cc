//
// neural_net.cc for GANNEngine in /home/robin_f/Programming/Git/CPP/GANNEngine
// 
// Made by Guillaume ROBIN
// Login   <robin_f@epitech.eu>
// 
// Started on  Wed Jul  8 15:52:17 2015 Guillaume ROBIN
// Last update Mon Aug 24 15:38:52 2015 Guillaume ROBIN
//

#include <stdlib.h>
#include <time.h>

#include "ANN/neural_net.h"
#include "ANN/tools.h"
#include "ANN/ann_const.h"

namespace GANN
{
  /*
  ** Constructor & Destructor.
  */
  ANN::ANN(void) throw(): _rand_min(-10), _rand_max(10), _cross_rate(DEF_CROSS_RATE),
			  _out_ftype(ANN::ActivationType::SIGMOID),
			  _layer_ftype(ANN::ActivationType::SIGMOID),
			  _out_activation(&Sigmoid),
			  _layer_activation(&Sigmoid)
  {
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
	  throw (ANNException(ERR_ANN_NLAYER));
      }
  }

  ANN::~ANN(void) throw()
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
    if (_layers.size() > 0)
      return (_layers[_layers.size() - 1]->getOutputs());
    else
      throw (ANNException(ERR_ANN_GETOUT));
  }

  double	ANN::getMinRandom(void) const throw()
  {
    return (_rand_min);
  }

  double	ANN::getMaxRandom(void) const throw()
  {
    return (_rand_max);
  }

  std::vector<ANNLayer *> const&	ANN::getLayers(void) const throw()
  {
    return (_layers);
  }

  std::vector<unsigned int> const&	ANN::getInfos(void) const throw()
  {
    return (_infos);
  }

  double	ANN::getCrossingRate(void) const throw()
  {
    return (_cross_rate);
  }

  ANNLayer::FActivate	ANN::getActivationFunction(void) const throw()
  {
    return (_layer_activation);
  }

  ANNLayer::FActivate	ANN::getOutputsActivation(void) const throw()
  {
    return (_out_activation);
  }

  ANN::ActivationType	ANN::getOutputType(void) const throw()
  {
    return (_out_ftype);
  }

  ANN::ActivationType	ANN::getLayerType(void) const throw()
  {
    return (_layer_ftype);
  }

  /*
  ** Setters.
  */
  void	ANN::setRandom(double min, double max) throw()
  {
    _rand_min = min;
    _rand_max = max;
  }

  void	ANN::setLayers(std::vector<ANNLayer *> const& layers) throw()
  {
    for (unsigned int i = 0; i < _layers.size(); i++)
      delete(_layers[i]);
    _layers.clear();
    for (unsigned int i = 0; i < layers.size(); i++)
      _layers.push_back(layers[i]);
  }

  void	ANN::setCrossingRate(double rate) throw()
  {
    if (rate >= 0 && rate <= 1)
      _cross_rate = rate;
    else
      {
	_cross_rate = DEF_CROSS_RATE;
	std::cerr << ERR_ANN_INVCROSSRATE << std::endl;
      }
  }

  void	ANN::setActivationFunction(ANNLayer::FActivate f, ANN::ActivationType type)
  {
    if (!f)
      throw(ANNException(ERR_ANN_ACTF));
    _layer_activation = f;
    _layer_ftype = type;
  }

  void	ANN::setOutputsActivation(ANNLayer::FActivate f,  ANN::ActivationType type)
  {
    if (!f)
      throw(ANNException(ERR_ANN_OUTF));
    _out_activation = f;
    _out_ftype = type;
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
    _out_ftype = b.getOutputType();
    _layer_ftype = b.getLayerType();
    _cross_rate = b.getCrossingRate();
    _infos = b.getInfos();
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

    if (_infos.size() > 0 && inputs.rows() == _infos[0])
      {
	for (unsigned int i = 0; i < _layers.size(); i++)
	  {
	    if (_layers[i])
	      {
		_layers[i]->Activate(current);
		current = Matrix<double>(_layers[i]->getOutputs());
	      }
	    else
	      throw(ANNException(ERR_ANN_ERRACTIVATE));
	  }
      }
    else
      throw (ANNException(""));
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
	  throw(ANNException(ERR_ANN_NLAYER));
      }
  }
}
