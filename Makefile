NAME = libasm.a

SRCC =  libasm/ft_strlen.s \
		libasm/ft_strcpy.s \
		libasm/ft_strcmp.s \
		libasm/ft_write.s \
		libasm/ft_read.s \
# 		libasm/ft_strdup.s

SRCO = $(SRCC:.s=.o)

CFLAGS = -f elf64

all : $(SRCC) $(NAME)

%.o : %.s
	nasm $(CFLAGS) $< -o ${<:.s=.o}

$(NAME) : $(SRCO)
	ar rcs $(NAME) $(SRCO)

re : fclean $(NAME)

fclean : clean
	rm -f $(NAME)
	rm -f test

clean :
	rm -f $(SRCO)

test: all
	gcc -Wall -Wextra -no-pie -g libasm/main.c -L. -lasm -o test

.PHONY: all re fclean clean test