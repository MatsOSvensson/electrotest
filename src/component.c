#include <stdlib.h>
#include <stdio.h>
#include <string.h>
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
    // fill array with zero's
    memset(res_array, 0, 3 * sizeof(float));

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
    int e12_array[number_e12_res];
    int decade_array[number_of_decades];

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
        //printf("d:%d\n", d);

        // iterate over the e12 resistances, from low to high
        for (size_t e = 0; e < number_e12_res; e++)
        {
            //printf("e:%d\n", e);

            //  ...and multiply the value with decade value
            int e12 = e12_array[e] * decade_array[d];

            //printf("res_value:%d\n", e12);

            if (e12 > orig_resistance)
            {
                // Hey!, current e12 is higher than original resistance...
                //printf("found :%d\n", previous_value);

                // ...return the previous value wich was lower
                return previous_value;
            }

            // update the previous value for the next iteration
            previous_value = e12;
        }
    }

    return 0;
}