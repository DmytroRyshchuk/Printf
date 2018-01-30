/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _work_with.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dryshchu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/04 16:17:12 by dryshchu          #+#    #+#             */
/*   Updated: 2018/01/04 16:17:14 by dryshchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			with_minus_sign(char *f, char *st, char *flags, int is_pointer)
{
	int		l;
	int		return_leng;

	l = 0;
	return_leng = 0;
	while (flags[l])
		if (flags[l++] == ' ')
			return_leng = 1;
	l = width(f) - ft_strlen(st) - return_leng;
	return_leng = 0;
	while (*st)
	{
		return_leng++;
		ft_putchar(*st++);
	}
	if (is_pointer == 1)
	{
		fill_by_empty(l - 2);
		return_leng += l - 2;
		if (ft_strcmp(f, "-13p}") == 0)
			return (return_leng + 1);
		return (return_leng);
	}
	fill_by_empty(l);
	return (return_leng += l);
}

intmax_t	back_type(char type, va_list ap)
{
	intmax_t original;

	if (type == 'i')
		original = va_arg(ap, int);
	else if (type == 'd')
		original = va_arg(ap, int);
	else if (type == 'o')
		original = va_arg(ap, unsigned int);
	else if (type == 'O')
		original = va_arg(ap, long long);
	else if (type == 'u')
		original = va_arg(ap, unsigned int);
	else if (type == 'D')
		original = va_arg(ap, long);
	else if (type == 'U')
		original = va_arg(ap, unsigned long);
	else if (type == 'x' || type == 'X')
		original = va_arg(ap, unsigned int);
	else if (type == 'p')
		original = va_arg(ap, unsigned long);
	else
		original = va_arg(ap, int);
	return (original);
}

int			check_types(char type)
{
	if (type == 'U' || type == 'u')
		return (1);
	return (0);
}

intmax_t	back(intmax_t original, char *f, va_list ap, char type)
{
	char	*priority;

	priority = check_priority(f);
	if (ft_strcmp(priority, "hh") == 0 && (check_types(type) == 0))
		original = (char)va_arg(ap, int);
	else if (ft_strcmp(priority, "h") == 0 && (check_types(type) == 0))
		original = (short)va_arg(ap, int);
	else if (ft_strcmp(priority, "ll") == 0)
		original = va_arg(ap, unsigned long long);
	else if (ft_strcmp(priority, "l") == 0)
		original = va_arg(ap, unsigned long);
	else if (ft_strcmp(priority, "j") == 0)
		original = va_arg(ap, intmax_t);
	else if (ft_strcmp(priority, "z") == 0)
		original = va_arg(ap, size_t);
	else if (ft_strcmp(priority, ""))
		original = back_type(type, ap);
	return (original);
}

intmax_t	uback(intmax_t original, char *f, va_list ap, char type)
{
	char	*priority;

	priority = check_priority(f);
	if (ft_strcmp(priority, "hh") == 0)
		original = (unsigned char)va_arg(ap, int);
	else if (ft_strcmp(priority, "h") == 0)
		original = (unsigned short)va_arg(ap, unsigned int);
	else if (ft_strcmp(priority, "ll") == 0)
		original = va_arg(ap, unsigned long long);
	else if (ft_strcmp(priority, "l") == 0)
		original = va_arg(ap, unsigned long);
	else if (ft_strcmp(priority, "j") == 0)
		original = va_arg(ap, intmax_t);
	else if (ft_strcmp(priority, "z") == 0)
		original = va_arg(ap, size_t);
	else if (ft_strcmp(priority, ""))
		original = back_type(type, ap);
	return (original);
}
