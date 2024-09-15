NAME	=	DiamondTrap

SRCS	=	ClapTrap.cpp	\
			DiamondTrap.cpp	\
			FragTrap.cpp	\
			main.cpp		\
			ScavTrap.cpp

OBJS	=	$(SRCS:.cpp=.o)

CXX		=	c++
CXXFLAG	=	-Wall -Wextra -Werror -std=c++98 -Wshadow -Wno-shadow

all : $(NAME)

%.o : %.cpp
	$(CXX) $(CXXFLAG) -c $< -o $@

$(NAME) : $(OBJS)
	$(CXX) $(CXXFLAG) $(OBJS) -o $(NAME)

clean :
	rm -f $(OBJS)

fclean :
	rm -f $(OBJS) $(NAME)

re :
	make fclean
	make all

.PHONY : all clean fclean re