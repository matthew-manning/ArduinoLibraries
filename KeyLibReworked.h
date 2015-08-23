
/*
* Matthew Manning, 2015.
*handles button setup, polling and
*generates pressed and released buffers.
*/

#ifndef __KEYLIBREWORKED_H__
#define __KEYLIBREWORKED_H__

#ifdef __cplusplus
extern "C" {
#endif

void initKeys(unsigned char Buttons[]);
void pollKeys(void);
unsigned char* getReleasedBufAdrs(void);
unsigned char* getPressedBufAdrs(void);
unsigned char getPBufSize(void);
unsigned char getRBufSize(void);

#ifdef __cplusplus
}
#endif

#endif
