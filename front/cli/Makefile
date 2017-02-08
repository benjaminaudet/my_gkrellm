##
##  Makefile
##  cpp_gkrellm
##
##  Created by Valentin Pichard on 21/01/2017.
##

SRC=		main.cpp \
		../../back/CPU.cpp \
		../../back/Memory.cpp \
		../../back/Network.cpp \
		../../back/SysInfo.cpp

NAME=		cli.exe

XX=		g++

OBJ=		$(SRC:.cpp=.o)

CXXFLAGS=	-g -W -Wall -Wextra -std=c++11

INC=		-I../../back/.

all:		$(NAME)
			@echo '==== END BUILDING CLI ===='

$(NAME):	$(OBJ)
		@$(XX) -o $(NAME) $(OBJ) $(INC) $(CXXFLAGS)
		@mv $(NAME) ../../.

clean:
		@rm -f $(OBJ)

fclean:		clean
		@rm -f $(NAME)

re:		fclean all

.PHONY:		all clean fclean re

.cpp.o:
		@$(XX) -c $< -o $@ $(INC) $(CXXFLAGS)
