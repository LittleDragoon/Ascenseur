

NAME = elevator

SRCS = test_main.c person.c elevator.c
#	main.c

# variable 
OBJS = ${SRCS:.c=.o}
 
# compile les -o
$(NAME) : ${OBJS}
		gcc -o $@  ${OBJS} -lncurses

#Transforme les .c en .o
%.o : %.c %.h
	gcc -c $<

all: $(NAME)

clean:
	rm -f  ${OBJS}

fclean: clean
	rm -f $(NAME)

re	: fclean all

	