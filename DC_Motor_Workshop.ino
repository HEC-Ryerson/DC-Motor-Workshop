/*
 Fade

 This example shows how to fade an LED on pin 9
 using the analogWrite() function.

 The analogWrite() function uses PWM, so if
 you want to change the pin you're using, be
 sure to use another PWM capable pin. On most
 Arduino, the PWM pins are identified with 
 a "~" sign, like ~3, ~5, ~6, ~9, ~10 and ~11.

 This example code is in the public domain.
 */

const int forward = 9;       // the PWM pin the LED is attached to
const int backward = 10;
const int pot = A0;
int adc_val;
//int brightness = 0;    // how bright the LED is
//int fadeAmount = 5;    // how many points to fade the LED by


// the setup routine runs once when you press reset:
void setup() {
  // declare pin 9 to be an output:
  pinMode(forward, OUTPUT);
  pinMode(backward, OUTPUT);
  pinMode(pot, INPUT);
}

int pot_reading() {
  int adc;
  adc = analogRead(pot);
  return(adc);
}

void pwm_output(int reading) {
  if (reading < 512){
    analogWrite(backward, abs(reading-512)/2);
  } else if (reading >= 512) {
    analogWrite(forward, (reading-512)/2);
  }
}

// the loop routine runs over and over again forever:
void loop() {
  // set the brightness of pin 9:
  //analogWrite(led, brightness);

  // change the brightness for next time through the loop:
  //brightness = brightness + fadeAmount;

  // reverse the direction of the fading at the ends of the fade:
  //if (brightness <= 0 || brightness >= 255) {
  //  fadeAmount = -fadeAmount;
  //}
  // wait for 30 milliseconds to see the dimming effect
  adc_val = pot_reading();
  pwm_output(adc_val);
  delay(30);
}
