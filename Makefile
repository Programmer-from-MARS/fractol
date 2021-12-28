NAME		= fractol

SRC			= add_pictures.c\
			initialize.c\
			color.c\
			mouse_control.c\
			key_control.c\
			formulas.c\
			fern.c\
			fractol_main.c\
			mandelbrot.c\
			render.c\

OBJ			= $(SRC:.c=.o)

FLAGS		= -Wall -Wextra -Werror -O3

RM			= rm -f

%.o:		%.c *.h
			gcc $(FLAGS) -c $< -o $(<:.c=.o)

all:		$(NAME)

$(NAME):	$(OBJ)
			gcc $(FLAGS) -include fractol.h -o $(NAME) $(OBJ) -L /usr/local/lib/ -lmlx -framework OpenGL -framework AppKit

clean:
			$(RM) $(OBJ)

fclean:		clean
			$(RM) $(NAME) $(BNAME)

re:			fclean all

.PHONY:		all clean fclean re