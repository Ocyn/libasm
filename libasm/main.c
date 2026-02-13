#include <stdio.h>
#include <string.h>

size_t	ft_strlen(const char *s);
char	*ft_strcpy(char *dst, const char *src);
int		ft_strcmp(const char *s1, const char *s2);
char	*ft_strdup(const char *s);

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
	printf("\n");
	printf("Testing ft_strcmp:\n");
	char s1[] = "Hello";
	char s2[] = "Hello"; 
	char s3[] = "World";
	int cmp1 = ft_strcmp(s1, s2);
	int cmp2 = ft_strcmp(s1, s3);
	printf("strcmp(s1, s2) = %d\n", cmp1);
	printf("strcmp(s1, s3) = %d\n", cmp2);
	if (cmp1 == 0)
		printf("ASM strcmp is correct for equal strings!\n");
	else
		printf("ASM strcmp is incorrect for equal strings!\n");
	if (cmp2 != 0)
		printf("ASM strcmp is correct for different strings!\n");
	else
		printf("ASM strcmp is incorrect for different strings!\n");
	printf("\nTesting ft_strdup:\n");
	char *dup = ft_strdup(src);
	printf("ASM strdup: %s\n", dup);
	if (strcmp(dup, src) == 0)
		printf("ASM strdup is correct!\n");
	else
		printf("ASM strdup is incorrect!\n");
	printf("\nTesting ft_strdup with empty string:\n");	
	char empty[] = "";
	char *dup_empty = ft_strdup(empty);
	printf("ASM strdup of empty string: '%s'\n", dup_empty);
	if (strcmp(dup_empty, empty) == 0)
		printf("ASM strdup is correct for empty string!\n");
	else
		printf("ASM strdup is incorrect for empty string!\n");
	printf("\nAll tests completed.\n");
	return 0;
}
