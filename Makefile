# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fsandel <fsandel@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/24 14:34:39 by fsandel           #+#    #+#              #
#    Updated: 2022/10/25 14:55:24 by fsandel          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			= cc
RM			= rm -f
CFLAGS		=# -Wall -Wextra -Werror
AFLAGS		= ar -rcs
NAME		= libftprintf.a
EXEC		= ft_printf.out

SRCS		= 	ft_printf.c \
				ft_print_arg.c \
				ft_print_utils.c

LIBDIR 		= 	/libft/libft.a

OBJS		= $(SRCS:.c=.o)

all:		$(NAME)

$(NAME):	$(OBJS)
			@cd libft && make
			$(AFLAGS) $(NAME) $(OBJS)

clean:
			$(RM) $(OBJS) $(BONUS_OBJS)

fclean:		clean
			$(RM) $(NAME)

re:			fclean
			$(NAME)

run:		$(NAME)
			$(CC) -o $(EXEC) *.c -L. -lftprintf -Llibft -lft
			./$(EXEC)

.PHONY:		all clean fclean re run
