# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rbony <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/28 08:34:54 by rbony             #+#    #+#              #
#    Updated: 2022/02/28 16:27:28 by rbony            ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

NAME = philo

SRCS = 	philo.c								\
		philo_init.c						\
		manage_threads.c					\
		actions.c							\
		philo_utils.c						\
		libft/ft_atoi.c						\
		libft/ft_isdigit.c					\
		libft/ft_lstlast.c					\
		libft/ft_lstnew.c					\
		libft/ft_lstclear.c					\
		libft/ft_lstadd_back.c				\

OBJS = ${SRCS:.c=.o}

INCLUDES = 	philo.h

CC = gcc
RM = rm -f

FLAGS = -Wall -Wextra -Werror

all: ${NAME}

$(NAME): ${OBJS}
	${CC} ${OBJS} -lpthread -o ${NAME}
	
%.o : %.c ${INCLUDES}
	${CC} -c $< -o ${<:.c=.o}

clean:
	${RM} ${OBJS}

fclean:	clean
	${RM} ${NAME} ${EXECUTABLE}

re:	fclean all
         
.PHONY: all clean fclean re 
