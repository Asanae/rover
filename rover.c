//#include <wiringPi.h>
#define DEL 50
#define	ENS
#define END
#define ENDDIR
#define ENSDIR

void test () {
	for(int i = 0;i < 8;i++) {
		pinMode (i, OUTPUT);
		digitalWrite (i, HIGH); delay (DEL);
		digitalWrite (i, LOW); delay (DEL);
	}
}

int main (void) {
	wiringPiSetup ();
	while (1) {
		int i = 0;
		int n = 0;
		int mode = 0;
		scanf("%d\n", i);
		scanf("%d\n", n);
		pinMode (i, OUTPUT);
		if (n > 0) {
			mode = HIGH;
		} else {
			mode = LOW;
		}
		digitalWrite (i, mode);
	}
	return 0;
}
