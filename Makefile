NAME = philo
INC = philo.h

SRCS += philo.c
SRCS += philo_utils1.c

OBJS_DIR = obj/
OBJS = $(addprefix $(OBJS_DIR),$(SRCS:.c=.o))

CC = gcc -Wall -Wextra -Werror


all: $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(OBJS) -lm -o $(NAME)

$(OBJS): $(OBJS_DIR)%.o: %.c $(OBJS_DIR)
	$(CC) -c $< -o $@

$(OBJS_DIR):
	mkdir $@

bonus : all

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
