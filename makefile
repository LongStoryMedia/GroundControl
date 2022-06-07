build:
	gcc -Wall -x c++ -o build/ground_control src/main.cpp -lwiringPi

.PHONY: build