##
##  Makefile
##  cpp_gkrellm
##
##  Created by Valentin Pichard on 21/01/2017.
##

cli:
	@($(MAKE) -C front/cli/.)

ncurses:
	@($(MAKE) -C front/ncurses/.)

qt:
	@($(MAKE) -C front/Qt/.)

all:	cli ncurses qt

clean:
	@(cd front/cli/. && make clean)
	@(cd front/ncurses/. && make clean)
	@(cd front/Qt/. && make clean)

fclean:	clean
	@(cd front/cli/. && make fclean)
	@(cd front/ncurses/. && make fclean)

re:	fclean all

.PHONY:	all clean fclean re cli ncurses qt
