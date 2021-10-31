/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edrodrig <edrodrig@student.42sp.org.b      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 18:02:03 by edrodrig          #+#    #+#             */
/*   Updated: 2021/10/31 02:02:04 by edrodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_printf(const char *s, ...)
{
	va_list va;
	size_t i;
	size_t len;

	i = 0;
	len = 0;
	va_start(va, s);
	while(s[i])
	{
		if (s[i] == '%')
		{
			i++;
			if (s[i] == 'c')
			{
				ft_putchar_fd(va_arg(va, int), 1);
				len++;
				i++;
			}
			else if (s[i] == 's')
			{
				len += ft_putstr_fd(va_arg(va, char *), 1);
				i++;
			}
			else if (s[i] == 'p')
			{
				len += ft_putnbr_base_ptr((unsigned long long)va_arg(va, char *), "0123456789abcdef");
				i++;
			}
			else if (s[i] == 'd' || s[i] == 'i')
			{
				len += ft_putnbr_base(va_arg(va, int), "0123456789");
				i++;
			}
			else if (s[i] == 'x')
			{
				len += ft_putnbr_base_lu((unsigned int)va_arg(va, int), "0123456789abcdef");
				i++;
			}
			else if (s[i] == 'u')
			{
				len += ft_putnbr_base_lu((unsigned int)va_arg(va, int), "0123456789");
				i++;
			}
			else if (s[i] == 'X')
			{
				len += ft_putnbr_base_lu((unsigned int)va_arg(va, int), "0123456789ABCDEF");
				i++;
			}
			else if (s[i] == '%')
			{
				ft_putchar_fd('%', 1);
				len++;
				i++;
			}
		}
		else
		{
			ft_putchar_fd(s[i++], 1);
			len++;
		}
	}
	va_end(va);
	return (len);
}
