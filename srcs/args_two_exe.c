/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_two_exe.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryhara <ryhara@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 11:25:18 by ryhara            #+#    #+#             */
/*   Updated: 2023/08/16 12:17:22 by ryhara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static size_t	get_list_size(char **num_list)
{
	size_t	count;

	count = 0;
	while (num_list[count] != NULL)
		count++;
	return (count);
}

static BOOLEAN	free_list(char **num_list)
{
	size_t	i;

	i = 0;
	while (num_list[i] != NULL)
	{
		free(num_list[i]);
		num_list[i] = NULL;
		i++;
	}
	free(num_list);
	num_list = NULL;
	return (TRUE);
}

static BOOLEAN	ft_puterr_free_list(char **num_list)
{
	free_list(num_list);
	return (ft_puterr());
}

BOOLEAN	args_two_exe(char **argv)
{
	char	**num_list;
	size_t	list_size;
	t_stack	*stack;

	num_list = ft_split(argv[1], ' ');
	if (num_list == NULL)
		return (ft_puterr());
	list_size = get_list_size(num_list);
	if (!check_args(list_size, num_list, 0))
		return (ft_puterr_free_list(num_list));
	if (!check_duplicate(list_size, num_list))
		return (ft_puterr_free_list(num_list));
	if (list_size == 1)
		return (free_list(num_list));
	stack = node_list_init(list_size, num_list, 0);
	if (!stack)
		return (ft_puterr_with_free(stack));
	coordinate_compress(stack->head_a);
	stack->size_a = stack->size;
	stack->size_b = 0;
	sort_select(stack);
	free_list(num_list);
	stack_free_all(stack);
	return (TRUE);
}
