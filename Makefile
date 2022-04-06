TARGET = cc2
OBJS = main.o tokenize.o parser.o code_gen.o
TEST_OBJS = cc2_test.o
CC     = g++

$(TARGET): $(OBJS)
	$(CC) -o $@ $^

%.o: %.cc
	$(CC) -c -o $@ $^

install:
	cd cctest && make install

update_submodule:
	git submodule update --remote

test:;
	./unit_test.sh
# TODO:
# ./integration_test.sh

c:;
	rm *.o $(TARGET) *_test
