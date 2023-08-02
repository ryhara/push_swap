# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ryhara <ryhara@student.42tokyo.jp>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/02 10:11:33 by ryhara            #+#    #+#              #
#    Updated: 2023/08/02 14:59:42 by ryhara           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# swap.c push.c rotate.c reverse_rotate.c

NAME = push_swap
SRCS =  main.c \
		stack_new.c stack_head_init.c stack_add_back.c stack_add_front.c stack_free_all.c stack_print.c \
		ft_atoi.c check_args.c print.c
OBJS = $(SRCS:%.c=$(OBJDIR)%.o)
OBJDIR = ./obj/
CC = cc
RM = rm -rf
CFLAGS = -Wall -Wextra -Werror

all : $(OBJDIR) $(NAME)

$(NAME): $(OBJS)
	$(CC) -o $@ $^

$(OBJDIR):
	mkdir obj

$(OBJDIR)%.o: %.c
	$(CC) $(CFLAGS)  -o $@ -c $<

clean :
	$(RM) $(OBJDIR)

fclean : clean
	$(RM) $(NAME)

re : fclean all

.PHONY : all clean fclean re