/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_sub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehattor <sehattor@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 20:08:00 by sehattor          #+#    #+#             */
/*   Updated: 2020/11/18 02:15:42 by sehattor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	print_ui(unsigned int n, unsigned int base)
{
	if (n >= base)
		print_ui(n / base, base);
	g_len++;
	if (g_type == 'X')
		write(1, &"0123456789ABCDEF"[n % base], 1);
	else
		write(1, &"0123456789abcdef"[n % base], 1);
}

void	print_p(unsigned long n, unsigned long base)
{
	if (n >= base)
		print_p(n / base, base);
	g_len++;
	write(1, &"0123456789abcdef"[n % base], 1);
}

void	print_i(int n, int base)
{
	long ln;

	ln = (long)n;
	if (ln < 0)
		ln = -ln;
	if (ln >= base)
		print_i((int)ln / base, base);
	g_len++;
	write(1, &"0123456789abcdef"[ln % base], 1);
}

void	putstr(char *str)
{
	int	i;

	i = ft_strlen(str);
	if (g_preci > 0)
		i = i > g_preci ? g_preci : i;
	if (!g_pzero)
	{
		write(1, str, i);
		g_len += i;
	}
}

void	print_ma(void)
{
	if (!(g_flag & LEFT))
		width_fill();
	preci_fill();
	if ((g_type == 'c' || g_type == '%') && ++g_len)
		write(1, &g_value, 1);
	if (g_type == 's')
		putstr((char*)g_value);
	if (!g_value && g_pzero)
		write(1, "", 0);
	else if ((g_type == 'x' || g_type == 'X' || g_type == 'd' || g_type == 'i'
			|| g_type == 'u') && g_pzero && !g_value && g_width > 0 && ++g_len)
		write(1, " ", 1);
	else if (g_type == 'x' || g_type == 'X')
		print_ui((unsigned int)g_value, 16);
	else if (g_type == 'p')
		print_p((unsigned long)g_value, 16);
	else if (g_type == 'd' || g_type == 'i')
		print_i((int)g_value, 10);
	else if (g_type == 'u')
		print_ui((unsigned int)g_value, 10);
	else if (g_type == 'o')
		print_ui((unsigned int)g_value, 8);
	if (g_flag & LEFT)
		width_fill();
}
