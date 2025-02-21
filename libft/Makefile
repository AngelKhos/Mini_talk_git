NAME=libft.a
CC=cc
AR=ar 
AR_ARG=-rcs
CC_FLAGS=-Wall -Wextra -Werror
SRCS=ft_atoi.c\
	ft_isalpha.c\
	ft_strmapi.c\
	ft_putnbr_fd.c\
	ft_putendl_fd.c\
	ft_putstr_fd.c\
	ft_putchar_fd.c\
	ft_striteri.c\
	ft_strtrim.c\
	ft_substr.c\
	ft_itoa.c\
	ft_strlcat.c\
	ft_strdup.c\
	ft_calloc.c\
	ft_strnstr.c\
	ft_memcmp.c\
	ft_memchr.c\
	ft_strncmp.c\
	ft_strchr.c\
	ft_strrchr.c\
	ft_isprint.c\
	ft_memset.c\
	ft_strlcpy.c\
	ft_toupper.c\
	ft_bzero.c\
	ft_isascii.c\
	ft_memcpy.c\
	ft_split.c\
	ft_strlen.c\
	ft_isalnum.c\
	ft_isdigit.c\
	ft_memmove.c\
	ft_strjoin.c\
	ft_tolower.c\
	ft_lstnew_bonus.c\
	ft_lstadd_front_bonus.c\
	ft_lstsize_bonus.c\
	ft_lstlast_bonus.c\
	ft_lstadd_back_bonus.c\
	ft_lstdelone_bonus.c\
	ft_lstclear_bonus.c\
	ft_lstiter_bonus.c\
	ft_lstmap_bonus.c\
	ft_printf.c\
	ft_printhexa.c\
	ft_printnbr.c\
	ft_printstr.c\
	ft_utils.c\
	get_next_line.c\
	get_next_line_utils.c
OBJS=$(SRCS:.c=.o)
DEPS=$(SRCS:.c=.d)

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(AR_ARG) $@ $(OBJS)
	
-include $(DEPS)
%.o: %.c
	$(CC) $(CC_FLAGS) -c -o $@ $< -MMD

clean:
	rm -f *.o
	rm -f *.d

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
.SILENT: