# Project
NAME	=	orz
EXEC	=	$(NAME).exe

# Tool
CC			?=	clang
RM			?=	rm
INSTALL		?=	install
MKDIR		?=	mkdir -p
PKGCONF		?=	pkg-config

# File
HEADERS		=	$(shell find include -type f -name '*.h')
SRCS		=	$(shell find src -type f -name '*.c')
OBJS		=	$(addprefix $(BUILD_DIR)/, $(SRCS:.c=.o))


# Path
BUILD_DIR	?=	$(abspath build)
prefix		?=	/usr/local

# Option
CPPFLAGS	=	-I./include
CFLAGS		=	-std=gnu23 -Wall -Wextra -g -O2 -fvisibility=hidden
LDFLAGS		=	
LDLIBS		=	$(shell $(PKGCONF) --libs raylib)

all: $(BUILD_DIR) $(BUILD_DIR)/$(EXEC)
$(BUILD_DIR):
	$(MKDIR) $@
$(BUILD_DIR)/$(EXEC): $(OBJS)
	$(CC) $(LDFLAGS) $^ $(LDLIBS) -o $@
$(BUILD_DIR)/%.o: %.c
	$(MKDIR) $(dir $@)
	$(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@
clean:
	$(RM) -rf $(BUILD_DIR)
.PHONY: all clean