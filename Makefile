CC		= gcc
CFLAGS	= - Wall -Wextra -Werror
PRINT1	= ar -rcs
PRINT2 	= ranlib
RM		= /bin/rm -f

NAME	= ft_printf.a

INCLUDE	= ft_printf.h
SRCS	= ft_printf.c ft_printf_utils.c
OBJS	= $(SRCS:.c=.o)

all:		$(NAME)

$(NAME):	$(OBJS)   $(INCLUDE)
			$(PRINT1) $(NAME) $(OBJS)
			$(PRINT2) $(NAME)

.c.o:
			$(CC) $(CFLAGS) -I $(INCLUDE) -c $< -o $(,:.c=.o)

clean:
			$(RM) $(OBJS)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re
