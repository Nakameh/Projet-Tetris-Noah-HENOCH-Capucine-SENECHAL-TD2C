CC := gcc
SRC_DIR ?= src
OBJ_DIR ?= obj
CFLAGS ?= -Wall -MMD -g -lSDL2
LDFLAGS := -lSDL2


OBJS := $(shell find $(SRC_DIR) -name "*.c" | sed 's/.c$$/.o/g' | sed 's/$(SRC_DIR)/$(OBJ_DIR)/g')
DEPS := $(OBJS : .o = .d)
TARGET ?= tetris

all : $(TARGET)

$(TARGET) : $(OBJS)
	@mkdir -p $(DEST_DIR)
	$(CC) -o $(DEST_DIR)/$(TARGET) $(OBJS) $(LDFLAGS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@


try: $(TARGET)
	./$(DEST_DIR)/$(TARGET)

clean :
	rm -rf $(OBJ_DIR)

mrproper : clean
	rm $(TARGET)

-include $(DEPS)