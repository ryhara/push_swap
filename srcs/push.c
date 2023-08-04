/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryhara <ryhara@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 10:29:58 by ryhara            #+#    #+#             */
/*   Updated: 2023/08/04 19:32:13 by ryhara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	pa(t_node *head_a, t_node *head_b)
{
	t_node	*tmp;

	tmp = head_b->next;
	head_b->next = tmp->next;
	tmp->next->prev = head_b;
	node_add_front(head_a, tmp);
	ft_putstr_fd("pa\n", 1);
}

void	pb(t_node *head_a, t_node *head_b)
{
	t_node	*tmp;

	tmp = head_a->next;
	head_a->next = tmp->next;
	tmp->next->prev = head_a;
	node_add_front(head_b, tmp);
	ft_putstr_fd("pb\n", 1);
}

void	push_min_b(t_stack *stack, t_node *min)
{
	size_t	pos;
	t_node	*head;

	head = stack->head_a;
	pos = get_pos(head, min);
	if (pos > (stack->size / 2))
	{
		while (head->next != min)
			rra(head);
		pb(stack->head_a, stack->head_b);
	}
	else
	{
		while (head->next != min)
			ra(head);
		pb(stack->head_a, stack->head_b);
	}
}
