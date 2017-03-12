//test for relay inputs
//sam taylor
#include <wiringPi.h>
#define DEL 10

int main (void) {
	wiringPiSetup ();

	while(1) {
		//delay(500);
		for (int i = 0; i < 5; i++) {
			pinMode (i, OUTPUT);
			digitalWrite(i, HIGH); delay(DEL);
			digitalWrite(i, LOW); delay(DEL);
		}
		digitalWrite(7, LOW); delay(DEL);

	}
	return 0;
}
