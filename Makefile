CC = gcc

CFLAGS = -Wall -Werror -Wextra

HEADER = minitalk.h

SRV = server.c

CLN = client.c

NAME_SRV = server

NAME_CLN = client

all: $(NAME_SRV) $(NAME_CLN)

$(NAME_SRV): $(SRV) $(HEADER)
	$(CC) $(CFLAGS) $< -o $@
  
$(NAME_CLN): $(CLN) $(HEADER)
  $(CC) $(CFLAGS) $< -o $@
  
clean:
  rm -rf $(NAME_SRV) $(NAME_CLN)
  
fclean: clean
 
re: fclean all
 
.PHONY: all re fclean clean
