/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dryshchu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/27 13:15:05 by dryshchu          #+#    #+#             */
/*   Updated: 2017/10/27 13:15:08 by dryshchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strlen(const char *s)
{
	size_t			i;
	unsigned char	*st;

	st = (unsigned char*)s;
	i = 0;
	while (st[i])
		i++;
	return (i);
}

int		ft_strlen_wchar(wchar_t *s)
{
	int			leng;

	leng = 0;
	while (*s)
		leng += ft_wchar_l(*s++);
	return (leng);
}
