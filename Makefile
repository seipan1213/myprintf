CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror
SRCDIR	=	./srcs/
SRCS	=	${SRCDIR}ft_printf.c ${SRCDIR}fill.c ${SRCDIR}print_sub.c ${SRCDIR}organize.c ${SRCDIR}analyze.c
OBJS	=	${SRCS:.c=.o}
ARFLAGS	=	rcs
NAME	=	libftprintf.a
HEADER	=	./includes/
LIBFT	=	./libft/

all: ${NAME}

${NAME}: ${OBJS}
	make -C ${LIBFT}
	cp ${LIBFT}libft.a ${NAME}
	${AR} ${ARFLAGS} ${NAME} ${OBJS}

clean:
	${RM} ${OBJS}
	make clean -C ${LIBFT}

fclean: clean
	${RM} ${NAME}
	make fclean -C ${LIBFT}

re: fclean ${NAME}

.PHONY: all clean fclean re
