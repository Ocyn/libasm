#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

size_t		ft_strlen(const char *s);
char		*ft_strcpy(char *dst, const char *src);
int			ft_strcmp(const char *s1, const char *s2);
char		*ft_strdup(const char *s);
ssize_t		ft_write(int fd, const void *buf, size_t count);
ssize_t		ft_read(int fd, const void *buf, size_t count);

int main()
{
	printf("Testing LIBASM\n\n");

	printf("Testing ft_strlen:\n");
	{
		printf("Testing ft_strlen with 'Hello World':\n");
		int asm_ver = ft_strlen("Hello World");
		printf("ASM strlen: %d\n", asm_ver);
		int original_ver = strlen("Hello World");
		printf("Original strlen: %d\n", original_ver);
		if (asm_ver == original_ver)
			printf("ASM strlen is correct!\n");
		else
			printf("ASM strlen is incorrect!\n");	
		printf("\nTesting ft_strlen with empty string:\n");
		asm_ver = ft_strlen("");
		printf("ASM strlen of empty string: %d\n", asm_ver);
		original_ver = strlen("");
		printf("Original strlen of empty string: %d\n", original_ver);
		if (asm_ver == original_ver)
			printf("ASM strlen is correct for empty string!\n");
		else
			printf("ASM strlen is incorrect for empty string!\n");
	}

	printf("\nTesting ft_strcpy:\n");

	{

		printf("Testing ft_strcpy with 'Hello World':\n");
		char src[] = "Hello World";
		char dst[50];
		ft_strcpy(dst, src);
		printf("ASM strcpy: %s\n", dst);
		if (strcmp(dst, src) == 0)
			printf("ASM strcpy is correct!\n");
		else
			printf("ASM strcpy is incorrect!\n");
		printf("\nTesting ft_strcpy with empty string:\n");
		char empty[] = "";
		ft_strcpy(dst, empty);
		printf("ASM strcpy of empty string: '%s'\n", dst);
		if (strcmp(dst, empty) == 0)
			printf("ASM strcpy is correct for empty string!\n");
		else
			printf("ASM strcpy is incorrect for empty string!\n");
		printf("\nTesting ft_strcpy with long string:\n");
		char long_src[] = "This is a very long string to test ft_strcpy function.";
		ft_strcpy(dst, long_src);
		printf("ASM strcpy of long string: %s\n", dst);
		if (strcmp(dst, long_src) == 0)
			printf("ASM strcpy is correct for long string!\n");
		else
			printf("ASM strcpy is incorrect for long string!\n");
	}
	printf("Testing ft_strcmp:\n");

	{
		printf("Testing ft_strcmp with 'Hello' and 'Hello':\n");
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
		printf("\nTesting ft_strcmp with empty strings:\n");
		char empty1[] = "";
		char empty2[] = "";
		int cmp_empty = ft_strcmp(empty1, empty2);
		printf("strcmp(empty1, empty2) = %d\n", cmp_empty);
		if (cmp_empty == 0)
			printf("ASM strcmp is correct for empty strings!\n");
		else
			printf("ASM strcmp is incorrect for empty strings!\n");
	}
	printf("\nTesting ft_write:\n");

	{
		printf("Testing ft_write by writing 'Hello, ft_write!\\n' to standard output:\n");
		const char *message = "Hello, ft_write!\n";
		ssize_t bytes_written = ft_write(1, message, strlen(message));
		printf("ASM ft_write wrote %zd bytes\n", bytes_written);
		if (bytes_written == (ssize_t)strlen(message))
			printf("ASM ft_write is correct!\n");
		else
			printf("ASM ft_write is incorrect!\n");
		printf("\nTesting ft_write with invalid file descriptor:\n");
		bytes_written = ft_write(-1, message, strlen(message));
		printf("ASM ft_write with invalid fd returned %zd\n", bytes_written);
		if (bytes_written == -1)
			printf("ASM ft_write correctly handled invalid file descriptor!\n");
		else
			printf("ASM ft_write did not handle invalid file descriptor correctly!\n");
		printf("\nTesting ft_write with zero bytes:\n");
		bytes_written = ft_write(1, message, 0);
		printf("ASM ft_write with zero bytes returned %zd\n", bytes_written);
		if (bytes_written == 0)
			printf("ASM ft_write correctly handled zero byte write!\n");
		else
			printf("ASM ft_write did not handle zero byte write correctly!\n");
		printf("\nTesting ft_write with NULL buffer:\n");
		bytes_written = ft_write(1, NULL, 10);
		printf("ASM ft_write with NULL buffer returned %zd\n", bytes_written);
		if (bytes_written == -1)
			printf("ASM ft_write correctly handled NULL buffer!\n");
		else
			printf("ASM ft_write did not handle NULL buffer correctly!\n");
	}


	printf("\nTesting ft_read:\n");

	{
		char test_file[] = "Makefile";
		printf("Testing ft_read by reading from a file:\n");
		int fd = open(test_file, O_RDONLY);
		if (fd == -1)	{
			perror("Failed to open test.txt");
		} else {
			char buffer[100];
			ssize_t bytes_read = ft_read(fd, buffer, sizeof(buffer) - 1);
			if (bytes_read == -1) {
				perror("ASM ft_read failed");
			} else {
				buffer[bytes_read] = '\0';
				printf("ASM ft_read read %zd bytes: %s\n", bytes_read, buffer);
				printf("ASM ft_read is correct!\n");
			}
			close(fd);
		}
		printf("\nTesting ft_read with invalid file descriptor:\n");
		char buffer[100];
		ssize_t bytes_read = ft_read(-1, buffer, sizeof(buffer));
		printf("ASM ft_read with invalid fd returned %zd\n", bytes_read);
		if (bytes_read == -1)
			printf("ASM ft_read correctly handled invalid file descriptor!\n");
		else
			printf("ASM ft_read did not handle invalid file descriptor correctly!\n");
		printf("\nTesting ft_read with zero bytes:\n");
		fd = open(test_file, O_RDONLY);
		if (fd == -1)	{
			perror("Failed to open test.txt");
		} else {
			bytes_read = ft_read(fd, buffer, 0);
			printf("ASM ft_read with zero bytes returned %zd\n", bytes_read);
			if (bytes_read == 0)
				printf("ASM ft_read correctly handled zero byte read!\n");
			else
				printf("ASM ft_read did not handle zero byte read correctly!\n");
			close(fd);
		}
		printf("\nTesting ft_read with NULL buffer:\n");
		fd = open(test_file, O_RDONLY);
		if (fd == -1)	{
			perror("Failed to open test.txt");
		} else {
			bytes_read = ft_read(fd, NULL, 10);
			printf("ASM ft_read with NULL buffer returned %zd\n", bytes_read);
			if (bytes_read == -1)
				printf("ASM ft_read correctly handled NULL buffer!\n");
			else
				printf("ASM ft_read did not handle NULL buffer correctly!\n");
			close(fd);
		}
	}


	printf("\nTesting ft_strdup:\n");
	{
		printf("Testing ft_strdup with 'Hello World':\n");
		char src[] = "Hello World";
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
		printf("\nTesting ft_strdup with long string:\n");
		char long_src[] = "This is a very long string to test ft_strdup function.";
		char *dup_long = ft_strdup(long_src);
		printf("ASM strdup of long string: %s\n", dup_long);
		if (strcmp(dup_long, long_src) == 0)
			printf("ASM strdup is correct for long string!\n");
		else
			printf("ASM strdup is incorrect for long string!\n");
		free(dup);
		free(dup_empty);
		free(dup_long);
	}
	printf("\nAll tests completed.\n");
	return 0;
}
