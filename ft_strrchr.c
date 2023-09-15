/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkasbari <thomas.kasbarian@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 13:48:06 by tkasbari          #+#    #+#             */
/*   Updated: 2023/09/15 12:37:24 by tkasbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char				*str;
	size_t				len;
	const unsigned char	myc = (const unsigned char) c;

	str = (char *)s;
	len = ft_strlen(str);
	str += len;
	if (*str == myc)
		return (str);
	while (len--)
	{
		str--;
		if (*str == myc)
			return (str);
	}
	return (NULL);
}
