/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryhara <ryhara@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 14:03:25 by ryhara            #+#    #+#             */
/*   Updated: 2023/08/02 14:29:13 by ryhara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stack_print(t_stack *head)
{
	t_stack	*stack_tmp;

	stack_tmp = head->next;
	while (stack_tmp != head)
	{
		ft_putnbr_fd(stack_tmp->number, 1);
		ft_putchar_fd(' ', 1);
		stack_tmp = stack_tmp->next;
	}
	ft_putchar_fd('\n', 1);
}