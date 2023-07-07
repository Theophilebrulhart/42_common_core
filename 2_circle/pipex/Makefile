SRCS         =	main.c\
				parsing_command.c\
				ft_split.c\
				child_execution.c\
				error_file.c\
				waitpid.c\
				access_path.c\
				printf/ft_printf.c\
				printf/ft_sort_out.c\
				printf/ft_itoa_print.c\
				printf/ft_itoa_base_print.c\
				printf/ft_putchar_print.c\
				printf/ft_putstr_print.c\

OBJS         = ${SRCS:.c=.o}

NAME         = pipex

AR             = ar rcs

GCC            = gcc

RM             = rm -f

CFLAGS         = -Wall -Wextra -Werror -g


all:         $(NAME)

.c.o:
			$(GCC) $(CFLAGS) -c $< -o $@

$(NAME):     $(OBJS)
			$(GCC) $(OBJS) $(CFLAGS) -o $(NAME)

re:	fclean $(NAME)

clean:
			${RM} ${OBJS}

fclean:     clean
			${RM} ${NAME}