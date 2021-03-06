/*
** ann_const.h for neural network in /home/robin_f/Programming/Git/CPP/GANNEngine
** 
** Made by Guillaume ROBIN
** Login   <robin_f@epitech.eu>
** 
** Started on  Wed Aug 19 13:51:31 2015 Guillaume ROBIN
** Last update Wed Aug 26 13:35:47 2015 Guillaume ROBIN
*/

#ifndef ANN_CONST_H_
# define ANN_CONST_H_

# define DEF_CROSS_RATE		(double)0.7
# define DEF_RAND_MIN		(double)-5
# define DEF_RAND_MAX		(double)5

# define DEF_ANN_ROWS	(const char *)"rows"
# define DEF_ANN_COLS	(const char *)"cols"
# define DEF_ANN_VALUES	(const char *)"values"
# define DEF_ANN_WEIGHT	(const char *)"weights"
# define DEF_ANN_BIAS	(const char *)"bias"
# define DEF_ANN_INFOS	(const char *)"infos"
# define DEF_ANN_RMIN	(const char *)"min"
# define DEF_ANN_RMAX	(const char *)"max"
# define DEF_ANN_RAND	(const char *)"random"
# define DEF_ANN_CROSS	(const char *)"crossing_rate"
# define DEF_ANN_OACT	(const char *)"output_activation"
# define DEF_ANN_LACT	(const char *)"layer_activation"
# define DEF_ANN_SIGM	(const char *)"sigmoid"
# define DEF_ANN_THRES	(const char *)"threshold"
# define DEF_ANN_LAYERS	(const char *)"layers"

# define ERR_ANN_NLAYER		(char *)"Error: allocation of an ANNLayer failed."
# define ERR_ANN_INVLAYERS	(char *)"Error: invalid size of layers."
# define ERR_ANN_INVCROSSRATE	(char *)"Error: invalid crossing rate."
# define ERR_ANN_NULLACTIVATION	(char *)"Error: activation function is null."
# define ERR_ANN_ERRACTIVATE	(char *)"Error: impossible to activate a null layer."
# define ERR_ANN_INVALIDINPUT	(char *)"Error: invalid size of input matrix."

# define ERR_ANN_LOADL	(const char *)"Error: ANN::LoadLayers(): allocation failed."
# define ERR_ANN_PARSE	(const char *)"Error: ANN::Load(): Jsoncpp cannot parse the input file."
# define ERR_ANN_GETOUT	(const char *)"Error: ANN::getOutputs(): cannot get neural net's outputs."
# define ERR_ANN_ACTF	(const char *)"Error: ANN::setActivationFunction(): function is null."
# define ERR_ANN_OUTF	(const char *)"Error: ANN::setOutputsActivation(): function is null."
# define ERR_ANN_SAVE	(const char *)"Error: ANN::Save(): cannot open the output file."
# define ERR_ANN_LAYER	(const char *)"Error: ANN::SaveLayers() | ANN::LoadLayers(): layer is null."
# define ERR_ANN_WEIGHT	(const char *)"Error: ANN::LoadLayers(): invalid weights matrix."
# define ERR_ANN_BIAS	(const char *)"Error: ANN::LoadLayers(): invalid bias matrix."
# define ERR_ANN_OUTPUT	(const char *)"Error: ANN::LoadLayers(): cannot create the outputs matrix."

#endif /* !ANN_CONST_H_ */
