/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkasbari <thomas.kasbarian@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 13:48:06 by tkasbari          #+#    #+#             */
/*   Updated: 2023/09/08 17:28:29 by tkasbari         ###   ########.fr       */
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
	str1 = (char *)s1;
	printf("ft_strrchr in trim: %s\n", strrchr(set, *str1));
	while (strrchr(set, *str1))
	{
		right++;
		str1--;
	}
	len = ft_strlen(s1) - left - right;
	printf("left: %lu\n", left);
	printf("right: %lu\n", right);
	printf("len: %lu\n", len);
	result = (char *)ft_calloc(sizeof(char), len + 1);
	if (!result)
		return (NULL);
	return (ft_substr(s1, left, len));
}
