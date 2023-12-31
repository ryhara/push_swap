# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ryhara <ryhara@student.42tokyo.jp>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/02 10:11:33 by ryhara            #+#    #+#              #
#    Updated: 2023/08/10 13:30:04 by ryhara           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
SRCDIR = ./srcs/
SRC =   main.c \
		stack.c node.c ft_free.c swap.c rotate.c reverse_rotate.c push.c \
		sort_utils.c sort.c sort_many.c get_max_min.c insert_count.c \
		check_args.c args_two_exe.c args_multi_exe.c \
		ft_atoi.c ft_split.c ft_strlcpy.c ft_print_utils.c
SRCS = $(addprefix $(SRCDIR), $(SRC))
OBJDIR = ./obj/
OBJS = $(addprefix $(OBJDIR), $(SRC:%.c=%.o))
CC = cc
RM = rm -rf
CFLAGS = -Wall -Wextra -Werror

all : $(OBJDIR) $(NAME)

$(NAME): $(OBJS)
	$(CC) -o $@ $^

$(OBJDIR):
	mkdir $(OBJDIR)

$(OBJDIR)%.o: $(SRCDIR)%.c
	$(CC) $(CFLAGS) -o $@ -c $<

clean :
	$(RM) $(OBJDIR)

fclean : clean
	$(RM) $(NAME)

re : fclean all

.PHONY : all clean fclean re