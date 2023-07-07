SRCS	= ft_itoa_print.c ft_printf.c ft_putchar_print.c ft_putstr_print.c ft_sort_out.c ft_itoa_base_print.c

OBJS= ${SRCS:.c=.o}

CFLAGS= -Wall -Werror -Wextra
NAME := libftprintf.a                

all: $(NAME)

.c.o:
	@echo Compiling $<
	gcc -c $(CFLAGS) $< -o ${<:.c=.o}

$(NAME): $(OBJS)
	@echo make $(NAME)
	ar -rcs $(NAME) $(OBJS)

re:	fclean $(NAME)

clean:
	@echo Cleaning out those old .o
	@$(RM) $(OBJS)

fclean: clean
	@echo Cleaning out that old $(NAME)
	@$(RM) $(NAME)

out:
	gcc $(CFLAGS) $(SRCS)

cleanout:
	$(RM) a.out

.PHONY:        all clean fclean re