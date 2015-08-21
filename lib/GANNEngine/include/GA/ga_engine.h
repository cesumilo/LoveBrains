/*
** ga_engine.h for GAEngine in /home/robin_f/Programming/Git/CPP/GANNEngine/include/GA
** 
** Made by Guillaume ROBIN
** Login   <robin_f@epitech.eu>
** 
** Started on  Wed Jul  8 14:02:16 2015 Guillaume ROBIN
** Last update Wed Jul 29 14:04:17 2015 Guillaume ROBIN
*/

#ifndef GA_ENGINE_H_
# define GA_ENGINE_H_

# include "GA/ga_engine_exception.h"
# include "GA/population.h"
# include "GA/a_observer.h"

namespace GA
{
  class GAEngine : public AObserver
  {
  public:
    /*
    ** Constructor & Destructor.
    */
    GAEngine(void);
    ~GAEngine(void);

    /*
    ** Getters.
    */
    Population const&		getPopulation(void) const throw();
    Population&			getPopulation(void) throw();
    double			getMutationRate(void) const throw();
    double			getSelectionRate(void) const throw();
    unsigned int		getPoolSize(void) const throw();
    GA::GAConfig::FEvaluate	getEvaluation(void) const throw();
    int				getMaxEpochs(void) const throw();
    unsigned int		getReportInterval(void) const throw();
    unsigned int		getNumberOfThread(void) const throw();
    double			getExpectedFitness(void) const throw();

    /*
    ** Setters.
    */
    void	setMaxEpochs(int max) throw();
    void	setExpectedFitness(double fitness) throw();
    void	setNumberOfThreads(unsigned int nb) throw();
    void	setReportInterval(unsigned int nb) throw();

    void	setMutationRate(double rate);
    void	setSelectionRate(double rate);
    void	setPoolSize(unsigned int size);

    /*
    ** Overload.
    */
    GAEngine&	operator=(GAEngine const& engine);

    /*
    ** Methods : CreatePopulation.
    */
    void		CreatePopulation(GAConfig const& config, unsigned int size);
    unsigned int       	Evolve(bool report);

  private:
    GA::GAConfig::FEvaluate		_evaluate;
    int					_max_epochs;
    unsigned int			_report_interval;
    unsigned int			_nb_threads;
    double				_expected_fitness;
    Population				_pop;
  };
}

#endif /* !GA_ENGINE_H_ */
