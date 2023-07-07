SRC = main.cpp
OBJ = $(SRC:.cpp=.o) 
GPP = g++ 
RM = rm -f 
GFLAGS = -Wall -Wextra -Werror -std=c++98

NAME = sed

all: $(NAME) 

$(NAME): $(OBJ) 
		$(GPP) $(GFLAGS) -o $(NAME) $(OBJ) 

clean: 
		$(RM) $(OBJ) 

fclean: clean 
		$(RM) $(NAME) 

re: fclean $(NAME) 

.PHONY:        all clean fclean re