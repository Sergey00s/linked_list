NAME = output
CC = gcc
src = main.c



all: $(NAME)


$(NAME): $(src)
	$(CC) $(src) -o $(NAME) -I../ ../liblist.a

clean:
	rm -f $(NAME)