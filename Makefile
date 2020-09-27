CC		= gcc

CFLAGS	= -Wall -Wextra -Werror

SRCDIR = srcs
INCDIR = includes

SRCS	= ${SRCDIR}/dictionary.c ${SRCDIR}/dictionary2.c ${SRCDIR}/error.c ${SRCDIR}/main.c ${SRCDIR}/baselib.c ${SRCDIR}/baselib2.c ${SRCDIR}/sort_dict.c ${SRCDIR}/tab_math.c ${SRCDIR}/tab_math2.c ${SRCDIR}/translate.c
OBJS	= ${SRCS:.c=.o}

NAME	= rush-02

all:		${NAME}

${NAME}:	
			${CC} ${CFLAGS} -o ${NAME} ${SRCS} -I ${INCDIR}

clean:		
			rm -f ${OBJS}

fclean:		clean
			rm -f ${NAME}

re:			fclean all

.PHONY:		all clean fclean re
