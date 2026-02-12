#include <stdio.h>
#include <string.h>

size_t ft_strlen(const char *s);
char *ft_strcpy(char *dst, const char *src);

int main()
{
	printf("Testing LIBASM\n");
	int asm_ver = ft_strlen("Hello World");
	printf("ASM strlen: %d\n", asm_ver);
	int original_ver = strlen("Hello World");
	printf("Original strlen: %d\n", original_ver);
	if (asm_ver == original_ver)
		printf("ASM strlen is correct!\n");
	else
		printf("ASM strlen is incorrect!\n");
	printf("\n");
	char src[] = "Hello World";
	char dst[20];
	ft_strcpy(dst, src);
	printf("ASM strcpy: %s\n", dst);
	if (strcmp(dst, src) == 0)
		printf("ASM strcpy is correct!\n");
	else
		printf("ASM strcpy is incorrect!\n");
	return 0;
}
