/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _t_unsigned_decimal.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dryshchu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 14:01:06 by dryshchu          #+#    #+#             */
/*   Updated: 2018/01/11 14:01:08 by dryshchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	unsigned_decimal_result(va_list ap, char *f, t_printf_s *s_p)
{
	char				*st;
	int					i;
	unsigned long long	type_of_arg;

	s_p->leng_p = 0;
	s_p->bp = 0;
	i = -1;
	type_of_arg = uback(0, f, ap, 'u');
	st = ft_uitoa(type_of_arg);
	if (udec_operations(s_p, f, st, i) == 1)
		return ;
}
