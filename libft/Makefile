# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mzhan <marczhan33@gmail.com>               +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/30 15:28:20 by mzhan             #+#    #+#              #
#    Updated: 2021/05/21 16:57:12 by mzhan            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= libft.a

SRCS 			= ft_atoi.c \
				ft_bzero.c \
				ft_calloc.c \
				ft_isalnum.c \
				ft_isalpha.c \
				ft_isascii.c \
				ft_isdigit.c \
				ft_isprint.c \
				ft_itoa.c \
				ft_memccpy.c \
				ft_memchr.c \
				ft_memcmp.c \
				ft_memcpy.c \
				ft_memmove.c \
				ft_memset.c \
				ft_putchar_fd.c \
				ft_putendl_fd.c \
				ft_putnbr_fd.c \
				ft_putstr_fd.c \
				ft_split.c\
				ft_strchr.c \
				ft_strdup.c \
				ft_strjoin.c \
				ft_strlcat.c \
				ft_strlcpy.c \
				ft_strlen.c \
				ft_strmapi.c \
				ft_strncmp.c \
				ft_strnstr.c \
				ft_strrchr.c \
				ft_strtrim.c \
				ft_substr.c \
				ft_tolower.c \
				ft_toupper.c

BONUS			= ft_lstnew.c \
			  	ft_lstadd_front.c \
			  	ft_lstlast.c \
			  	ft_lstadd_back.c \
			  	ft_lstdelone.c \
			  	ft_lstclear.c \
			  	ft_lstsize.c \
			  	ft_lstiter.c \
				ft_lstmap.c

OBJS			= ${SRCS:.c=.o}

BONUS_OBJS		= ${BONUS:.c=.o}

AR				= ar rcs

CC 				= gcc

CFLAGS 			= -Wall -Werror -Wextra


RM 				= rm -f

INCLUDE 		= \
		  		libft.h

#**************************************************************************************************************#
#            RULES                   #

#the .o file depends upon the .c version of the file and the .h files included in the INCLUDE macro
#-c genere un fichier .o
# the -o $@ says to put the output of the compilation in the file named on the left of the : 
# $@ the file name of the target of the rule, here is the object file
# $< the name of the first prerequisite, here %.c
%.o: %.c ${INCLUDE}
	${CC} ${CFLAGS} -I ${INCLUDE} -c $< -o $@

all:			${NAME}

$(NAME):		${OBJS} ${INCLUDE}
					${AR} ${NAME} ${OBJS}


${BONUS_OBJS}: ${BONUS}
				${CC} ${CFLAGS} ${BONUS} -I ${INCLUDE}

bonus:			${OBJS} ${BONUS_OBJS}
					${AR} ${NAME} ${OBJS} ${BONUS_OBJS}

clean:
				${RM} ${OBJS} ${BONUS_OBJS}

fclean:			clean
				${RM} ${NAME}

re: 			fclean all

.PHONY: 		all clean fclean re bonus
