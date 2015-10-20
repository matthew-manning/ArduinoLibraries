#include "WaveAmplitude.h"
#include <Arduino.h>
#include <math.h>

struct ActiveNote generateNote(int Freq, int WaveType, int Length);
{
    NewNote.Frequency = Freq;
    NewNote.Length = length;

    NewNote.StartTime = millis();//get current time

    //assigning wave function
    switch(WaveType)
    {
    case SQUARE_WAVE_NOTE:
        NewNote.WaveFunction = &squareWave;// not sure if cast is needed first
        break;
    case SINE_WAVE_NOTE:
        NewNote.WaveFunction = &sineWave;
    }

    return NewNote;
}

//50% duty cycle, starts high for 8-bit
int squareWave(double Freq, unsigned long StartTime)
{
    unsigned long TimePassed = millis()-StartTime; //time since note began
    double WaveLength = 1/Freq;

    double RelitiveTime = TimePassed%WaveLength;//not sure if % works with floats

    //if in first half of a cycle is high
    if (RealtiveTime < Wavelength/2)
    {
        return 255;
    }
    else
    {
        return 0;
    }

}

int sineWave(double Freq, unsigned long StartTime)
{
    unsigned long TimePassed = millis()-StartTime; //time since note began
    double WaveLength = 1/Freq;

    double RelitiveTime = TimePassed%WaveLength;//not sure if % works with floats
    float CycleAngle = (RelitiveTime/WaveLength)*6.28;// radians value

    return sin(CycleAngle)*255;//sine at peak to peak of 256


}
