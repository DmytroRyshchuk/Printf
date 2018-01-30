/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_format.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dryshchu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/30 17:26:01 by dryshchu          #+#    #+#             */
/*   Updated: 2018/01/30 17:26:03 by dryshchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		check_format_percent(t_printf_s *s_p, va_list ap)
{
	int		len;

	if (*s_p->temp_st == '%')
	{
		if (check_if_empty_string(s_p->temp_st + 1) == 0 &&
			(ft_strcmp(check_flags(s_p->temp_st + 1), "")))
			return (1);
		len = check_exactly_format(s_p->temp_st + 1, ap, s_p);
		while (len-- > 0)
			s_p->temp_st++;
		if (ft_strcmp(s_p->temp_st, "%") != 0)
			s_p->leng_p_for_several += s_p->leng_p;
		else
			s_p->temp_st++;
	}
	return (0);
}

int		check_format_else(char *f, t_printf_s *s_p)
{
	if (*s_p->temp_st != '%' && priority_letters(f) == 1)
		return (1);
	if (ft_strcmp(s_p->temp_st, "h") == 0 ||
		ft_strcmp(s_p->temp_st, "l") == 0 ||
		ft_strcmp(s_p->temp_st, "z") == 0 ||
		ft_strcmp(s_p->temp_st, "j") == 0)
		return (1);
	if (*s_p->temp_st != '%')
	{
		ft_putchar(*s_p->temp_st);
		s_p->temp_st++;
		s_p->leng_p_for_several++;
	}
	else if (ft_strlen(s_p->temp_st) == 1 && ft_strcmp(s_p->temp_st, "%") == 0)
	{
		if (*(s_p->temp_st + 1) == '%')
		{
			ft_putchar(*s_p->temp_st);
			s_p->leng_p_for_several++;
		}
		return (1);
	}
	return (0);
}

char	*check_priority_flag(char *f, int i, int now_priority, char *priority)
{
	while (f[++i])
		if (f[i] == 'z')
			return ("z");
		else if (f[i] == 'j' && now_priority < 5)
		{
			priority = "j";
			now_priority = 5;
		}
		else if (f[i] == 'l' && now_priority < 3)
		{
			priority = (f[i + 1] == 'l') ? "ll" : "l";
			now_priority = (f[i + 1] == 'l') ? 3 : 4;
		}
		else if (f[i] == 'h' && now_priority < 1)
		{
			priority = (f[i + 1] == 'h') ? "hh" : "h";
			now_priority = (f[i + 1] == 'h') ? 1 : 2;
		}
		else if (f[i] == '%')
			return ((ft_strcmp(priority, "") == 0) ? "" : priority);
	return (priority);
}
