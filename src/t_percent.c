/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _t_percent.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dryshchu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 18:17:59 by dryshchu          #+#    #+#             */
/*   Updated: 2018/01/11 18:18:01 by dryshchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	percent_result(char *f, t_printf_s *s_p)
{
	int	i;

	s_p->leng_p = 0;
	s_p->flags = check_flags(f);
	i = -1;
	if (width(f) > 0)
	{
		while (s_p->flags[++i])
			if (s_p->flags[i] == '-')
			{
				fill_by_sign(s_p, '%');
				s_p->leng_p += fill_by_empty(width(f) - 1);
				return ;
			}
			else if (s_p->flags[i] == '0')
			{
				s_p->leng_p += fill_by_zero(width(f) - 1);
				fill_by_sign(s_p, '%');
				return ;
			}
		s_p->leng_p += fill_by_empty(width(f) - 1);
	}
	fill_by_sign(s_p, '%');
	return ;
}
