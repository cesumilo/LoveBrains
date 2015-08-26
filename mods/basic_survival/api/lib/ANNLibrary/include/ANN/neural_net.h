/*
** NeuralNet.h for GANNEngine in /home/robin_f/Programming/Git/CPP/GANNEngine
** 
** Made by Guillaume ROBIN
** Login   <robin_f@epitech.eu>
** 
** Started on  Wed Jul  8 14:47:02 2015 Guillaume ROBIN
** Last update Thu Aug 20 12:42:46 2015 Guillaume ROBIN
*/

#ifndef NEURAL_NET_H_
# define NEURAL_NET_H_

# include "ANN/ann_layer.h"
# include "ANN/ann_exception.h"
# include "json/json.h"

namespace GANN
{
  class ANN
  {
  public:
    enum class ActivationType { SIGMOID, THRESHOLD, CUSTOM };

    ANN(void) throw();
    ANN(std::vector<unsigned int> const& infos);
    ~ANN(void) throw();

    /*
    ** Getters.
    */
    Matrix<double> const&		getOutputs(void) const;
    double				getMinRandom(void) const throw();
    double				getMaxRandom(void) const throw();
    std::vector<ANNLayer *> const&	getLayers(void) const throw();
    std::vector<unsigned int> const&	getInfos(void) const throw();
    double				getCrossingRate(void) const throw();
    ANNLayer::FActivate			getActivationFunction(void) const throw();
    ANNLayer::FActivate			getOutputsActivation(void) const throw();
    ActivationType			getOutputType(void) const throw();
    ActivationType			getLayerType(void) const throw();

    /*
    ** Setters.
    */
    void	setRandom(double min, double max) throw();
    void	setLayers(std::vector<ANNLayer *> const& layers) throw();
    void	setCrossingRate(double rate) throw();
    void	setActivationFunction(ANNLayer::FActivate f, ActivationType type);
    void	setOutputsActivation(ANNLayer::FActivate f, ActivationType type);

    /*
    ** Overload.
    */
    ANN&	operator=(ANN const& b);

    /*
    ** Methods.
    */
    void	Create(std::vector<unsigned int> const& infos);
    void	Activate(Matrix<double> const& inputs);
    void	Save(const char *path) const;
    void	Load(const char *path);

  private:
    double			_rand_min;
    double			_rand_max;
    double			_cross_rate;
    ActivationType		_out_ftype;
    ActivationType		_layer_ftype;
    ANNLayer::FActivate		_out_activation;
    ANNLayer::FActivate		_layer_activation;
    std::vector<unsigned int>	_infos;
    std::vector<ANNLayer *>	_layers;

    /*
    ** Methods.
    */
    void	SaveInfos(Json::Value& ann) const throw();
    void	SaveRandomize(Json::Value& ann) const throw();
    void	SaveOutputActivation(Json::Value& ann) const throw();
    void	SaveLayerActivation(Json::Value& ann) const throw();
    void	SaveLayers(Json::Value& ann) const;

    void	LoadInfos(Json::Value const& ann) throw();
    void	LoadGenerateInfos(Json::Value const& ann) throw();
    void	LoadOutputActivation(Json::Value const& ann) throw();
    void	LoadLayerActivation(Json::Value const& ann) throw();
    void	LoadLayers(Json::Value const& ann);
  };
}

#endif /* !NEURAL_NET_H_ */
