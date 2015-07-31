# LoveBrains - API Description

# Description
As it was mention in the LoveBrains README.md file, you can create a plugin to add several features. The API is very simple, the big part is your job that is creating a plugin !

# How to compile my plugin with the API ?
I have created a little example in the directory called "mods". However, I give you an example of a Makefile :

```make

CC	= g++

RM	= rm -f

# -- Put your name below /!\ ".so" is MANDATORY /!\ -- #
NAME	= plugin_name.so

CXXFALGS	+= -std=c++11

CXXFLAGS	+= -I ./include/ -I ./api/include/ -I ./api/lib/ANNLibrary/include/

LDFLAGS	= -lANN -L./api/lib/ANNLibrary/ -lsfml-graphics -lsfml-window -lsfml-system

# -- Add your sources below -- #
SRCS	+=

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

```

If you copy and paste this Makefile, you can be sure that your plugin is compatible with LoveBrains !

# Interfaces

## IPlugin interface

```c++

  class IPlugin
  {
  public:
    /*
    ** Typedef.
    */
    /*
    ** Madatory name for the PluginCreator function : "CreatePlugin"
    ** Example: IPlugin	*CreatePlugin(void);
    */
    typedef IPlugin	*(*PluginCreator)(void);

    virtual ~IPlugin(void) { }

    /*
    ** Methods.
    */
    virtual std::vector<Graphics::IObject *>&	getObjects(void) = 0;
    virtual std::vector<Graphics::ICollider *>&	getColliders(void) = 0;
    virtual std::vector<Graphics::ISensor *>&	getSensors(void) = 0;
  };

```

> virtual std::vector<Graphics::IObject *>&	getObjects(void) = 0;

This function is called by LoveBrains to add your objects in the factory. Your objects have to inherit of IObject interface described below.

> virtual std::vector<Graphics::ICollider *>&	getColliders(void) = 0;

Work in progress...
