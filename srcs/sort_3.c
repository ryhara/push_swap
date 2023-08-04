/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryhara <ryhara@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 18:51:12 by ryhara            #+#    #+#             */
/*   Updated: 2023/08/04 10:12:01 by ryhara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void sort_3(t_stack *head_a)
{
	t_stack *top;
	t_stack *mid;
	t_stack *bottom;

	top = head_a->next;
	mid = top->next;
	bottom = mid->next;

	if (top->number > mid->number && top->number < bottom->number)
		sa(head_a);
	else if (top->number > mid->number && mid->number > bottom->number)
	{
		sa(head_a);
		rra(head_a);
	}
	else if (top->number > mid->number && top->number > bottom->number)
		ra(head_a);
	else if (top->number < mid->number && top->number < bottom->number)
	{
		sa(head_a);
		ra(head_a);
	}
	else if (top->number < mid->number && top->number > bottom->number)
		rra(head_a);
	else
		return ;
}