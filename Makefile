#
# Compiler flags
#
CC 		= gcc
CFLAGS	= -Wall -Wextra -Werror
DBFLAGS = -Wall -Wextra -Werror -g3 -fsanitize=address

#
# Project files
#
SRCS	= push_swap.c \
		 ./libft/ft_atoi.c \
		 ./libft/ft_split.c \
		 ./libft/ft_strlen.c
OBJS	= ${SRCS:.c=.o}
LIBFT	= ./libft



INCLUDE = push_swap.h

NAME	= push_swap

RM 		= rm -rf

$(LIBFT)/%.o: %.c ${INCLUDE}
	${CC} ${CFLAGS} -I ./libft/libft.h -c $< -o $@


all : ${NAME}

${NAME} : ${OBJS} ${INCLUDE}
	make -C ./libft
	${CC} ${CFLAGS} -I ./libft/libft.h ${OBJS} -o ${NAME} 

debug : ${OBJS} ${INCLUDE}
	make -C ./libft
	${CC} ${DBFLAGS} -I ./libft/libft.h ${SRCS} -o ${NAME}

clean  :
	make -C ./libft clean
	${RM} ${OBJS}
	
fclean : clean
	make -C ./libft fclean
	${RM} ${NAME}

re : fclean all

