/*Author: Tyler Reeves
 *Purpose: A finite state machine to control the motor of a sleeping pad inflator.
 *This program works by transitioning between states (each state performs a unique function) based on user selected transition conditions.
 *
*/


//Inflator user paramiters
const double OnDelay = 2;         //OnDelay is the time in seconds the inflator will wait to start the fan after being pluged in
//const double RampDelay = 5;     //time in seconds the fan will ramp up to max speed. Note, not compatible with AttinyA13 MC, uncomment for additional functuionality if you'r using an MC with more flash memmory
const double OnTime = 165;        //OnTime is the time the inflator will stay on in seconds.
const double DutyCycle = 34.5;      //Max fan speed in terms of percentage. EX: if DutyCycle = 35, then fan will max out at 35% speed. WARNING, depending on motor installed, DutyCycle >= 45 may cause overheating and damage

//peramiters governing finite state machine behavior
const int motorPin = 0;           //Which microcontroller pin sends out the PWM signal?
const double TickDelay = 50;      //Time between state transitions in milliseconds

//Finite State Machine variables
int Speed;                        //Speed is used to ramp up and down fan speed during state ticks. If Speed == 0 no fan, if Speed==255 Max fan.
int i;                            //used to keep track of # of ticks through a given state of the finite state machine

enum States{Wait, Ramp, Sustain, Off} State = Wait; //Declare the states of the finite state machine and set the initial starting state.


void setup()
{
  pinMode (motorPin, OUTPUT);
  Speed=0;
  i=0;
  
}

void Tick(){
  switch(State){ // State transitions
    case Wait:
    if(i<(OnDelay/(TickDelay/1000))){ //Check i to see if power has been on for less than onDelay time
        State = Wait;
      }
      else {
        i=0;
        State = Ramp;
      }
    break;
      
    case Ramp:
      if(Speed<(255*(DutyCycle/100))){ //replace 20 with (255*(DutyCycle/100))
        State = Ramp;
      }
      else if(Speed>=(255*(DutyCycle/100))){
        i=0;
        State = Sustain;
      }
    break;
    
    case Sustain:
      if(i<(OnTime/(TickDelay/1000))){ //Check i to see if fan has ran for its max time. Sustain power if not.
        State = Sustain;
      }
      else if(i>=(OnTime/(TickDelay/1000))){ //Check i to see if fan has run for its max time. Power off by changing speed to 0 if true.
        Speed = 0;
        State = Off;
      }
    break;

    case Off:
      State = Off;
    break;
  }

  switch(State){ // State Actions
    case Wait:
      i++;
      analogWrite(motorPin, Speed);
    break;
      
    case Ramp:
      //This block of code does not work with attinyA13 MC. If you change the MC, uncommenting this code and its accompening const variable in setup
      //will allow one to define the interval of time in which the ramp up to max speed happens
      //===============================================
      /*i++;
      if((i*(TickDelay/1000))==(RampDelay/DutyCycle)){
      Speed++;
      analogWrite(motorPin, Speed);
      i=0;
      }*/
      //==============================================
      Speed++;
      analogWrite(motorPin, Speed);
    break;
    
    case Sustain:
      analogWrite(motorPin, Speed);
      i++;
    break;

    case Off:
    analogWrite(motorPin, Speed);
    break;
  }
}




void loop()
{
  Tick();
  delay(TickDelay);
}
