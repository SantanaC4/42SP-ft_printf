/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edrodrig <edrodrig@student.42sp.org.b      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 23:13:08 by edrodrig          #+#    #+#             */
/*   Updated: 2021/10/31 04:50:47 by edrodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putstr_fd(char *s, int fd)
{
	size_t	i;

	i = ft_strlen(s);
	if (!s)
		return (ft_putstr_fd("(null)", 1));
	while (*s)
		ft_putchar_fd(*s++, fd);
	return (i);
}
