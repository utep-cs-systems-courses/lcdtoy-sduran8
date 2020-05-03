COMMON_OBJECTS  =
CPU             = msp430g2553
CFLAGS          = -mmcu=${CPU} -I../h
LDFLAGS		= -L/opt/ti/msp430_gcc/include
CC              = msp430-elf-gcc
AS              = msp430-elf-as

all: main.elf

main.elf: ${COMMON_OBJECTS} main.o led.o buzzer.o switches.o actions.o stateMachine_a.o stateMachine.o p1_interruptHandler.o wdInterruptHandler.o lcddraw.o lcdutils.o ../lib/libTimer.a 
	${CC} ${CFLAGS} ${LDFLAGS} -o $@ $^


load: main.elf
	msp430loader.sh main.elf $^
clean:
	rm -f *.o *.elf

led.c: led.h
stateMachine.o: led.h stateMachine.h
wdInterruptHanndler.o: stateMachine.h
buzzer.c: buzzer.h
switches.c: switches.h
main.o: led.h buzzer.h switches.h
