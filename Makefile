NAME = cub3D
CC = cc
DFLAGS = -Wall -Werror -Wextra -g
CFLAGS = -Lminilibx-linux -lmlx -lX11 -lXext -lm

P_SRCS = main.c \
		${wildcard parsing/*.c} \
		${wildcard execution/exec/*.c execution/basic/*.c execution/utils/*.c}\


SRCS = $(P_SRCS) $(O_SRCS)
OBJS = $(SRCS:.c=.o)


all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC)  $(OBJS) $(CFLAGS) -o $(NAME)



%.o: %.c
	$(CC) $(DFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all