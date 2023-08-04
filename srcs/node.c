/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryhara <ryhara@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 10:33:29 by ryhara            #+#    #+#             */
/*   Updated: 2023/08/04 10:33:29 by ryhara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_node	*node_new(int num)
{
	t_node	*new;

	new = (t_node *)malloc(sizeof(t_node));
	if (new == NULL)
		return (NULL);
	new->num = num;
	new->index = 0;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

void	node_add_back(t_node *head, t_node *new)
{
	if (head == NULL || new == NULL)
		return ;
	new->next = head;
	new->prev = head->prev;
	head->prev->next = new;
	head->prev = new;
}

void	node_add_front(t_node *head, t_node *new)
{
	if (head == NULL || new == NULL)
		return ;
	new->next = head->next;
	new->prev = head;
	head->next->prev = new;
	head->next = new;
}

void	coordinate_compress(t_node *head_a)
{
	t_node	*tmp_i;
	t_node	*tmp_j;
	size_t	count;

	tmp_i = head_a->next;
	while (tmp_i != head_a)
	{
		count = 0;
		tmp_j = head_a->next;
		while (tmp_j != head_a)
		{
			if (tmp_i->num >= tmp_j->num)
				count++;
			tmp_j = tmp_j->next;
		}
		tmp_i->index = count;
		tmp_i = tmp_i->next;
	}
}

t_stack	*node_list_init(size_t argc, char **argv, size_t start)
{
	t_stack	*stack;
	t_node	*new;

	stack = stack_init();
	if (stack == NULL)
		return (NULL);
	stack->size = argc - start;
	while (start < argc)
	{
		new = node_new(ft_atoi(argv[start]));
		new->index = start;
		if (new == NULL)
			return (NULL);
		node_add_back(stack->head_a, new);
		start++;
	}
	return (stack);
}
