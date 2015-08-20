/*
** app_const.h for LoveBrains in /home/robin_f/Programming/Git/CPP/LoveBrains
** 
** Made by Guillaume ROBIN
** Login   <robin_f@epitech.eu>
** 
** Started on  Fri Jul 31 11:49:24 2015 Guillaume ROBIN
** Last update Thu Aug 20 13:21:34 2015 Guillaume ROBIN
*/

#ifndef APP_CONST_H_
# define APP_CONST_H_

/*
** Error strings.
*/
# define ERR_APP_INVALIDCONF	(const char *)"Error: ConfigManager: invalid configuration file"
# define ERR_APP_UNEXPECTED_TOK	(const char *)"Error: ConfigManager: unexpected token: "
# define ERR_APP_SIMULATOR	(const char *)"Error: App: cannot initialize the simulator"
# define ERR_APP_NEEDIA		(const char *)"Error: App: no brains found"

# define ERR_APP_HELP (const char *)"Usage: ./LoveBrains simulationFile environmentFile outputFile"

/*
** Default values.
*/
# define DEF_FUNCTION_SIGMOID	(const char *)"sigmoid"
# define DEF_FUNCTION_THRESHOLD	(const char *)"threshold"
# define DEF_DELIMITER_SIZE	(const char *)"x"
# define DEF_MAX_GETTERS	(unsigned int)12
# define DEF_GET_CROSSING_RATE	(const char *)"crossing_rate"
# define DEF_GET_MUTATION_RATE	(const char *)"mutation_rate"
# define DEF_GET_SELECTION_RATE	(const char *)"selection_rate"
# define DEF_GET_EXPECTED_FIT	(const char *)"expected_fitness"
# define DEF_GET_POOL_SIZE	(const char *)"tournament pool_size"
# define DEF_GET_MAX_EPOCHS	(const char *)"max epochs"
# define DEF_GET_REPORT_INTER	(const char *)"report interval"
# define DEF_GET_POPULATION_SIZ	(const char *)"population size"
# define DEF_GET_ANNINFOS	(const char *)"neural network"
# define DEF_GET_ACTIVATION	(const char *)"activation function"
# define DEF_GET_OACTIVATION	(const char *)"outputs activation function"
# define DEF_GET_ENVIRONMENT_S	(const char *)"environment size"

# define DEF_CONST_MINCHAR	(char)'a'
# define DEF_CONST_MAXCHAR	(char)'z'
# define DEF_CONST_SPCHAR	(char)' '
# define DEF_CONST_DELIMCHAR	(char)':'
# define DEF_CONST_DELIMSTR	(const char *)":"
# define DEF_CONST_SPACESTR	(const char *)" "
# define DEF_CONST_DASHCHAR	(char)'-'
# define DEF_CONST_UNDERSCHAR	(char)'_'
# define DEF_CONST_MINNUMCHAR	(char)'0'
# define DEF_CONST_MAXNUMCHAR	(char)'9'

#endif /* !APP_CONST_H_ */
