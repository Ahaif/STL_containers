CC = c++
FLAGS = -g  -std=c++98 -Wall -Werror -Wextra #-fsanitize=address  -fsanitize=undefined

OBJECT_PATH = ./object_files/
OBJ_SRC = object_files
SRC = main.cpp

NAME = main

INCLUDE = vector set stack map
INCLUDE_FLAGS = $(addprefix -I, $(INCLUDE_DIRS))

OBJECTS = $(addprefix $(OBJECT_PATH), $(SRC:.cpp=.o))

all: $(NAME) $(INCLUDE)

$(NAME): $(OBJ_SRC) $(OBJECTS) $(INCLUDE)
	@$(CC) $(FLAGS) $(INCLUDE_FLAGS) $(OBJECTS) -o $@

$(OBJECT_PATH)%.o : %.cpp 
	@$(CC) $(FLAGS) $(INCLUDE_FLAGS) -o $@  -c $<


$(OBJ_SRC) :
	@mkdir $@

clean:
	@rm -rf $(OBJECTS)
	@rm -rf $(OBJ_SRC)

fclean: clean
	@rm -rf $(NAME)

re: fclean all