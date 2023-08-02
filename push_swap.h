/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryhara <ryhara@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 10:13:38 by ryhara            #+#    #+#             */
/*   Updated: 2023/08/02 20:51:07 by ryhara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define BOOLEAN int
# define TRUE 1
# define FALSE 0

# include <limits.h>
# include <stdlib.h>
# include <unistd.h>
#include <stdio.h>

typedef struct s_stack
{
	int				number;
	struct s_stack	*next;
	struct s_stack	*prev;
}					t_stack;

void	stack_head_init(t_stack *head);
t_stack	*stack_new(int number);
void	stack_add_front(t_stack *head, t_stack *new);
void	stack_add_back(t_stack *head, t_stack *new);
void	stack_free_all(t_stack *head);
void	stack_print(t_stack *head);

void ss(t_stack *head_a, t_stack *head_b);
void sa(t_stack *head_a);
void sb(t_stack *head_b);
void rr(t_stack *head_a, t_stack *head_b);
void ra(t_stack *head_a);
void rb(t_stack *head_b);
void rrr(t_stack *head_a, t_stack *head_b);
void rra(t_stack *head_a);
void rrb(t_stack *head_b);
void pa(t_stack *head_a, t_stack *head_b);
void pb(t_stack *head_a, t_stack *head_b);

void sort_3(t_stack *head_a);
void sort_5(t_stack *head_a, t_stack *head_b);

void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
int		ft_atoi(const char *nptr);

BOOLEAN	check_int(int ans, char sign, char *s);
BOOLEAN	check_args(int argc, char **argv);

#endif