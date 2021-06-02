//
// Created by z on 6/2/21.
//

#include "Wire.h"
#include "pch.h"

Wire::Wire(int pin1_x, int pin1_y, int pin2_x, int pin2_y)
{
    pin1.x = pin1_x;
    pin1.y = pin1_y;
    pin2.x = pin2_x;
    pin2.y = pin2_y;
    status = false;
    node_num = -1;
}

Pin Wire::get_pin1() { return pin1; }

Pin Wire::get_pin2() { return pin2; }

bool Wire::get_status() const { return status; }

int Wire::get_node_num() const { return node_num; }

void Wire::change_status(bool in) { status = in; }

void Wire::change_node_num(int in) { node_num = in; }

