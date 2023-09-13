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

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	char *const			dest = dst;
	const char *const	source = src;
	size_t				start;

	start = 0;
	while (start < n)
	{
		*(dest + start) = *(source + start);
		if (*(dest + start) == c)
		{
			start = n;
		}
		else
		{
			start++;
		}
	}
	return (dst);
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

		char	buff1[20];
		char	buff2[20];
		char	*src = "abcdef";

		printf("memcpy   : %s\n", (char *)(memccpy((void*)buff1, src, '\0', 10)));
		printf("ft_memcpy: %s\n", (char *)(ft_memccpy((void*)buff2, src, '\0', 10)));
		printf("buff1: %s\n", buff1);
		printf("buff2: %s\n", buff2);


		int	a = 1;
		int	b = 2;
		int	c = 3;
		char	*d = "abc";

		t_list	*node1;
		t_list	*node2;
		t_list	*node3;
		t_list	*node4;

		node1 = ft_lstnew((void*)&a);
		node2 = ft_lstnew((void*)&b);
		node3 = ft_lstnew((void*)&c);
		node4 = ft_lstnew((void*)&d);
		node1->next = node2;
		node2->next = node3;


		t_list	*new_list = NULL;
		//t_list	**new_list = malloc(sizeof(t_list **));
		ft_lstadd_front(&new_list, node1);

		printf("new_list->content: %d\n", *(int *)(new_list->content));
		printf("new_list->next->content: %d\n", *(int *)(new_list->next->content));
		printf("new_list->next->next->content: %d\n", *(int *)(new_list->next->next->content));

		printf("ft_lstsize: %d\n", ft_lstsize(new_list));
		t_list	*lastnode;
		lastnode = ft_lstlast(new_list);
		printf("lastnode->content: %p\n", &lastnode->content);
		ft_lstadd_back(&new_list, node4);
		printf("ft_lstsize: %d\n", ft_lstsize(new_list));
		printf("lastnode->content: %p\n", &(ft_lstlast(new_list)->content));
		
		/*
		printf("ft_itoa: %s\n", ft_itoa(5));
		printf("ft_itoa: %s\n", ft_itoa(-623));
		printf("ft_strncmp: %d\n", ft_strncmp(ft_itoa(-623), "-623", 10));
		
		printf("strnstr with void: %s\n",strnstr((void *)0, "fake", 3));
		printf("ft_strnstr with void: %s\n",ft_strnstr((void *)0, "fake", 3));
		const char	*str1 = "";
		const char	*str2 = NULL;
		printf("first: %s\n", ft_strjoin("abcdefghijklmn", "xxxxxxxxxxxxxxxxxxxxxx"));
		char *s1 = "my favorite animal is";
		char *s2 = " ";
		char *s3 = "the nyancat";
		char *tmp = ft_strjoin(s1, s2);
		char *res = ft_strjoin(tmp, s3);
		printf("ft_strjoin: %s\n", ft_strjoin((const char *)buff1, (const char *)buff2));
		printf("tmp: %s\n", tmp);
		printf("res: %s\n", res);
		
		char	*src = "the cake is a lie !\0I'm hidden lol\r\n";
		char	dest[200];
		char	ft_dest[200];
		printf("strlen ft_dest: %lu\n", strlen(ft_dest));
		printf("ft_strlen ft_dest: %lu\n", ft_strlen(ft_dest));
		
		size_t max = strlen("the cake is a lie !\0I'm hidden lol\r\n") + 4;
		printf("max: %lu\n", max);
		printf("return of strlcat: %lu\n", strlcat(dest, src, max));
		printf("dest    : %s\n\n", dest);
		printf("return of ft_strlcat: %lu\n", ft_strlcat(ft_dest, src, max));
		printf("ft_ dest: %s\n\n", ft_dest);
		
		printf("\n\n");

		char *src2 = "aaa";
		char dst1[20];
		char dst2[20];
		int ret1;
		int ret2;

		memset(dst1, 'B', sizeof(dst1));
		memset(dst2, 'B', sizeof(dst2));
		strlcat(dst1, src2, 20);
		printf("dst1: %s\n", dst1);
		strlcat(dst1, src2, 20);
		printf("dst1: %s\n", dst1);
		ret1 = strlcat(dst1, src2, 20);
		printf("dst1: %s\n", dst1);
		printf("ret1: %d\n\n", ret1);
		(void)ret2;
		ft_strlcat(dst2, src2, 20);
		printf("dst2: %s\n", dst2);
		ft_strlcat(dst2, src2, 20);
		printf("dst2: %s\n", dst2);
		ret2 = ft_strlcat(dst2, src2, 20);
		printf("dst2: %s\n", dst2);
		printf("ret2: %d\n\n", ret2);

		char dest3[100];
		dest3[0] = '\0';
		dest3[11] = 'a';
		printf("return of ft_strlcat: %lu\n", ft_strlcat(dest3, "lorem ipsum", 15));
		write(1, "\n", 1);
		write(1, dest, 15);
	Expected (cat -e test03.output):
	11$
	lorem ipsum^@^@^@^@
	Your result (cat -e user_output_test03):
	11$
	lorem ipsum^@^@^@^@dst_len in ft_strlcat: 0$
	src_len in ft_strlcat: 11$


		
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
