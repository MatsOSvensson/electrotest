#include <stdio.h>
#include "power.h"

void test_normal() {
    float voltage = 4;
    float resistance = 4;
    float expected = 4;
    float actual = calc_power_r(voltage, resistance);
    if(actual == expected) {
        printf("Test case passed with success!\n");
    } else {
        printf("Test case failed!\n Expected value: %.2f , Actual value: %.2f\n", expected, actual);
    }
}

void test_illegal_volatage() {
    float voltage = 0;
    float resistance = 4;
    float expected = -2;
    float actual = calc_power_r(voltage, resistance);
    if(actual == expected) {
        printf("Test case passed with success!\n");
    } else {
        printf("Test case failed!\n Expected value: %.2f , Actual value: %.2f\n", expected, actual);
    }
}
void test_illegal_resistance() {
    float voltage = 4;
    float resistance = 0;
    float expected = -1;
    float actual = calc_power_r(voltage, resistance);
    if(actual == expected) {
        printf("Test case passed with success!\n");
    } else {
        printf("Test case failed!\n Expected value: %.2f , Actual value: %.2f\n", expected, actual);
    }    
}

void main() {
    test_normal();
    test_illegal_volatage();
    test_illegal_resistance();
}