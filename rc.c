#include <stdio.h>
#include <stdlib.h>
#include <wiringPi.h> 
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

void testPin() {
    printf("pin0\n");
    digitalWrite(0 , HIGH); delay(1000);
    digitalWrite(0 , LOW); delay(100);
    printf("pin1\n");
    digitalWrite(1 , HIGH); delay(1000);
    digitalWrite(1 , LOW); delay(100);
    printf("pin2\n");
    digitalWrite(2 , HIGH); delay(1000);
    digitalWrite(2 , LOW); delay(100);
    printf("pin4\n");
    digitalWrite(4 , HIGH); delay(1000);
    digitalWrite(4 , LOW); delay(100);
}
int main (void) {
	wiringPiSetup ();
	m_init();
    
	while (1) {
        testPin();
	}
	return 0;
}
