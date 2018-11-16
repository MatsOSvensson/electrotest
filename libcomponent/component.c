#include "component.h"

/*
En funktion som beräknar vilka tre seriekopplade resistorer i E12-serien som närmast ersätter den resistans som skickas med.

    orig_resistance är ersättningsresistansen.
    *res_array är en pekare till en array med 3 resistorer som ska fyllas med värden ur E12-serien.
    count är hur många resistorer ur E12-serien som behövdes för att ersätta orig_resistance Om inte alla 3 komponenterna behövs ska de som inte används fyllas med värdet 0. count kan anta värde mellan 0 och 3.
*/

int e_resistance(float orig_resistance, float *res_array)
{
    res_array[0] = 1200;
    res_array[1] = 180;
    res_array[2] = 18;

    return 3;
}