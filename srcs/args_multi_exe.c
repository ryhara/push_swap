/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_multi_exe.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryhara <ryhara@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 11:32:17 by ryhara            #+#    #+#             */
/*   Updated: 2023/08/16 10:14:46 by ryhara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

BOOLEAN	args_multi_exe(int argc, char **argv)
{
	t_stack	*stack;

	if (!check_args(argc, argv, 1))
		return (ft_puterr());
	if (!check_duplicate(argc, argv))
		return (ft_puterr());
	stack = node_list_init(argc, argv, 1);
	if (!stack)
		return (ft_puterr_with_free(stack));
	coordinate_compress(stack->head_a);
	stack->size_a = stack->size;
	stack->size_b = 0;
	sort_select(stack);
	stack_free_all(stack);
	return (TRUE);
}
