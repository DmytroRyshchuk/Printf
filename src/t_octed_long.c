/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _t_octed_long.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dryshchu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 20:02:02 by dryshchu          #+#    #+#             */
/*   Updated: 2018/01/11 20:02:04 by dryshchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	octat_long_result(va_list ap, char *f, t_printf_s *s_p)
{
	char	*st;
	int		i;
	size_t	original;

	s_p->leng_p = 0;
	i = 0;
	if (ft_strcmp(f, "hhO") == 0 || ft_strcmp(f, "hhO\n") == 0)
		original = va_arg(ap, int);
	else
		original = uback(0, f, ap, 'O');
	st = convert_decimal_to_octal(original);
	if (!ft_strcmp(check_priority(f), " "))
		st = convert_decimal_to_octal(original);
	s_p->st = st;
	if (octat_operations(s_p, f, i, 0) == 1)
		return ;
}

char	*convert_decimal_to_octal(unsigned long long dn)
{
	int					i;
	unsigned long long	n;
	char				*w;

	n = dn;
	i = 0;
	if (dn == 0)
		return ("0");
	while (n != 0)
	{
		i++;
		n /= 8;
	}
	w = ft_strnew(i);
	while (dn != 0)
	{
		w[--i] = dn % 8 + 48;
		dn /= 8;
	}
	return (w);
}
