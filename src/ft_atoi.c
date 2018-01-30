/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dryshchu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/03 19:54:54 by dryshchu          #+#    #+#             */
/*   Updated: 2017/11/03 19:54:56 by dryshchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	ptrdiff_t	check_the_number(ptrdiff_t n, int s, int i)
{
	if (s == 1)
		n = -n;
	if ((i > 19) && (s == 0))
		return (-1);
	else if ((i > 19) && (s == 1))
		return (0);
	if (s == 1)
		return (-n);
	return (n);
}

static	int			spaces(const char *str, int i)
{
	while (str[i] == '\n' || str[i] == '\t' || str[i] == '\v' ||
	str[i] == '\f' || str[i] == '\r' || str[i] == ' ')
		i++;
	return (i);
}

ptrdiff_t			ft_atoi(const char *str)
{
	ptrdiff_t	res;
	int			i;
	int			n;
	int			j;

	i = 0;
	res = 0;
	n = 0;
	j = 0;
	i = spaces(str, i);
	if (str[i] == '-' || str[i] == '+')
		if (str[i++] == '-')
			n = 1;
	while (str[i] == '0')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + (str[i] - 48);
		i++;
		j++;
	}
	res = check_the_number(res, n, j);
	if (n == 1)
		return (-res);
	return (res);
}
