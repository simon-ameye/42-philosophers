################	COMPILER		#################

CC			=		gcc -Wall -Wextra -Werror -pthread

################	DIRECTORIES		#################

SRCS_DIR	=		src

OBJS_DIR	=		obj

INCLUDE_DIR	=		include

#################	HEADER FILES	#################

INCLUDE		=		-I include

#################	SOURCE FILES	#################

SRCS		= 		philo.c  philo_check.c  philo_data.c  philo_eat.c  philo_mutex.c  philo_print.c  philo_think.c  philo_thread.c  philo_time.c  philo_utils_1.c  philo_utils_2.c
SOURCES		=		$(addprefix $(SRCS_DIR)/,$(SRCS))

#################	OBJECT FILES	#################

OBJS		=		$(addsuffix .o, $(basename $(SRCS)))
OBJECTS		=		$(addprefix $(OBJS_DIR)/,$(OBJS))

################	BINARIES		#################

NAME		=		philo

################	TARGETS			#################

all:				$(NAME)

$(NAME):			$(OBJS_DIR) $(OBJECTS)
					@echo Building $@...
					@$(CC) $(INCLUDE) $(OBJECTS) -o $(NAME)

$(OBJS_DIR):
					mkdir -p $@

$(OBJECTS):			$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c
					@$(CC) $(INCLUDE) -c $< -o $@

clean:
					@echo Cleaning $@ objects...
					@rm -f $(OBJECTS)

fclean:				clean
					@echo Cleaning $@ binary...
					@rm -f $(NAME)

re:					fclean all

.PHONY:				all clean fclean re
