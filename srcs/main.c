/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryhara <ryhara@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 10:18:34 by ryhara            #+#    #+#             */
/*   Updated: 2023/08/10 13:37:11 by ryhara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	if (argc < 2)
		return (0);
	else
	{
		if (argc == 2)
		{
			if (!args_two_exe(argv))
				return (1);
			else
				return (0);
		}
		else
		{
			if (!args_multi_exe(argc, argv))
				return (1);
			else
				return (0);
		}
	}
	return (0);
}

// __attribute__((destructor))
// static void destructor()
// {
// 	system("leaks -q push_swap");
// }