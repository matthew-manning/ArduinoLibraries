

#ifndef __InShiftMux_H__
#define __InShiftMux_H__

#ifdef __cplusplus
extern "C" {
#endif

struct InRegister
{
    unsigned char LatchPin;
    unsigned char AdvancePin;
    unsigned char ReadPin;

};


struct InRegister initInShiftMux( int LatchPin, int AdvPin, int ReadPin);

void refreshReg(struct InRegister InReg);

//advances by 1, starts at Q7 and goes down to Q0
void shiftReg(struct InRegister InReg);

void shiftRegMult(struct InRegister InReg, int NumPlaces);


#ifdef __cplusplus
}
#endif

#endif
