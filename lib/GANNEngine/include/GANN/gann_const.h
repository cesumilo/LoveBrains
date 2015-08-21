/*
** const.h for GANNEngine in /home/robin_f/Programming/Git/CPP/GANNEngine
** 
** Made by Guillaume ROBIN
** Login   <robin_f@epitech.eu>
** 
** Started on  Tue Jul 21 12:27:13 2015 Guillaume ROBIN
** Last update Tue Jul 21 16:53:38 2015 Guillaume ROBIN
*/

#ifndef GANN_CONST_H_
# define GANN_CONST_H_

# define ERR_GANN_GENERATOR	(const char *)"Error: GANN: generator failed (allocation)."
# define ERR_GANN_INVCROSS	(const char *)"Error: GANN: invalid crossover !"
# define ERR_GANN_ALLOCCROSS	(const char *)"Error: GANN: invalid crossover (allocation)."
# define ERR_GANN_INVSIZE	(const char *)"Error: GANN: invalid size of population."
# define ERR_GANN_ALLOC		(const char *)"Error: GANN: allocation failed."
# define ERR_GANN_NULL		(const char *)"Error: GANN: layer is null !"
# define ERR_GANN_GETBESTANN	(const char *)"Error: GANN: cannot get the best ann !"
# define ERR_GANN_CROSSOVER	(const char *)"Error: GANN: a layer is null"
# define ERR_GANN_MUTATION	(const char *)"Error: GANN: a layer is null"
# define ERR_GANN_DNA		(const char *)"Error: GANN: cannot use a null DNA"
# define ERR_GANN_INVCONFIG	(const char *)"Error: GANN: invalid configuration"

# define ERR_ANN_GENERATOR	(const char *)"Error: ANN: the generator failed ! (allocation)"

# define DEF_GANN_SIZE		(unsigned int)2

#endif /* !GANN_CONST_H_ */
