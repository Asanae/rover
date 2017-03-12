#include <wiringPi.h>

void test () {
	for(int i = 0;i < 8;i++) {
		pinMode (i, OUTPUT);
		digitalWrite (i, HIGH);
		digitalWrite (i, LOW);
	}
}
void m_init() {
	for(int i = 0;i < 8;i++) {
		pinMode (i, OUTPUT);
		digitalWrite (i, LOW);
	}
}

void clear () {
	for(int i = 0;i < 8;i++) {
		digitalWrite (i, LOW);
	}
}

void writePin () {
	int pin = 0;
	int mode = 0;
	printf("\n\npin, mode: ");
	scanf("%d %d", &pin, & mode);
	//scanf("%d\n", &mode);
	printf("pin: %d, mode %d\n", pin, mode);

	pinMode (pin, OUTPUT);
	digitalWrite (pin, mode);
}

void m_right() {
	digitalWrite(2, LOW);
	digitalWrite(1, LOW);
	digitalWrite(3, LOW);
	digitalWrite(2, HIGH);
}

void m_left() {
	digitalWrite(2, LOW);
	digitalWrite(1, HIGH);
	digitalWrite(3, HIGH);
	digitalWrite(2, HIGH);
}

void m_forward() {
	digitalWrite(6, LOW);
	digitalWrite(4, HIGH);
	digitalWrite(5, HIGH);
	digitalWrite(6, HIGH);
}

void m_back() {
	digitalWrite(6, LOW);
	digitalWrite(4, LOW);
	digitalWrite(5, LOW);
	digitalWrite(6, HIGH);
}

int main (void) {
	wiringPiSetup ();
	m_init();

	while (1) {
		char c = '';

		printf("\n\n command: f b l r (forward, back, left, right)\n");
		scanf("%c", &c);

		clear ();
		if (c == 'f') { printf("Forward\n"); m_forward();}
		if (c == 'b') { printf("Back\n"); m_back();}
		if (c == 'l') { printf("Left\n"); m_left();}
		if (c == 'r') { printf("Right\n"); m_right();}
	}
	return 0;
}
