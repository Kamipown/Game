NAME = app

# Possible values: [debug, release]
MODE = debug

# Possible values: [windows, mac, linux]
OS = windows

CC = g++

# FLAGS
ifeq ($(MODE), debug)
FLAGS = -std=c++17 -Wall -Wextra -Werror -g
else
FLAGS = -std=c++17 -Wall -Wextra -Werror
endif

# DIRECTORIES
OUT_DIR = Build
SRC_DIR = Dev/src
OBJ_DIR = Dev/obj

# File extensions
SRC_EXT = .cpp
OBJ_EXT = .o
ifeq ($(OS), windows)
OUT_EXT = .exe
else
OUT_EXT =
endif

FILES =	main \
		engine/Engine \
		engine/Config \
		engine/Window \
		game/Game \
		Vector2

SRC = $(addprefix $(SRC_DIR)/, $(addsuffix $(SRC_EXT), $(FILES)))
OBJ = $(addprefix $(OBJ_DIR)/, $(addsuffix $(OBJ_EXT), $(FILES)))
OUT = $(addprefix $(OUT_DIR)/, $(addsuffix $(OUT_EXT), $(NAME)))

INC = -I Dev/inc -I SDL2/include

LIB = -lmingw32 -LSDL2/lib -lSDL2main -lSDL2 -lSDL2_image -lSDL2_mixer -lSDL2_ttf

all: $(OUT)

$(OUT): $(OBJ)
	$(CC) $(FLAGS) $(OBJ) -o $(OUT) $(INC) $(LIB)

$(OBJ_DIR)/%$(OBJ_EXT): $(SRC_DIR)/%$(SRC_EXT)
	@mkdir -p $(@D)
	$(CC) $(FLAGS) -o $@ -c $< $(INC) $(LIB)
	@cygstart $(OUT_DIR)

start:
ifeq ($(OS), windows)
	@cygstart $(OUT_DIR)
endif
ifeq ($(OS), mac)
	@open $(OUT_DIR)
endif
ifeq ($(OS), linux)
	@nautilus $(OUT_DIR)
endif

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(OUT)

re: clean all
