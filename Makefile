# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fsandel <fsandel@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/24 14:34:39 by fsandel           #+#    #+#              #
#    Updated: 2022/10/28 15:31:17 by fsandel          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			= cc
RM			= rm -f
CFLAGS		= -Wall -Wextra -Werror
AFLAGS		= ar -rcs
NAME		= libftprintf.a
EXEC		= ft_printf.out
MAIN		= main.c

SRCS		= 	ft_printf.c \
				ft_printf_arg.c \
				ft_printf_arg2.c \
				ft_printf_utils.c

LIBFTSRCS=	libft/ft_bzero.c \
			libft/ft_calloc.c \
			libft/ft_memset.c \
			libft/ft_strdup.c \
			libft/ft_strlen.c \
			libft/ft_toupper.c \
			libft/ft_putchar_fd.c \
			libft/ft_putstr_fd.c \
			libft/ft_putnbr_fd.c  


OBJS		= $(SRCS:.c=.o)

LIBFTOBJS	= $(LIBFTSRCS:.c=.o)

all:		$(NAME)

$(NAME):	$(OBJS) $(LIBFTOBJS)
			$(AFLAGS) $(NAME) $(OBJS) $(LIBFTOBJS)

clean:
			$(RM) $(OBJS) $(LIBFTOBJS)

fclean:		clean
			$(RM) $(NAME)

re:			fclean $(NAME)

run:		$(NAME)
			$(CC) -o $(EXEC) $(SRCS) $(LIBFTSRCS) $(MAIN) -L. -lftprintf
			./$(EXEC)

.PHONY:		all clean fclean re run
