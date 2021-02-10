NAME = bsq
CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRCs = ${wildcard ./srcs/*.c}

all:		$(NAME)

$(NAME):
			$(CC) $(CFLAGS) -o $(NAME) $(SRC)
clean:
			/bin/rm -f *.o

fclean: 	clean
			/bin/rm -f $(NAME)

re: 		fclean all

.PHONY:		all ${NAME} clear fclean re
