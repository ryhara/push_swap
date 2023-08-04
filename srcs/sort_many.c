/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_many.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryhara <ryhara@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 19:46:20 by ryhara            #+#    #+#             */
/*   Updated: 2023/08/04 19:46:20 by ryhara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"


void sort_all(t_stack *stack)
{
	size_t	size_b;
	size_b = get_stack_size(stack->head_b);
	while (size_b > SORT_SIZE)
	{
		pa_harf(stack);
		// 常にsizeを測りながら最小値を下に送っていくことにする。
		stack_print(stack);
		size_b = get_stack_size(stack->head_b);
	}
	sort_3(stack->head_a);
	pa(stack->head_a, stack->head_b);
	ra(stack->head_a);
	pa(stack->head_a, stack->head_b);
	ra(stack->head_a);
	pa(stack->head_a, stack->head_b);
	ra(stack->head_a);
	stack_print(stack);
}

void	sort_many(t_stack *stack)
{
	t_node	*head_a;

	head_a = stack->head_a;
	if (check_sorted(head_a))
		return ;
	pb_harf(stack);
	sort_all(stack);
}

void	pb_harf(t_stack *stack)
{
	t_node	*tmp;
	size_t	size;
	size_t	count;

	tmp = stack->head_a->next;
	size = get_stack_size(stack->head_a);
	count = 0;
	while (count <= (size / 2) - 1)
	{
		tmp = stack->head_a->next;
		if (tmp->index <= (size / 2))
		{
			pb(stack->head_a, stack->head_b);
			count++;
		}
		else
			ra(stack->head_a);
	}
}

void	pa_harf(t_stack *stack)
{
	t_node	*tmp;
	t_node	*max;
	t_node	*min;
	size_t	size;
	size_t	count;

	tmp = stack->head_b->next;
	size = get_stack_size(stack->head_b);
	count = 0;
	printf("size %ld\n", size);
	while (count <= (size / 2) - 1)
	{
		tmp = stack->head_b->next;
		size = get_stack_size(stack->head_b);
		max = get_max(stack->head_b);
		min = get_min(stack->head_b);
		if (tmp->index == min->index)
		{
			pa(stack->head_a, stack->head_b);
			ra(stack->head_a);
			count++;
		}
		else if (tmp->index > (size / 2) && max == tmp)
		{
			pa(stack->head_a, stack->head_b);
			count++;
		}
		else
			ra(stack->head_b);
	}
}
