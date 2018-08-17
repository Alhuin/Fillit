# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: jjanin-r <jjanin-r@student.le-101.fr>      +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2017/11/07 14:07:48 by jmonneri     #+#   ##    ##    #+#        #
#    Updated: 2017/11/27 22:42:58 by jmonneri    ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #
.PHONY: all clean fclean re

CC = gcc
CC_FLAGS = -Wall -Wextra -Werror

#******************************************************************************#
#                                    LIBFT                                     #
#******************************************************************************#
NAME_LIBFT = libft.a
PATH_SRC_LIBFT = ./Libft/
PATH_OBJ_LIBFT = ./Libft/
PATH_INC_LIBFT = ./Libft/
FILES_LIBFT = ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c ft_memmove.c\
		ft_memcmp.c ft_memchr.c ft_strncat.c ft_strlcat.c ft_strcat.c\
		ft_strncpy.c ft_strcpy.c ft_strdup.c ft_strlen.c ft_putchar.c\
		ft_putstr.c ft_putnbr.c ft_strchr.c ft_strrchr.c ft_strstr.c\
		ft_strnstr.c ft_strcmp.c ft_strncmp.c ft_atoi.c ft_isalpha.c\
		ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_toupper.c\
		ft_tolower.c ft_memalloc.c ft_memdel.c ft_strnew.c ft_strdel.c\
		ft_strclr.c ft_striter.c ft_striteri.c ft_strmap.c ft_strmapi.c\
		ft_strequ.c ft_strnequ.c ft_strsub.c ft_strjoin.c ft_strtrim.c\
		ft_strsplit.c ft_itoa.c ft_putendl.c ft_putchar_fd.c ft_putstr_fd.c\
		ft_putendl_fd.c ft_putnbr_fd.c ft_lstnew.c ft_lstdelone.c ft_lstdel.c\
		ft_lstadd.c ft_lstiter.c ft_lstmap.c ft_intlen.c ft_print_strlst.c\
		ft_putstr2d.c ft_freestr2d.c
OBJ_LIBFT = $(addprefix $(PATH_OBJ_LIBFT), $(FILES_LIBFT:.c=.o))
SRC_LIBFT = $(addprefix $(PATH_SRC_LIBFT), $(FILES_LIBFT))
INC_LIBFT = $(addprefix $(PATH_INC_LIBFT), libft.h)

#******************************************************************************#
#                                   FILLIT                                     #
#******************************************************************************#

NAME = fillit
PATH_SRC_FILLIT = ./Filit/
PATH_OBJ_FILLIT = ./Filit/
PATH_INC_FILLIT = ./Filit/
FILES_FILLIT = ft_util.c ft_solve.c ft_get_coord.c ft_read.c ft_test.c main.c
OBJ_FILLIT = $(addprefix $(PATH_OBJ_FILLIT), $(FILES_FILLIT:.c=.o))
SRC_FILLIT = $(addprefix $(PATH_SRC_FILLIT), $(FILES_FILLIT))
INC_FILLIT = $(addprefix $(PATH_INC_FILLIT), fillit.h)

#******************************************************************************#
#                                    ALL                                       #
#******************************************************************************#

all: $(NAME)

#******************************************************************************#
#                             Compilation FILLIT                               #
#******************************************************************************#

$(NAME): $(NAME_LIBFT) $(OBJ_FILLIT) $(INC_FILLIT)
	@echo "\n\033[1m🦄 🦄 🦄 🦄 CREATION DE FILLIT🦄 🦄 🦄 🦄\033[0m\n"
	@$(CC) $(CC_FLAGS) $(OBJ_FILLIT) -L ./ -l ft -o $(NAME)
	@echo "   👍  👍  👍 \033[1mFILLIT CREE\033[0m👍  👍  👍"

$(PATH_OBJ_FILLIT)%.o: $(PATH_SRC_FILLIT)%.c
	@echo "0️⃣  Compilation de \033[1m$<\033[0m en \033[1m$@\033[0m"
	@$(CC) $(CC_FLAGS) -o $@ -c $< -I $(PATH_INC_FILLIT)
	@echo "  \033[0;32mCOMPILATION REUSSIE\033[0m\n"

#******************************************************************************#
#                             Compilation LIBFT                                #
#******************************************************************************#

$(NAME_LIBFT): $(OBJ_LIBFT) $(INC_LIBFT)
	@echo "\n\033[1m🦄 🦄 🦄 🦄 CREATION DE LA LIBFT🦄 🦄 🦄 🦄\033[0m\n"
	@ar rcs $(NAME_LIBFT) $(OBJ_LIBFT)
	@echo "  👍  👍  👍 \033[1mLIBRAIRIE CREEE\033[0m👍  👍  👍\n"

$(PATH_OBJ_LIBFT)%.o: $(PATH_SRC_LIBFT)%.c
	@echo "0️⃣  Compilation de \033[1m$<\033[0m en \033[1m$@\033[0m"
	@$(CC) $(CC_FLAGS) -o $@ -c $< -I $(PATH_INC_LIBFT)
	@echo "   \033[0;32mCOMPILATION REUSSIE\033[0m\n"

#******************************************************************************#
#                                   OTHER                                      #
#******************************************************************************#

clean:
	@echo "\n\033[1m🦄 🦄 🦄 🦄 SUPPRESSION DES OBJETS🦄 🦄 🦄 🦄\033[0m\n"
	@rm -f $(OBJ_LIBFT) $(OBJ_FILLIT)

fclean: clean
	@echo "\n\033[1m🦄 🦄 🦄 🦄 SUPPRESSION DE $(NAME_LIBFT) ET $(NAME)🦄 🦄 🦄 🦄\033[0m\n"
	@rm -f $(NAME_LIBFT) $(NAME)

re: fclean all

exe: all
	@time ./fillit test.txt

exec: exe fclean
