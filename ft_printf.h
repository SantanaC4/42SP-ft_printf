/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edrodrig <edrodrig@student.42sp.org.b      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 18:14:29 by edrodrig          #+#    #+#             */
/*   Updated: 2021/10/31 00:39:20 by edrodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <stdarg.h>
#include "libft/libft.h"
int		ft_printf(const char *s, ...);
int		ft_putnbr_base_ptr(unsigned long long nbr, char *base);
int		ft_putnbr_base(int nbr, char *base);
int		ft_putnbr_base_lu(unsigned int nbr, char *base);

#endif
