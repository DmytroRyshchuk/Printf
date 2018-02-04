/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dryshchu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/04 15:23:46 by dryshchu          #+#    #+#             */
/*   Updated: 2017/11/07 21:28:47 by dryshchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <stddef.h>
# include <stdarg.h>
# include <stdio.h>
# include <wchar.h>

# define US1 (s_p->w_f > ft_strlen_wchar(st) && ft_strlen_wchar(st) < s_p->p_f)
# define US2 (s_p->w_f > ft_strlen_wchar(st) && s_p->p_f == 0)
# define C1 (ft_strcmp(s_p->pr_t, "l") == 0 && unic_char(ap, s_p->f, s_p) == 1)
# define S1 (fill_by_empty(width(f) - precision(f) - ft_strlen(s_p->st)))

typedef	struct		s_printf_s
{
	int				leng_p;
	int				leng_p_for_several;
	int				leng_used;
	int				second_time;
	char			*st;
	int				*st_wc;
	char			*temp_st;
	char			*flags;
	char			*pr_t;
	int				w_f;
	int				s_st;
	int				p_f;
	char			*f;
	int				bp;
	char			h;
	int				len;
}					t_printf_s;

/*
**Types
*/
void				char_result(va_list ap, t_printf_s *s_p);
void				double_result(va_list ap, char *f, t_printf_s *s_p);
void				hex_result(va_list ap, char *f, t_printf_s *s_p);
void				hex_upper_result(va_list ap, char *f, t_printf_s *s_p);
void				non_valid_spec(char *f, char c, t_printf_s *s_p);
void				octat_result(va_list ap, char *f, t_printf_s *s_p);
void				octat_long_result(va_list ap, char *f, t_printf_s *s_p);
void				percent_result(char *f, t_printf_s *s_p);
void				pointer_result(va_list ap, char *f, t_printf_s *s_p);
void				str_result(va_list ap, char *f, t_printf_s *s_p);
int					unic_char(va_list ap, char *f, t_printf_s *s_p);
void				unicode_str_result(va_list ap, char *f, t_printf_s *s_p);
void				unsigned_decimal_result(va_list ap, char *f,
					t_printf_s *s_p);
void				unsigned_long_result(va_list ap, char *f, t_printf_s *s_p);
void				upper_double_result(va_list ap, char *f, t_printf_s *s_p);

/*
**Libft
*/
ptrdiff_t			ft_atoi(const char *str);
char				*ft_itoa(ptrdiff_t nbr);
char				*ft_uitoa(unsigned long long nbr);
int					ft_strlen(const char *s);
int					ft_strlen_wchar(wchar_t *s);
void				ft_putchar(char c);
int					ft_strcmp(const char *s1, const char *s2);
char				*ft_strnew(size_t size);

/*
**Different
*/
int					ft_printf(char *format, ...);
char				*convert_decimal_to_octal(unsigned long long dn);
int					fill_by_zero(int n);
int					fill_by_empty(int n);
int					with_minus_sign(char *f, char *st, char *flags,
					int is_pointer);
intmax_t			back_type(char type, va_list ap);
int					check_types(char type);
intmax_t			back(intmax_t original, char *f, va_list ap, char type);
intmax_t			uback(intmax_t original, char *f, va_list ap, char type);
void				print_st(t_printf_s *s_p, char *st);
void				fill_by_sign(t_printf_s *s_p, char sign);
void				precision_bigger_str(char *f, char *st, t_printf_s *s_p);
void				str_with_minus(char *st, t_printf_s *s_p);

/*
**Check
*/
int					type_back(char *f, int i, va_list ap, t_printf_s *s_p);
int					type_back2(char *f, int i, va_list ap, t_printf_s *s_p);
int					type_back3(char *f, int i, va_list ap, t_printf_s *s_p);
int					type_back4(char *f, int i, va_list ap, t_printf_s *s_p);
int					check_format_percent(t_printf_s *s_p, va_list ap);
int					check_format_else(char *f, t_printf_s *s_p);
char				*check_priority_flag(char *f, int i, int now_priority,
					char *priority);
char				*check_priority(char *f);
int					check_exactly_format(char *f, va_list ap,
					t_printf_s *s_p);
void				check_format(char *f, va_list ap, t_printf_s *s_p);
int					c_0m(char *f);
int					only_for_minus(char *f);
int					check_dot(char *s);
int					dot_p(char *s);
int					value_zero(char *s);
int					priority_letters(char *s);
int					check_if_empty_string(char *s);
int					at_first(char *s, int i);
int					check_all(char *f);
void				crutch(char *s);
int					is_width_real(char c);
int					check_percent(char *s, t_printf_s *s_p);
int					precision(char *s);
int					precision_in_work(char *s, int i, int num, int decimal);
int					width(char *s);
int					work_with_width(char *s, int i, int num, int decimal);
char				*check_flags(char *f);
char				*fill_which_flags(char *f, int i, char *which_flags,
					int flag);

/*
**Doubles
*/
int					minus_and_plus_flags(char *s);
int					check_dot_full(char *s);
int					double_f1(t_printf_s *s_p, char *f, char *st);
int					double_f2(t_printf_s *s_p, char *st, int i);
int					double_f3_0(t_printf_s *s_p, char *st, int i, char *f);
int					double_f3(t_printf_s *s_p, char *st, int k, char *f);
int					double_f4(t_printf_s *s_p, char *st, int k, char *f);
int					double_f5(t_printf_s *s_p, char *st, int k, char *f);
int					double_f6(t_printf_s *s_p, char *st, char *f);
int					double_f7(t_printf_s *s_p, char *st, char *f, int k);
int					double_f8(t_printf_s *s_p, char *st, char *f);
int					double_f9(t_printf_s *s_p, char *st, char *f, int k);
int					double_f10(t_printf_s *s_p, char *st, char *f, int k);
int					double_f11(t_printf_s *s_p, char *st, char *f);
int					double_f12(t_printf_s *s_p, char *st, char *f, int k);
int					double_f13(t_printf_s *s_p, char *st, int k, int i);
void				double_f14(t_printf_s *s_p, char *st, int k, int i);

