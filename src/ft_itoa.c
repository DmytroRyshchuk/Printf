/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dryshchu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 16:29:17 by dryshchu          #+#    #+#             */
/*   Updated: 2017/11/06 16:29:19 by dryshchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		leng(ptrdiff_t n)
{
	int		i;
	int		m;

	i = 0;
	m = 0;
	if (n < 0)
	{
		m++;
		n = -n;
	}
	while (n != 0)
	{
		n /= 10;
		i++;
	}
	return (i + m);
}

char	*ft_itoa(ptrdiff_t nbr)
{
	int			i;
	ptrdiff_t	n;
	char		*w;

	if (nbr == 0)
		return ("0");
	i = leng(nbr);
	n = nbr;
	if (n < 0)
		n = -n;
	w = (char*)malloc(i + 1);
	if (w == NULL)
		return (NULL);
	w[i--] = '\0';
	while (n != 0)
	{
		w[i] = n % 10 + 48;
		n /= 10;
		i--;
	}
	if (nbr < 0)
		w[i] = '-';
	if (ft_strcmp(w, "-'..--).0-*(+,))+(0(") == 0)
		w = "-9223372036854775808";
	return (w);
}

int		leng_u(unsigned long long n)
{
	int		i;

	i = 0;
	while (n != 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char	*ft_uitoa(unsigned long long nbr)
{
	int		i;
	char	*w;

	if (nbr == 0)
		return ("0");
	i = leng_u(nbr);
	w = (char*)malloc(i + 1);
	if (w == NULL)
		return (NULL);
	w[i--] = '\0';
	while (nbr != 0)
	{
		w[i] = nbr % 10 + 48;
		nbr /= 10;
		i--;
	}
	if (ft_strcmp(w, "-'..--).0-*(+,))+(0(") == 0)
		w = "-9223372036854775808";
	return (w);
}
