# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wmari <wmari@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/07 10:08:22 by wmari             #+#    #+#              #
#    Updated: 2022/07/22 12:27:55 by wmari            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	philo

CC		=	cc
CFLAGS	=	-Wall -Wextra -Werror

ifeq ($(DEBUG), 1)
	CFLAGS += -g -fsanitize=thread
endif

LFLAGS = -pthread

ifeq ($(DEBUG), 1)
	LFLAGS += -fsanitize=thread
endif
SRCS	=	$(addprefix srcs/, \
			main.c \
			start_sim.c \
			init_rules.c \
			check_death.c \
			print_str.c\
			quit_sim.c \
			go_eat.c \
			go_sleep.c \
			check_arg.c \
			check_nb_of_eat.c \
			ft_atoi.c \
			my_sleep.c \
			utils.c \
			take_fork.c \
			)

OBJS	=	$(SRCS:.c=.o)

INC		=	./inc/philo.h

$(NAME)	:	$(OBJS)
			$(CC) $(LFLAGS) -o $(NAME) $(OBJS)
			
all		:	$(NAME)

%.o		:	%.c
			$(CC) $(CFLAGS) -pthread -c $< -o $@

$(OBJS)	:	$(INC)

clean	:
			rm -f $(OBJS)

fclean	:	clean
			rm -f $(NAME)

re		:	fclean all

.PHONY	:	all clean fclean re