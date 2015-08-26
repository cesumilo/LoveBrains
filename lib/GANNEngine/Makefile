##
## Makefile for GANNEngine in /home/robin_f/Programming/Git/CPP/GANNEngine
## 
## Made by Guillaume ROBIN
## Login   <robin_f@epitech.eu>
## 
## Started on  Tue Jul  7 16:36:25 2015 Guillaume ROBIN
## Last update Tue Aug 25 16:57:02 2015 Guillaume ROBIN
##

CC	= g++

RM	= rm -f

NAME	= libGANNEngine.a

CXXFLAGS	+= -Werror -Wextra -Wall -pthread -std=c++11

CXXFLAGS	+= -I ./include

LDFLAGS	= -lm

SRCS	+= src/ANN/ann_layer.cc \
	   src/ANN/neural_net.cc \
	   src/ANN/tools.cc \
	   src/ANN/ann_generator.cc \
	   src/ANN/neural_net_save.cc \
	   src/ANN/neural_net_load.cc \
	   src/ANN/ann_exception.cc

SRCS	+= src/GA/population.cc \
	   src/GA/population_exception.cc \
	   src/GA/ga_engine.cc \
	   src/GA/ga_engine_exception.cc \
	   src/GA/ga_config.cc \
	   src/GA/a_observer.cc \
	   src/GA/a_observable.cc \
	   src/GA/i_dna.cc \
	   src/GA/i_generator.cc

SRCS	+= src/GANN/gann.cc \
	   src/GANN/gann_engine.cc \
	   src/GANN/gann_exception.cc \
	   src/GANN/gann_crossover.cc

SRCS	+= src/json/jsoncpp.cc

OBJS	= $(SRCS:.cc=.o)


all: $(NAME)

%.o: %.cc
	$(CC) -o $@ $(CXXFLAGS) $(LDFLAGS) -c $<

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all re clean fclean
