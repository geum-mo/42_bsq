# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gekang <gekang@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/07/22 15:57:05 by gekang            #+#    #+#              #
#    Updated: 2020/07/22 15:59:16 by gekang           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = bsq
SRCS = ${wildcard srcs/*.c} # change later

OBJS = ${SRCS:.c=.o}

CC = gcc
CFLAGS = -Wall -Wextra -Werror

RM = rm -f

INC = -I includes

.c.o:
	${CC} ${CFLAGS} ${INC} -c ${<} -o ${<:.c=.o}

$(NAME): ${OBJS}
	${CC} ${CFALGS} ${INC} ${SRCS} -o ${NAME}

all: ${NAME}

clean:
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME}

re: fclean all
