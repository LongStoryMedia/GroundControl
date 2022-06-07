build:
	gcc -o build/ground_control src/*.cpp lib/**/*.cpp -lwiringPi

.PHONY: build