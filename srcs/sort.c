/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryhara <ryhara@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 14:44:04 by ryhara            #+#    #+#             */
/*   Updated: 2023/08/04 14:44:04 by ryhara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort_2(t_node *head_a)
{
	t_node	*top;

	top = head_a->next;
	if (top->num > top->next->num)
		sa(head_a);
	else
		return ;
}

void	sort_3(t_node *head_a)
{
	t_node	*max;
	t_node	*min;

	max = get_max(head_a);
	min = get_min(head_a);
	while (1)
	{
		if (check_sorted(head_a))
			break ;
		if (head_a->next == min && head_a->prev == max)
			break ;
		if (head_a->next == max)
			ra(head_a);
		if (head_a->next == min && head_a->prev == max)
			break ;
		if (head_a->next == min || head_a->prev == max)
			sa(head_a);
		if (head_a->next == max)
			ra(head_a);
		if (head_a->prev == min)
			rra(head_a);
		break ;
	}
}

void	sort_4(t_node *head_a, t_node *head_b)
{
	t_node	*min;

	if (check_sorted(head_a))
		return ;
	min = get_min(head_a);
	if (head_a->next == min)
		pb(head_a, head_b);
	else if (head_a->prev == min)
	{
		rra(head_a);
		pb(head_a, head_b);
	}
	else
	{
		while (head_a->next != min)
			rra(head_a);
		pb(head_a, head_b);
	}
	sort_3(head_a);
	pa(head_a, head_b);
}

void	sort_5(t_stack *stack)
{
	t_node	*head_a;
	t_node	*head_b;
	t_node	*min1;
	t_node	*min2;

	head_a = stack->head_a;
	head_b = stack->head_b;
	if (check_sorted(head_a))
		return ;
	min1 = get_min(head_a);
	min2 = get_next_min(head_a, min1);
	push_min_b(stack, min1);
	push_min_b(stack, min2);
	sort_3(head_a);
	pa(head_a, head_b);
	pa(head_a, head_b);
}

void	sort_select(t_stack *stack)
{
	t_node	*head_a;
	t_node	*head_b;
	size_t	size;

	head_a = stack->head_a;
	head_b = stack->head_b;
	size = stack->size;
	if (size == 2)
		sort_2(head_a);
	else if (size == 3)
		sort_3(head_a);
	else if (size == 4)
		sort_4(head_a, head_b);
	else if (size == 5)
		sort_5(stack);
	else
		return ;
}
