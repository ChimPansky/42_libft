/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkasbari <thomas.kasbarian@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 13:13:44 by tkasbari          #+#    #+#             */
/*   Updated: 2023/10/28 13:17:43 by tkasbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*add_prefix(char *s, char *pre)
{
	char	*result;

	result = ft_strjoin_free(pre, s, 2);
	if (!result)
		return (s);
	return (result);
}

char	*pad_negative(char *s, char cpad, size_t width, int to_free)
{
	char	*result;

	result = s;
	*result = '0';
	result = ft_strlpad_free(result, cpad, width, to_free);
	if (result)
		*result = '-';
	return (result);
}

char	*apply_precision_s(char *s, int prec)
{
	int		len;
	char	*result;

	result = s;
	len = prec;
	if (!ft_strncmp(result, "(null)", 6) && (len < 6))
		len = 0;
	result = ft_substr_free(result, 0, len, 1);
	return (result);
}
