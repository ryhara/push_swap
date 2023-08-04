/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryhara <ryhara@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 10:30:17 by ryhara            #+#    #+#             */
/*   Updated: 2023/08/04 19:32:22 by ryhara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	rra(t_node *head_a)
{
	t_node	*top;
	t_node	*bottom;
	t_node	*bottom_prev;

	top = head_a->next;
	bottom = head_a->prev;
	bottom_prev = bottom->prev;
	bottom_prev->next = head_a;
	top->prev = bottom;
	head_a->next = bottom;
	head_a->prev = bottom_prev;
	bottom->next = top;
	bottom->prev = head_a;
	ft_putstr_fd("rra\n", 1);
}

void	rrb(t_node *head_b)
{
	t_node	*top;
	t_node	*bottom;

	top = head_b->next;
	bottom = head_b->prev;
	head_b->next = bottom;
	head_b->prev = bottom->prev;
	top->prev = bottom;
	bottom->prev->next = head_b;
	bottom->next = top;
	bottom->prev = head_b;
	ft_putstr_fd("rrb\n", 1);
}

void	rrr(t_node *head_a, t_node *head_b)
{
	rra(head_a);
	rrb(head_b);
	ft_putstr_fd("rrr\n", 1);
}
