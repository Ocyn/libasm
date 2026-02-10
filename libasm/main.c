#include <stdio.h>
#include <string.h>

size_t ft_strlen(const char *s);

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
	return 0;
}
