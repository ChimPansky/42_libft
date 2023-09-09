/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chimpansky <chimpansky@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 13:48:06 by tkasbari          #+#    #+#             */
/*   Updated: 2023/09/09 21:24:41 by chimpansky       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_get_int_order(int nb)
{
	size_t	ord;

	ord = 1;
	while (nb / 10 != 0)
	{
		ord++;
		nb /= 10;
	}
	return (ord);
}
char *ft_itoa(int n);
{
	char	*str;
	size_t	len;

	len = ft_get_int_order(n);
	if (n < 0)
		len++;
	str = ft_calloc(sizeof(char), len);
	


	str = (char *)s;
	len = ft_strlen(str);
	str += len;
	if (*str == c)
		return (str);
	while (len--)
	{
		str--;
		if (*str == c)
			return (str);
	}
	return (NULL);
}
