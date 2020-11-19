/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analyze.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehattor <sehattor@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 21:56:17 by sehattor          #+#    #+#             */
/*   Updated: 2020/11/18 02:52:58 by sehattor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	organize(void)
{
	if (g_preci > 0 || g_pzero)
		g_isp = 1;
	if (g_type == 's')
	{
		if ((int)ft_strlen((char*)g_value) < g_preci)
			g_preci = ft_strlen((char*)g_value);
		if (g_preci <= 0 && !g_pzero)
			g_preci = ft_strlen((char*)g_value);
		g_width -= g_preci;
	}
	else if (g_type == 'x' || g_type == 'X' || g_type == 'o')
	{
		g_width -= g_preci > base_len((unsigned int)g_value) ?
			g_preci : base_len((unsigned int)g_value);
		g_preci -= base_len((unsigned int)g_value);
	}
	else if (g_type == 'i' || g_type == 'd')
	{
		g_width -= g_preci > base_len((int)g_value)
				? g_preci : base_len((int)g_value);
		g_width -= (int)g_value < 0 ? 1 : 0;
		g_preci -= base_len((int)g_value);
	}
	organize_con();
}

void	organize_con(void)
{
	if (g_type == 'p')
	{
		g_width -= g_preci > base_len(g_value) ? g_preci : base_len(g_value);
		g_width -= 2;
		g_preci -= base_len(g_value);
	}
	else if (g_type == 'c' || g_type == '%')
	{
		g_width--;
	}
	else if (g_type == 'u')
	{
		g_width -= g_preci > base_len((unsigned int)g_value) ?
			g_preci : base_len((unsigned int)g_value);
		g_preci -= base_len((unsigned int)g_value);
	}
}
