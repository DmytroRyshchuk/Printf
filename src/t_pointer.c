/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _t_poiner.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dryshchu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/18 18:13:13 by dryshchu          #+#    #+#             */
/*   Updated: 2018/01/18 18:13:14 by dryshchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	pointer_result(va_list ap, char *f, t_printf_s *s_p)
{
	char		*st;
	int			i;
	ptrdiff_t	type_of_arg;

	s_p->leng_p = 0;
	i = 0;
	s_p->bp = 0;
	type_of_arg = back(0, f, ap, 'p');
	s_p->w_f = width(f);
	s_p->p_f = precision(f);
	st = my_itoa_base(ft_itoa(type_of_arg), 16, 1);
	if (pointer_operations(s_p, f, st, i) == 1)
		return ;
}
