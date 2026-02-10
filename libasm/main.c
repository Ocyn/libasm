#include <stdio.h>

int main()
{
	printf("Testing LIBASM\n");
	printf("FT_STRLEN: %zu\n", ft_strlen("Hello, World!"));
	printf("FT_STRCPY: %s\n", ft_strcpy((char[20]){0}, "Hello, World!"));
	printf("FT_STRCMP: %d\n", ft_strcmp("Hello", "Hello"));
	printf("FT_WRITE: %zd\n", ft_write(1, "Hello, World!\n", 14));
	printf("FT_READ: %zd\n", ft_read(0, (char[20]){0}, 20));
	printf("FT_STRDUP: %s\n", ft_strdup("Hello, World!"));
	return 0;
}