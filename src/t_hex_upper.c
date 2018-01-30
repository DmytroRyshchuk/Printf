/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _t_hex_upper.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dryshchu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 12:51:46 by dryshchu          #+#    #+#             */
/*   Updated: 2018/01/13 12:51:48 by dryshchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	hex_upper_result(va_list ap, char *f, t_printf_s *s_p)
{
	char		*st;
	int			i;
	ptrdiff_t	type_of_arg;

	s_p->leng_p = 0;
	i = 0;
	s_p->bp = 0;
	type_of_arg = uback(0, f, ap, 'X');
	s_p->h = 'X';
	st = my_itoa_base(ft_itoa(type_of_arg), 16, 0);
	s_p->flags = check_flags(f);
	if (hex_operations(s_p, f, st, i) == 1)
		return ;
}
