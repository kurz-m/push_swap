NAME := push_swap
NAME_BONUS := checker
.DEFAULT_GOAL := all

#############################################################################
#############################################################################
#############################################################################

CC := gcc
CFLAGS ?= -Wextra -Wall -Werror -MMD -MP -g3
CFLAGS += -Wno-unused-function
LIBFT := ./lib/Libft
HEADERS := -I./include -I$(LIBFT)/header
LIBFT_NAME := $(LIBFT)/lib/libft.a

#############################################################################
#############################################################################
#############################################################################

VPATH := src src/utils src/parse src/sort src/box
SRC = push_swap.c
SRC_BOX := init.c insert.c new_node.c pop.c print.c rotate.c swap.c
SRC_PARSE := parse_input.c
SRC_SORT := sort.c sort_big.c sort_utils.c
SRC_UTILS := utils.c movements.c error_handling.c
SRCS := $(SRC) $(SRC_BOX) $(SRC_PARSE) $(SRC_SORT) $(SRC_UTILS)

SRC_CHECKER :=
SRCS_BONUS := $(SRC_BOX) $(SRC_PARSE) $(SRC_UTILS) $(SRC_CHECKER)

#############################################################################
#############################################################################
#############################################################################

OBJ_DIR := ./_obj
OBJS := $(addprefix $(OBJ_DIR)/, $(SRCS:%.c=%.o))
OBJS_BONUS := $(addprefix $(OBJ_DIR)/, $(SRCS_BONUS:%.c=%.o))

#############################################################################
#############################################################################
#############################################################################

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT_NAME)
	@echo $(Y)Compiling [$(NAME)]...$(X)
	@printf $(UP)$(CUT)
	@$(CC) $(OBJS) $(LIBFT_NAME) -o $(NAME)
	@echo $(G)Finished"  "[$(NAME)]...$(X)

$(OBJ_DIR)/%.o: %.c
	@echo $(Y)Compiling [$@]...$(X)
	@mkdir -p _obj
	@$(CC) $(CFLAGS) -c $< $(HEADERS) -o $@
	@printf $(UP)$(CUT)

$(LIBFT_NAME):
	$(MAKE) -C $(LIBFT)

bonus: $(NAME_BONUS)

$(NAME_BONUS): $(OBJS_BONUS) $(LIBFT_NAME)
	@echo $(Y)Compiling [$(NAME_BONUS)]...$(X)
	@printf $(UP)$(CUT)
	@$(CC) $(OBJS_BONUS) $(LIBFT_NAME) -o $(NAME_BONUS)
	@echo $(G)Finished"  "[$(NAME_BONUS)]...$(X)

#############################################################################
#############################################################################
#############################################################################

clean:
	@$(MAKE) -C ./lib/Libft/ clean
	@printf $(UP)$(CUT)
	@if [ -d "${OBJ_DIR}" ]; then \
		echo $(R)Cleaning"  "[$(OBJ_DIR)]...$(X); \
		rm -rf ${OBJ_DIR}; \
		echo $(G)Cleaned!$(X); \
	fi

#############################################################################
#############################################################################
#############################################################################

fclean: clean
	@echo $(R)Cleaning executables...
	@make -C ./lib/Libft/ fclean
	@printf $(UP)$(CUT)
	@if [ -f "$(NAME)" ]; then \
		echo $(R)Cleaning"  "[$(NAME)]...$(X); \
		rm -f $(NAME); \
		echo $(G)Cleaned!$(X); \
	fi

re: fclean all
#############################################################################
#############################################################################
#############################################################################

Y := "\033[33m"
R := "\033[31m"
G := "\033[32m"
X := "\033[0m"
UP := "\033[A"
CUT := "\033[K"

#############################################################################
#############################################################################
#############################################################################

.PHONY: all clean fclean re bonus
-include $(OBJS:%.o=%.d)
