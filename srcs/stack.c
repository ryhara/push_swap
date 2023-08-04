/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryhara <ryhara@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 10:35:59 by ryhara            #+#    #+#             */
/*   Updated: 2023/08/04 10:35:59 by ryhara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_node	*head_init(void)
{
	t_node	*head;

	head = node_new(0);
	if (head == NULL)
		return (NULL);
	head->index = 0;
	head->next = head;
	head->prev = head;
	return (head);
}

t_stack	*stack_init(void)
{
	t_stack	*new;

	new = (t_stack *)malloc(sizeof(t_stack));
	if (new == NULL)
		return (NULL);
	new->head_a = head_init();
	new->head_b = head_init();
	if (new->head_a == NULL || new->head_b == NULL)
		return (NULL);
	return (new);
}

void	head_print(t_node *head, char *head_name)
{
	t_node	*tmp;

	tmp = head->next;
	ft_putstr_fd(head_name, STDOUT_FILENO);
	while (tmp != head)
	{
		ft_putchar_fd(' ', STDOUT_FILENO);
		ft_putnbr_fd(tmp->num, STDOUT_FILENO);
		tmp = tmp->next;
	}
	ft_putchar_fd('\n', STDOUT_FILENO);
}

void	stack_print(t_stack *stack)
{
	head_print(stack->head_a, "a:");
	head_print(stack->head_b, "b:");
}
