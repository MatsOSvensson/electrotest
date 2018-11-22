#ifndef POWER_H
#define POWER_H

// Calculate power using P = U^2 / R
// Arguments: 
// volt must be > 0
// resistance must be > 0
// Function accepting any resistor value in E12?
// Return value: 
// -1 if resistance is <= 0
// -2 if voltage is <= 0
// power in watt
float calc_power_r(float volt, float resistance);

float calc_power_i(float volt, float current);

#endif