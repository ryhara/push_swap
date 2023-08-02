/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryhara <ryhara@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 10:18:34 by ryhara            #+#    #+#             */
/*   Updated: 2023/08/02 20:06:42 by ryhara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	int		i;
	t_stack	*head_a;
	t_stack *head_b;

	i = 1;
	if (argc < 2)
		return (0);
	else
	{
		if (check_args(argc, argv))
			ft_putstr_fd("args OK!\n\n", 1);
		else
		{
			ft_putstr_fd("Error\n", 2);
			return (0);
		}
		head_a = stack_new(0);
		stack_head_init(head_a);
		head_b = stack_new(0);
		stack_head_init(head_b);
		while (i < argc)
		{
			stack_add_back(head_a, stack_new(ft_atoi(argv[i])));
			i++;
		}
		ft_putstr_fd("a :", 1);
		stack_print(head_a);
		ft_putstr_fd("b :", 1);
		stack_print(head_b);
		if (argc == 4)
			sort_3(head_a);
		if (argc == 6)
			sort_5(head_a, head_b);
		ft_putstr_fd("a :", 1);
		stack_print(head_a);
		ft_putstr_fd("b :", 1);
		stack_print(head_b);
		stack_free_all(head_a);
		stack_free_all(head_b);
	}
	return (0);
}

__attribute__((destructor))
static void destructor()
{
	system("leaks -q push_swap");
}