/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryhara <ryhara@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 19:41:35 by ryhara            #+#    #+#             */
/*   Updated: 2023/08/02 20:50:55 by ryhara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void sort_5(t_stack *head_a, t_stack *head_b)
{
	t_stack *min1;
	t_stack *min2;
	t_stack *tmp;
	int count;

	tmp = head_a->next;
	min1 = tmp;
	min2 = tmp->next;
	count = 0;
	while(tmp->next != head_a)
	{
		if (min1->number > tmp->next->number)
			min1 = tmp->next;
		else if (min2->number > tmp->next->number)
			min2 = tmp->next;
		tmp = tmp->next;
	}
	printf("%d  %d\n", min1->number, min2->number);
	while(count < 2)
	{
		tmp = head_a->next;
		if (tmp == min1 || tmp == min2)
		{
			pb(head_a, head_b);
			count++;
		}
		else
			sa(head_a);

	}
	sort_3(head_a);
	tmp = head_b->next;
	if (tmp->number < tmp->next->number)
		sb(head_b);
	pa(head_a, head_b);
	pa(head_a, head_b);
}