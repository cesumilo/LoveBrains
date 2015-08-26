/*
** gann.h for GANNEngine in /home/robin_f/Programming/Git/CPP/GANNEngine
** 
** Made by Guillaume ROBIN
** Login   <robin_f@epitech.eu>
** 
** Started on  Wed Jul  8 19:53:34 2015 Guillaume ROBIN
** Last update Tue Aug 25 17:18:15 2015 Guillaume ROBIN
*/

#ifndef GANN_ENGINE_H_
# define GANN_ENGINE_H_

# include "GA/ga_engine.h"
# include "GANN/gann_exception.h"
# include "GANN/gann.h"

namespace GANN
{
  class GANNEngine
  {
  public:
    GANNEngine(void) throw();
    ~GANNEngine(void) throw();

    /*
    ** Initializer.
    */
    void	Init(GA::GAConfig const& config, unsigned int size);

    /*
    ** Getters.
    */
    ANN const&		getBestANN(void) const;
    GA::GAEngine&	getGAEngine(void) throw();
    GA::GAEngine const&	getGAEngine(void) const throw();
    GA::GAConfig const&	getGAConfig(void) const throw();

    /*
    ** Setters.
    */
    void		setGAConfig(GA::GAConfig const& config);

    /*
    ** Methods.
    */
    void	StartSimulation(bool report);

  private:
    /*
    ** GA Parameters.
    */
    unsigned int	_pool_size;
    double		_mutation_rate;
    double		_selection_rate;

    GA::GAEngine       	_engine;
    GA::GAConfig	_config;

    /*
    ** GA Functions.
    */
    static bool       	ANNComparator(const GA::IDNA *, const GA::IDNA *);
    static GA::IDNA	*ANNCrossover(const GA::IDNA *, const GA::IDNA *);
    static void       	ANNMutation(GA::IDNA *);
  };
}

#endif /* !GANN_ENGINE_H_ */
