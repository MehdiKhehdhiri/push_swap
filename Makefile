NAME	= push_swap

SRCS	=	$(wildcard srcs/*.c)

OBJS	= ${SRCS:.c=.o}

PATH_LIBFT	= libft

CC	= cc
CFLAGS	= -Wall -Wextra -Werror -Iincludes -g

RM	= rm -rf

all:	${NAME}

${NAME}:	${OBJS}
		make -C ./libft
		${CC} ${CFLAGS} -o ${NAME} ${OBJS} ./libft/libft.a

clean:
		make -C ${PATH_LIBFT} clean
		${RM} ${OBJS}

fclean:		clean
		make -C ${PATH_LIBFT} fclean
		${RM} ${NAME}

re:		fclean all

.PHONY:		all clean fclean re
