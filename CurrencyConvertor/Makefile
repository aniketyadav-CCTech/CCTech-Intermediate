.PHONY: all
all: program
	./program

.PHONY: test
test: Testing
	./Testing

program: CurrencyIO.o
Testing: CurrencyIO.o

.PHONY: clean
clean:
	rm -f program CurrencyIO Testing *.o