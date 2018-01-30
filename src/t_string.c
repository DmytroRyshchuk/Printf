/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _t_string.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dryshchu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 12:13:19 by dryshchu          #+#    #+#             */
/*   Updated: 2018/01/10 12:13:21 by dryshchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	str_result(va_list ap, char *f, t_printf_s *s_p)
{
	char	*st;

	s_p->leng_p = 0;
	st = va_arg(ap, char *);
	s_p->pr_t = check_priority(f);
	if (ft_strcmp(s_p->pr_t, "l") == 0)
	{
		s_p->leng_p += ft_printf("%S", st);
		return ;
	}
	s_p->st = st;
	if (string_operations(s_p, f, st, 0) == 1)
		return ;
}
