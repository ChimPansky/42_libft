/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chimpansky <chimpansky@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 13:48:06 by tkasbari          #+#    #+#             */
/*   Updated: 2023/09/09 20:11:22 by chimpansky       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	char	*str1;
	char	*str2;
	size_t	i;

	str1 = (char *) s1;
	str2 = (char *) s2;
	i = 0;
	if (!n)
		return (0);
	while (i < n)
	{
		if (*(str1 + i) - *(str2 + i))
			return (*(str1 + i) - *(str2 + i));
		i++;
	}
	return (0);
}
