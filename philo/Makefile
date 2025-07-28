# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aistok <aistok@student.42london.com>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/28 12:11:39 by aistok            #+#    #+#              #
#    Updated: 2025/07/28 12:21:55 by aistok           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_DIR			=	./src
INC_DIR			=	./inc
BIN_DIR			=	./bin
OBJ_DIR			=	./obj

CC				=	clang
CFLAGS			=	-Wall -Werror -Wextra
DFLAGS			=	-g3 -O0 -fsanitize=thread
#DFLAGS			=	-fsanitize=address
RM				=	rm -rf
AR				=	ar rcs
MKDIR			=	mkdir -p

# this is a temporary solution until the project becomes
# more stable, with fewer changes
ALL_SRC_DIRS	=	$(shell find $(SRC_DIR) -type d)
ALL_OBJ_DIRS	=	$(subst $(SRC_DIR),$(OBJ_DIR),$(ALL_SRC_DIRS))

INC_FILES		=	${shell find $(INC_DIR) -name "*.h"}
SRC_FILES		=	$(shell find $(SRC_DIR) -name "*.c")
OBJ_FILES		=	$(subst $(SRC_DIR),$(OBJ_DIR),$(SRC_FILES:.c=.o))

NAME			=	$(BIN_DIR)/philo

all: $(NAME)

$(NAME): $(OBJ_FILES) $(INC_FILES) | $(BIN_DIR)
	@$(CC) $(CFLAGS) $(DFLAGS) $(OBJ_FILES) -I$(INC_DIR) -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(INC_FILES) | $(OBJ_DIR)
	@$(CC) $(CFLAGS) $(DFLAGS) -I$(INC_DIR) -c $< -o $@

run: $(NAME)
	@$(NAME)

run1: $(NAME)
	$(NAME) 1 800 100 100

run2: $(NAME)
	$(NAME) 2 800 100 100

run21: $(NAME)
	$(NAME) 2 800 200 200

test:
	@echo SRC_FILES:
	@echo $(SRC_FILES)
	@echo OBJ_FILES:
	@echo $(OBJ_FILES)
#	@echo $(ALL_OBJ_DIRS)

$(BIN_DIR):
	$(MKDIR) $(BIN_DIR)

$(OBJ_DIR):
	$(MKDIR) $(ALL_OBJ_DIRS)

clean:
	$(RM) $(OBJ_DIR)

fclean: clean
	$(RM) $(BIN_DIR)

re: fclean all

.PHONY: all re clean fclean run run1 run2 run21
