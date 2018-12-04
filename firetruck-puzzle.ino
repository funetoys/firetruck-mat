/*
 * LilyPad Buzzer Sound Demo
 *
 * Using your Arduino and a Lilypad Buzzer to play musical scales
 */

/* Items you will need
 *
 *  one (1) Lilypad buzzer
 *  one (1) Arduino
 *  two patch cables
 */

/* Setup
 *
 *  Connect digital pin #9 from Arduino to buzzer
 *  Connect GND (ground) from Arduino to - (negative) on buzzer
 */

// CODE FOLLOWS

const int Buzzer = 3; // declaring buzzer will be on pin #3
const int Led = 2; // declaring LED will be on pin #2

void setup()
{

  pinMode(Buzzer, OUTPUT); // declaring pin #3 will be used for OUTPUT
  pinMode(Led, OUTPUT); // declaring pin #2 will be used for OUTPUT
  digitalWrite (Led, LOW);
}

void loop()  // the rest of this code was located at http://web.media.mit.edu/~leah/LilyPad/07_sound.html
{
  scale(); // call the scale() function
  delay(200); // delay for 1 second
}

void beep (int Buzzer, int frequencyInHertz, long timeInMilliseconds)     // the sound producing function
{
  int x;
  long delayAmount = (long)(1000000 / frequencyInHertz);
  //long loopTime = (long)((timeInMilliseconds * 1000) / (delayAmount * 2));
  long loopTime = (long)((timeInMilliseconds * 500) / (delayAmount * 1.5));
  for (x = 0; x < loopTime; x++)
  {
    digitalWrite(Buzzer, HIGH);
    digitalWrite (Led, HIGH);
    delayMicroseconds(delayAmount);
    digitalWrite(Buzzer, LOW);
    digitalWrite (Led, LOW);
    delayMicroseconds(delayAmount);
  }

}

void scale ()
{
  beep(Buzzer, 4186, 700);
  beep(Buzzer, 2093, 700); //C: play the note C (C7 from the chart linked to above) for 500ms
}

