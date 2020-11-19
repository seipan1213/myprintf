# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sehattor <sehattor@student.42tokyo.>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/12 00:46:12 by sehattor          #+#    #+#              #
#    Updated: 2020/11/17 21:00:52 by sehattor         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = ft_strlen.c ft_strchr.c ft_strncmp.c ft_atoi.c ft_isdigit.c
OBJS = $(SRCS:.c=.o)
CC	= gcc
ARFLAGS = rc
CFLAGS = -Wall -Wextra -Werror -I.
NAME = libft.a

all: $(NAME)

$(NAME): $(OBJS)
	${AR} ${ARFLAGS} $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean $(NAME)

.PONEY: re fclean clean all
