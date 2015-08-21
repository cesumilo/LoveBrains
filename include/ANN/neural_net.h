/*
** NeuralNet.h for GANNEngine in /home/robin_f/Programming/Git/CPP/GANNEngine
** 
** Made by Guillaume ROBIN
** Login   <robin_f@epitech.eu>
** 
** Started on  Wed Jul  8 14:47:02 2015 Guillaume ROBIN
** Last update Fri Aug 21 23:52:24 2015 Guillaume ROBIN
*/

#ifndef NEURAL_NET_H_
# define NEURAL_NET_H_

# include "ANN/ann_layer.h"
# include "ANN/ann_exception.h"
# include "json/json.h"

namespace GANN
{
  /*!
   * \class ANN
   * \brief Define what is a neural network.
   */
  class ANN
  {
  public:
    /*!
     * \brief Define the type of the activation function.
     */
    enum class ActivationType { SIGMOID, THRESHOLD, CUSTOM };

    /*!
     * \brief Constructor.
     */
    ANN(void) throw();
    /*!
     * \brief Constructor.
     * \param infos : Contains the topology of the neural network.
     */
    ANN(std::vector<unsigned int> const& infos);
    /*!
     * \brief Destructor.
     */
    ~ANN(void) throw();

    /*
    ** Getters.
    */

    /*!
     * \brief Get the matrix of outputs.
     * \return GANN::Matrix<double> const&
     */
    Matrix<double> const&		getOutputs(void) const;
    /*!
     * \brief Get the minimum value of the randomization range.
     * \return double
     */
    double				getMinRandom(void) const throw();
    /*!
     * \brief Get the maximum value of the randomization range.
     * \return double
     */
    double				getMaxRandom(void) const throw();
    /*!
     * \brief Get the vector that contains all the layers of the neural network.
     * \return std::vector<ANNLayer *> const&
     */
    std::vector<ANNLayer *> const&	getLayers(void) const throw();
    /*!
     * \brief Get the topology of the neural network.
     * \return std::vector<unsigned int> const&
     */
    std::vector<unsigned int> const&	getInfos(void) const throw();
    /*!
     * \brief Get the crossing rate of the nerual network.
     * \return double
     */
    double				getCrossingRate(void) const throw();
    /*!
     * \brief Get the activation function of the intern layers.
     * \return GANN::ANNLayer::FActivate
     */
    ANNLayer::FActivate			getActivationFunction(void) const throw();
    /*!
     * \brief Get the activation function of the output layer.
     * \return GANN::ANNLayer::FActivate
     */
    ANNLayer::FActivate			getOutputsActivation(void) const throw();
    /*!
     * \brief Get the activation function's type of the intern layers.
     * \return ANN::ActivationType
     */
    ActivationType			getOutputType(void) const throw();
    /*!
     * \brief Get the activation function's type of the output layer.
     * \return ANN::ActivationType
     */
    ActivationType			getLayerType(void) const throw();

    /*
    ** Setters.
    */

    /*!
     * \brief Set the range of the randomization.
     * \param min : the minimum value.
     * \param max : the maximum value.
     */
    void	setRandom(double min, double max) throw();
    /*!
     * \brief Set the vector of layers.
     * \param layers : Contains all the layers.
     */
    void	setLayers(std::vector<ANNLayer *> const& layers) throw();
    /*!
     * \brief Set the crossing rate of the neural network.
     * \param rate : Contains the new crossing rate.
     */
    void	setCrossingRate(double rate) throw();
    /*!
     * \brief Set the function pointer of the intern layers activation function.
     * \param f : Contains the function pointer.
     * \param type : Contains the type of the activation function.
     */
    void	setActivationFunction(ANNLayer::FActivate f, ActivationType type);
    /*!
     * \brief Set the function pointer of the output layer's activation function.
     * \param f : Contains the function pointer.
     * \param type : Contains the type of the activation function.
     */
    void	setOutputsActivation(ANNLayer::FActivate f, ActivationType type);

    /*
    ** Overload.
    */
    ANN&	operator=(ANN const& b);

    /*
    ** Methods.
    */

    /*!
     * \brief Create a neural network.
     * \param infos : Contains the topology of the neural network.
     */
    void	Create(std::vector<unsigned int> const& infos);
    /*!
     * \brief Activate the neural network and set the matrix of outputs.
     * \param inputs : Contains the inputs for the neural network.
     */
    void	Activate(Matrix<double> const& inputs);
    /*!
     * \brief Save the neural network in JSON (using the librairy called "Jsoncpp").
     * \param path : the path to the output file.
     */
    void	Save(const char *path) const;
    /*!
     * \brief Load the neural network from the JSON file (using the librairy called "Jsoncpp").
     * \param path : the path to the input file.
     */
    void	Load(const char *path);

  private:
    double			_rand_min; /*!< Contains the minimum value of the randomization range. */
    double			_rand_max; /*!< Contains the maximum value of the randomization range. */
    double			_cross_rate; /*!< Contains the crossing rate of the neural network. */
    ActivationType		_out_ftype; /*!< Contains the type of the output layer's activation function. */
    ActivationType		_layer_ftype; /*!< Contains the type of the intern layers activation function. */
    ANNLayer::FActivate		_out_activation; /*!< Contains the function pointer of the output layer's activation function. */
    ANNLayer::FActivate		_layer_activation; /*!< Contains the function pointer of the intern layers activation function. */
    std::vector<unsigned int>	_infos; /*!< Contains the topology of the neural network. */
    std::vector<ANNLayer *>	_layers; /*!< Contains the layers of the neural network. */

    /*
    ** Methods.
    */

    /*!
     * \brief Save the topology of the neural network.
     * \param ann : Contains the json neural network.
     */
    void	SaveInfos(Json::Value& ann) const throw();
    /*!
     * \brief Save the range of the randomization.
     * \param ann : Contains the json neural network.
     */
    void	SaveRandomize(Json::Value& ann) const throw();
    /*!
     * \brief Save the type of the output layer's activation function.
     * \param ann : Contains the json neural network.
     */
    void	SaveOutputActivation(Json::Value& ann) const throw();
    /*!
     * \brief Save the type of the intern layers activation function.
     * \param ann : Contains the json neural network.
     */
    void	SaveLayerActivation(Json::Value& ann) const throw();
    /*!
     * \brief Save the values contained in all the layers.
     * \param ann : Contains the json neural network.
     * \return error : ANNException
     */
    void	SaveLayers(Json::Value& ann) const;


    /*!
     * \brief Load the topology of the neural network.
     * \param ann : Contains the json neural network.
     */
    void	LoadInfos(Json::Value const& ann) throw();
    /*!
     * \brief Load the informations in order to generate the neural network.
     * \param ann : Contains the json neural network.
     */
    void	LoadGenerateInfos(Json::Value const& ann) throw();
    /*!
     * \brief Load the output layer's activation function.
     * \param ann : Contains the json neural network.
     */
    void	LoadOutputActivation(Json::Value const& ann) throw();
    /*!
     * \brief Load the intern layers activation function.
     * \param ann : Contains the json neural network.
     */
    void	LoadLayerActivation(Json::Value const& ann) throw();
    /*!
     * \brief Load the layers of the neural network.
     * \param ann : Contains the json neural network.
     * \return error : ANNException
     */
    void	LoadLayers(Json::Value const& ann);
  };
}

#endif /* !NEURAL_NET_H_ */
