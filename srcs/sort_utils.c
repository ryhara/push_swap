/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryhara <ryhara@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 15:42:22 by ryhara            #+#    #+#             */
/*   Updated: 2023/08/04 15:42:22 by ryhara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_node	*get_max(t_node *head)
{
	t_node	*max;
	t_node	*tmp;

	max = head->next;
	tmp = max->next;
	while (tmp != head)
	{
		if (max->num < tmp->num)
			max = tmp;
		tmp = tmp->next;
	}
	return (max);
}

t_node	*get_min(t_node *head)
{
	t_node	*min;
	t_node	*tmp;

	min = head->next;
	tmp = min->next;
	while (tmp != head)
	{
		if (min->num > tmp->num)
			min = tmp;
		tmp = tmp->next;
	}
	return (min);
}

t_node	*get_next_min(t_node *head, t_node *min)
{
	t_node	*next_min;
	t_node	*tmp;

	next_min = head->next;
	if (next_min == min)
		next_min = next_min->next;
	tmp = next_min->next;
	while (tmp != head)
	{
		if ((next_min->index > tmp->index) && (tmp->index > min->index))
			next_min = tmp;
		tmp = tmp->next;
	}
	return (next_min);
}

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
