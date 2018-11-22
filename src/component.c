/*
    Mats Svensson
*/
#include <stdlib.h>
#include <stdio.h>
#include "component.h"

int get_nearest_e12_resistance(float org_res);
const int number_e12_res = 12;
const int number_of_decades = 6;

/*
    En funktion som beräknar vilka tre seriekopplade resistorer i E12-serien som närmast ersätter den resistans som skickas med.

    orig_resistance är ersättningsresistansen.
    *res_array är en pekare till en array med 3 resistorer som ska fyllas med värden ur E12-serien.
    count är hur många resistorer ur E12-serien som behövdes för att ersätta orig_resistance,
    Om inte alla 3 komponenterna behövs ska de som inte används fyllas med värdet 0. 
    count kan anta värde mellan 0 och 3.
*/
int e_resistance(float orig_resistance, float *res_array)
{
    // number of resulting resistances
    int count = 0;

    //float the_rest = orig_resistance;
    int new_value = -1;

    do
    {
        // try to get the nearest resitor from E12 table
        new_value = get_nearest_e12_resistance(orig_resistance);

        if (new_value > 0)
        {
            // put the matched e12 resitance in the return array
            res_array[count++] = (float)new_value;

            // calculate how much is left to match from the e12 series
            orig_resistance = orig_resistance - new_value;
        }

    } while (new_value > 0);

    return count;
}

/// It reutrns the nearest resistance from the e12 series of resitances,
// 0 if to low
int get_nearest_e12_resistance(float orig_resistance)
{
    // E12 series of resitances
    int e12_array[number_e12_res];
    e12_array[0] = 10;
    e12_array[1] = 12;
    e12_array[2] = 15;
    e12_array[3] = 18;
    e12_array[4] = 22;
    e12_array[5] = 27;
    e12_array[6] = 33;
    e12_array[7] = 39;
    e12_array[8] = 47;
    e12_array[9] = 56;
    e12_array[10] = 68;
    e12_array[11] = 82;

    // Arrat to multiply the resistances up to 8,2 MOhm
    int decade_array[number_of_decades];
    decade_array[0] = 1;
    decade_array[1] = 10;
    decade_array[2] = 100;
    decade_array[3] = 1000;
    decade_array[4] = 10000;
    decade_array[5] = 100000;

    int previous_value = 0;

    // iterate over the decades, from low to high
    for (size_t d = 0; d < number_of_decades; d++)
    {
        // iterate over the e12 resistances, from low to high
        for (size_t e = 0; e < number_e12_res; e++)
        {
            //  ...and multiply the value with decade value
            int e12 = e12_array[e] * decade_array[d];

            if (e12 > orig_resistance)
            {
                // Hey!, current e12 is higher than input resistance...

                if(e12 == e12_array[0])
                {
                    // The input value is lower than the lowest in E12 series
                    return 0;
                }

                // ...return the previous value which was lower
                return previous_value;
            }

            // update the previous value for the next iteration
            previous_value = e12;
        }
    }

    return 0;
}