/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edrodrig <edrodrig@student.42sp.org.b      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 18:02:03 by edrodrig          #+#    #+#             */
/*   Updated: 2021/10/29 20:10:07 by edrodrig         ###   ########.fr       */
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
		}
		else
		{
			ft_putchar_fd(s[i++], 1);
			len++;
		}
	}
	return (len);
}



