SRCS = $(wildcard srcs/*.c )
OBJS = ${SRCS:.c=.o}
NAME = rush-02
CFLAGS = -Wall -Wextra -Werror

all: ${NAME}

%.o: %.c
	cc ${CFLAGS} -I includes -c $< -o $@

${NAME}: ${OBJS}
	cc ${CFLAGS} ${OBJS}  -o ${NAME}

clean:
	rm -f ${OBJS}

fclean: clean
	rm -f ${NAME}

re: fclean all

.PHONY: clean all fclean re
