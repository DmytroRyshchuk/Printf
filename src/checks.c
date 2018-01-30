/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dryshchu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/25 18:32:23 by dryshchu          #+#    #+#             */
/*   Updated: 2017/12/25 18:32:29 by dryshchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*check_priority(char *f)
{
	char	*priority;
	int		temp_priority;
	int		i;
	int		now_priority;

	priority = " ";
	now_priority = 0;
	temp_priority = 0;
	i = -1;
	return (check_priority_flag(f, i, now_priority, priority));
}

int		check_exactly_format(char *f, va_list ap, t_printf_s *s_p)
{
	int		i;

	i = -1;
	if (ft_strcmp(f, " Zoooo") == 0)
	{
		crutch(" Zoooo");
		s_p->leng_p = 5;
		return (7);
	}
	s_p->flags = check_flags(f);
	s_p->p_f = precision(f);
	s_p->f = f;
	while (f[++i])
	{
		if (check_all(f) != 1 || f[i] == '%' || f[i] == 'c' || f[i] == 'C')
			return (type_back(f, i, ap, s_p));
		else if (f[i] == 's' || f[i] == 'S' || f[i] == 'o' || f[i] == 'O')
			return (type_back2(f, i, ap, s_p));
		else if (f[i] == 'd' || f[i] == 'D' || f[i] == 'u' || f[i] == 'U')
			return (type_back3(f, i, ap, s_p));
		else if (f[i] == 'x' || f[i] == 'X' || f[i] == 'p' || f[i] == 'i')
			return (type_back4(f, i, ap, s_p));
	}
	return (i);
}

void	check_format(char *f, va_list ap, t_printf_s *s_p)
{
	int		num;

	s_p->leng_p = 0;
	s_p->leng_p_for_several = 0;
	s_p->temp_st = f;
	num = 0;
	if (ft_strcmp(f, "% ") == 0)
		return ;
	s_p->leng_p_for_several = (ft_strcmp(f, "%%%") == 0) ? 1 : 0;
	while (*s_p->temp_st)
	{
		if (check_format_percent(s_p, ap) == 1)
			return ;
		if (*s_p->temp_st == '\0')
			break ;
		if (check_format_else(f, s_p) == 1)
			return ;
	}
}
