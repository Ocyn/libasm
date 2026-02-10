NAME = libasm.a

SRCC =  helloworld.s

SRCO = $(SRCC:.c=.o)

CFLAGS = 

all : $(SRCC) $(NAME)

%.o : %.s
	nasm $(CFLAGS) -c $< -o ${<:.c=.o}

$(NAME) : $(SRCO)
	ar crs $(NAME) $(SRCO)

re : fclean $(NAME)

fclean : clean
	rm -f $(NAME)

clean :
	rm -f $(SRCO)

.PHONY: all re fclean clean