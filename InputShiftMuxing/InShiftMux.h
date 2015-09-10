

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

}


struct InRegister InitInShiftMux(int PowerPin, int LatchPin, int AdvPin, int ReadPin);

void refreshReg(struct InRegister InReg);

void ShiftReg(struct InRegister InReg);

void ShiftRegMult(struct InRegister InReg, int NumPlaces);


#ifdef __cplusplus
}
#endif

#endif
