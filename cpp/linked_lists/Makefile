SRCS = main.cpp test.cpp

OBJS = $(SRCS:.cpp=.out)

all: $(OBJS)

.cpp.out:
	c++ $< -o $@

clean:
	rm -f *.out

test: test.out
	./test.out
