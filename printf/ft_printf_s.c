/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_s.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarkis <msarkis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 08:30:30 by msarkis           #+#    #+#             */
/*   Updated: 2024/07/29 08:30:30 by msarkis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(char *str)
{
	int	count;

	count = 0;
	while (str[count])
		count += ft_printf_c(str[count]);
	return (count);
}

int	ft_printf_s(char *str)
{
	int	count;

	count = 0;
	if (!str)
	{
		count += ft_putstr(NULL_STR);
		return (count);
	}
	count += ft_putstr(str);
	return (count);
}
