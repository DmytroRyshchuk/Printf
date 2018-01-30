/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _t_upper_double.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dryshchu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 13:53:40 by dryshchu          #+#    #+#             */
/*   Updated: 2018/01/11 13:53:41 by dryshchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	upper_double_result(va_list ap, char *f, t_printf_s *s_p)
{
	char		*st;
	int			i;
	ptrdiff_t	type_of_arg;
	int			k;

	s_p->leng_p = 0;
	i = -1;
	k = 0;
	s_p->bp = 0;
	if (ft_strcmp(f, "hhD") == 0 || ft_strcmp(f, "hhD\n") == 0)
		type_of_arg = va_arg(ap, int);
	else
		type_of_arg = uback(0, f, ap, 'D');
	st = ft_itoa(type_of_arg);
	s_p->st = st;
	double_f14(s_p, st, k, i);
}
