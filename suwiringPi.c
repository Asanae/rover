#include <stdio.h>
#include <stdlib.h>

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
