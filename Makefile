CC=			gcc
NAME=		libftprintf.a
RM=			rm -f
CD=			cd

CFLAGS=		-Wall\
			-Werror\
			-Wextra\

SRC_DIR=	src
LFT_DIR=	libft

GREEN = 	\033[0;32m
YELLOW = 	\033[0;33m
RED = 		\033[0;31m
RESET = 	\033[0m

SRCS=		$(shell find $(SRC_DIR) -maxdepth 1 -type f -name "*.c")
OBJS=		$(SRCS:.c=.o)

all: $(NAME)

$(NAME): libft $(OBJS)
	@cp $(LFT_DIR)/libft.a ./libftprintf.a
	@ar rcs $@ $(OBJS)
	@echo "$(GREEN)[Printf Compiled!] $(RESET)"

%.o: %.c $(INCLUDE)
		@$(CC) $(CFLAGS) -c $< -o $@

libft:
	@$(MAKE) all -C ./libft

clean:
	@$(RM) $(OBJS)
	@echo "$(RED)[ft_printf.o cleaned!] $(RESET)"

fclean: clean
	@$(CD) $(LFT_DIR) && make -i fclean
	@$(RM) $(NAME)
	@echo "$(RED)[libftprintf.a cleaned!] $(RESET)"

re: fclean all

.PHONY: all libft clean fclean re