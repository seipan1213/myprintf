/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehattor <sehattor@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 20:02:22 by sehattor          #+#    #+#             */
/*   Updated: 2020/11/18 02:16:33 by sehattor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_printf(const char *s, ...)
{
	va_list	args;
	long	s_len;
	char	*str;

	g_len = 0;
	str = (char *)s;
	va_start(args, s);
	while (*str != '\0')
	{
		s_len = 0;
		while (str[s_len] && str[s_len] != '%')
			s_len++;
		write(1, str, s_len);
		str += s_len;
		g_len += s_len;
		if (*str == '%')
			str += analysis(str + 1, args) + 1;
	}
	va_end(args);
	return (g_len);
}
