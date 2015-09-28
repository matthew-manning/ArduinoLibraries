/*Matthew Manning 09/2015
 *
 *handles setup of pins for input muxing using a 74hc165 shift register
 *wired with a circlar register.
 *As a Uno does not have a vcc pin on that side it also sets up an output pin
 *to supply power.
 *only made to deal with one register.
 */

 #include "InShiftMux.h"
 #include "Arduino.h"




struct InRegister initInShiftMux( int LatchPin, int AdvPin, int ReadPin)//take pin numbers to setup
{
    struct InRegister NewReg;

    //init struct
    NewReg.LatchPin = LatchPin;
    NewReg.AdvancePin = AdvPin;
    NewReg.ReadPin = ReadPin;

    //set i/o status of pins
    pinMode(LatchPin, OUTPUT);
    pinMode(AdvPin, OUTPUT);
    pinMode(ReadPin, INPUT);//does it need to be set to pull up?

    //initial pin states
    digitalWrite(LatchPin, HIGH);
    digitalWrite(AdvPin, LOW);


    return NewReg;
}


/*refreshs data in reister*/
void refreshReg(struct InRegister InReg)
{
    //pulse latch pin low for 1 micro second; advance pin needs to be high when this is done
    digitalWrite(InReg.AdvancePin, HIGH);
    delayMicroseconds(1);
    digitalWrite(InReg.LatchPin, LOW);
    delayMicroseconds(1);
    digitalWrite(InReg.LatchPin, HIGH);
    digitalWrite(InReg.AdvancePin, LOW);
}

/*Shifts regester*/
void shiftReg(struct InRegister InReg)
{
    //pulse advance pin high for 1 micro second
    digitalWrite(InReg.AdvancePin, HIGH);
    delayMicroseconds(1);
    digitalWrite(InReg.AdvancePin, LOW);
}


//for a shift more than one place
void shiftRegMult(struct InRegister InReg, int NumPlaces)
{
    int i;
    for(i = 0; i <NumPlaces;i++)
    {
        //pulse advance pin high for 1 micro second, for each
        digitalWrite(InReg.AdvancePin, HIGH);
        delayMicroseconds(1);
        digitalWrite(InReg.AdvancePin, LOW);
    }
}
