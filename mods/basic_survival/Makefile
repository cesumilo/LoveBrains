##
## Makefile for Basic_survival_mod in /home/robin_f/Programming/Git/CPP/LoveBrains/test/mod_basic_survival
## 
## Made by Guillaume ROBIN
## Login   <robin_f@epitech.eu>
## 
## Started on  Thu Jul 30 16:03:56 2015 Guillaume ROBIN
## Last update Fri Jul 31 16:41:58 2015 Guillaume ROBIN
##

CC	= g++

RM	= rm -f

NAME	= basic_survival.so

CXXFALGS	+= -std=c++11

CXXFLAGS	+= -I ./include/ -I ./api/include/ -I ./api/lib/ANNLibrary/include/

LDFLAGS	= -lANN -L./api/lib/ANNLibrary/ -lsfml-graphics -lsfml-window -lsfml-system

SRCS	+= src/circle.cc \
	   src/plugin.cc \
	   src/ia.cc

OBJS	= $(SRCS:.cc=.o)


all: lib $(NAME)

lib:
	make -C ./api/lib/ANNLibrary/

clib:
	make clean -C ./api/lib/ANNLibrary/

flib:
	make fclean -C ./api/lib/ANNLibrary/

%.o: %.cc
	$(CC) -fPIC $(LDFLAGS) -c $< -o $@ $(CXXFLAGS)

$(NAME): $(OBJS)
	$(CC) -shared $(OBJS) -o $(NAME) -Wl,--whole-archive -lANN -L./api/lib/ANNLibrary -Wl,--no-whole-archive

clean: clib
	$(RM) $(OBJS)

fclean: clean flib
	$(RM) $(NAME)

re: fclean all

.PHONY: all re clean fclean lib clib flib
