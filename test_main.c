#include "libft.h"
#include <ctype.h>
#include <stdio.h>
#include <strings.h>
#include <string.h>
#include <stddef.h>
#include <bsd/string.h>

char	ft_rotx(unsigned int x, char c)
{
	return (c + x);
}

int	addition(int a, int b)
{
	return (a + b);
}
int subtraction(int a, int b)
{
	return (a - b);
}

int calculate(int (*operation)(int, int), int x, int y)
{
	return (operation(x, y));
}

char	*strfunc(char *(*funcname)(char *, const char *, size_t), char *s1, const char *s2, size_t size)
{
	return (funcname(s1, s2, size));
}

int	main(int argc, char **argv)
{
	printf("begin testing\n");
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
		(void)argv;

		t_list	*my_node1;
		t_list	*my_node2;
		t_list	**my_list;

		int	a = 5;
		int	b = 6;
		my_node1 = ft_lstnew(&a);
		my_node2 = ft_lstnew(&b);
		my_list = malloc(sizeof(t_list **)*10);
		*my_list = my_node1;

		printf("my_node1->content: %d\n", *(int *)my_node1->content);
		printf("*my_list->content: %d\n", *(int *)(*my_list)->content);
		ft_lstadd_front(my_list, my_node2);
		*my_list = my_node2;
		printf("*my_list->content: %d\n", *(int *)(*my_list)->content);
		printf("ft_lstsize: %d\n", ft_lstsize(*my_list));
		printf("ft_lstlast.content: %d\n", *(int *)ft_lstlast(*my_list)->content);
		/*
		char const str = "abcdef";

		printf("ft_strmapi: %s\n", ft_strmapi(str, ft_rotx, 1, ))
		printf("calc: %d\n", calculate(subtraction, 5, 7));
		char	buff1[20];
		printf("strfunc: \n", );
		strfunc(ft_strlcpy, buff1, "abcdefghij", 5);

		//const char *teststr;

		printf("ft_strrchr: %s\n", ft_strrchr("XxXxxaXbcxxxxxaaaa", 'x'));
		printf("ft_strtrim: %s\n", ft_strtrim("XxXxxaXbcxxxxxx", "cdfxa"));
		printf("ft_strjoin: %s\n", ft_strjoin("daklfn", " X"));
		printf("substr: %s\n", ft_substr("abcdefghij", 7, 5));
		char dest[10] = "abc";
		ft_strlcat(dest,"def",10);
		printf("ft_strlcat: %s\n", dest);


		printf("ft_strdup: %s\n", ft_strdup(""));
		printf("strdup   : %s\n", strdup(""));


		printf("ft_calloc: %s\n", (char *)ft_calloc(100,100));
		printf("calloc   : %s\n", (char *)calloc(100,100));

		char	my_big[40] = "sfsgdneedlefjnjgjnneedlesx";
		char	*my_little = "neeXd";

		char	my_str1[10] = "abc";
		char	my_str2[10] = "abd";

		printf("ft_atoi: %d\n", ft_atoi("   134sa"));
		printf("atoi   : %d\n", atoi("   134sa"));

		printf("ft_strnstr: %s\n", ft_strnstr(my_big, my_little, 100));
		printf("strnstr   : %s\n", strnstr(my_big, my_little, 100));
		printf("ft_memcmp: %d\n", ft_memcmp((void *)my_str1, (void *)my_str2, 3));
		printf("memcmp   : %d\n", memcmp((void *)my_str1, (void *)my_str2, 3));

		//printf("memrchr   : %p\n", memrchr((void *)my_str, 'a', 0));
		printf("ft_memrchr: %s\n", (char *)ft_memrchr((void *)my_str, 'a', 10));
		char	my_str[1] = "";
		char	my_dest[10] = "abcdefghij";
		//char	*nptr1 = NULL;
		//char	*nptr2 = NULL;

		printf("my_dest : %s\n", my_dest);
		printf("%lu\n", strlcat(my_dest, my_str, sizeof(my_dest)));
		//printf("%zu\n", strlcat(my_dest, my_str, 10));
		printf("my_dest : %s\n", my_dest);

		char	my_dest1[10] = "abcdefghij";

		printf("my_dest1: %s\n", my_dest1);
		printf("%lu\n", ft_strlcat(my_dest1, my_str, sizeof(my_dest1)));
		//printf("%ld\n", ft_strlcat(my_dest1, my_str, 10));
		printf("my_dest1: %s\n", my_dest1);


		char	my_str[21] = "Hello World! Wazzzup?";
		void* my_dest;
		void* my_src;

		my_src = (void*)my_str;
		my_dest = (void*)(my_str);

		printf("mystr: %s\n", my_str);
		memmove(my_dest, my_src, 10);
		printf("mystr: %s\n", my_str);

		char	dest[10] = "xxxxxxxxxx";
		printf("dest : %s\n", dest);
		ft_memmove(dest, src, 0);
		printf("dest : %s\n", dest);

		char	src1[10] = "0123456789";
		char	dest1[10] = "xxxxxxxxxx";
		printf("dest1: %s\n", dest1);
		memmove(dest1, src1, 0);
		printf("dest1: %s\n", dest1);
		*/
	}
	return (0);
}
