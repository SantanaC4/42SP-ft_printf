/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edrodrig <edrodrig@student.42sp.org.b      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/30 22:05:07 by edrodrig          #+#    #+#             */
/*   Updated: 2021/10/31 02:14:54 by edrodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_putchar(int nbr, char *base)
{
	int			aux;
	static int	count;

	if (*base == 'x')
	{
		aux = count;
		count = 0;
		return (aux);
	}
	if (*base == '-')
	{
		write(1, &(*base), 1);
		return (count++);
	}
	nbr = *(base + nbr);
	write(1, &nbr, 1);
	return (count++);
}

static void	ft_putnbr(int nbr, size_t base_len, char *base)
{
	unsigned int	n;

	if (nbr < 0)
	{
		ft_putchar(0, "-");
		n = nbr * (-1);
	}
	else
		n = nbr;
	if (n < base_len)
	{
		ft_putchar(n, base);
		return ;
	}
	else
		ft_putnbr(n / base_len, base_len, base);
	ft_putnbr(n % base_len, base_len, base);
}

int	ft_putnbr_base(int nbr, char *base)
{
	ft_putnbr(nbr, ft_strlen(base), base);
	return (ft_putchar(0, "x"));
}
