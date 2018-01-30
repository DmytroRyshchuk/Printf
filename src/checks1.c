/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _checks1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dryshchu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 17:26:58 by dryshchu          #+#    #+#             */
/*   Updated: 2018/01/26 17:26:59 by dryshchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		c_0m(char *f)
{
	int		j;
	int		minus;
	int		zero;

	j = -1;
	minus = 0;
	zero = 0;
	while (f[j++])
		if (f[j] == '-')
			minus++;
	j = -1;
	while (f[j++])
		if (f[j] == '0')
			zero++;
	if (minus >= 1 && zero >= 1)
		return (0);
	return (1);
}

int		only_for_minus(char *f)
{
	int		i;

	i = 0;
	while (f[i])
	{
		if (f[i] == '+')
			return (1);
		i++;
	}
	return (0);
}

int		check_dot(char *s)
{
	int		i;
	int		d;

	i = 0;
	d = 0;
	while (s[i])
	{
		if (((s[i - 1] >= 48 && s[i - 1] <= 57) ||
			(s[i + 1] >= 48 && s[i + 1] <= 57)) && s[i] == '.')
			return (1);
		i++;
	}
	return (0);
}

int		dot_p(char *s)
{
	int		i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '.')
		{
			if (s[i + 1] == 'p')
				return (1);
		}
		i++;
	}
	return (0);
}

int		value_zero(char *s)
{
	if (ft_strcmp(s, "0") == 0)
		return (1);
	return (0);
}
