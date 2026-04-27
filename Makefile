CC=cc
CFLAGS=-Wall -Wextra -Werror -g #-fsanitize=thread
PTHREAD_FLAGS= -pthread #-lpthread

NAME=philo

SRCS=srcs/main.c
# UTILS
SRCS += srcs/utils/utils.c srcs/utils/char_utils.c srcs/utils/print_utils.c \
		srcs/utils/simulation_utils.c
# INIT
SRCS += srcs/init/set_conditions.c srcs/init/philo_init.c
# CLEAN
SRCS += srcs/clean/clean.c
# DINNER
SRCS += srcs/dinner/start_dinner.c srcs/dinner/philo_actions.c

OBJ=$(SRCS:.c=.o)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
