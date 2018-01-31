/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _checks4.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dryshchu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 17:47:40 by dryshchu          #+#    #+#             */
/*   Updated: 2018/01/26 17:47:41 by dryshchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		width(char *s)
{
	int		i;
	int		yes;
	int		num;
	int		decimal;

	i = -1;
	yes = 0;
	num = 0;
	decimal = 0;
	while (s[++i])
		if (s[i - 1] >= '0' && s[i - 1] <= '9')
			yes = 1;
	if (yes == 1)
		return (work_with_width(s, i, num, decimal));
	return (0);
}

int		modificator_is_real(char m)
{
	if (m == 'c' || m == 'C' || m == 's' || m == 'S' || m == 'o'
		 || m == 'O' || m == 'd' || m == 'D' || m == 'x' || m == 'X'
		  || m == 'u' || m == 'U' || m == 'p')
		return (1);
	return (0);
}

int		work_with_width(char *s, int i, int num, int decimal)
{
	int		is_real;

	is_real = 0;
	i = -1;
	while (s[++i])
	{
		if (modificator_is_real(s[i]) == 1)
			return (num);
		if ((s[i] >= '0' && s[i] <= '9') || s[i] == '.')
		{
			if (s[i] == '.')
				return (num);
			if (decimal >= 1)
				num *= 10;
			num += (s[i] - 48);
			decimal++;
		}
		if (is_width_real(s[i]) == 1 && is_real == 0)
		{
			break ;
			is_real = 1;
		}
	}
	return ((is_real == 0) ? num : 0);
}

char	*check_flags(char *f)
{
	int		flag;
	int		i;
	int		flag_count;
	char	*which_flags;

	flag = 0;
	i = -1;
	flag_count = 0;
	while (f[i++])
		if (f[i] == '-' || f[i] == '+' || f[i] == ' ' || f[i] == '#' ||
			f[i] == '0')
			flag_count++;
	which_flags = (char*)malloc(i + c_0m(f));
	if (which_flags == NULL)
		return (NULL);
	i = -1;
	fill_which_flags(f, i, which_flags, flag);
	return (which_flags);
}

char	*fill_which_flags(char *f, int i, char *which_flags, int flag)
{
	while (f[++i])
		if (f[i] == '-' || f[i] == '+')
			which_flags[flag++] = (f[i] == '-') ? '-' : '+';
		else if (f[i] == ' ' || f[i] == '#')
			which_flags[flag++] = (f[i] == ' ') ? ' ' : '#';
		else if (f[i] == '0' && c_0m(f) == 1)
			which_flags[flag++] = '0';
		else if (f[i] == 'l' || f[i] == 'h' || f[i] == 'j' || f[i] == 'z')
			i = i + 0;
		else
		{
			while (f[++i])
				if (f[i] == '-' || f[i] == '+')
					which_flags[flag++] = (f[i] == '-') ? '-' : '+';
				else if (f[i] == '#')
					which_flags[flag++] = '#';
			break ;
		}
	which_flags[flag] = '\0';
	return (which_flags);
}
