#include <stdio.h>
#include <stdlib.h>
#include <wiringPi.h> 
/*

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
//*/
#define TURN_CENTRE_TIME 500

void test () {
	for(int i = 0;i < 8;i++) {
		pinMode (i, OUTPUT);
		digitalWrite (i, HIGH);
		digitalWrite (i, LOW);
	}
}
void m_init() {
    printf("\n\n command: f b l r (forward, back, left, right)\n");
    
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

void run () {
    		char c;
        char turn;
		scanf("%c", &c);
        
		if (c == 'l') { printf("Left\n");turn=c;m_left();}
		if (c == 'r') { printf("Right\n");turn=c;m_right();}
		if (c == 'f') { printf("Forward\n");    m_forward();}
		if (c == 'b') { printf("Back\n");       m_back();}
        if (c == 'h') { printf("Halt\n");turn=c;clear();}
        if (c == 'e') { printf("Exit...\n");    clear(); return 0;}
        
        if (c == 's') { 
            printf("Straight\n");
            if (turn = c) {m_right(); delay (TURN_CENTRE_TIME);}
            else {          m_left(); delay (TURN_CENTRE_TIME);}
        }
        
        if (c == 'l' || c == 'r') {            
            if (digitalRead(0) == 1) {
                digitalWrite(2, LOW);
            } else {
                digitalWrite(2, HIGH);
            }
        }
}
int main (void) {
	wiringPiSetup ();
	m_init();
    
	while (1) {
        //run();
        for (int i = 0; i < 8; i++) {
            printf("pin %d", i);
                digitalWrite(i, HIGH); delay(1000);
                digitalWrite(i, LOW); delay(100);
        }
	}
	return 0;
}
