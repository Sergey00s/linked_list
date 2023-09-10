NAME=liblist.a
CFLAGS=-Wall -Wextra -Werror
CC=clang
SRC= llist_create.c llist_operations.c  llist_remove.c  llist_sizer.c
OBJ= $(SRC:.c=.o)
INC= .
RM= rm -f

all: $(NAME)


$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ) 

%.o: %.c
	$(CC) $(CFLAGS) -I$(INC) -c $< -o $@

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all