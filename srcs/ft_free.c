/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryhara <ryhara@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 13:38:28 by ryhara            #+#    #+#             */
/*   Updated: 2023/08/04 13:06:18 by ryhara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	head_free_all(t_node *head)
{
	t_node	*tmp;
	t_node	*delete;

	if (head == NULL)
		return ;
	tmp = head->next;
	while (tmp != head)
	{
		delete = tmp;
		head->next = tmp->next;
		tmp->next->prev = head;
		tmp = tmp->next;
		free(delete);
		delete = NULL;
	}
	free(head);
	head = NULL;
}

void	stack_free_all(t_stack *stack)
{
	if (stack == NULL)
		return ;
	head_free_all(stack->head_a);
	head_free_all(stack->head_b);
}

BOOLEAN	ft_puterr_with_free(t_stack *stack)
{
	stack_free_all(stack);
	ft_putstr_fd("Error\n", 2);
	return (FALSE);
}
