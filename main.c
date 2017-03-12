#include <wiringPi.h>
#define DEL 10
void clear() {
	for (int i = 0; i < 8; i++) {
		digitalWrite(i, LOW); delay(DEL);
	}
}

void range(int time) {
	for (int i = 0; i< 8; i++) {
		digitalWrite(i, HIGH); delay(time);
		digitalWrite(i, LOW); delay(time);
	}
}

void blinkAll(int time) {
	for (int i = 0; i < 8; i++) {
		digitalWrite(i, HIGH);
	}
	delay(time);
}
int main (void) {
	wiringPiSetup ();
	clear();

	while(1) {
		range(500);
		blink(1000);
	}
	return 0;
}
