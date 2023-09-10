#include "libft.h"
#include <ctype.h>
#include <stdio.h>
#include <strings.h>
#include <string.h>
#include <stddef.h>
#include <bsd/string.h>


int	main(int argc, char **argv)
{
	if (argc > 1)
	{
		//printf("strlen: %lu\n",strlen(argv[1]));
		//printf("ft_strlen: %lu\n",ft_strlen(argv[1]));
	}
	else
	{
		(void)argv;

		printf("begin testing\n");
		
		char *str = "the cake is a lie !I'm hidden lol\r\n";

		char buff1[50] = "there is no stars in the sky";
//		char buff2[50] = "there is no stars in the sky";
		size_t max = strlen("the cake is a lie !I'm hidden lol\r\n") + 4;

		strlcat(buff1, str, max);
//		ft_strlcat(buff2, str, max);

		printf("buff1: %s\n", buff1);
//		printf("buff2: %s\n", buff2);
/*
		printf("ft_strrchr: %s\n", ft_strrchr(" ", '\0'));
		printf("strrchr   : %s\n", strrchr(" ", '\0'));
		
		printf("ft_strtrim: %s\n", ft_strtrim("xXXaaa","xXa"));
		
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
