#include <wiringPi.h>

#define DEL 50
#define	ENS
#define END
#define ENDDIR
#define ENSDIR

void test () {
	for(int i = 0;i < 8;i++) {
		pinMode (i, OUTPUT);
		digitalWrite (i, HIGH);
		digitalWrite (i, LOW);
	}
}

void clear () {
	for(int i = 0;i < 8;i++) {
		pinMode (i, OUTPUT);
		digitalWrite (i, LOW);
	}
}

int main (void) {
	wiringPiSetup ();
	clear ();
	
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
