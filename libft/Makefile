# Project name
NAME = libft.a

# Source files
SRCS = ft_isdigit.c ft_strlen.c ft_strncmp.c ft_putendl_fd.c

# Object files
OBJS = $(SRCS:.c=.o)

# Compiler settings
CC = cc
CFLAGS = -Wall -Wextra -Werror

# Build rules
$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)

.PHONY: all clean fclean re

all: $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

