#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "component.h"

void test_value(float input_value);
int resistance_array_size = 3;

int main(int argc, char const *argv[])
{
    float input_value = 0.0;
    test_value(1398);
    test_value(-1);
    test_value(7);
    test_value(10);
    test_value(1000000);
    test_value(8000000);
    test_value(8200000);
    test_value(8090000);
    test_value(8000001);

    return 0;
}


void test_value(float input_value)
{
    float *components = malloc(resistance_array_size * sizeof(float));
    memset(components, 0, resistance_array_size * sizeof(float));
    int count = 0;
    float sum = 0;

    // test 1
    count = e_resistance(input_value, components);
    
    printf("%.01f ger Ersättningsresistanser i E12-serien kopplade i serie:\n", input_value);
    
    for (int i = 0; i < count; i++)
    {
        printf("motstånd %i: %.01f\n", i + 1, components[i]);
        sum = sum + components[i];
    }
    printf("sum = %.01f\n", sum);
    sum = 0;
    printf("=====\n");

    free(components);
}