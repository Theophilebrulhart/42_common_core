# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tbrulhar <tbrulhar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/11 11:08:44 by tbrulhar          #+#    #+#              #
#    Updated: 2023/01/13 13:22:20 by tbrulhar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = main.cpp Animal.cpp Dog.cpp Cat.cpp WrongCat.cpp WrongAnimal.cpp
OBJ = $(SRC:.cpp=.o) 
GPP = c++ 
RM = rm -f 
GFLAGS = -Wall -Wextra -Werror -std=c++98

NAME = animal

all: $(NAME) 

$(NAME): $(OBJ) 
		$(GPP) $(GFLAGS) -o $(NAME) $(OBJ) 

clean: 
		$(RM) $(OBJ) 

fclean: clean 
		$(RM) $(NAME) 

re: fclean $(NAME) 

.PHONY:        all clean fclean re