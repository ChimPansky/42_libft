/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkasbari <thomas.kasbarian@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 13:48:06 by tkasbari          #+#    #+#             */
/*   Updated: 2023/09/08 18:09:01 by tkasbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str1;
	char	*result;
	size_t	left;
	size_t	right;
	size_t	len;

	str1 = (char *)s1;
	left = 0;
	right = 0;
	while (ft_strchr(set, *str1))
	{
		left++;
		str1++;
	}
	str1 = (char *)(s1 + ft_strlen(s1) - 1);
	while (ft_strrchr(set, *str1)) // PROBLEM WITH RETURNED INDEX
	{
		right++;
		str1--;
	}
	len = ft_strlen(s1) - left - right;
	result = (char *)ft_calloc(sizeof(char), len + 1);
	if (!result)
		return (NULL);
	return (ft_substr(s1, left, len));
}
