/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryhara <ryhara@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 10:13:38 by ryhara            #+#    #+#             */
/*   Updated: 2023/08/02 14:13:26 by ryhara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define BOOLEAN int
# define TRUE 1
# define FALSE 0

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

typedef struct s_stack
{
	int number;
	struct s_stack *next;
	struct s_stack *prev;
} t_stack;

void stack_head_init(t_stack *head);
t_stack *stack_new(int number);
void stack_add_front(t_stack *head, t_stack *new);
void stack_add_back(t_stack *head, t_stack *new);
void stack_free_all(t_stack *head);
void	stack_print(t_stack *head);
int	ft_atoi(const char *nptr);


#endif