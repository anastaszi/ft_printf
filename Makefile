.PHONY: clean fclean re all

NAME = libftprintf.a
LIBFILENAME = ft_abc.c ft_atoi.c ft_bzero.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c \
ft_itoa.c ft_lstadd.c ft_lstdelone.c ft_lsttotaldel.c ft_lstlastelem.c ft_lstdel.c \
ft_lstindex.c ft_lstiter.c ft_lstlen.c ft_lstmap.c ft_lstnew.c ft_lstprint.c ft_lstpush_back.c \
ft_lstpush_head.c ft_memalloc.c ft_memccpy.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_lstevenelem.c ft_memdel.c \
ft_memmove.c ft_memset.c ft_putchar.c ft_putchar_fd.c ft_stradd.c ft_putendl.c ft_putendl_fd.c ft_putnbr.c \
ft_putnbr_fd.c ft_putstr.c ft_putstr_fd.c ft_strcat.c ft_straddfirst.c ft_straddchar.c ft_strchr.c ft_strclr.c ft_strcmp.c \
ft_strcpy.c ft_strsplit.c ft_strdel.c ft_strdup.c ft_strequ.c ft_strjoin.c ft_strnequ.c ft_striter.c \
ft_striteri.c ft_strlcat.c ft_strlen.c ft_strmap.c ft_strmapi.c ft_strnewset.c ft_strncat.c ft_strncmp.c ft_strncpy.c \
ft_strnew.c ft_strnstr.c ft_strdelpart.c ft_strreverse.c ft_strrchr.c ft_strstr.c ft_strsub.c ft_strtrim.c ft_tolower.c ft_toupper.c \
ft_chararraylen.c ft_lst_tostring.c ft_del.c ft_lstdelelemfromlst.c ft_topower.c ft_topowerdouble.c ft_strnadd.c
PRINTFILENAME =   ft_printf.c help_argum.c help_bytes.c help_colors.c help_fill.c help_fill_2.c help_floats.c help_floats_2.c \
help_functions.c help_itoa.c help_posix.c help_read.c help_string.c help_wchar.c
LIBSRCSFLDR = ./src_libft/
PRINTSRCSFLDR = ./src_printf/
OBJLFLDR = ./obj/
OBJPFLDR = ./obj/
HEADERFLDR = ./includes/
LIBSRCS = $(basename $(FILENAME))
PRINTSRCS = $(basename $(PRINTFILENAME))
LIBOBJCS = $(addprefix $(OBJLFLDR),$(LIBFILENAME:.c=.o))
PRINTOBJCS = $(addprefix $(OBJPFLDR),$(PRINTFILENAME:.c=.o))
FLAGS = -Wall -Wextra -Werror

all: $(NAME)

obj:
	@mkdir -p $(OBJLFLDR)
	@mkdir -p $(OBJPFLDR)

$(NAME): obj $(LIBOBJCS) $(HEADERFLDR)libft.h $(PRINTOBJCS) $(HEADERFLDR)ft_printf.h
	@ar rc $(NAME) $(LIBOBJCS) $(PRINTOBJCS)
	@ranlib $(NAME)

$(OBJLFLDR)%.o:$(LIBSRCSFLDR)%.c
	@gcc $(FLAGS) -I $(HEADERFLDR) -o $@ -c $<

$(OBJPFLDR)%.o:$(PRINTSRCSFLDR)%.c
	@gcc $(FLAGS) -I $(HEADERFLDR) -o $@ -c $<

$(LIBSRCS):%:$(OBJLFLDR)%.o obj
$(PRINTSRCSFLDR):%:$(OBJPFLDR)%.o obj
clean:
	@/bin/rm -rf $(OBJFLDR)
	@/bin/rm -rf $(OBJPFLDR)

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all



