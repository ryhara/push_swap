/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryhara <ryhara@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 14:34:43 by ryhara            #+#    #+#             */
/*   Updated: 2023/08/04 19:31:45 by ryhara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static BOOLEAN	check_int(int ans, char sign, char *s)
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

BOOLEAN	check_args(size_t size, char **num_list, size_t start)
{
	int		ans;
	char	sign;
	char	*s;

	while (start < size)
	{
		s = num_list[start++];
		ans = 0;
		sign = '+';
		if (*s == '-')
		{
			sign = '-';
			s++;
		}
		while (*s >= '0' && *s <= '9')
		{
			if (!check_int(ans, sign, s))
				return (FALSE);
			ans = ans * 10 + (*s - '0');
			s++;
		}
		if (*s != '\0')
			return (FALSE);
	}
	return (TRUE);
}

BOOLEAN	check_duplicate(int argc, char **argv)
{
	int	i;
	int	j;
	int	num_1;
	int	num_2;

	i = 1;
	while (i < argc)
	{
		j = 1;
		num_1 = ft_atoi(argv[i]);
		while (j < argc)
		{
			num_2 = ft_atoi(argv[j]);
			if (i != j && num_1 == num_2)
				return (FALSE);
			j++;
		}
		i++;
	}
	return (TRUE);
}
