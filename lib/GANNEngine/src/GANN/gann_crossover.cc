//
// gann_crossover.cc for GANNEngine in /home/robin_f/Programming/Git/CPP/GANNEngine
// 
// Made by Guillaume ROBIN
// Login   <robin_f@epitech.eu>
// 
// Started on  Tue Jul 21 17:08:08 2015 Guillaume ROBIN
// Last update Wed Aug 19 17:05:48 2015 Guillaume ROBIN
//

#include "GANN/gann_engine.h"
#include "GANN/gann_const.h"
#include "ANN/tools.h"

namespace GANN
{
  static bool	containsInt(std::vector<unsigned int>& vect, unsigned int pattern)
  {
    for (unsigned int i = 0; i < vect.size(); ++i)
      {
	if (vect[i] == pattern)
	  return (true);
      }
    return (false);
  }

  static Matrix<double> 	MatrixCrossover(Matrix<double> const& m1, Matrix<double> const& m2, double rate)
  {
    std::vector<unsigned int>	index;
    unsigned int		tmp;
    unsigned int		size = m1.rows() * (double)m1.cols() * rate;
    unsigned int		i = 0;
    Matrix<double>		m(m1.rows(), m1.cols(), 0);

    while (i < size)
      {
	tmp = RandomInt(0, size);
	if (containsInt(index, (unsigned int)tmp) == false)
	  {
	    index.push_back((unsigned int)tmp);
	    i++;
	  }
      }
    for (unsigned int i = 0; i < m.rows() * m.cols(); ++i)
      {
	if (containsInt(index, i) == true)
	  m[i] = m1[i];
	else
	  m[i] = m2[i];
      }
    return (m);
  }

  GA::IDNA			*GANNEngine::ANNCrossover(const GA::IDNA *s1, const GA::IDNA *s2)
  {
    GA::IDNA			*child;
    ANN				ann;
    std::vector<ANNLayer *>	b1 = ((GANN *)s1)->getGenes().getLayers();
    std::vector<ANNLayer *>	b2 = ((GANN *)s2)->getGenes().getLayers();
    std::vector<ANNLayer *>	layers;
    Matrix<double>		tmp;

    if (b1.size() != b2.size())
      throw (GANNException(ERR_GANN_INVCROSS));
    ann.Create(((GANN *)s1)->getGenes().getInfos());
    for (unsigned int i = 0; i < b1.size(); i++)
      {
	layers.push_back(new ANNLayer());
	if (!b1[i] || !b2[i])
	  throw (GANNException(ERR_GANN_CROSSOVER));
	tmp = MatrixCrossover(b1[i]->getWeights(), b2[i]->getWeights(), ((GANN *)s1)->getGenes().getCrossingRate());
	if (!layers[i])
	  throw (GANNException(ERR_GANN_CROSSOVER));
	layers[i]->setWeights(tmp);
	tmp = MatrixCrossover(b1[i]->getBias(), b2[i]->getBias(), ((GANN *)s1)->getGenes().getCrossingRate());
	layers[i]->setBias(tmp);
	layers[i]->setOutputs(Matrix<double>(tmp.rows(), 1, 0));
	layers[i]->setActivationFunction(b1[i]->getActivationFunction());
      }
    ann.setLayers(layers);
    ann.setRandom(((GANN *)s1)->getGenes().getMinRandom(), ((GANN *)s1)->getGenes().getMaxRandom());
    ann.setActivationFunction(((GANN *)s1)->getGenes().getActivationFunction(),
			      ((GANN *)s1)->getGenes().getLayerType());
    ann.setOutputsActivation(((GANN *)s1)->getGenes().getOutputsActivation(),
			     ((GANN *)s1)->getGenes().getOutputType());
    ann.setCrossingRate(((GANN *)s1)->getGenes().getCrossingRate());
    if (!(child = new GANN(ann)))
      throw (GANNException(ERR_GANN_ALLOCCROSS));
    return (child);
  }
}
