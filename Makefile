build:
	gcc -O2 -Wall -Wextra -Wformat=2 -Wformat-overflow -Wformat-truncation -Wshadow -Wdouble-promotion -Wundef -fno-common -z noexecstack -Wconversion -fsanitize=undefined -g -o ./bin/gitcheck gitcheck.c
run:
	./bin/gitcheck
