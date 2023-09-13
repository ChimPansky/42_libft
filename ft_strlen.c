/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chimpansky <chimpansky@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 13:48:06 by tkasbari          #+#    #+#             */
/*   Updated: 2023/09/13 11:54:46 by chimpansky       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
size_t	ft_strlen(const char* s)
{
	size_t	len;

	len = 0;
	while (*(s + len))
		len++;
	return (len);
}
*/

size_t	ft_strlen(const char* s)
{
	size_t	len;

	len = 0;
	while (*s++)
		len++;
	return (len);
}