##
## Makefile for GANNEngine in /home/robin_f/Programming/Git/CPP/GANNEngine
## 
## Made by Guillaume ROBIN
## Login   <robin_f@epitech.eu>
## 
## Started on  Tue Jul  7 16:36:25 2015 Guillaume ROBIN
## Last update Thu Jul 30 19:08:25 2015 Guillaume ROBIN
##

CC	= g++ -g3

RM	= rm -f

NAME	= libANN.a

CXXFLAGS	+= -Werror -Wextra -Wall -pthread -std=c++11

CXXFLAGS	+= -I ./include

LDFLAGS	= -lm

SRCS	+= src/ANN/ann_layer.cc \
	   src/ANN/neural_net.cc \
	   src/ANN/tools.cc

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
