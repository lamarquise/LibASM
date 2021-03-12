

NAME	=	libasm.a

NASM	=	nasm -felf64
LD		=	ld -o $(NAME)

FILES	=	ft_strlen.s \
			ft_strcpy.s \
			ft_strcmp.s \
			ft_write.s \
			ft_read.s \
			ft_strdup.s \
			hello_world.s \
			ft_list_size_bonus.s \

MAIN	=	main.c \


OBJ_NAME = $(FILES:.s=.o)
OBJ_DIR	 = obj/
OBJS = $(addprefix $(OBJ_DIR),$(OBJ_NAME))



all: $(NAME)

$(NAME): $(OBJS)
	ar rsc $@ $(OBJS)
	ranlib $@

$(OBJ_DIR)%.o: %.s
	mkdir -p $(OBJ_DIR)
	$(NASM) -o $@ $<
	printf "$(_CYAN)\r\33[2K\rCompling $@$(_END)"


test: all
	gcc main.c -L. -lasm -o test
#	./test

# Temporarily
bonus: all


#$(NAME): $(OBJS) $(MAIN)
#	gcc $(OBJS) $(MAIN) -o test
#	printf "$(_GREEN)\r\33[2K\r$(NAME) created 😎\n$(_END)"

#$(OBJ_DIR)%.o: %.s
#	mkdir -p $(OBJ_DIR)
#	$(NASM) -o $@ $<
#	printf "$(_CYAN)\r\33[2K\rCompling $@$(_END)"

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)
	echo "$(_RED)$(NAME) Deleted  😱$(_END)"

re: fclean all


############
#  COLORS  #
############


_GREEN=$ \033[32m
_RED=$ \033[31m
_YELLOW=$ \033[33m
_BLUE=$ \033[34m


.SILENT:
