/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarkis <msarkis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 08:51:56 by msarkis           #+#    #+#             */
/*   Updated: 2024/07/29 08:52:00 by msarkis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	const unsigned char	*sp;
	unsigned char		*dp;

	sp = (const unsigned char *)src;
	dp = (unsigned char *)dest;
	if (dest == src)
		return (dest);
	if (dp > sp && dp < (n + sp))
	{
		while (n--)
		{
			*(dp + n) = *(sp + n);
		}
	}
	else
	{
		while (n--)
		{
			*dp = *sp;
			dp++;
			sp++;
		}
	}
	return (dest);
}
