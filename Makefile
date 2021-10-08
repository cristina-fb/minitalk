# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: crisfern <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/08 11:32:40 by crisfern          #+#    #+#              #
#    Updated: 2021/10/08 12:14:08 by crisfern         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

CFLAGS = -Wall -Werror -Wextra

HEADER = minitalk.h

SRV = server.c

CLN = client.c

NAME_SRV = server

NAME_CLN = client

all: $(NAME_SRV) $(NAME_CLN)

$(NAME_SRV): $(SRV) $(HEADER)
	@$(CC) $(CFLAGS) $< -o $@
  
$(NAME_CLN): $(CLN) $(HEADER)
	@$(CC) $(CFLAGS) $< -o $@
  
clean:
	@rm -rf $(NAME_SRV) $(NAME_CLN)
  
fclean: clean
 
re: fclean all

norm:
	@norminette

.PHONY: all re fclean clean norm
