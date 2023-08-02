/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_free_all.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryhara <ryhara@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 13:38:28 by ryhara            #+#    #+#             */
/*   Updated: 2023/08/02 14:06:54 by ryhara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void stack_free_all(t_stack *head)
{
	t_stack *stack_tmp;
	t_stack *stack_del;

	if (head == NULL)
		return ;
	stack_tmp = head->next;
	while (stack_tmp != head)
	{
		stack_del = stack_tmp;
		head->next = stack_tmp->next;
		stack_tmp->next->prev = head;
		stack_tmp = stack_tmp->next;
		free(stack_del);
	}
	free(head);
}