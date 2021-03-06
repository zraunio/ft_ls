NAME = libft.a

PRINTF = libftprintf.a

CC = gcc

CFLAGS = -Wall -Wextra -Werror -g -I$(HDR_SRC)

# ASCII_DIR = ./ascii/ 
# CONV_DIR = ./convert/
# LIST_DIR = ./list/
# MATH_DIR = ./math/
# MEM_DIR = ./mem/
# PRINT_DIR = ./print/
# PRINTF_DIR = ./ft_printf/
# STR_DIR = ./src/
# BIT_DIR = ./bits

# ASCII = $(addprefix $(ASCII_DIR), $(_ASCII_SRC)) 
# CONV = $(addprefix $(CONV_DIR), $(_CONV_SRC))
# LIST = $(addprefix $(LIST_DIR), $(_LIST_SRC)) 
# MATH = $(addprefix $(MATH_DIR, $(_MATH_SRC))
# MEM = $(addprefix $(MEM_DIR, $(_MEM_SRC))
# PRINT = $(addprefix $(PRINT_DIR), $(_PRINT_SRC)) 
# STR = $(addprefix $(STR_DIR), $(_STR_SRC))

_ASCII_SRC =  ascii/ft_isalnum.c \
		ascii/ft_isalpha.c \
		ascii/ft_isascii.c \
		ascii/ft_isprint.c \
		ascii/ft_ispunct.c \
		ascii/ft_isdigit.c \
		ascii/ft_isspace.c \

_CONV_SRC = convert/ft_atoi.c \
		convert/ft_itoa_base.c \
		convert/ft_itoa.c \
		convert/ft_lutoa_base.c \
		convert/ft_lutoa.c \
		convert/ft_tolower.c \
		convert/ft_toupper.c \
		convert/ft_utoa_base.c \
		convert/ft_utoa.c \
		convert/ft_atof.c \
		convert/ft_litoa.c \
		convert/ft_ftoa.c \
		convert/ft_sizetoa.c \

_LIST_SRC = list/ft_lstadd.c \
		list/ft_lstdel.c \
		list/ft_lstdelone.c \
		list/ft_lstiter.c \
		list/ft_lstmap.c \
		list/ft_lstnew.c \

_MATH_SRC = math/dig_count_base.c \
		math/dig_count.c \
		math/ft_abs.c \
		math/ft_float_abs.c \
		math/ft_double_abs.c \
		math/ft_wdcounter.c \
		math/ft_strstr_start.c \
		math/ft_long_abs.c \

_MEM_SRC = mem/ft_bzero.c \
		mem/ft_memalloc.c \
		mem/ft_memccpy.c \
		mem/ft_memchr.c \
		mem/ft_memcmp.c \
		mem/ft_memcpy.c \
		mem/ft_memdel.c \
		mem/ft_memmove.c \
		mem/ft_memset.c \
		mem/ft_realloc.c \
		mem/ft_arrfree.c \

_PRINT_SRC = print/ft_putchar_fd.c \
		print/ft_putchar.c \
		print/ft_putendl_fd.c \
		print/ft_putendl.c \
		print/ft_putnbr_fd.c \
		print/ft_putnbr.c \
		print/ft_putstr_fd.c \
		print/ft_putstr.c \
		print/get_next_line.c \
		print/ft_putlong.c \
		print/ft_putdouble.c \
		print/ft_putshort.c \
		print/ft_print_bits.c \

_BIT_SRC = bits/ft_oradd_bit.c \
		bits/ft_orfill_bit.c

_STR_SRC = str/ft_strcat.c \
		str/ft_strchr.c \
		str/ft_strclr.c \
		str/ft_strcmp.c \
		str/ft_strcpy.c \
		str/ft_strctrim.c \
		str/ft_strdel.c \
		str/ft_strdup.c \
		str/ft_strequ.c \
		str/ft_striter.c \
		str/ft_striteri.c \
		str/ft_strjoin.c \
		str/ft_strjoin_free.c \
		str/ft_strlcat.c \
		str/ft_strlen.c \
		str/ft_strmap.c \
		str/ft_strmapi.c \
		str/ft_strncat.c \
		str/ft_strmapi.c \
		str/ft_strncat.c \
		str/ft_strncmp.c \
		str/ft_strnequ.c \
		str/ft_strnew.c \
		str/ft_strcnew.c \
		str/ft_strnstr.c \
		str/ft_strnstr.c \
		str/ft_strrchr.c \
		str/ft_strsplit.c \
		str/ft_strstr.c \
		str/ft_strsub.c \
		str/ft_strtrim.c \
		str/ft_strtrim_top.c \
		str/ft_strtrim_end.c

_TREE_SRC = trees/ft_add_node.c \
		trees/ft_new_node.c \
		trees/ft_tree_hight.c

_PRINTF_SRC = ft_printf/ft_printf.c \
		ft_printf/print_split.c \
		ft_printf/convert.c \
		ft_printf/parse.c\
		ft_printf/floats.c \
		ft_printf/diu.c \
		ft_printf/oxx.c \
		ft_printf/print_oxx.c \
		ft_printf/spc.c 


PRINTF_OBJ = $(_PRINTF_SRC:.c=.o)
OBJ = $(LIBFT_OBJ) $(PRINTF_OBJ)
OBJ_DIR = obj
LIBFT_SRCS = $(_STR_SRC) $(_PRINT_SRC) $(_MEM_SRC) $(_MATH_SRC) $(_LIST_SRC) $(_CONV_SRC) $(_ASCII_SRC) $(_TREE_SRC) $(_BIT_SRC)
LIBFT_OBJ = $(_ASCII_SRC:.c=.o) $(_CONV_SRC:.c=.o) $(_LIST_SRC:.c=.o) $(_MATH_SRC:.c=.o) $(_MEM_SRC:.c=.o) $(_PRINT_SRC:.c=.o) $(_STR_SRC:.c=.o) $(_BIT_SRC:.c=.o) $(_TREE_SRC:.c=.o)

HDR_SRC= ./incl

all: $(NAME)

$(NAME): $(OBJ_DIR) $(OBJ)
	@echo "creating some stuff..."
	@ $(CC) $(CFLAGS) -c $(LIBFT_SRCS) $(_PRINTF_SRC)
	@mv *.o $(OBJ_DIR)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

clean:
	@rm -f $(OBJS)
	@rm -f $(LIBFT_OBJ)
	@find . -type f -name '*.o' -print -delete -o -name '#*#' -print -delete
	@find . -type f -name '*~' -print -delete -o -name '#*#' -print -delete
	@find . -type f -name '.DS_Store' -print -delete
	@echo "deleted some stuff"

fclean: clean
	@rm -f $(NAME)
	@rm -rf $(OBJ_DIR)
	@echo "deleted rest of the stuff"

re: fclean all

.PHONY: all clean fclean re
