//
// neural_net_save.cc for GANNEngine in /home/robin_f/Programming/Git/CPP/GANNEngine
// 
// Made by Guillaume ROBIN
// Login   <robin_f@epitech.eu>
// 
// Started on  Wed Aug 19 17:38:17 2015 Guillaume ROBIN
// Last update Thu Aug 20 12:42:30 2015 Guillaume ROBIN
//

#include <string>
#include <fstream>

#include "ANN/neural_net.h"
#include "ANN/ann_const.h"

namespace GANN
{
  void		ANN::SaveInfos(Json::Value& ann) const throw()
  {
    Json::Value	array;

    for (unsigned int i = 0; i < _infos.size(); ++i)
      array.append(_infos[i]);
    ann[DEF_ANN_INFOS] = array;
  }

  void		ANN::SaveRandomize(Json::Value& ann) const throw()
  {
    Json::Value	object;

    object[DEF_ANN_RMIN] = _rand_min;
    object[DEF_ANN_RMAX] = _rand_max;
    ann[DEF_ANN_RAND] = object;
  }

  void		ANN::SaveOutputActivation(Json::Value& ann) const throw()
  {
    switch (_out_ftype)
      {
      case ANN::ActivationType::SIGMOID:
	ann[DEF_ANN_OACT] = DEF_ANN_SIGM;
	break;
      case ANN::ActivationType::THRESHOLD:
	ann[DEF_ANN_OACT] = DEF_ANN_THRES;
	break;
      default:
	break;
      }
  }

  void		ANN::SaveLayerActivation(Json::Value& ann) const throw()
  {
    switch (_layer_ftype)
      {
      case ANN::ActivationType::SIGMOID:
	ann[DEF_ANN_LACT] = DEF_ANN_SIGM;
	break;
      case ANN::ActivationType::THRESHOLD:
	ann[DEF_ANN_LACT] = DEF_ANN_THRES;
	break;
      default:
	break;
      }
  }

  void		ANN::SaveLayers(Json::Value& ann) const
  {
    Matrix<double>	w;
    Matrix<double>	b;
    Json::Value		weights;
    Json::Value		bias;
    Json::Value		array;
    Json::Value		layers;
    Json::Value		layer;

    for (unsigned int i = 0; i < _layers.size(); ++i)
      {
	if (_layers[i])
	  {
	    w = _layers[i]->getWeights();
	    b = _layers[i]->getBias();
	    weights[DEF_ANN_ROWS] = w.rows();
	    weights[DEF_ANN_COLS] = w.cols();
	    bias[DEF_ANN_ROWS] = b.rows();
	    bias[DEF_ANN_COLS] = b.cols();
	    for (unsigned int j = 0; j < w.rows() * w.cols(); ++j)
	      array.append(w[j]);
	    weights[DEF_ANN_VALUES] = array;
	    array.clear();
	    for (unsigned int j = 0; j < b.rows() * b.cols(); ++j)
	      array.append(b[j]);
	    bias[DEF_ANN_VALUES] = array;
	    array.clear();
	    layer[DEF_ANN_WEIGHT] = weights;
	    layer[DEF_ANN_BIAS] = bias;
	    layers.append(layer);
	    layer.clear();
	  }
	else
	  throw(ANNException(ERR_ANN_LAYER));
      }
    ann[DEF_ANN_LAYERS] = layers;
  }

  void			ANN::Save(const char *path) const
  {
    std::ofstream	file(path);
    Json::FastWriter	writer;
    Json::Value		ann;

    if (file)
      {
	SaveInfos(ann);
	SaveRandomize(ann);
	SaveOutputActivation(ann);
	SaveLayerActivation(ann);
	try
	  {
	    SaveLayers(ann);
	  }
	catch (ANNException const& e)
	  {
	    throw (ANNException(e.what()));
	  }
	file << writer.write(ann);
      }
    else
      throw(ANNException(ERR_ANN_SAVE));
  }
}
