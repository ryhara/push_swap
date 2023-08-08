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


t_node	*insert_count(t_stack *stack)
{
	t_node	*tmp_a;
	t_node	*tmp_b;
	t_node	*min_a;
	size_t	count_a;
	size_t	count_b;
	size_t	count_min;

	tmp_b = stack->head_b->next;
	count_min = stack->size;
	min_a = get_min(stack->head_a);
	stack->size_a = get_stack_size(stack->head_a);
	stack->size_b = get_stack_size(stack->head_b);
	while (tmp_b != stack->head_b)
	{
		tmp_a = stack->head_a->next;
		count_b = get_pos(stack->head_b, tmp_b);
		if (count_b > stack->size_b / 2)
			count_b = stack->size_b - count_b;
		count_a = 0;
		if (tmp_b->index < min_a->index)
		{
			while (tmp_a->index != min_a->index)
			{
				tmp_a = tmp_a->next;
				count_a++;
			}
			if (count_a > stack->size_a / 2)
				count_a = stack->size_a - count_a;
		}
		else
		{
			if (tmp_a->index > tmp_b->index && stack->head_a->prev->index < tmp_b->index)
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
		}
		if (count_min > count_a + count_b)
			count_min = count_a + count_b;
		if (count_min <= 2)
			break ;
		if (tmp_b->next == stack->head_b)
			break ;
		// printf("index %ld count %ld\n", tmp_b->index, count_min);
		tmp_b = tmp_b->next;
	}
	// printf("[ANS] index %ld count %ld\n", tmp_b->index, count_min);
	return (tmp_b);
}

t_node	*insert_count_middle(t_stack *stack)
{
	t_node	*tmp_a;
	t_node	*tmp_b;
	t_node	*min_a;
	size_t	count_a;
	size_t	count_b;
	size_t	count_min;

	tmp_b = stack->head_b->next;
	count_min = stack->size;
	min_a = get_min(stack->head_a);
	stack->size_a = get_stack_size(stack->head_a);
	stack->size_b = get_stack_size(stack->head_b);
	while (tmp_b != stack->head_b)
	{
		while (tmp_b->index < stack->size / 3)
			tmp_b = tmp_b->next;
		tmp_a = stack->head_a->next;
		count_b = get_pos(stack->head_b, tmp_b);
		if (count_b > stack->size_b / 2)
			count_b = stack->size_b - count_b;
		count_a = 0;
		if (tmp_b->index < min_a->index)
		{
			while (tmp_a->index != min_a->index)
			{
				tmp_a = tmp_a->next;
				count_a++;
			}
			if (count_a > stack->size_a / 2)
				count_a = stack->size_a - count_a;
		}
		else
		{
			if (tmp_a->index > tmp_b->index && stack->head_a->prev->index < tmp_b->index)
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
		}
		if (count_min > count_a + count_b)
			count_min = count_a + count_b;
		if (count_min <= 2)
			break ;
		if (tmp_b->next == stack->head_b)
			break ;
		// printf("index %ld count %ld\n", tmp_b->index, count_min);
		tmp_b = tmp_b->next;
	}
	// printf("[ANS] index %ld count %ld\n", tmp_b->index, count_min);
	return (tmp_b);
}

t_node	*insert_count_big(t_stack *stack)
{
	t_node	*tmp_a;
	t_node	*tmp_b;
	t_node	*min_a;
	size_t	count_a;
	size_t	count_b;
	size_t	count_min;

	tmp_b = stack->head_b->next;
	count_min = stack->size;
	min_a = get_min(stack->head_a);
	stack->size_a = get_stack_size(stack->head_a);
	stack->size_b = get_stack_size(stack->head_b);
	while (tmp_b != stack->head_b)
	{
		while (tmp_b->index < stack->size / 3 * 2)
			tmp_b = tmp_b->next;
		tmp_a = stack->head_a->next;
		count_b = get_pos(stack->head_b, tmp_b);
		if (count_b > stack->size_b / 2)
			count_b = stack->size_b - count_b;
		count_a = 0;
		if (tmp_b->index < min_a->index)
		{
			while (tmp_a->index != min_a->index)
			{
				tmp_a = tmp_a->next;
				count_a++;
			}
			if (count_a > stack->size_a / 2)
				count_a = stack->size_a - count_a;
		}
		else
		{
			if (tmp_a->index > tmp_b->index && stack->head_a->prev->index < tmp_b->index)
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
		}
		if (count_min > count_a + count_b)
			count_min = count_a + count_b;
		if (count_min <= 2)
			break ;
		if (tmp_b->next == stack->head_b)
			break ;
		printf("index %ld count %ld\n", tmp_b->index, count_min);
		stack_print(stack);
		tmp_b = tmp_b->next;
	}
	// printf("[ANS] index %ld count %ld\n", tmp_b->index, count_min);
	return (tmp_b);
}

void	insert_new(t_stack *stack, t_node *node)
{
	t_node *min_a;
	size_t	count_a;
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
	min_a = get_min(stack->head_a);
	if (node->index < min_a->index)
	{
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
	else
	{
		t_node	*tmp_a;
		tmp_a = stack->head_a->next->next;
		while (tmp_a->prev->index > node->index)
				tmp_a = tmp_a->next;
		while (tmp_a->index < node->index)
			tmp_a = tmp_a->next;
		count_a = get_pos(stack->head_a, tmp_a);
		stack->size_a = get_stack_size(stack->head_a);
		if (count_a > stack->size_a / 2)
		{
			while (1)
			{
				if (stack->head_a->next->index > node->index && stack->head_a->prev->index < node->index)
					break ;
				rra(stack->head_a);
			}
		}
		else
		{
			while (1)
			{
				if (stack->head_a->next->index > node->index && stack->head_a->prev->index < node->index)
					break ;
				ra(stack->head_a);
			}
		}
		pa(stack->head_a, stack->head_b);
	}
}

void	sort_many(t_stack *stack)
{
	t_node	*head_a;
	t_node	*tmp_b;
	size_t	count;

	head_a = stack->head_a;
	if (check_sorted(head_a))
		return ;
	pa_remain_max_five(stack);
	sort_5(stack);
	stack->size_b = get_stack_size(stack->head_b);
	while (stack->size_b > stack->size / 3 * 2)
	{
		tmp_b = insert_count_big(stack);
		insert_new(stack, tmp_b);
		printf("FILE_NAME %s, LINE %d\n", __FILE__, __LINE__);
		stack_print(stack);
		stack->size_b = get_stack_size(stack->head_b);
	}
	while (stack->size_b > stack->size / 3 + 1)
	{
		tmp_b = insert_count_middle(stack);
		insert_new(stack, tmp_b);
		printf("FILE_NAME %s, LINE %d\n", __FILE__, __LINE__);
		stack_print(stack);
		stack->size_b = get_stack_size(stack->head_b);
	}
	while (stack->size_b != 0)
	{
		tmp_b = insert_count(stack);
		insert_new(stack, tmp_b);
		stack->size_b = get_stack_size(stack->head_b);
	}
	t_node	*min_a;
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
	// stack_print(stack);
}
