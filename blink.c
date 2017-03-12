#include <wiringPi.h>
#define DEL 50

int main (void) {
	wiringPiSetup ();
	while (1) {
		for(int i = 0;i < 8;i++) {
			pinMode (i, OUTPUT);
			digitalWrite (i, HIGH); delay (DEL);
			digitalWrite (i, LOW); delay (DEL);
		}
	}
	return 0;
}

