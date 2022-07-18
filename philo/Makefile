# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wmari <wmari@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/07 10:08:22 by wmari             #+#    #+#              #
#    Updated: 2022/07/18 18:39:23 by wmari            ###   ########.fr        #
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
			)

OBJS	=	$(SRCS:.c=.o)

$(NAME)	:	$(OBJS)
			$(CC) $(LFLAGS) -o $(NAME) $(OBJS)
			
all		:	$(NAME)

%.o		:	%.c
			$(CC) $(CFLAGS) -pthread -c $< -o $@

clean	:
			rm -f $(OBJS)

fclean	:	clean
			rm -f $(NAME)

re		:	fclean all

.PHONY	:	all clean fclean re