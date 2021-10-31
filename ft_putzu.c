/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putzu.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edrodrig <edrodrig@student.42sp.org.b      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/30 16:46:46 by edrodrig          #+#    #+#             */
/*   Updated: 2021/10/31 03:44:16 by edrodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_putchar(unsigned int nbr, char *base)
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

static void	ft_putnbr(unsigned int nbr, size_t base_len, char *base)
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

int	ft_putzu(unsigned int nbr, char *base)
{
	if (*base == '1' && *(base + 1) == '6')
		base = "0123456789abcdef";
	ft_putnbr(nbr, ft_strlen(base), base);
	return (ft_putchar(0, "x"));
}
