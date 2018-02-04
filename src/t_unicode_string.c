/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _t_unicode_string.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dryshchu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 13:09:34 by dryshchu          #+#    #+#             */
/*   Updated: 2018/01/24 13:09:36 by dryshchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	unicode_str_result(va_list ap, char *f, t_printf_s *s_p)
{
	int			i;
	int			*st;

	s_p->leng_p = 0;
	s_p->w_f = width(f);
	s_p->p_f = precision(f);
	st = va_arg(ap, int *);
	s_p->st_wc = st;
	i = -1;
	if (st == NULL)
	{
		s_p->leng_p += ft_printf("%s", NULL);
		return ;
	}
	if (uni_str2(s_p, st, f) == 1)
		return ;
	if (uni_str5(s_p, st, i, f) == 1)
		return ;
	while (s_p->flags[++i])
		if (uni_str6(s_p, st, i) == 1)
			return ;
	if (i == 0 && s_p->p_f > 0)
		if (s_p->p_f > ft_strlen_wchar(st))
			s_p->leng_p += fill_by_empty(s_p->p_f - ft_strlen_wchar(st));
	uni_str0(s_p, st);
}
