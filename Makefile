CC = gcc

CFLAGS = -Wall -Wextra -std=c99 -m32 -fno-pie -fno-stack-protector

TARGET1 = task1
TARGET2 = task4

SRCS1 = task1.c
SRCS2 = task4.c

OBJS1 = $(SRCS1:.c=.o) 
OBJS2 = $(SRCS2:.c=.o)

all: $(TARGET1) $(TARGET2)

$(TARGET1): $(OBJS1)
	$(CC) $(CFLAGS) -o $(TARGET1) $(OBJS1)

$(TARGET2): $(OBJS2)
	$(CC) $(CFLAGS) -o $(TARGET2) $(OBJS2)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(TARGET1) $(OBJS1)
	rm -f $(TARGET2) $(OBJS2)

.PHONY: all clean
