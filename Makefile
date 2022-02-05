OBJDIR = objs
OBJS = $(addprefix $(OBJDIR)/,main.o board.o game.o)
CFLAGS = -std=c99 -pedantic-errors
DLIBS = -lncurses

.PHONY: clean

$(OBJDIR)/%.o: src/%.c
	gcc -c $< -o $@ $(CFLAGS)

all: build

$(OBJS): | $(OBJDIR)

$(OBJDIR):
	mkdir $(OBJDIR)

build: $(OBJS)
	gcc $^ -o main $(DLIBS)

clean:
	rm $(OBJS) -v
