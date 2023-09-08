/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkasbari <thomas.kasbarian@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 13:48:06 by tkasbari          #+#    #+#             */
/*   Updated: 2023/09/08 18:07:44 by tkasbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"


int	ft_count_words(char *str, char sep)
{
	int	count;
	int	i;
	int	start;

	i = -1;
	count = 0;
	start = 1;
	while (str[++i])
	{
		if (str[i] == sep)
			start = 1;
		else
		{
			if (start)
				count++;
			start = 0;
		}
	}
	return (count);
}

char	*ft_create_word(char *str, char sep, int index)
{
	int	i;
	int	len;
	char *word;

	i = index;
	len = 0;
	while (str[i] && str[i] != sep)
	{
		len++;
		i++;
	}
	if (!(word = (char *)malloc(sizeof(char) * (len + 1))))
		return (0);
	i = -1;
	while (++i < len)
		word[i] = str[index + i];
	word[i] = '\0';
	return (word);
}

char	**ft_split(char const *s, char c)
{
	char **result;
	char	*str;
	int		words;
	int		i;
	int		j;

	str = (char *) s;
	words = ft_count_words(str, c);
	if (!(result = (char **)malloc(sizeof(char *) * (words + 1))))
		return (0);
	i = -1;
	j = 0;
	while(++i < words)
	{
		while(str[i] == c)
			j++;
		if (!((result[i] = ft_create_word(str, c, j))))
		{
			while (i > 0)
			{
				if (result[--i])
					free(result[i]);
			}
			free(result);
			return (0);
		}
		j += ft_strlen(result[i]);
	}
	result[i] = 0;
	return (result);
}
/*
#include <stdio.h>
int	main(int argc, char *argv[])
{
	if (argc == 3)
	{
		char **my_split;
		int	i;

		my_split = ft_split(argv[1], argv[2]);


		if (my_split)
		{
			printf("sizeof(ft_split(%s, %s)): %ld\n", argv[1], argv[2], sizeof(my_split));
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
		printf("Please enter arguments for ft_split(char *str, char *charset):\n");
	}
	return (0);
}
*/
