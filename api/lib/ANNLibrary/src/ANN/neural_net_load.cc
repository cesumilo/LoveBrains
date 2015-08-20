//
// neural_net_load.cc for GANNEngine in /home/robin_f/Programming/Git/CPP/GANNEngine
// 
// Made by Guillaume ROBIN
// Login   <robin_f@epitech.eu>
// 
// Started on  Thu Aug 20 11:35:11 2015 Guillaume ROBIN
// Last update Thu Aug 20 12:40:30 2015 Guillaume ROBIN
//

#include <string>
#include <fstream>

#include "ANN/neural_net.h"
#include "ANN/ann_const.h"
#include "ANN/tools.h"

namespace GANN
{
  void	ANN::LoadInfos(Json::Value const& ann) throw()
  {
    _infos.clear();
    for (unsigned int i = 0; i < ann[DEF_ANN_INFOS].size(); ++i)
      _infos.push_back(ann[DEF_ANN_INFOS][i].asUInt());
  }

  void	ANN::LoadGenerateInfos(Json::Value const& ann) throw()
  {
    _cross_rate = ann[DEF_ANN_CROSS].asDouble();
    _rand_min = ann[DEF_ANN_RAND][DEF_ANN_RMIN].asDouble();
    _rand_max = ann[DEF_ANN_RAND][DEF_ANN_RMAX].asDouble();
  }

  void	ANN::LoadOutputActivation(Json::Value const& ann) throw()
  {
    if (ann[DEF_ANN_OACT].asString().compare(DEF_ANN_THRES) == 0)
      {
	_out_activation = &Threshold;
	_out_ftype = ANN::ActivationType::THRESHOLD;
      }
    else
      {
	_out_activation = &Sigmoid;
	_out_ftype = ANN::ActivationType::SIGMOID;
      }
  }

  void	ANN::LoadLayerActivation(Json::Value const& ann) throw()
  {
    if (ann[DEF_ANN_LACT].asString().compare(DEF_ANN_THRES) == 0)
      {
	_layer_activation = &Threshold;
	_layer_ftype = ANN::ActivationType::THRESHOLD;
      }
    else
      {
	_layer_activation = &Sigmoid;
	_layer_ftype = ANN::ActivationType::SIGMOID;
      }
  }

  void			ANN::LoadLayers(Json::Value const& ann)
  {
    ANNLayer		*layer;
    Matrix<double>	weights;
    Matrix<double>	bias;

    for (unsigned int i = 0; i < _layers.size(); ++i)
      delete(_layers[i]);
    _layers.clear();
    for (unsigned int i = 0; i < ann[DEF_ANN_LAYERS].size() && (layer = new ANNLayer()); ++i)
      {
	weights = Matrix<double>(ann[DEF_ANN_LAYERS][i][DEF_ANN_WEIGHT][DEF_ANN_ROWS].asDouble(),
				 ann[DEF_ANN_LAYERS][i][DEF_ANN_WEIGHT][DEF_ANN_COLS].asDouble(), 0);
	bias = Matrix<double>(ann[DEF_ANN_LAYERS][i][DEF_ANN_BIAS][DEF_ANN_ROWS].asDouble(),
			      ann[DEF_ANN_LAYERS][i][DEF_ANN_BIAS][DEF_ANN_COLS].asDouble(), 0);
	for (unsigned int j = 0; j < weights.rows() * weights.cols(); ++j)
	  weights[j] = ann[DEF_ANN_LAYERS][i][DEF_ANN_WEIGHT][DEF_ANN_VALUES][j].asDouble();
	for (unsigned int j = 0; j < bias.rows() * bias.cols(); ++j)
	  bias[j] = ann[DEF_ANN_LAYERS][i][DEF_ANN_BIAS][DEF_ANN_VALUES][j].asDouble();
	layer->setWeights(weights);
	layer->setBias(bias);
	layer->setOutputs(Matrix<double>(ann[DEF_ANN_LAYERS][i][DEF_ANN_WEIGHT][DEF_ANN_ROWS].asDouble(),
					 1, 0));
	if (i == ann[DEF_ANN_LAYERS].size() - 1)
	  layer->setActivationFunction(_out_activation);
	else
	  layer->setActivationFunction(_layer_activation);
	_layers.push_back(layer);
      }
    if (!layer)
      throw(ANNException(ERR_ANN_LOADL));
  }

  void			ANN::Load(const char *path)
  {
    std::ifstream	file(path);
    std::string		line;
    std::string		jsonMessage("");
    Json::Reader	reader;
    Json::Value		ann;

    if (file)
      {
	while (getline(file, line))
	  jsonMessage += line;
	if (reader.parse(jsonMessage, ann))
	  {
	    LoadInfos(ann);
	    LoadGenerateInfos(ann);
	    LoadOutputActivation(ann);
	    LoadLayerActivation(ann);
	    try
	      {
		LoadLayers(ann);
	      }
	    catch (ANNException const& e)
	      {
		throw (ANNException(e.what()));
	      }
	  }
      }
    else
      throw(ANNException(ERR_ANN_PARSE));
  }
}
