/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _checks3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dryshchu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 17:30:37 by dryshchu          #+#    #+#             */
/*   Updated: 2018/01/26 17:30:38 by dryshchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		is_width_real(char c)
{
	if (c == 's' || c == 'S' || c == 'o' || c == 'O' || c == 'c' ||
		c == 'C' || c == 'd' || c == 'D' || c == 'u' || c == 'U')
		return (1);
	return (0);
}

int		check_percent(char *s, t_printf_s *s_p)
{
	int		i;
	int		at_first_time;

	i = -1;
	at_first_time = 0;
	if ((s[ft_strlen(s) - 1] == '%') || (s[ft_strlen(s) - 2] == '%'))
	{
		while (s[++i])
		{
			while (s[i] == 32 && at_first_time == 0)
				i++;
			if (at_first(s, i) >= 1 && at_first_time == 0)
			{
				i += at_first(s, i);
				at_first_time = 1;
			}
			if (s[i] == '%')
				i++;
			if (s[i] != 0 && s_p->leng_p++)
				ft_putchar(s[i]);
		}
		return (1);
	}
	return (0);
}

int		precision_in_work(char *s, int i, int num, int decimal)
{
	int		dot;

	dot = 0;
	while (s[++i])
	{
		if (s[i] == '.' && dot == 0)
		{
			num = 0;
			decimal = 0;
			dot = 1;
		}
		if (dot == 1 && s[i] >= '0' && s[i] <= '9')
		{
			if (decimal >= 1)
				num *= 10;
			num += (s[i] - 48);
			decimal++;
		}
		else if (dot == 1 && !((s[i] >= '0' && s[i] <= '9') || s[i] == '.'))
			return (num);
	}
	return (num);
}

int		precision(char *s)
{
	int		i;
	int		num;
	int		decimal;

	i = -1;
	num = 0;
	decimal = 0;
	return (precision_in_work(s, i, num, decimal));
}
