/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehattor <sehattor@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 18:23:25 by sehattor          #+#    #+#             */
/*   Updated: 2020/11/18 00:40:04 by sehattor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>
# define FLAG "-0 "
# define TYPE "csopdiuxX%"
# define ZERO 1
# define LEFT 2
# define SPACE 4

int		g_flag;
int		g_width;
int		g_preci;
int		g_type;
int		g_pzero;
long	g_value;
int		g_isp;
int		g_len;

size_t	ft_strlen(const char *s);
int		ft_isdigit(int c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_atoi(const char *str);
char	*ft_strchr(const char *s, int c);
int		ft_printf(const char *s, ...);
int		base_len(long n);
void	preci_fill(void);
void	width_fill(void);
void	print_ui(unsigned int n, unsigned int base);
void	print_i(int n, int base);
void	print_p(unsigned long n, unsigned long base);
void	putstr(char *str);
void	print_ma(void);
long	init_g(char *str);
int		num_len(char *str);
int		analysis(char *str, va_list args);
void	value_ana(va_list args);
void	organize(void);
void	organize_con(void);

#endif
