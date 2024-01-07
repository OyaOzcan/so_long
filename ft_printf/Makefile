SRCS			= ft_printf.c ft_printf_funcs.c

OBJS = $(SRCS:.c=.o)

CC = gcc
RM = rm -f
FLAGS = -Wall -Wextra -Werror
NAME = libftprintf.a
AR = ar -rcs

all : $(NAME)

$(NAME) :
		$(CC) $(FLAGS) -c $(SRCS)
		$(AR) $(NAME) $(OBJS)

clean :
	$(RM) $(OBJS)

fclean : clean
	$(RM) $(NAME)

re : fclean $(NAME)

.PHONY : all clean fclean re
