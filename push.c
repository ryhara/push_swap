/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryhara <ryhara@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 10:29:58 by ryhara            #+#    #+#             */
/*   Updated: 2023/08/02 18:00:18 by ryhara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void pa(t_stack *head_a, t_stack *head_b)
{
	t_stack	*stack_tmp;
	stack_tmp = head_b->next;
	head_b->next = stack_tmp->next;
	stack_tmp->next->prev = head_b;
	stack_add_front(head_a, stack_tmp);
}

void pb(t_stack *head_a, t_stack *head_b)
{
	t_stack	*stack_tmp;

	stack_tmp = head_a->next;
	head_a->next = stack_tmp->next;
	stack_tmp->next->prev = head_a;
	stack_add_front(head_b, stack_tmp);

}
