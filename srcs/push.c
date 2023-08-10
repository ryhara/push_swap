/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryhara <ryhara@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 10:29:58 by ryhara            #+#    #+#             */
/*   Updated: 2023/08/10 12:56:29 by ryhara           ###   ########.fr       */
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
	ft_putstr_fd("pa\n", STDOUT_FILENO);
}

void	pb(t_node *head_a, t_node *head_b)
{
	t_node	*tmp;

	tmp = head_a->next;
	head_a->next = tmp->next;
	tmp->next->prev = head_a;
	node_add_front(head_b, tmp);
	ft_putstr_fd("pb\n", STDOUT_FILENO);
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

void	pa_middle_and_small(t_stack *stack)
{
	size_t	count;

	count = 0;
	while (count < stack->size)
	{
		if (stack->head_a->next->index <= stack->size / 3)
		{
			pb(stack->head_a, stack->head_b);
			rb(stack->head_b);
		}
		else if (stack->head_a->next->index <= stack->size / 3 * 2)
			pb(stack->head_a, stack->head_b);
		else
			ra(stack->head_a);
		count++;
	}
}

void	pa_remain_max_five(t_stack *stack)
{
	int		count;
	t_node	*max;

	count = 0;
	max = get_max(stack->head_a);
	while (count++ < 4)
		max = get_next_max(stack->head_a, max);
	pa_middle_and_small(stack);
	stack->size_a = get_stack_size(stack->head_a);
	while (stack->size_a > 5)
	{
		if (stack->head_a->next->index < max->index)
			pb(stack->head_a, stack->head_b);
		else
			ra(stack->head_a);
		stack->size_a = get_stack_size(stack->head_a);
	}
}
