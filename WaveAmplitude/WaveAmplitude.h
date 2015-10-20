/*Matthew Manning; lastest modifaction 19-10-2015
 *
 *these function gives the momentary amplitude
 *of different wave froms based on their frequncy
 *and the note starting time.
 *
 *also contained are functions for checking if a notes should
 *be removed from the playing notes array
 */

 #define SQUARE_WAVE_NOTE 1
 #define SINE_WAVE_NOTE 2


struct ActiveNote
{
    unsigned long StartTime;
    double Frequency;
    void * WaveFunction;
    int Length;//time note plays for; in ms

};

struct ActiveNote generateNote(double Freq, int WaveType, int Length);
