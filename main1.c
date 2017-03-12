#include <wiringPi.h>

#define DEL 1000
#define M_DIR 1
#define M_EN 0
int main (void) {
	wiringPiSetup ();
	pinMode (M_EN, OUTPUT);
	pinMode (M_DIR, OUTPUT);

	while(1) {
		digitalWrite(M_EN, HIGH);
		digitalWrite(M_DIR, HIGH); delay(DEL);
		digitalWrite(M_DIR, LOW); delay(DEL);
		digitalWrite(M_EN, LOW); delay(DEL);
	}
	return 0;

}
