/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkasbari <thomas.kasbarian@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 13:48:06 by tkasbari          #+#    #+#             */
/*   Updated: 2023/09/14 12:00:01 by tkasbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_get_left(char const *s1, char const *set)
{
	char	*str;
	size_t	left;

	left = 0;
	str = (char *)s1;
	while (ft_strchr(set, *str))
	{
		left++;
		str++;
	}
	return (left);
}

size_t	ft_get_right(char const *s1, char const *set)
{
	char	*str;
	size_t	right;

	right = 0;
	str = (char *)(s1 + ft_strlen(s1) - 1);
	while (ft_strrchr(set, *str))
	{
		right++;
		str--;
	}
	return (right);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*result;
	size_t	left;
	size_t	right;
	size_t	len;

	if (!s1)
		return (NULL);
	len = ft_strlen(s1);
	left = ft_get_left(s1, set);
	right = ft_get_right(s1, set);
	if (left > len || right > len)
		len = 0;
	else
		len = len - left - right;
	result = (char *)ft_calloc(sizeof(char), len + 1);
	if (!result)
		return (NULL);
	return (ft_substr(s1, left, len));
}
