#include "Rotation.h"
#include "Solve.h"
Solution s;
void setup() {
Serial.begin(9600);
delay(100);
Serial.println("Start!");
}

void loop() {
s.whiteCross();
s.F2L();
s.OLL();
s.PLL();
}
