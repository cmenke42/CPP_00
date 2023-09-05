# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cmenke <cmenke@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/05 18:54:58 by cmenke            #+#    #+#              #
#    Updated: 2023/09/05 21:04:08 by cmenke           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := megaphone

OBJDIR := objects

SRCS := megaphone.cpp

OBJS := $(patsubst %.cpp, ${OBJDIR}/%.o, ${SRCS})

#Production flags
# CFLAGS := -Wall -Wextra -Werror -std=c++98

#Development flags
# CFLAGS += -g -O0
# CFLAGS += -fsanitize=thread
# CFLAGS += -fsanitize=address

CC := c++

RM := rm -f

all: ${NAME}

${NAME}: ${OBJS}
	${CC} ${CFLAGS} ${OBJS} -o ${NAME}

${OBJDIR}/%.o: %.cpp | ${OBJDIR}
	${CC} ${CFLAGS} -c $< -o $@

${OBJDIR}:
	mkdir -p ${OBJDIR}

clean:
	${RM} -r ${OBJDIR}

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re

.NOTPARALLEL: