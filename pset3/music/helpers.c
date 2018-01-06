// Helper functions for music

#include <cs50.h>

#include "helpers.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Converts a fraction formatted as X/Y to eighths
int duration(string fraction)
{
    int denom = atoi(&fraction[strlen(fraction) - 1]);
    int numer = atoi(&fraction[strlen(fraction) - 3]);
    if (denom == 8){
        return numer;
    } else {
        return 8 / denom;
    }
}

// Calculates frequency (in Hz) of a note
int frequency(string note)
{
    float result;
    // n --- total distance from A4 in semitones
    int n = 0;
    //check for accent
    char pitch;
    if (strlen(note) == 3){
            pitch = note[1];
    } else {
        pitch = 'X';
    }
    // octave - representation of the octave value as an int converted from a string
    int octave = (note[strlen(note) - 1]) - 48;;
    // adds to total distance based on octave value
    n += ((octave - 4) * 12);
    //add note values to n, based on accidental or not
    switch(note[0]){
        case 'A':
            if (pitch == '#'){
                n += 1;
                break;
            } else if (pitch == 'b'){
                n -= 1;
                break;
            } else {
                break;
            }
        case 'B':
            if (pitch == 'b'){
                n += 1;
                break;
            } else {
                n += 2;
                break;
            }
        case 'C':
            if (pitch == '#'){
                n -= 8;
                break;
            } else {
                n -= 9;
                break;
             }
        case 'D':
            if (pitch == '#'){
                n -= 6;
                break;
            } else if (pitch == 'b'){
                n -= 8;
                break;
            } else {
            n -= 7;
            break;
            }
        case 'E':
            if (pitch == 'b'){
                n -= 6;
                break;
            } else {
                n -= 5;
                break;
            }
        case 'F':
            if (pitch == '#'){
                n -= 3;
                break;
            } else {
                n -= 4;
                break;
            }
        case 'G':
            if (pitch == '#'){
                n -= 1;
                break;
            } else if (pitch == 'b'){
                n -= 3;
                break;
            } else {
                n -= 2;
                break;
            }
    }
    //calculate frequency based upon n
    result = round(pow(2.0, (float) n / 12.0) *  440.0);
    return result;
}


// Determines whether a string represents a rest
bool is_rest(string s)
{
    if (strlen(s) == 0){
        return true;
    } else {
        return false;
    }
}
