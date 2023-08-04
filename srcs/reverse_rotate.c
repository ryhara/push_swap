/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryhara <ryhara@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 10:30:17 by ryhara            #+#    #+#             */
/*   Updated: 2023/08/04 10:11:48 by ryhara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void rra(t_stack *head_a)
{
	t_stack *stack_top;
	t_stack *stack_bottom;

	printf("%d %d %d\n", head_a->next->number, head_a->next->next->number, head_a->next->next->next->number);
	stack_top = head_a->next;
	stack_bottom = head_a->prev;
	stack_bottom->prev->next = head_a;
	stack_top->prev = stack_bottom;
	head_a->next = stack_bottom;
	head_a->prev = stack_bottom->prev;
	stack_bottom->next = stack_top;
	stack_bottom->prev = head_a;
	ft_putstr_fd("rra\n",1);
	printf("%d %d %d\n", head_a->next->number, head_a->next->next->number, head_a->next->next->next->number);
}

void rrb(t_stack *head_b)
{
	t_stack *stack_top;
	t_stack *stack_bottom;

	stack_top = head_b->next;
	stack_bottom = head_b->prev;
	head_b->next = stack_bottom;
	head_b->prev = stack_bottom->prev;
	stack_top->prev = stack_bottom;
	stack_bottom->prev->next = head_b;
	stack_bottom->next = stack_top;
	stack_bottom->prev = head_b;
	ft_putstr_fd("rrb\n",1);
}

void rrr(t_stack *head_a, t_stack *head_b)
{
	rra(head_a);
	rrb(head_b);
	ft_putstr_fd("rrr\n",1);
}