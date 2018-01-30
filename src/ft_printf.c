/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dryshchu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/21 14:04:08 by dryshchu          #+#    #+#             */
/*   Updated: 2017/12/21 14:04:09 by dryshchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printf(char *format, ...)
{
	int				j;
	t_printf_s		*s_p;
	va_list			ap;

	s_p = malloc(sizeof(t_printf_s));
	va_start(ap, format);
	check_format(format, ap, s_p);
	va_end(ap);
	j = s_p->leng_p_for_several;
	return (j);
}
