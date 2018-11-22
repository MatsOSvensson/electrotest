#include "power.h"

float calc_power_r(float volt, float resistance){


    if(resistance <= 0 ) {
        return -1;
    }
    if(volt <= 0) {
        return -2;
    } 
    float power = (volt * volt) / resistance;
    return power;
};

float calc_power_i(float volt, float current){

    // P = U * I  (Spänning gånger strömmen)

    if(current <= 0 ) {
        return -1;
    }
    if(volt <= 0) {
        return -2;
    }
    float power = volt * current;
    return power;
};

