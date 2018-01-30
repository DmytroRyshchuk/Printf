/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_exactly_format.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dryshchu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/30 16:47:12 by dryshchu          #+#    #+#             */
/*   Updated: 2018/01/30 16:47:13 by dryshchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		type_back(char *f, int i, va_list ap, t_printf_s *s_p)
{
	if (check_all(f) != 1)
	{
		non_valid_spec(f, f[check_all(f)], s_p);
		return (check_all(f) + 2);
	}
	else if (f[i] == '%')
	{
		percent_result(f, s_p);
		return (i + 2);
	}
	else if (f[i] == 'c')
	{
		char_result(ap, s_p);
		return (i + 2);
	}
	else if (f[i] == 'C')
	{
		unic_char(ap, f, s_p);
		return (i + 2);
	}
	else
		return (type_back2(f, i, ap, s_p));
}

int		type_back2(char *f, int i, va_list ap, t_printf_s *s_p)
{
	if (f[i] == 's')
	{
		str_result(ap, f, s_p);
		return (i + 2);
	}
	else if (f[i] == 'S')
	{
		unicode_str_result(ap, f, s_p);
		return (i + 2);
	}
	else if (f[i] == 'o')
	{
		octat_result(ap, f, s_p);
		return (i + 2);
	}
	else if (f[i] == 'O')
	{
		octat_long_result(ap, f, s_p);
		return (i + 2);
	}
	else
		return (type_back3(f, i, ap, s_p));
}

int		type_back3(char *f, int i, va_list ap, t_printf_s *s_p)
{
	if (f[i] == 'd')
	{
		double_result(ap, f, s_p);
		return (i + 2);
	}
	else if (f[i] == 'D')
	{
		upper_double_result(ap, f, s_p);
		return (i + 2);
	}
	else if (f[i] == 'u')
	{
		unsigned_decimal_result(ap, f, s_p);
		return (i + 2);
	}
	else if (f[i] == 'U')
	{
		unsigned_long_result(ap, f, s_p);
		return (i + 2);
	}
	else
		return (type_back4(f, i, ap, s_p));
}

int		type_back4(char *f, int i, va_list ap, t_printf_s *s_p)
{
	if (f[i] == 'x')
	{
		hex_result(ap, f, s_p);
		return (i + 2);
	}
	else if (f[i] == 'X')
	{
		hex_upper_result(ap, f, s_p);
		return (i + 2);
	}
	else if (f[i] == 'p')
	{
		pointer_result(ap, f, s_p);
		s_p->leng_p += 2;
		return (i + 2);
	}
	else if (f[i] == 'i')
	{
		double_result(ap, f, s_p);
		return (i + 2);
	}
	return (0);
}
