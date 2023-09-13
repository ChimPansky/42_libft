/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chimpansky <chimpansky@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 13:48:06 by tkasbari          #+#    #+#             */
/*   Updated: 2023/09/13 13:23:03 by chimpansky       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	char	*str;
	int		neg;
	size_t	len;
	long	nb;

	neg = 0;
	nb = (long)n;
	len = ft_get_int_order(n);
	if (nb < 0)
		neg = 1;
	str = ft_calloc(sizeof(char), len + neg + 1);
	if (!str)
		return (NULL);
	if (neg)
	{
		str[0] = '-';
		nb *= -1;
	}
	str[len + neg + 1] = '\0';
	while (len--)
	{
		str[len + neg] = '0' + (nb % 10);
		nb /= 10;
	}
	return (str);
}
