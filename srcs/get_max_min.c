/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_max_min.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryhara <ryhara@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 09:28:36 by ryhara            #+#    #+#             */
/*   Updated: 2023/08/08 09:28:36 by ryhara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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

t_node	*get_next_min(t_node *head, t_node *min)
{
	t_node	*next_min;
	t_node	*tmp;

	next_min = head->next;
	if (next_min->index <= min->index)
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

t_node	*get_next_max(t_node *head, t_node *max)
{
	t_node	*next_max;
	t_node	*tmp;

	next_max = head->next;
	if (next_max->index >= max->index)
		next_max = next_max->next;
	tmp = next_max->next;
	while (tmp != head)
	{
		if ((next_max->index < tmp->index) && (tmp->index < max->index))
			next_max = tmp;
		tmp = tmp->next;
	}
	return (next_max);
}
