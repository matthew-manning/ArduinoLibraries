#include "KeyLibReworked.h"

#define NUMBEROFKEYS 10
#define BUFFERSIZE 5

#include "Arduino.h"








unsigned char KeyList[NUMBEROFKEYS];//10 keys
unsigned char KeyReg[NUMBEROFKEYS];
unsigned char PressedBuffer[BUFFERSIZE] = {0, 0, 0, 0, 0};
unsigned char ReleasedBuffer[BUFFERSIZE] = {0, 0, 0, 0, 0};
unsigned char NumPB = 0;//number of presses in buffer
unsigned char NumRB = 0;
unsigned char NumberAssignedKeys = 0;

void initKeys(unsigned char Keys[]){
//Keys is array of pin number to setup as keys

    unsigned char i;
    for(i = 0; i<(sizeof(Keys)/sizeof(Keys[0]));i++){
        pinMode(Keys[i], INPUT_PULLUP);
        KeyList[i] = Keys[i];
        KeyReg[i] = 0;
        NumberAssignedKeys++;
    }

}

void pollKeys(void){

    //clear buffer
    NumPB = 0;
    NumRB = 0;

    unsigned char i;
    for(i=0; i <NumberAssignedKeys; i++){
        if (digitalRead(KeyList[i])==KeyReg[i]){//button state changed
            KeyReg[i] = 1-KeyReg[i];//toggle the key reg between 0 and 1

            if (KeyReg[i]){
                //add event to pressed buffer  reput terminator as next char
                PressedBuffer[NumPB] = KeyList[i];
                NumPB++;


            }
            else{
                //add event to Released buffer add reput terminator as next char
                ReleasedBuffer[NumRB] = KeyList[i];
                NumRB++;
            }
        }
    }

}

unsigned char* getPressedBufAdrs(void){
return PressedBuffer;
}

unsigned char* getReleasedBufAdrs(void){
return ReleasedBuffer;
}

//VV size is number of items in buffer, not actual size of array
unsigned char getPBufSize(void){
return NumPB;
}

unsigned char getRBufSize(void){
return NumRB;
}
