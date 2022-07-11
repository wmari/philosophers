# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wmari <wmari@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/11 11:36:50 by wmari             #+#    #+#              #
#    Updated: 2022/07/11 16:10:38 by wmari            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	philo

CC		=	cc
CFLAGS	=	-Wall -Wextra -Werror

ifeq ($(DEBUG), 1)
	CFLAGS += -g
endif

SRCS	=	$(addprefix srcs/, \
			main.c \
			routine.c \
			on_exit.c\
			init_rules.c \
			go_eat.c \
			sleep_and_repeat.c \
			print_str.c \
			)

OBJS	=	 $(SRCS:.c=.o)

OBJSDIR	=	objs

$(NAME)	:	$(OBJS)
			$(CC) -pthread -o $(NAME) $(OBJS)
			
all		:	$(NAME)

%.o		:	%.c
			$(CC) $(CFLAGS) -pthread -c $< -o $@

clean	:
			rm -f $(OBJS)

fclean	:	clean
			rm -f $(NAME)

re		:	fclean all

.PHONY	:	all clean fclean re