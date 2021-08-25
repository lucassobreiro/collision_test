TARGET=collision_test

all:
	make clear
	make compile
	make run

compile:
	g++ src/*.cpp -c -I src/ -Wall
	g++ *.o -o $(TARGET) -lsfml-graphics -lsfml-window -lsfml-system

run:
	./$(TARGET)

clear:
	rm *.o $(TARGET)

