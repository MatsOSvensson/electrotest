#include <stdio.h>
#include <stdlib.h>
#include "component.h"

int main(int argc, char const *argv[])
{
    float *components = (float *)malloc(3 * sizeof(float));
    float replaceable = 1398;

    int count = e_resistance(1382, components);

    for (size_t i = 0; i < count; i++)
    {
        printf("%.1f\n", components[i]);
    }

    free(components);

    return 0;
}
