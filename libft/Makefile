NAME=		libft.a
RM=			rm -f

CC=			gcc
CFLAGS=		-Wall\
			-Werror\
			-Wextra\

GREEN = 	\033[0;32m
YELLOW = 	\033[0;33m
RED = 		\033[0;31m
RESET = 	\033[0m

SRCS=		$(shell find . -maxdepth 1 -type f -name "*.c")
OBJS=		$(SRCS:.c=.o)

all: $(NAME) clean

$(NAME): $(OBJS)
	@ar rcs $@ $^
	@echo "$(GREEN)[Libft functions Compiled!] $(RESET)"

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@$(RM) $(OBJS)

fclean: clean
	@$(RM) $(NAME)
	@echo "$(RED)[libft.a cleaned!] $(RESET)"

re: fclean all

.PHONY: all bonus clean fclean re