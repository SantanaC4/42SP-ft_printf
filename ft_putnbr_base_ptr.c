/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base_ptr.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edrodrig <edrodrig@student.42sp.org.b      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/30 16:46:46 by edrodrig          #+#    #+#             */
/*   Updated: 2021/10/31 02:01:50 by edrodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_putchar(unsigned long long nbr, char *base)
{
	static int count;
	int aux;

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
	if (nbr < base_len)
	{
		ft_putchar(nbr, base);
		return ;
	}
	else
		ft_putnbr(nbr / base_len, base_len, base);
	ft_putnbr(nbr % base_len, base_len, base);
}
int		ft_putnbr_base_ptr(unsigned long long nbr, char *base)
{
	if (!nbr)
	{
		ft_putstr_fd("(nil)", 1);
		return (5);
	}
	ft_putstr_fd("0x",1);
	ft_putnbr(nbr, ft_strlen(base), base);
	return (ft_putchar(0, "x") + 2);
}
