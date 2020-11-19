/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analyze.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehattor <sehattor@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 21:56:17 by sehattor          #+#    #+#             */
/*   Updated: 2020/11/18 02:17:43 by sehattor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

long	init_g(char *str)
{
	int i;

	i = 0;
	g_flag = 0;
	while (ft_strchr(FLAG, str[i]))
	{
		if (str[i] == '0')
			g_flag |= ZERO;
		if (str[i] == '-')
			g_flag |= LEFT;
		if (str[i] == ' ')
			g_flag |= SPACE;
		i++;
	}
	g_preci = 0;
	g_type = 0;
	g_width = 0;
	g_pzero = 0;
	g_value = 0;
	g_isp = 0;
	return (i);
}

int		num_len(char *str)
{
	int i;

	i = 0;
	while (ft_isdigit(str[i]))
		i++;
	return (i);
}

int		analysis(char *str, va_list args)
{
	long	len;

	len = init_g(str);
	if ((g_width = ft_atoi(&str[len])))
		len += num_len(&str[len]);
	else if (str[len] == '*' && ++len)
		g_width = va_arg(args, int);
	if (str[len] == '.' && ++len)
	{
		if ((g_preci = ft_atoi(&str[len])) || str[len] == '0')
			len += num_len(&str[len]);
		else if (str[len] == '*' && len++)
			g_preci = va_arg(args, int);
		if (g_preci == 0)
			g_pzero = 1;
	}
	if (g_width < 0 && (g_flag |= LEFT))
		g_width = -g_width;
	if (ft_strchr(TYPE, str[len]) && (g_type = *ft_strchr(TYPE, str[len])))
	{
		value_ana(args);
		return (++len);
	}
	write(1, "%", 1);
	return (0);
}

void	value_ana(va_list args)
{
	if (g_type == '%')
		g_value = '%';
	else
		g_value = va_arg(args, long);
	if (!g_value && g_type == 's')
		g_value = (long)"(null)";
	organize();
	print_ma();
}
