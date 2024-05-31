SRC = src/parsers.c src/utils.c src/philosophers.c src/errors.c src/inits.c src/routine.c

NAME = philo
OBJ = $(SRC:.c=.o)
CC = cc
RM = rm -rf
CFLAGS = -Wall -Wextra -Werror -lpthread

Reset = \033[0m
G = \033[32m
R = \033[31m
Y = \033[33m
blink = \033[5m

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)
	@echo "$(blink) $(G) ✅ $(NAME) successfully compiled $(Reset)"

hell:
	valgrind --tool=helgrind ./philo 3 300 100 100 3
val:
	valgrind --leak-check=full ./philo 3 300 100 100 3
clean:
	$(RM) $(OBJ)
	@echo "$(Y) 😉 Objects from the $(NAME) project have been removed $(Reset)"

fclean: clean
	$(RM) $(NAME)
	@echo "$(R) ❌ removed $(NAME) executable $(Reset)"

re: fclean all

.PHONY: all clean fclean re
