/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryhara <ryhara@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 10:30:43 by ryhara            #+#    #+#             */
/*   Updated: 2023/08/04 14:41:44 by ryhara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sa(t_node *head_a)
{
	t_node	*node_1;
	t_node	*node_2;

	node_1 = head_a->next;
	node_2 = node_1->next;
	head_a->next = node_2;
	node_1->prev = node_2;
	node_1->next = node_2->next;
	node_2->next->prev = node_1;
	node_2->next = node_1;
	node_2->prev = head_a;
	ft_putstr_fd("sa\n", 1);
}

void	sb(t_node *head_b)
{
	t_node	*node_1;
	t_node	*node_2;

	node_1 = head_b->next;
	node_2 = node_1->next;
	head_b->next = node_2;
	node_1->prev = node_2;
	node_1->next = node_2->next;
	node_2->next->prev = node_1;
	node_2->next = node_1;
	node_2->prev = head_b;
	ft_putstr_fd("sb\n", 1);
}

void	ss(t_node *head_a, t_node *head_b)
{
	sa(head_a);
	sb(head_b);
	ft_putstr_fd("ss\n", 1);
}
