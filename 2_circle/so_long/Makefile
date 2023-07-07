
SRCS         =	main.c\
				get_next_line/get_next_line.c\
				get_next_line/get_next_line_utils.c\
				files_management.c \
				game.c \
				mlx_hook.c \
				moove_player.c \
				end_game.c \
				printf/ft_printf.c\
				printf/ft_sort_out.c\
				printf/ft_itoa_print.c\
				printf/ft_itoa_base_print.c\
				printf/ft_putchar_print.c\
				printf/ft_putstr_print.c\

OBJS         = ${SRCS:.c=.o}

NAME         = so_long

AR             = ar rcs

GCC            = gcc

RM             = rm -f

CFLAGS         = -Wall -Wextra -Werror

MLX_PATH    =     ./mlx/

LBFT_PATH    =     ./libft/

FRAMLIBS    =     -L ${LBFT_PATH} -lft -L ${MLX_PATH} -lmlx -framework OpenGL -framework AppKit

all:         $(NAME)

.c.o:
			$(GCC) $(CFLAGS) -Imlx -c $< -o $@

$(NAME):     $(OBJS)
			@$(MAKE) -C $(LBFT_PATH)
			@$(MAKE) -C $(MLX_PATH)
			$(GCC) $(OBJS) $(CFLAGS) -I ${MLX_PATH} -I ${LBFT_PATH} -o $(NAME) $(FRAMLIBS)

clean:
			${RM} ${OBJS}
			@$(MAKE) -C $(LBFT_PATH) clean
			@$(MAKE) -C $(MLX_PATH) clean

fclean:     clean
			${RM} ${NAME}
			@$(MAKE) -C $(LBFT_PATH) fclean