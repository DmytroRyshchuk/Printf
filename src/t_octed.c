/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _t_octed.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dryshchu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 12:15:19 by dryshchu          #+#    #+#             */
/*   Updated: 2018/01/10 12:15:21 by dryshchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	octat_result(va_list ap, char *f, t_printf_s *s_p)
{
	char	*st;
	int		i;
	size_t	original;

	s_p->leng_p = 0;
	i = 0;
	original = uback(0, f, ap, 'o');
	st = convert_decimal_to_octal(original);
	if (!ft_strcmp(check_priority(f), " "))
		st = convert_decimal_to_octal(original);
	s_p->st = st;
	if (octat_operations(s_p, f, i, 0) == 1)
		return ;
}
