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

static void	move_to_top_b(t_stack *stack, t_node *node)
{
	size_t	count_b;

	count_b = get_pos(stack->head_b, node);
	stack->size_a = get_stack_size(stack->head_a);
	stack->size_b = get_stack_size(stack->head_b);
	if (count_b > stack->size_b / 2)
	{
		while (stack->head_b->next->index != node->index)
			rrb(stack->head_b);
	}
	else
	{
		while (stack->head_b->next->index != node->index)
			rb(stack->head_b);
	}
}

static void	insert_under_min_a(t_stack *stack, t_node *min_a)
{
	size_t	count_a;

	count_a = get_pos(stack->head_a, min_a);
	stack->size_a = get_stack_size(stack->head_a);
	if (count_a > stack->size_a / 2)
	{
		while (stack->head_a->next->index != min_a->index)
			rra(stack->head_a);
	}
	else
	{
		while (stack->head_a->next->index != min_a->index)
			ra(stack->head_a);
	}
	pa(stack->head_a, stack->head_b);
}

static void	insert_over_min_a(t_stack *stack, t_node *node, size_t count_a)
{
	if (stack->head_a->next->index > node->index
		&& stack->head_a->prev->index < node->index)
			;
	else if (count_a > stack->size_a / 2)
	{
		while (1)
		{
			if (stack->head_a->next->index > node->index
				&& stack->head_a->prev->index < node->index)
				break ;
			rra(stack->head_a);
		}
	}
	else
	{
		while (1)
		{
			if (stack->head_a->next->index > node->index
				&& stack->head_a->prev->index < node->index)
				break ;
			ra(stack->head_a);
		}
	}
	pa(stack->head_a, stack->head_b);
}

void	insert(t_stack *stack, t_node *node)
{
	t_node	*min_a;
	t_node	*tmp_a;
	size_t	count_a;

	move_to_top_b(stack, node);
	min_a = get_min(stack->head_a);
	if (node->index < min_a->index)
		insert_under_min_a(stack, min_a);
	else
	{
		tmp_a = stack->head_a->next->next;
		while (tmp_a->prev->index > node->index)
				tmp_a = tmp_a->next;
		while (tmp_a->index < node->index)
			tmp_a = tmp_a->next;
		count_a = get_pos(stack->head_a, tmp_a);
		stack->size_a = get_stack_size(stack->head_a);
		insert_over_min_a(stack, node, count_a);
	}
}

void	sort_many(t_stack *stack)
{
	t_node	*head_a;
	t_node	*tmp_b;

	head_a = stack->head_a;
	if (check_sorted(head_a))
		return ;
	pa_remain_max_five(stack);
	sort_5(stack);
	stack->size_b = get_stack_size(stack->head_b);
	while (stack->size_b != 0)
	{
		tmp_b = insert_count(stack);
		insert(stack, tmp_b);
		stack->size_b = get_stack_size(stack->head_b);
	}
	sort_asc(stack);
}
