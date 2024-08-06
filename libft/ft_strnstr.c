/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarkis <msarkis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 08:53:55 by msarkis           #+#    #+#             */
/*   Updated: 2024/07/29 08:53:57 by msarkis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	lenlittle;
	size_t	i;
	size_t	j;

	i = 0;
	lenlittle = ft_strlen (little);
	if (lenlittle == 0 || little == big)
		return ((char *)big);
	while (big[i] != '\0' && i < len)
	{
		j = 0;
		while (((j + i) < len) && little[j] != '\0'
			&& big[i + j] != '\0' && big[i + j] == little[j])
		{
			j++;
			if (j == lenlittle)
				return ((char *)big + i);
		}
		i++;
	}
	return (0);
}
