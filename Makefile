CC = gcc
CFLAGS = -std=c11 -Wall -Wextra
LDFLAGS = -lws2_32  # For network functions if needed

TARGET = coolcli.exe

SRCS = main.c commands.c utils.c
HDRS = commands.h utils.h

$(TARGET): $(SRCS) $(HDRS)
	$(CC) $(CFLAGS) $(SRCS) -o $(TARGET) $(LDFLAGS)

clean:
	del $(TARGET)

.PHONY: clean