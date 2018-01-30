/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _t_hex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dryshchu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 12:09:39 by dryshchu          #+#    #+#             */
/*   Updated: 2018/01/12 12:09:41 by dryshchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	hex_result(va_list ap, char *f, t_printf_s *s_p)
{
	char		*st;
	int			i;
	ptrdiff_t	type_of_arg;

	s_p->leng_p = 0;
	i = 0;
	s_p->bp = 0;
	type_of_arg = uback(0, f, ap, 'x');
	s_p->h = 'x';
	st = my_itoa_base(ft_itoa(type_of_arg), 16, 1);
	s_p->flags = check_flags(f);
	if (hex_operations(s_p, f, st, i) == 1)
		return ;
}
