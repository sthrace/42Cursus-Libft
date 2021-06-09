NAME	= libft.a

SRCS	= ./ft_atoi.c \
		./ft_atol.c \
		./ft_bzero.c \
		./ft_calloc.c \
		./ft_isalnum.c \
		./ft_isalpha.c \
		./ft_isascii.c \
		./ft_isdigit.c \
		./ft_isprint.c \
		./ft_memchr.c \
		./ft_memcmp.c \
		./ft_memcpy.c \
		./ft_memccpy.c \
		./ft_memmove.c \
		./ft_memset.c \
		./ft_strchr.c \
		./ft_strdup.c \
		./ft_strlcat.c \
		./ft_strlcpy.c \
		./ft_strlen.c \
		./ft_strncmp.c \
		./ft_strnstr.c \
		./ft_strrchr.c \
		./ft_tolower.c \
		./ft_toupper.c \
		./ft_substr.c \
		./ft_strjoin.c \
		./ft_strtrim.c \
		./ft_split.c \
		./ft_itoa.c \
		./ft_strmapi.c \
		./ft_putchar_fd.c \
		./ft_putstr_fd.c \
		./ft_putendl_fd.c \
		./ft_putnbr_fd.c \
		./ft_charjoin.c \
		./ft_gnl.c \
		./ft_itoa_base.c \
		./ft_nbrlen_base.c \
		./ft_putnbr_base_fd.c \
		./ft_realloc.c \
		./ft_strncmpul.c \
		./ft_lstnew.c \
		./ft_lstadd_front.c \
		./ft_lstsize.c \
		./ft_lstlast.c \
		./ft_lstadd_back.c \
		./ft_lstdelone.c \
		./ft_lstclear.c \
		./ft_lstiter.c \
		./ft_lstmap.c \

OBJS =		$(SRCS:.c=.o)
HEADER = libft.h

CC = clang
CFLAGS	= -g3 -Wall -Wextra -Werror

all: 		$(NAME)

$(NAME): 	COMP $(OBJS) DONE
			ar rc $(NAME) ${OBJS}

.c.o:
			$(CC) -c $(CFLAGS) -o $@ $<
			printf "$(WHITE)██"

clean:		CLEAN
			rm -f ${OBJS}}

fclean: 	clean FCLEAN
			rm -f $(NAME)

leaks:		
			valgrind --show-leak-kinds=definite --leak-check=full ./$(NAME)

git:
			make fclean
			@git add *
			@git commit -m "commit"
			@git push

re: 		fclean all

.PHONY: 	all clean fclean re leaks git
.SILENT:

RED = \033[1;31m
GREEN = \033[1;32m
YELLOW = \033[1;33m
CYAN = \033[1;36m
WHITE = \033[1;37m
DEFAULT = \033[0m

COMP:
	echo "\n$(WHITE) COMPILING LIBFT$(DEFAULT)"
DONE:
	echo "\n$(WHITE) COMPILED LIBFT$(DEFAULT)"
CLEAN :
	echo "$(YELLOW) REMOVING LIBFT OBJECT FILES $(DEFAULT)"
FCLEAN :
	echo "$(RED) REMOVING LIBFT LIBRARY $(DEFAULT)"
