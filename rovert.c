//#include <wiringPi.h>
#include <stdio.h>
#include <stdlib.h>

#define DEL 50
#define	ENS
#define END
#define ENDDIR
#define ENSDIR

#define OUTPUT 1
#define HIGH 1
#define LOW 0

void digitalWrite(int i, int n) {
	if (n < 1) {
		printf("%d OUTPUT LOW\n", i);
	} else {
		printf("%d OUTPUT HIGH\n", i);
	}
}

void pinMode (int pin, int out) {
	printf ("%d OUTPUT\n", pin);
}

void wiringPiSetup() {
	printf("initComplete\n");
}

void test () {
	for(int i = 0;i < 8;i++) {
		pinMode (i, OUTPUT);
		digitalWrite (i, HIGH);
		digitalWrite (i, LOW);
	}
}

int main (void) {
	wiringPiSetup ();
	while (1) {
		int pin = 0;
		int mode = 0;
		printf("\n\npin, mode: ");
		scanf("%d %d", &pin, & mode);
		//scanf("%d\n", &mode);
		printf("pin: %d, mode %d\n", pin, mode);

		pinMode (pin, OUTPUT);
		digitalWrite (pin, mode);
	}
	return 0;
}
