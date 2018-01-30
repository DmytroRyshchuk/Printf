/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dryshchu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/04 19:41:13 by dryshchu          #+#    #+#             */
/*   Updated: 2017/11/04 19:41:17 by dryshchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char			*s;
	unsigned int	i;

	s = (char*)malloc(size + 1);
	i = 0;
	if (s == NULL)
		return (NULL);
	while (i < size)
		s[i++] = 0;
	s[i] = '\0';
	return (s);
}
