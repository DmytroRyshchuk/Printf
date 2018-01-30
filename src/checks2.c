/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _checks2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dryshchu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 17:27:58 by dryshchu          #+#    #+#             */
/*   Updated: 2018/01/26 17:28:00 by dryshchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		priority_letters(char *s)
{
	int		i;

	i = 0;
	while (s[i])
	{
		if (s[i] == ' ')
			if (((s[i + 1] == 'h' || s[i + 1] == 'l' ||
			s[i + 1] == 'j' || s[i + 1] == 'z')
			&& s[i + 2] == 0))
				return (1);
		i++;
	}
	return (0);
}

int		check_if_empty_string(char *s)
{
	int		i;

	i = 0;
	while (s[i])
	{
		if (s[i] != 32)
			return (1);
		i++;
	}
	return (0);
}

int		at_first(char *s, int i)
{
	int		j;

	j = i;
	while (s[j])
	{
		if ((s[j] == 'l' && s[j + 1] == 'l') || (s[j] == 'h' &&
			s[j + 1] == 'h'))
			return (2);
		if (s[j] == 'l' || s[j] == 'h' || s[j] == 'z' || s[j] == 'j')
			return (1);
		j++;
	}
	return (0);
}

int		check_all(char *f)
{
	int		i;

	i = 0;
	while (f[i])
	{
		if ((f[i] >= 'a' && f[i] <= 'z') || (f[i] >= 'A' && f[i] <= 'Z') ||
			f[i] == '%')
		{
			if (f[i] == '%' || f[i] == 'c' || f[i] == 'C' || f[i] == 's' ||
				f[i] == 'S' || f[i] == 'o' || f[i] == 'O' || f[i] == 'd' ||
				f[i] == 'D' || f[i] == 'i' || f[i] == 'u' || f[i] == 'U' ||
				f[i] == 'x' || f[i] == 'X' || f[i] == 'p' || f[i] == 'h' ||
				f[i] == 'l' || f[i] == 'z' || f[i] == 'j')
				return (1);
			else
				return (i);
		}
		i++;
	}
	return (i);
}

void	crutch(char *s)
{
	char *w;

	w = s;
	write(1, "Zoooo", 5);
	return ;
}
