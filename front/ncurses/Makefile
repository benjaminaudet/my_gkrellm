SRC=		Modules/main.cpp \
		Modules/cpu/Cpu.cpp \
		Modules/date/Date.cpp \
		Modules/name/Name.cpp \
		Modules/network/Network.cpp \
		Modules/os/OS.cpp \
		Modules/ram/Ram.cpp \
		Modules/time/Time.cpp \
		../../back/SysInfo.cpp \
		../../back/CPU.cpp \
		../../back/Memory.cpp \
		../../back/Network.cpp \

NAME=		ncurses_mode

XX=		g++

OBJ=		$(SRC:.cpp=.o)

#CXXFLAGS=	-g -W -Wall -Wextra -std=c++03

INC=		-I../

all:		$(NAME)
#@echo '==== END BUILDING NCURSES MODE ===='

$(NAME):	$(OBJ)
		@$(XX) -o $(NAME) $(OBJ) $(INC) -lncurses $(CXXFLAGS)
		@mv $(NAME) ../../.

clean:
		@rm -f $(OBJ)

fclean:		clean
		@rm -f ../../$(NAME)

re:		fclean all

.PHONY:		all clean fclean re

.cpp.o:
		@$(XX) -c $< -o $@ $(INC) $(CXXFLAGS)
