CC=clang
LIBS=-L$(LIB)
CFLAGS += -std=c99 -I$(INCLUDE_DIR) -Wpedantic -pedantic-errors 
CFLAGS += -Werror -Wall -Wextra -Waggregate-return
CFLAGS += -Wbad-function-cast -Wcast-align -Wcast-qual
CFLAGS += -Wfloat-equal -Wformat=2 -Wmissing-declarations
CFLAGS += -Wmissing-include-dirs -Wmissing-prototypes
CFLAGS += -Wnested-externs -Wpointer-arith -Wredundant-decls
CFLAGS += -Wsequence-point -Wshadow -Wstrict-prototypes -Wswitch
CFLAGS += -Wundef -Wunreachable-code -Wunused-but-set-parameter
CFLAGS += -Wwrite-strings
LDFLAGS=

MAIN_DIR=src/main
COMMON_DIR=src/common
GAME_DIR=src/game
TUI_DIR=src/tui
BUILD_DIR=build
INCLUDE_DIR=src

MAIN_SRC=$(wildcard $(MAIN_DIR)/*.c)
COMMON_SRC=$(wildcard $(COMMON_DIR)/*.c)
GAME_SRC=$(wildcard $(GAME_DIR)/*.c)
TUI_SRC=$(wildcard $(TUI_DIR)/*.c)

TUI_VER_SRC += $(MAIN_SRC)
TUI_VER_SRC += $(COMMON_SRC) 
TUI_VER_SRC += $(GAME_SRC) 
TUI_VER_SRC += $(TUI_SRC)

FILENAMES=$(notdir $(TUI_VER_SRC))
OBJECTS=$(FILENAMES:%.c=$(BUILD_DIR)/%.o)
EXECUTABLE=$(BUILD_DIR)/cchess

vpath %.c $(MAIN_DIR) $(COMMON_DIR) $(GAME_DIR) $(TUI_DIR) 

all: $(OBJECTS) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) -o $@ $^ $(LDFLAGS)

$(BUILD_DIR)/%.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $<

.PHONY: clean
clean:
	rm -rf $(BUILD_DIR)/*
