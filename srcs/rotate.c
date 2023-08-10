/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryhara <ryhara@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 10:30:32 by ryhara            #+#    #+#             */
/*   Updated: 2023/08/10 12:27:24 by ryhara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ra(t_node *head_a)
{
	t_node	*top;
	t_node	*bottom;

	top = head_a->next;
	bottom = head_a->prev;
	if (top == bottom)
		return ;
	head_a->next = top->next;
	head_a->prev = top;
	bottom->next = top;
	top->next = head_a;
	top->prev = bottom;
	ft_putstr_fd("ra\n", STDOUT_FILENO);
}

void	rb(t_node *head_b)
{
	t_node	*top;
	t_node	*bottom;

	top = head_b->next;
	bottom = head_b->prev;
	if (top == bottom)
		return ;
	head_b->next = top->next;
	head_b->prev = top;
	bottom->next = top;
	top->next = head_b;
	top->prev = bottom;
	ft_putstr_fd("rb\n", STDOUT_FILENO);
}

void	rr(t_node *head_a, t_node *head_b)
{
	t_node	*top;
	t_node	*bottom;

	top = head_a->next;
	bottom = head_a->prev;
	if (top == bottom)
		return ;
	head_a->next = top->next;
	head_a->prev = top;
	bottom->next = top;
	top->next = head_a;
	top->prev = bottom;
	top = head_b->next;
	bottom = head_b->prev;
	if (top == bottom)
		return ;
	head_b->next = top->next;
	head_b->prev = top;
	bottom->next = top;
	top->next = head_b;
	top->prev = bottom;
	ft_putstr_fd("rr\n", STDOUT_FILENO);
}
