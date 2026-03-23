CC=arm-none-eabi-gcc
CFLAGS=-mcpu=cortex-m4 -mthumb -nostdlib -Wall
LDFLAGS=-T linker/stm32.id

SRC=src/main.c startup/startup.c

all:
	$(CC) $(CFLAGS) $(SRC) $(LDFLAGS) -o build/main.elf

flash:
	openocd -f interface/stlink.cfg -f target/stm32f4x.cfg \-c "program build/main.elf verify reset exit"

clean:
	rm -rf build/*
