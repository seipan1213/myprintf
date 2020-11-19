/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehattor <sehattor@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 20:05:57 by sehattor          #+#    #+#             */
/*   Updated: 2020/11/18 02:29:27 by sehattor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		base_len(long n)
{
	int				i;
	unsigned long	base;
	unsigned long	nl;

	nl = (unsigned long)n;
	if (g_type == 'd' || g_type == 'i' || g_type == 'u')
		base = 10;
	else if (g_type == 'p' || g_type == 'x' || g_type == 'X')
		base = 16;
	else
		base = 10;
	i = 1;
	if (n < 0)
		n = -n;
	while (n >= (long)base && g_type != 'p')
	{
		n /= base;
		i++;
	}
	while (nl >= base && g_type == 'p')
	{
		nl /= base;
		i++;
	}
	return (i);
}

void	preci_fill(void)
{
	int	i;

	i = g_preci;
	if ((g_isp == 1 || g_flag != ZERO) && (int)g_value < 0 &&
		(g_type == 'i' || g_type == 'd'))
	{
		write(1, "-", 1);
		g_len++;
	}
	if (g_flag & SPACE && g_value >= 0)
	{
		write(1, " ", 1);
		g_len++;
	}
	if (g_type == 'c' || g_type == 's' || g_type == '%')
		return ;
	if (g_type == 'p' && (g_len += 2))
		write(1, "0x", 2);
	while (i-- > 0 && ++g_len)
		write(1, "0", 1);
}

void	width_fill(void)
{
	char	c;
	int		i;

	i = g_width;
	if ((g_isp == 0 || g_type == '%') && g_type != 'c' && g_type != 'p')
		c = g_flag == ZERO ? '0' : ' ';
	else
		c = ' ';
	if (g_isp == 0 && g_flag == ZERO && (int)g_value < 0 &&
		(g_type == 'i' || g_type == 'd'))
	{
		write(1, "-", 1);
		g_len++;
	}
	if (!g_value && g_pzero)
		i++;
	while (i-- > 0 && ++g_len)
		write(1, &c, 1);
}
