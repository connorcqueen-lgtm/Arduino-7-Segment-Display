// 4-Bit Input to Hexadecimal 7-Segment Display
// Inputs: D12, D11, D10, D9
// Outputs: D2 through D8
// Display: Common Anode / Active-Low
 
// Pushbutton / switch input pins
const int button1 = 12;   // Binary value 1
const int button2 = 11;   // Binary value 2
const int button3 = 10;   // Binary value 4
const int button4 = 9;    // Binary value 8
 
// 7-segment output pins
const int segA = 2;
const int segB = 3;
const int segC = 4;
const int segD = 5;
const int segE = 6;
const int segF = 7;
const int segG = 8;
 
void setup()
{
    // Configure the four switches as digital inputs.
    pinMode(button1, INPUT);
    pinMode(button2, INPUT);
    pinMode(button3, INPUT);
    pinMode(button4, INPUT);
 
    // Configure segments A-G as digital outputs.
    pinMode(segA, OUTPUT);
    pinMode(segB, OUTPUT);
    pinMode(segC, OUTPUT);
    pinMode(segD, OUTPUT);
    pinMode(segE, OUTPUT);
    pinMode(segF, OUTPUT);
    pinMode(segG, OUTPUT);
}
 
void loop()
{
    // Begin with a value of zero.
    int number = 0;
 
    // Each active-high switch adds its binary place value.
    if (digitalRead(button1) == HIGH)
        number = number + 1;
 
    if (digitalRead(button2) == HIGH)
        number = number + 2;
 
    if (digitalRead(button3) == HIGH)
        number = number + 4;
 
    if (digitalRead(button4) == HIGH)
        number = number + 8;
 
    // Display the resulting value from 0 through F.
    displayHex(number);
}
 
// Select the correct segment pattern for values 0 through 15.
// Because the display is active-low, LOW turns a segment ON.
void displayHex(int number)
{
    switch (number)
    {
        case 0:  setSegments(LOW,  LOW,  LOW,  LOW,  LOW,  LOW,  HIGH); break;
        case 1:  setSegments(HIGH, LOW,  LOW,  HIGH, HIGH, HIGH, HIGH); break;
        case 2:  setSegments(LOW,  LOW,  HIGH, LOW,  LOW,  HIGH, LOW);  break;
        case 3:  setSegments(LOW,  LOW,  LOW,  LOW,  HIGH, HIGH, LOW);  break;
        case 4:  setSegments(HIGH, LOW,  LOW,  HIGH, HIGH, LOW,  LOW);  break;
        case 5:  setSegments(LOW,  HIGH, LOW,  LOW,  HIGH, LOW,  LOW);  break;
        case 6:  setSegments(LOW,  HIGH, LOW,  LOW,  LOW,  LOW,  LOW);  break;
        case 7:  setSegments(LOW,  LOW,  LOW,  HIGH, HIGH, HIGH, HIGH); break;
        case 8:  setSegments(LOW,  LOW,  LOW,  LOW,  LOW,  LOW,  LOW);  break;
        case 9:  setSegments(LOW,  LOW,  LOW,  LOW,  HIGH, LOW,  LOW);  break;
        case 10: setSegments(LOW,  LOW,  LOW,  HIGH, LOW,  LOW,  LOW);  break; // A
        case 11: setSegments(HIGH, HIGH, LOW,  LOW,  LOW,  LOW,  LOW);  break; // b
        case 12: setSegments(LOW,  HIGH, HIGH, LOW,  LOW,  LOW,  HIGH); break; // C
        case 13: setSegments(HIGH, LOW,  LOW,  LOW,  LOW,  HIGH, LOW);  break; // d
        case 14: setSegments(LOW,  HIGH, HIGH, LOW,  LOW,  LOW,  LOW);  break; // E
        case 15: setSegments(LOW,  HIGH, HIGH, HIGH, LOW,  LOW,  LOW);  break; // F
    }
}
 
// Write the desired state to all seven segments.
// Parameter order: A, B, C, D, E, F, G.
void setSegments(int A, int B, int C, int D, int E, int F, int G)
{
    digitalWrite(segA, A);
    digitalWrite(segB, B);
    digitalWrite(segC, C);
    digitalWrite(segD, D);
    digitalWrite(segE, E);
    digitalWrite(segF, F);
    digitalWrite(segG, G);
}
