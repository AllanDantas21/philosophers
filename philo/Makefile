SRC = src/parsers.c src/init.c src/philosophers.c src/errors.c

NAME = philo
OBJ = $(SRC:.c=.o)
CC = cc
RM = rm -rf
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re