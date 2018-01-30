/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _t_double.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dryshchu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 12:14:47 by dryshchu          #+#    #+#             */
/*   Updated: 2018/01/10 12:14:48 by dryshchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	double_result(va_list ap, char *f, t_printf_s *s_p)
{
	char		*st;
	int			i;
	ptrdiff_t	type_of_arg;
	int			k;

	s_p->leng_p = 0;
	i = -1;
	k = 0;
	s_p->bp = 0;
	type_of_arg = back(0, f, ap, 'd');
	st = ft_itoa(type_of_arg);
	s_p->st = st;
	double_f14(s_p, st, k, i);
}
