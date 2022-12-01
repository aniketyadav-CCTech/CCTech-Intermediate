cat: clean
	g++ cat.cpp -o cat
	./cat
clean :
	rm -f ./cat
test :
	diff <(cat ../cat/cat.cpp) <(./cat ../cat/cat.cpp)