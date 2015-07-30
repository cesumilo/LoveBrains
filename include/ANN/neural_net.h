/*
** NeuralNet.h for GANNEngine in /home/robin_f/Programming/Git/CPP/GANNEngine
** 
** Made by Guillaume ROBIN
** Login   <robin_f@epitech.eu>
** 
** Started on  Wed Jul  8 14:47:02 2015 Guillaume ROBIN
** Last update Tue Jul 21 16:53:58 2015 Guillaume ROBIN
*/

#ifndef NEURAL_NET_H_
# define NEURAL_NET_H_

# include "ANN/ann_layer.h"

namespace GANN
{
  class ANN
  {
  public:
    ANN(void);
    ANN(std::vector<unsigned int> const& infos);
    ~ANN(void);

    /*
    ** Getters.
    */
    Matrix<double> const&		getOutputs(void) const;
    double				getMinRandom(void) const;
    double				getMaxRandom(void) const;
    std::vector<ANNLayer *> const&	getLayers(void) const;
    std::vector<unsigned int> const&	getInfos(void) const;
    double				getCrossingRate(void) const;
    ANNLayer::FActivate			getActivationFunction(void) const;
    ANNLayer::FActivate			getOutputsActivation(void) const;

    /*
    ** Setters.
    */
    void	setRandom(double min, double max);
    void	setLayers(std::vector<ANNLayer *> const& layers);
    void	setCrossingRate(double rate);
    void	setActivationFunction(ANNLayer::FActivate f);
    void	setOutputsActivation(ANNLayer::FActivate f);

    /*
    ** Overload.
    */
    ANN&	operator=(ANN const& b);

    /*
    ** Methods.
    */
    void	Create(std::vector<unsigned int> const& infos);
    void	Activate(Matrix<double> const& inputs);

  private:
    std::vector<unsigned int>	_infos;
    std::vector<ANNLayer *>	_layers;
    double			_rand_min;
    double			_rand_max;
    double			_cross_rate;
    ANNLayer::FActivate		_out_activation;
    ANNLayer::FActivate		_layer_activation;
  };
}

#endif /* !NEURAL_NET_H_ */
