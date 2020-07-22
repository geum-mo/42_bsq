# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gekang <gekang@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/07/22 15:57:05 by gekang            #+#    #+#              #
#    Updated: 2020/07/22 22:05:27 by gekang           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = bsq
SRCS = srcs/check_input_map.c srcs/main.c srcs/mem_mgt.c srcs/parsing_map.c srcs/process.c srcs/solve.c srcs/stdin.c srcs/util_funcs.c
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
