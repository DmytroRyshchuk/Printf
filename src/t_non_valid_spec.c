/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _t_non_valid_spec.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dryshchu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 15:13:45 by dryshchu          #+#    #+#             */
/*   Updated: 2018/01/22 15:13:47 by dryshchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	non_valid_spec2(t_printf_s *s_p, int w, char c)
{
	if (w > 0)
	{
		s_p->leng_p += fill_by_empty(w - 1);
		ft_putchar(c);
		s_p->leng_p++;
	}
}

void	non_valid_spec(char *f, char c, t_printf_s *s_p)
{
	int		i;

	s_p->flags = check_flags(f);
	s_p->w_f = width(f);
	s_p->leng_p = 0;
	i = -1;
	while (s_p->flags[++i])
	{
		if (s_p->flags[0] == '-')
			if (s_p->w_f > 0)
			{
				ft_putchar(c);
				s_p->leng_p++;
				s_p->leng_p += fill_by_empty(s_p->w_f - 1);
			}
		if (s_p->flags[i] == '0')
			if (s_p->w_f > 0)
			{
				s_p->leng_p += fill_by_zero(s_p->w_f - 1);
				ft_putchar(c);
				s_p->leng_p++;
			}
		return ;
	}
	non_valid_spec2(s_p, s_p->w_f, c);
}
