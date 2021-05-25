//
// Created by z on 5/25/21.
//

#ifndef ANALOG_ELECTRONIC_TECH_ELEMENT_H
#define ANALOG_ELECTRONIC_TECH_ELEMENT_H
#include "pch.h"
typedef std::pair<int, int>pin;

class Element {
private:
    int ID;
    int Type;
    double V_pin1;
    double V_pin2;
    double I_1to2;
    double R;
    pin pin1;
    pin pin2;
public:
    
};


#endif //ANALOG_ELECTRONIC_TECH_ELEMENT_H
