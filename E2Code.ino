// C++ code
//

#include <Servo.h>

int pos = 0;

Servo servo;


void setup()
{
  
  servo.attach(A0, 0, 360);

cli();//stop interrupts

//set timer1 interrupt at 1Hz
  TCCR1A = 0;// set entire TCCR1A register to 0
  TCCR1B = 0;// same for TCCR1B
  TCNT1  = 0;//initialize counter value to 0
  // set compare match register for 1hz increments
  OCR1A = 15624;// = (16*10^6) / (1*1024) - 1 (must be <65536)
  // turn on CTC mode
  TCCR1B |= (1 << WGM12);
  // Set CS10 and CS12 bits for 1024 prescaler
  TCCR1B |= (1 << CS12) | (1 << CS10);  
  // enable timer compare interrupt
  TIMSK1 |= (1 << OCIE1A);

sei();//allow interrupts

  Serial.begin(9600);
}


ISR(TIMER1_COMPA_vect){//Interrupt at freq of 1kHz
  Serial.print("1 sec");
}


void loop()
{
  
}
