# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rbony <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/28 08:34:54 by rbony             #+#    #+#              #
#    Updated: 2022/03/08 19:23:45 by rbony            ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

NAME = philo_bonus

SRCS = 	srcs/philo_bonus.c					\
		srcs/philo_utils.c				\
		srcs/fncts/ft_atoi.c			\
		srcs/fncts/ft_die.c				\
		srcs/fncts/ft_eat.c				\
		srcs/fncts/ft_isdigit.c			\
		srcs/fncts/ft_lstadd_back.c		\
		srcs/fncts/ft_lstclear.c		\
		srcs/fncts/ft_lstlast.c			\
		srcs/fncts/ft_lstnew.c			\
		srcs/fncts/ft_sleep.c			\
		srcs/fncts/ft_take_fork.c		\
		srcs/fncts/ft_think.c			\
		srcs/fncts/initialisations.c	\
		srcs/fncts/kill_philos.c		\
		srcs/fncts/manage_thread.c		\
		srcs/fncts/routine.c			\
		srcs/fncts/take_forks.c
		

OBJS = ${SRCS:.c=.o}

HEADERS = 	headers/philo_bonus.h

CC = gcc
RM = rm -f

FLAGS = -Wall -Wextra -Werror

all: ${NAME}

bonus: ${NAME}

$(NAME): ${OBJS}
	${CC} ${OBJS} -lpthread -o ${NAME}
	
%.o : %.c ${HEADERS} Makefile
	${CC} ${FLAGS} -I headers -c $< -o ${<:.c=.o}

clean:
	${RM} ${OBJS}

fclean:	clean
	${RM} ${NAME}

re:	fclean all
         
.PHONY: all clean fclean re 
