/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _hex_itoa_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dryshchu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 13:49:08 by dryshchu          #+#    #+#             */
/*   Updated: 2018/01/12 13:49:11 by dryshchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		leng_my(size_t n, int base)
{
	int		i;

	i = 0;
	while (n != 0)
	{
		n /= base;
		i++;
	}
	return (i);
}

char	*my_itoa_base(char *n, int base, int letter)
{
	int				i;
	int				len;
	char			*w;
	unsigned long	num;

	i = 0;
	if (ft_strcmp(n, "0") == 0)
		return ("0");
	num = ft_atoi(n);
	len = leng_my(num, base);
	w = (char*)malloc(len + 1);
	w[len] = '\0';
	if (w == NULL)
		return (NULL);
	while (num != 0)
	{
		if (letter == 0)
			w[--len] = (num % base) + (num % base > 9 ? 'A' - 10 : '0');
		else
			w[--len] = (num % base) + (num % base > 9 ? 'a' - 10 : '0');
		num /= base;
	}
	return (w);
}
