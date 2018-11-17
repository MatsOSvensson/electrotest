#include <stdlib.h>
#include <stdio.h>
#include "component.h"

int resistance_array_size = 3;

int main(int argc, char const *argv[])
{
    float *components = malloc(resistance_array_size * sizeof(float));
    float replaceable = 1398;

    int count = e_resistance(replaceable, components);
    
    printf("Ersättningsresistanser i E12-serien kopplade i serie:\n");
    
    for (int i = 0; i < count; i++)
    {
        printf("motstånd %i: %.1f\n", i + 1, components[i]);
    }

    free(components);

    return 0;
}
