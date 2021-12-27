/*Code for turn and off ** automatically with Arduino
  Author: João Peralta
  Date:27/12/2021
  Language: C#
  Controller: Arduino Uno
*/

//Digital outputs\\

int Output1=8; 
int Output2=9;

//Buttons to interrupt\\

int Button1=2;
int Button2=3;

//State of the equipments(leds)\\

int state1=LOW; 
int state2=LOW;

//Timers\\

unsigned long tempos1=0;
unsigned long tempos11=0;
unsigned long tempos12=0;

void setup() {
//System setup\\

  Serial.begin(9600);
  
//Buttons to interrupt\\

  pinMode(Button1, INPUT_PULLUP);
  pinMode(Button2, INPUT_PULLUP); 
  
//Digital outputs\\

  pinMode(Output1, OUTPUT);
  pinMode(Output2, OUTPUT);

//Interruptions setup\\

  attachInterrupt(digitalPinToInterrupt(Button1), Toque1, FALLING);
  attachInterrupt(digitalPinToInterrupt(Button2), Toque2, FALLING);
  interrupts();
}

void loop ()
{
  tempos1=millis();

                //First activation during 5 seconds\\
                
if (tempos1-tempos11<=5000 && tempos1-tempos11<tempos1)
{
 state1=HIGH;
 state2=HIGH; 
 digitalWrite(Output1,state1);
 delay(20);                                                                   
 digitalWrite(Output2,state2); 
}
 
               //First interruption during 2 seconds\\
               
 if (tempos1-tempos11>5000 && tempos1-tempos11<7000)
{
 state1=LOW;
 state2=LOW; 
 digitalWrite(Output1,state1);                                                                   
 digitalWrite(Output2,state2); 
}

              //Second activation during 5 seconds\\
              
if (tempos1-tempos11>=7000 && tempos1-tempos11<=12000)
{
 state1=HIGH;
 state2=HIGH; 
 digitalWrite(Output1,state1);   
 delay(20);                                                                  
 digitalWrite(Output2,state2); 
}

               //Stop First function by turning off the equipments(leds) after second automatic turn on during 5 seconds\\
               
else
{
 state1=LOW;
 state2=LOW; 
 digitalWrite(Output1,state1);                                                                   
 digitalWrite(Output2,state2); 
}

                      //First activation during 2 seconds\\

if (tempos1-tempos12<=2000 && tempos1-tempos12<tempos1)
{
 state1=HIGH;
 state2=HIGH; 
 digitalWrite(Output1,state1);   
 delay(20);                                                                  
 digitalWrite(Output2,state2); 
}
 
                        //First interruption during 5 seconds\\
                        
 if (tempos1-tempos12>2000 && tempos1-tempos12<7000)
{
 state1=LOW;
 state2=LOW; 
 digitalWrite(Output1,state1);                                                                   
 digitalWrite(Output2,state2); 
}

                        //Second activation during 2 seconds\\
                        
if (tempos1-tempos12>=7000 && tempos1-tempos12<=9000)
{
 state1=HIGH;
 state2=HIGH; 
 digitalWrite(Output1,state1);  
 delay(20);                                                                   
 digitalWrite(Output2,state2); 
}

                          //Stop Second function by turning off the equipments(leds) after second automatic turn on during 2 seconds\\
                          
else
{
 state1=LOW;
 state2=LOW; 
 digitalWrite(Output1,state1);                                                                   
 digitalWrite(Output2,state2); 
}
}


//First interrupt function to activate timer\\

void Toque1(void){
 tempos11=tempos1;
}

//Second interrupt function to activate timer\\

void Toque2(void){
 tempos12=tempos1;
}
