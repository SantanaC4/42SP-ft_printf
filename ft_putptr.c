/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edrodrig <edrodrig@student.42sp.org.b      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/30 16:46:46 by edrodrig          #+#    #+#             */
/*   Updated: 2021/10/31 04:29:34 by edrodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_putchar(unsigned long long nbr, char *base)
{
	int			aux;
	static int	count;

	if (*base == 'x')
	{
		aux = count;
		count = 0;
		return (aux);
	}
	nbr = *(base + nbr);
	write(1, &nbr, 1);
	return (count++);
}

static void	ft_putnbr(unsigned long long nbr, size_t base_len, char *base)
{
	if (nbr < 16)
	{
		ft_putchar(nbr, base);
		return ;
	}
	else
		ft_putnbr(nbr / base_len, base_len, base);
	ft_putnbr(nbr % base_len, base_len, base);
}

int	ft_putptr(unsigned long long nbr, char *base)
{
	if (!nbr)
	{
		ft_putstr_fd("0x0", 1);
		return (3);
	}
	if (*base == '1' && *(base + 1) == '6')
		base = "0123456789abcdef";
	ft_putstr_fd("0x", 1);
	ft_putnbr(nbr, ft_strlen(base), base);
	return (ft_putchar(0, "x") + 2);
}
