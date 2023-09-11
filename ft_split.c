/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkasbari <thomas.kasbarian@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 13:48:06 by tkasbari          #+#    #+#             */
/*   Updated: 2023/09/11 16:46:25 by tkasbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <stdio.h>

char	**ft_split(char const *s, char c);
int		ft_create_words(char **res, char *str, int wordc, char sep);
char	**ft_free_result(char **res, int count);
size_t	ft_count_words(char *str, char sep);


size_t	ft_count_words(char *str, char sep)
{
	size_t	count;
	int		start;

	count = 0;
	start = 1;
	while (*str)
	{
		if (*str == sep)
			start = 1;
		else
		{
			if (start)
				count++;
			start = 0;
		}
		str++;
	}
	return (count);
}

char	**ft_free_result(char **res, int count)
{
	while (count > 0)
	{
		if (res[--count])
			free(res[count]);
	}
	free(res);
	return (NULL);
}

int	ft_create_words(char **res, char *str, int wordc, char sep)
{
	int		i;
	size_t	wlen;

	i = 0;
	wlen = 0;
	while (i < wordc)
	{
		wlen = 0;
		while (*str == sep)
			str++;
		while (*str && *str != sep)
		{
			wlen++;
			str++;
		}
		res[i] = (char *)ft_calloc(sizeof(char), wlen + 1);
		if (!res[i])
		{
			ft_free_result(res, i);
			return (0);
		}
		ft_strlcpy(res[i++], (str - wlen), wlen + 1);
	}
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char	*str;
	size_t	wordc;
	char	**result;

	str = (char *) s;
	wordc = ft_count_words(str, c);
	result = (char **)ft_calloc(sizeof(char *), wordc + 1);
	if (!result)
		return (NULL);
	if (!ft_create_words(result, str, wordc, c))
		return (NULL);
	result[wordc] = NULL;
	return (result);
}
/*

int	main(int argc, char *argv[])
{
	if (argc == 3)
	{
		char **my_split;
		int	i;

		my_split = ft_split(argv[1], *argv[2]);
		if (my_split)
		{
			printf("sizeof(ft_split(%s, %c)): %ld\n", argv[1], *argv[2], sizeof(my_split));
			i = -1;
			while(my_split[++i])
			{
				printf("my_split[%d]: %s\n", i, my_split[i]);
				free(my_split[i]);
			}
			free(my_split);
		}
		//printf("ft_count_words(%s, %s): %d\n", argv[1], argv[2], ft_count_words(argv[1], argv[2]));
		//printf("ft_in_str(%s, %c): %d\n", argv[1], argv[2][0], ft_in_str(argv[1], argv[2][0]));
	}
	else
	{
		printf("Please enter arguments for ft_split(const char *str, char c):\n");
	}
	return (0);
}
*/