/*
**Hex
*/
char				*my_itoa_base(char *n, int base, int letter);
void				x_zero(t_printf_s *s_p);
int					hex_operations(t_printf_s *s_p, char *f, char *st, int i);
int					hex_make_it_short(t_printf_s *s_p, char *f, char *st);
int					hex_flags(t_printf_s *s_p, char *f, char *st, int i);
void				hex_f_empty(t_printf_s *s_p, char *f, char *st, int i);
void				hex_f_minus(t_printf_s *s_p, char *f, char *st, int i);
int					hex_f_plus(t_printf_s *s_p, char *f, char *st, int i);
int					hex_f_zero(t_printf_s *s_p, char *f, char *st);
int					hex_f_sharp1(t_printf_s *s_p, char *f, char *st);
int					hex_f_sharp2(t_printf_s *s_p, char *f, char *st);
int					hex_f_sharp3(t_printf_s *s_p, char *f, char *st);
int					hex_width1(t_printf_s *s_p, char *f, char *st);
int					hex_width2(t_printf_s *s_p, char *f, char *st);
void				hex_width3(t_printf_s *s_p, char *f, char *st);

/*
**Unsigned decimal
*/
int					udec_f_minus(t_printf_s *s_p, char *f, char *st, int i);
int					udec_f_plus(t_printf_s *s_p, char *f, char *st, int i);
void				udec_f_zero(t_printf_s *s_p, char *f, char *st, int i);
int					udec_width1(t_printf_s *s_p, char *f, char *st);
int					udec_width2(t_printf_s *s_p, char *f, char *st);
int					udec_make_it_short(t_printf_s *s_p, char *f, char *st);
int					udec_check_dot(t_printf_s *s_p, char *f, char *st);
int					udec_operations(t_printf_s *s_p, char *f, char *st, int i);

/*
**Octat
*/
int					octat_first_f(t_printf_s *sp, char *f, char *st);
int					octat_f_zero(t_printf_s *s_p, char *f, char *st);
int					octat_f_plus(t_printf_s *s_p, char *f, char *st, int i);
int					octat_f_minus1(t_printf_s *s_p, char *f, char *st);
int					octat_f_minus2(t_printf_s *s_p, char *f, char *st, int p);
int					octat_f_sharp(t_printf_s *s_p, char *f, char *st);
int					octat_flags(t_printf_s *s_p, char *f, int i);
int					octat_f1(t_printf_s *s_p, char *f, char *st);
int					octat_f2(t_printf_s *s_p, char *f, char *st);
int					octat_operations(t_printf_s *s_p, char *f, int i,
					size_t original);

/*
**Unicode Char
*/
int					ft_wchar(wchar_t c);
int					ft_wchar_l(wchar_t c);

/*
**String
*/
int					if_string_null(t_printf_s *s_p, char *st, char *f, int i);
int					string_first_f(t_printf_s *s_p, char *st, char *f);
int					string_check_dot(t_printf_s *s_p, char *st, char *f, int i);
int					string_flags(t_printf_s *s_p, char *s, char *f, int i);
int					string_f_zero(t_printf_s *s_p, char *s, char *f, int i);
void				string_f_plus(t_printf_s *s_p, char *s, char *f, int i);
int					string_f_minus(t_printf_s *s_p, char *s, char *f, int i);
int					string_operations(t_printf_s *s_p, char *f, char *st,
					int i);

/*
**Unicode String
*/
int					calc_uni_str(wchar_t *st);
void				uni_str0(t_printf_s *s_p, wchar_t *st);
void				uni_str1(t_printf_s *s_p, wchar_t *st);
int					uni_str2(t_printf_s *s_p, wchar_t *st, char *f);
int					uni_str3(t_printf_s *s_p, wchar_t *st, int ar);
void				uni_str4(t_printf_s *s_p, int v);
int					uni_str5(t_printf_s *s_p, wchar_t *st, int i, char *f);
int					uni_str6_1(t_printf_s *s_p, wchar_t *st, int i);
int					uni_str6(t_printf_s *s_p, wchar_t *st, int i);

/*
**Pointer
*/
void				fill_by_0x(char *what, int plus, t_printf_s *s_p);
void				pointer_f_space(t_printf_s *s_p, char *st, int i, int k);
int					pointer_f_minus(t_printf_s *s_p, char *f, char *st, int i);
int					pointer_f_plus(t_printf_s *s_p, char *st, int i);
int					pointer_f_zero(t_printf_s *s_p, char *st);
int					pointer_f_sharp1(t_printf_s *s_p, char *st, int k);
int					pointer_f_sharp(t_printf_s *s_p, char *f, char *st, int i);
int					pointer_flags(t_printf_s *s_p, char *f, char *st, int i);
int					pointer_width1(t_printf_s *s_p, char *st, int k, int j);
int					pointer_width2(t_printf_s *s_p, char *st);
int					pointer_width(t_printf_s *s_p, char *f, char *st, int k);
int					pointer_make_it_short(t_printf_s *s_p, char *f, char *st,
					int i);
void				pointer_make_it_short2(t_printf_s *s_p, char *f, char *st);
int					pointer_operations(t_printf_s *s_p, char *f, char *st,
					int i);

#endif
