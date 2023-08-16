/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryhara <ryhara@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 15:42:22 by ryhara            #+#    #+#             */
/*   Updated: 2023/08/16 10:17:40 by ryhara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

BOOLEAN	check_sorted(t_node *head)
{
	t_node	*now;
	t_node	*next;

	now = head->next;
	while (now->next != head)
	{
		next = now->next;
		if (now->num < next->num)
			now = now->next;
		else
			return (FALSE);
	}
	return (TRUE);
}

size_t	get_pos(t_node *head, t_node *target)
{
	t_node	*tmp;
	size_t	pos;

	pos = 0;
	tmp = head->next;
	while (tmp != target)
	{
		tmp = tmp->next;
		pos++;
	}
	return (pos);
}

void	sort_asc(t_stack *stack)
{
	t_node	*min_a;
	size_t	count;

	min_a = get_min(stack->head_a);
	count = get_pos(stack->head_a, min_a);
	if (count > stack->size / 2)
	{
		while (stack->head_a->next != min_a)
			rra(stack->head_a);
	}
	else
	{
		while (stack->head_a->next != min_a)
			ra(stack->head_a);
	}
}
