CC = clang
CFLAGS = -Wall -g

TARGET = rod_cut
SRCS = main.c cutting_options.c rod_cut.c
OBJS = $(SRCS:.c=.o)

all: format $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

%.o: %.c %.h
	$(CC) $(CFLAGS) -c $< -o $@

format:
	clang-format -i $(SRCS) *.h

clean:
	rm -f $(TARGET) $(OBJS)
