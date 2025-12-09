CC = gcc
LIB_PATHS = ./sqlite-autoconf-3510100
INCLUDES = -I$(LIB_PATHS) -I./
CFLAGS = -Wall -Wextra -Werror -g3 $(INCLUDES)
LDLIBS = $(LIB_PATHS)/libsqlite3.a 
LDFLAGS = -lm
TARGET = sql_lite_example
SRCS = sql_lite_example.c \
	   sql_lite_version.c
OBJS = $(SRCS:.c=.o)

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@ $(LDLIBS) $(LDFLAGS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(TARGET) $(OBJS)