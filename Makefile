NAME = libasm.a

SRCC =  libasm/ft_strlen.s

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

clean :
	rm -f $(SRCO)

.PHONY: all re fclean clean