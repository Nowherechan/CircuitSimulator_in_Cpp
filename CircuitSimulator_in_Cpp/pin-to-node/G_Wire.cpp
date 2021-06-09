//
// Created by z on 6/2/21.
//

#include "G_Wire.h"
#include "pch.h"

G_Wire::G_Wire(int pin1_x, int pin1_y, int pin2_x, int pin2_y)
{
    pin1.x = pin1_x;
    pin1.y = pin1_y;
    pin2.x = pin2_x;
    pin2.y = pin2_y;
    status = false;
    node_num = -1;
}

Pin G_Wire::get_pin1() { return pin1; }

Pin G_Wire::get_pin2() { return pin2; }

//void G_Wire::set_pin1(Pin new_pin1) {pin1.x = new_pin1.x; pin1.y = new_pin1.y; }

//void G_Wire::set_pin2(Pin new_pin2) {pin2.x = new_pin2.x; pin2.y = new_pin2.y; }

bool G_Wire::get_status() const { return status; }

int G_Wire::get_node_num() const { return node_num; }

void G_Wire::change_status(bool in) { status = in; }

void G_Wire::change_node_num(int in) { node_num = in; }

