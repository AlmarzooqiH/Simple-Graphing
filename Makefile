PROGRAM_NAME := continues_input_graph

COMPILER := c++
STD_VERSION := c++20

STD_FLAG := -std=$(STD_VERSION)
WARN_FLAGS := -Wall -Wextra -Werror
OPT_FLAGS := 
INCLUDE_FLAGS := -Iincludes
SDL_FLAGS := $(shell sdl2-config --cflags)
SDL_LIBS := $(shell sdl2-config --libs)

FLAGS := $(STD_FLAG) $(WARN_FLAGS) $(OPT_FLAGS) $(INCLUDE_FLAGS) $(SDL_FLAGS)

SRC_DIR := srcs
OBJS_DIR := objs

SRC_FILES := $(wildcard $(SRC_DIR)/*.cpp)
OBJS_FILES := $(SRC_FILES:$(SRC_DIR)/%.cpp=$(OBJS_DIR)/%.o)

all: $(PROGRAM_NAME)

$(PROGRAM_NAME): $(OBJS_FILES)
	$(COMPILER) $(FLAGS) $^ -o $@ $(SDL_LIBS)

$(OBJS_DIR):
	mkdir -p $(OBJS_DIR)

$(OBJS_DIR)/%.o: $(SRC_DIR)/%.cpp | $(OBJS_DIR)
	$(COMPILER) $(FLAGS) -c $< -o $@

clean:
	rm -rf *.log $(OBJS_DIR)/*.o

fclean: clean
	rm -rf $(PROGRAM_NAME) $(OBJS_DIR)

re: fclean all

.PHONY: all clean fclean re
