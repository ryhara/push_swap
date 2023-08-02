/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryhara <ryhara@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 10:30:43 by ryhara            #+#    #+#             */
/*   Updated: 2023/08/02 15:23:51 by ryhara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void sa(t_stack *head_a)
{
	t_stack *stack_0;
	t_stack *stack_1;

	stack_0 = head_a->next;
	stack_1 = stack_0->next;
	head_a->next = stack_1;
	stack_0->prev = stack_1;
	stack_0->next = stack_1->next;
	stack_1->next = stack_0;
	stack_1->prev = head_a;
}

void sb(t_stack *head_b)
{
	t_stack *stack_0;
	t_stack *stack_1;

	stack_0 = head_b->next;
	stack_1 = stack_0->next;
	head_b->next = stack_1;
	stack_0->prev = stack_1;
	stack_0->next = stack_1->next;
	stack_1->next = stack_0;
	stack_1->prev = head_b;

}

void ss(t_stack *head_a, t_stack *head_b)
{
	sa(head_a);
	sb(head_b);
}