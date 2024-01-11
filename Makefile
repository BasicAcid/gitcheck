build: | bin
	gcc -O2 -Wall -Wextra -Wformat=2 -Wformat-overflow -Wformat-truncation -Wshadow -Wdouble-promotion -Wundef -fno-common -z noexecstack -Wconversion -fsanitize=undefined -fstack-protector -mshstk -g -o ./bin/gitcheck gitcheck.c

bin:
	mkdir -p bin

run:
	./bin/gitcheck

install:
	install ./bin/gitcheck ~/.local/bin/gitcheck
