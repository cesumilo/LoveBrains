/*
** graphics_const.h for LoveBrains in /home/robin_f/Programming/Git/CPP/LoveBrains
** 
** Made by Guillaume ROBIN
** Login   <robin_f@epitech.eu>
** 
** Started on  Wed Jul 22 14:11:24 2015 Guillaume ROBIN
** Last update Mon Aug 24 15:09:56 2015 Guillaume ROBIN
*/

#ifndef GRAPHICS_CONST_H_
# define GRAPHICS_CONST_H_

/*
** Errors.
*/
# define ERR_OFACTORY_REGISTER	(const char *)"Error: FactoryObjects::Register: null object"
# define ERR_OFACTORY_REGKEY   	(const char *)"Error: FactoryObjects::Register: key already exists"

# define ERR_PHYSICS_CREATE	(const char *)"Error: Physics::UpdateEnv: factory's creation is null"

# define ERR_ENV_INVALIDFILE	(const char *)"Error: Environment: invalid configuration file"
# define ERR_ENV_INVALIDTYPE	(const char *)"Error: Environment: invalid type of object"
# define ERR_ENV_INVALIDNUMOFOB	(const char *)"Error: Environment: invalid number of objects"

/*
** Default values.
*/
# define DEF_IA_TYPE	(const char *)"nanobrain"

# define DEF_APP_TITLE	(const char *)"LoveBrains - Create your mind !"
# define DEF_APP_WIDTH	(unsigned int)1280
# define DEF_APP_HEIGHT	(unsigned int)720
# define DEF_APP_FRAMER	(unsigned int)60
# define DEF_APP_FONTS	(char *)"resources/fonts/"
# define DEF_APP_BRAINS	(const char *)"brains/"
# define DEF_APP_TOURN	(const char *)"tournament.txt"

# define DEF_ENV_POINTCHAR	(char)'.'
# define DEF_ENV_DELIM		(const char *)","
# define DEF_ENV_DELIMCHAR	(char)','
# define DEF_ENV_MINCHAR	(char)'a'
# define DEF_ENV_MAXCHAR	(char)'z'
# define DEF_ENV_MINNUM		(char)'0'
# define DEF_ENV_MAXNUM		(char)'9'
# define DEF_ENV_SPACECHAR	(char)' '
# define DEF_ENV_UNDERCHAR	(char)'_'
# define DEF_ENV_DASHCHAR	(char)'-'
# define DEF_ENV_BOOLEAN	(const char *)"true"
# define DEF_ENV_STRBFITNESS	(const char *)"Best fitness: "
# define DEF_ENV_STRAFITNESS	(const char *)"Average fitness: "
# define DEF_ENV_STREPOCHS	(const char *)"Epochs: "
# define DEF_ENV_SEP_SCORE	(const char *)" : "

#endif /* !GRAPHICS_CONST_H_ */
