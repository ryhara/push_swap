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
	// t_node	*max;
	// t_node	*min;
	// t_node	*tmp;

	// max = get_max(stack->head_b);
	// min = get_min(stack->head_b);
	// tmp = stack->head_b->next;
	size_b = get_stack_size(stack->head_b);
	while (size_b > SORT_SIZE)
	{
		// if (tmp->index == min->index)
		// {
		// 	pa(stack->head_a, stack->head_b);
		// 	ra(stack->head_a);
		// 	min = get_next_min(stack->head_b, min);
		// }
		// else if (tmp->index > (size_b / 2))
		// 	pa(stack->head_a, stack->head_b);
		// tmp = stack->head_b->next;
		pa_harf(stack);
		stack_print(stack);
		size_b = get_stack_size(stack->head_b);
		// printf("%ld %ld\n", size_b, min->index);
	}
	stack_print(stack);
}

void	sort_many(t_stack *stack)
{
	t_node	*head_a;
	// t_node	*min;
	// t_node	*head_b;
	// size_t	size;
	// t_node	*tmp;

	head_a = stack->head_a;
	// head_b = stack->head_b;
	// size = stack->size;
	if (check_sorted(head_a))
		return ;
	// int pos = 50;
	pb_harf(stack);
	// while (stack->head_b->next != stack->head_b)
	// {
	// 	min = get_min(stack->head_b);
	// 	pa_min_and_ra(stack, min);
	// }
	// while (pos--)
	// 	pb(stack->head_a, stack->head_b);
	// while (stack->head_b->next != stack->head_b)
	// {
	// 	min = get_min(stack->head_b);
	// 	pa_min_and_ra(stack, min);
	// }
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
	size_t	size;
	size_t	count;

	tmp = stack->head_b->next;
	size = get_stack_size(stack->head_b);
	count = 0;
	printf("size %ld\n", size);
	while (count <= (size / 2) - 1)
	{
		tmp = stack->head_b->next;
		max = get_max(stack->head_b);
		if (tmp->index > (size / 2) && max == tmp)
		{
			pa(stack->head_a, stack->head_b);
			count++;
		}
		else
			ra(stack->head_b);
	}
}
