CC := gcc
SRC_DIR ?= src
OBJ_DIR ?= obj
CFLAGS ?= -Wall -MMD -g
LDFLAGS := -lSDL2 -lncursesw -lSDL2_ttf
TARGETDIR := build


OBJS := $(shell find $(SRC_DIR) -name "*.c" | sed 's/.c$$/.o/g' | sed 's/$(SRC_DIR)/$(OBJ_DIR)/g')
DIRSOBJ := $(shell find $(SRC_DIR) -type d |sed 's/$(SRC_DIR)/$(OBJ_DIR)/g')
DEPS := $(OBJS : .o = .d)
TARGET ?= tetris

all : $(TARGET)

objdirs : 
	$(shell for dir in $(DIRSOBJ); do mkdir -p "$$dir"; done)


$(TARGET) : objdirs $(OBJS)
	@mkdir -p $(TARGETDIR)
	$(CC) -o $(TARGETDIR)/$(TARGET) $(OBJS) $(LDFLAGS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@


try: $(TARGET)
	./$(TARGETDIR)/$(TARGET)

clean :
	rm -rf $(OBJ_DIR)

mrproper : clean
	rm -rf $(TARGETDIR)

-include $(DEPS)