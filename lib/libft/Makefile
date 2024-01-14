SRCS = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c \
			ft_isprint.c ft_strlen.c ft_memset.c ft_bzero.c \
			ft_memcpy.c ft_toupper.c ft_tolower.c ft_memmove.c \
			ft_strlcpy.c ft_strlcat.c ft_strchr.c ft_strrchr.c \
			ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c \
			ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c \
			ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c \
			ft_strmapi.c ft_striteri.c ft_putchar_fd.c \
			ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c\
			ft_printf.c ft_aux_pf.c ft_format_pf.c\
			ft_putchar_pf.c ft_putdec_pf.c ft_puthex_pf.c\
			ft_putnbr_pf.c ft_putptr_pf.c ft_putstr_pf.c\
			ft_putend_fd.c ft_lstnew.c ft_lstlast.c\
			ft_lstadd_back.c ft_lstsize.c

OBJS			= $(SRCS:.c=.o)

CC				= gcc
RM				= rm -f
CFLAGS			= -Wall -Wextra -Werror -I.

NAME			= libft.a

out = *.out

all:			$(NAME)

$(NAME):		$(OBJS)
				ar rcs $(NAME) $(OBJS)

clean:
				$(RM) $(OBJS) $(BONUS_OBJS)

fclean:			clean
				$(RM) $(NAME)

re:				fclean $(NAME)

f.out:			
					$(RM) $(out)

.PHONY:			all clean fclean re bonus
