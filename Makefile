##
## Makefile for LoveBrains in /home/robin_f/Programming/Git/CPP/LoveBrains
## 
## Made by Guillaume ROBIN
## Login   <robin_f@epitech.eu>
## 
## Started on  Wed Jul 22 09:52:28 2015 Guillaume ROBIN
## Last update Wed Aug 26 12:28:51 2015 Guillaume ROBIN
##

CC	= g++

RM	= rm -f

NAME	= LoveBrains

CXXFLAGS	+= -Werror -Wall -Wextra -pthread -std=c++11

CXXFLAGS	+= -I ./include/

LDFLAGS	= -lGANNEngine -L ./lib/GANNEngine/ -lsfml-graphics -lsfml-window -lsfml-system -ldl

SRCS	+= src/Graphics/factory_object.cc \
	   src/Graphics/physics.cc \
	   src/Graphics/environment.cc

SRCS	+= src/Simulator/simulator_exception.cc \
	   src/Simulator/simulator_config.cc \
	   src/Simulator/simulator.cc

SRCS	+= src/Plugin/plugin_manager.cc \
	   src/Plugin/plugin_exception.cc

SRCS	+= src/App/config_getter.cc \
	   src/App/config_manager.cc \
	   src/App/app.cc \
	   src/App/app_exception.cc

SRCS	+= src/main.cc

OBJS	= $(SRCS:.cc=.o)

all: lib $(NAME)

lib:
	make -C ./lib/GANNEngine/

clib:
	make clean -C ./lib/GANNEngine/

flib:
	make fclean -C ./lib/GANNEngine/

%.o: %.cc
	$(CC) $(CXXFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	$(CC) $(CXXFLAGS) $(OBJS) -o $(NAME) $(LDFLAGS)

clean: clib
	$(RM) $(OBJS)

fclean: flib clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all re clean fclean lib clib flib
