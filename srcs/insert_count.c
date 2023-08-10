/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_count.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryhara <ryhara@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 12:52:32 by ryhara            #+#    #+#             */
/*   Updated: 2023/08/10 12:52:32 by ryhara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static size_t	count_under_min_a(t_stack *stack, t_node *tmp_a, t_node *min_a)
{
	size_t	count_a;

	count_a = 0;
	while (tmp_a->index != min_a->index)
	{
		tmp_a = tmp_a->next;
		count_a++;
	}
	if (count_a > stack->size_a / 2)
		count_a = stack->size_a - count_a;
	return (count_a);
}

static size_t	count_over_min_a(t_stack *stack, t_node *tmp_a, t_node *tmp_b)
{
	size_t	count_a;

	count_a = 0;
	if (tmp_a->index > tmp_b->index
		&& stack->head_a->prev->index < tmp_b->index)
		count_a++;
	else
	{
		while (tmp_a->index > tmp_b->index)
		{
			tmp_a = tmp_a->next;
			count_a++;
		}
		while (tmp_a->index < tmp_b->index)
		{
			tmp_a = tmp_a->next;
			count_a++;
		}
		if (count_a > stack->size_a / 2)
			count_a = stack->size_a - count_a;
	}
	return (count_a);
}

static size_t	count_all(t_stack *stack, t_node *tmp_a, t_node *tmp_b)
{
	size_t	count_a;
	size_t	count_b;
	t_node	*min_a;

	min_a = get_min(stack->head_a);
	count_b = get_pos(stack->head_b, tmp_b);
	stack->size_a = get_stack_size(stack->head_a);
	stack->size_b = get_stack_size(stack->head_b);
	if (count_b > stack->size_b / 2)
		count_b = stack->size_b - count_b;
	if (tmp_b->index < min_a->index)
		count_a = count_under_min_a(stack, tmp_a, min_a);
	else
		count_a = count_over_min_a(stack, tmp_a, tmp_b);
	return (count_a + count_b);
}

t_node	*insert_count(t_stack *stack)
{
	t_node	*tmp_a;
	t_node	*tmp_b;
	t_node	*ans;
	size_t	count_tmp;
	size_t	count_min;

	tmp_b = stack->head_b->next;
	while (tmp_b != stack->head_b)
	{
		tmp_a = stack->head_a->next;
		count_tmp = count_all(stack, tmp_a, tmp_b);
		if (count_min > count_tmp)
		{
			count_min = count_tmp;
			ans = tmp_b;
		}
		if (count_min <= 2)
		{
			ans = tmp_b;
			break ;
		}
		tmp_b = tmp_b->next;
	}
	return (ans);
}
