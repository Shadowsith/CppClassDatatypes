all:
	mkdir -p ./bin/
	g++ -std=c++11 ../src/String.cpp ./cli-textformatpp/src/textformatpp.cpp stringtest.cpp -o ./bin/stringtest
	g++ -std=c++11 ../src/Integer.cpp ./cli-textformatpp/src/textformatpp.cpp inttest.cpp -o ./bin/inttest


string:
	mkdir -p ./bin/
	g++ -std=c++11 ../src/String.cpp ./cli-textformatpp/src/textformatpp.cpp stringtest.cpp -o ./bin/stringtest

int:
	mkdir -p ./bin/
	g++ -std=c++11 ../src/Integer.cpp ./cli-textformatpp/src/textformatpp.cpp inttest.cpp -o ./bin/inttest

run_str:
	./bin/stringtest

run_int:
	./bin/inttest

clear: 
	rm -r ./bin
