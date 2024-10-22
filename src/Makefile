OBJS= history.o tester.o tokenizer.o uimain.o

CFLAGS=-g -O3
all:uimain
uimain: $(OBJS)

	cc -o uimain $(CFLAGS) $(OBJS)

clean:
	rm -f *.o uimain

run:uimain
	./uimain
