NAME = philo
INC = philo.h

SRCS += philo.c
SRCS += philo_utils1.c
SRCS += philo_data.c
SRCS += philo_init.c
SRCS += philo_utils2.c
SRCS += philo_utils3.c

OBJS_DIR = obj
OBJS = $(addprefix $(OBJS_DIR)/,$(SRCS:.c=.o))
CC = gcc -Wall -Wextra -Werror

all : $(OBJS_DIR) $(NAME)

$(OBJS_DIR)/ :
	$(shell mkdir -p $(OBJS_DIR))

$(NAME) : $(OBJS)
	$(CC) $(OBJS) -o $@

$(OBJS_DIR)/%.o : %.c
	@echo "compiling $<"
	@$(CC) -c $< -o $@

bonus : all

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re