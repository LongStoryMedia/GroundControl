NAME != basename $(CURDIR)
DIR := ~/firmware/$(NAME)
HOSTNAME := raspberrypi.local
LIBLIST != cat linklibs.txt
LIBS != for lib in ${LIBLIST}; do printf -- "-l$${lib} "; done
SRCS := $(DIR)/src/*.cpp $(DIR)/src/LCD/*.c $(DIR)/src/LCD/Fonts/*.c $(DIR)/src/LCD/GUI/*.c

compile-controls:
	arduino-cli compile -b Seeeduino:samd:seeed_XIAO_m0 i2cInputs/main.cpp --build-path src/Input

compile-core:
	ssh $(HOSTNAME) "g++ -Wall -Wno-narrowing -o $(DIR).fw $(SRCS) $(LIBS)"

flash-controls:
	-ssh $(HOSTNAME) "arduino-cli upload -p /dev/ttyACM0 -b Seeeduino:samd:seeed_XIAO_m0 --input-dir $(DIR)/src/Input"

upload:
	rsync -avzru --delete ./src $(HOSTNAME):$(DIR)

build: compile-core flash-controls

start:
	ssh $(HOSTNAME) "sudo $(DIR).fw > /dev/null 2>&1 &" > /dev/null 2>&1 &
	# ssh $(HOSTNAME) "sudo $(DIR).fw"

stop:
	-ssh $(HOSTNAME) "pgrep $(NAME) | xargs sudo kill -2"

reboot:
	ssh $(HOSTNAME) "sudo reboot"

init: compile-controls upload build

flash: stop init start