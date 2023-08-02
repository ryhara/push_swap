/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryhara <ryhara@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 10:30:32 by ryhara            #+#    #+#             */
/*   Updated: 2023/08/02 19:15:04 by ryhara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ra(t_stack *head_a)
{
	t_stack *stack_top;
	t_stack *stack_bottom;

	stack_top = head_a->next;
	stack_bottom = head_a->prev;
	head_a->next = stack_top->next;
	head_a->prev = stack_top;
	stack_bottom->next = stack_top;
	stack_top->next = head_a;
	stack_top->prev = stack_bottom;
	ft_putstr_fd("ra\n",1);
}

void rb(t_stack *head_b)
{
	t_stack *stack_top;
	t_stack *stack_bottom;

	stack_top = head_b->next;
	stack_bottom = head_b->prev;
	head_b->next = stack_top->next;
	head_b->prev = stack_top;
	stack_bottom->next = stack_top;
	stack_top->next = head_b;
	stack_top->prev = stack_bottom;
	ft_putstr_fd("rb\n",1);
}

void rr(t_stack *head_a, t_stack *head_b)
{
	ra(head_a);
	rb(head_b);
	ft_putstr_fd("rr\n",1);
}