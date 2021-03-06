NAME	=	libasm.a

TESTER	=	test

NASM	=	nasm -felf64

FILES	=	ft_strlen.s \
			ft_strcpy.s \
			ft_strcmp.s \
			ft_write.s \
			ft_read.s \
			ft_strdup.s \

BONUS_FILES	=	ft_list_size_bonus.s \
				ft_list_push_front_bonus.s \

OBJ_NAME = $(FILES:.s=.o)
OBJ_BONUS_NAME = $(BONUS_FILES:.s=.o)
OBJ_DIR	 = obj/

ifdef WITH_BONUS
OBJS = $(addprefix $(OBJ_DIR),$(OBJ_NAME)) $(addprefix $(OBJ_DIR),$(OBJ_BONUS_NAME))
MAIN = main_bonus.c
else
OBJS = $(addprefix $(OBJ_DIR),$(OBJ_NAME))
MAIN = main.c
endif

all: $(NAME)

$(NAME): $(OBJS)
	ar rsc $@ $(OBJS)
	ranlib $@

$(OBJ_DIR)%.o: %.s
	mkdir -p $(OBJ_DIR)
	$(NASM) -o $@ $<
	echo "$(_CYAN)\r\33[2K\rCompling $@$(_END)"

bonus:
	$(MAKE) WITH_BONUS=1 all

test: all
	gcc $(MAIN) -I. -L. -lasm -o $(TESTER)
	printf "$(_GREEN)\r\33[2K\r$(TESTER) created 😎\n$(_END)"
#	./$(TESTER)

btest:
	$(MAKE) WITH_BONUS=1 $(TESTER)

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)
	rm -f $(TESTER)
	echo "$(_RED)$(NAME) Deleted  😱$(_END)"

re: fclean all

############
#  COLORS  #
############

_GREEN=$ \033[32m
_RED=$ \033[31m
_YELLOW=$ \033[33m
_BLUE=$ \033[34m
_CYAN=$ \033[36m

.SILENT:
