/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryhara <ryhara@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 14:34:43 by ryhara            #+#    #+#             */
/*   Updated: 2023/08/02 15:08:27 by ryhara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

BOOLEAN	check_int(int ans, char sign, char *s)
{
	if (sign == '+')
	{
		if ((ans == (INT_MAX / 10) && (*s - '0') > (INT_MAX % 10))
			|| ans >= (INT_MAX / 10) + 1)
			return (FALSE);
	}
	if (sign == '-')
	{
		if ((ans == (INT_MAX / 10) && (*s - '0') > (INT_MAX % 10 + 1))
			|| ans >= (INT_MAX / 10) + 1)
			return (FALSE);
	}
	return (TRUE);
}

BOOLEAN	check_args(int argc, char **argv)
{
	int		i;
	int		ans;
	char	sign;
	char	*s;

	i = 1;
	ans = 0;
	sign = '+';
	while (i < argc)
	{
		s = argv[i];
		if (*s++ == '-')
			sign = '-';
		while (*s >= '0' && *s <= '9')
		{
			if (!check_int(ans, sign, s))
				return (FALSE);
			ans = ans * 10 + (*s - '0');
			s++;
		}
		if (*s != '\0')
			return (FALSE);
		i++;
	}
	return (TRUE);
}
