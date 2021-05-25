//
// Created by z on 5/25/21.
//

#include "Element.h"
using std::endl;
using std::cout;
using std::istream;
const double EPS = 1e-10;

Element::Element(int id, int type, double v_pin1, double v_pin2, double i_1to2,
                 double r, int p1_x, int p1_y, int p2_x, int p2_y)
{
    ID = id;
    Type = type;
    V_pin1 = v_pin1;
    V_pin2 = v_pin2;
    I_1to2 = i_1to2;
    R = r;
    pin1.first = p1_x;
    pin1.second = p1_y;
    pin2.first = p2_x;
    pin2.second = p2_y;
}

int Element::get_ID() const { return ID; }

int Element::get_Type() const { return Type; }

pin Element::get_pin1() { return pin1; }

pin Element::get_pin2() { return pin2; }

double Element::get_V_pin1() const { return V_pin1; }

double Element::get_V_pin2() const { return V_pin2; }

double Element::get_I_1to2() const { return I_1to2; }

double Element::get_R() const { return R; }

void Element::modify_I_1to2(double in) { I_1to2 = in; }

void Element::modify_V_pin1(double in) { V_pin1 = in; }

void Element::modify_V_pin2(double in) { V_pin2 = in; }

