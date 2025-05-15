NAME = cub3D
CC = cc
#DFLAGS = -Wall -Werror -Wextra -fsanitize=address
CFLAGS = -g -Lminilibx-linux -lmlx -lX11 -lXext -lm

P_SRCS = ${wildcard execution/exec/*.c execution/basic/*.c execution/utils/*.c}\


SRCS = $(P_SRCS)
OBJS = $(SRCS:.c=.o)


all: $(NAME)

$(NAME): $(OBJS)

%.o: %.c
	$(CC) -c $<  $(CFLAGS) -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all