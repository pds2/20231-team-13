data: ./src/data.o main.o
	g++ ./src/data.o main.o -o main  -l sqlite3

./src/data.o: ./src/data.cpp
	g++ -c ./src/data.cpp -o ./src/data.o  -l sqlite3

main.o: main.cpp
	g++ -c main.cpp  -l sqlite3

clean:
	rm *.o data
