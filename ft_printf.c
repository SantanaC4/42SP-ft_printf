/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edrodrig <edrodrig@student.42sp.org.b      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 18:02:03 by edrodrig          #+#    #+#             */
/*   Updated: 2021/10/31 04:46:22 by edrodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_select_format(char c, va_list args)
{
	int	len;

	len = 0;
	if (c == 'c')
		len += ft_putchar_fd(va_arg(args, int), 1);
	else if (c == 's')
		len += ft_putstr_fd(va_arg(args, char *), 1);
	else if (c == 'p')
		len += ft_putptr((unsigned long long)va_arg(args, char *), "16");
	else if (c == 'd' || c == 'i')
		len += ft_putnbr_base(va_arg(args, int), "0123456789");
	else if (c == 'x')
		len += ft_putzu(va_arg(args, unsigned int), "0123456789abcdef");
	else if (c == 'u')
		len += ft_putzu(va_arg(args, unsigned int), "0123456789");
	else if (c == 'X')
		len += ft_putzu(va_arg(args, unsigned int), "0123456789ABCDEF");
	else if (c == '%')
		len += ft_putchar_fd('%', 1);
	return (len);
}

int	ft_printf(const char *s, ...)
{
	va_list	va;
	size_t	i;
	size_t	len;

	i = 0;
	len = 0;
	va_start(va, s);
	while (s[i])
	{
		if (s[i] == '%')
		{
			i++;
			len += ft_select_format(s[i++], va);
		}
		else
			len += ft_putchar_fd(s[i++], 1);
	}
	va_end(va);
	return (len);
}
