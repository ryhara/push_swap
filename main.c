/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryhara <ryhara@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 10:18:34 by ryhara            #+#    #+#             */
/*   Updated: 2023/08/02 15:02:58 by ryhara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	int		i;
	t_stack	*head;

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
		head = stack_new(0);
		stack_head_init(head);
		while (i < argc)
		{
			stack_add_back(head, stack_new(ft_atoi(argv[i])));
			i++;
		}
		stack_print(head);
		stack_add_front(head, stack_new(5));
		stack_print(head);
		stack_free_all(head);
	}
	return (0);
}

__attribute__((destructor)) static void destructor()
{
	system("leaks -q push_swap");
}