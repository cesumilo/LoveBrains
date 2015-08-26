##
## Makefile for GANNEngine in /home/robin_f/Programming/Git/CPP/GANNEngine
## 
## Made by Guillaume ROBIN
## Login   <robin_f@epitech.eu>
## 
## Started on  Tue Jul  7 16:36:25 2015 Guillaume ROBIN
## Last update Tue Aug 25 17:22:17 2015 Guillaume ROBIN
##

CC	= g++

RM	= rm -f

NAME	= libANN.a

CXXFLAGS	+= -Werror -Wextra -Wall -std=c++11

CXXFLAGS	+= -I ./include

LDFLAGS	= -lm

SRCS	+= src/ANN/ann_layer.cc \
	   src/ANN/ann_exception.cc \
	   src/ANN/neural_net.cc \
	   src/ANN/neural_net_load.cc \
	   src/ANN/neural_net_save.cc \
	   src/ANN/tools.cc

SRCS	+= src/json/jsoncpp.cc

OBJS	= $(SRCS:.cc=.o)


all: $(NAME)

%.o: %.cc
	$(CC) -fPIC -o $@ $(CXXFLAGS) $(LDFLAGS) -c $<

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all re clean fclean
