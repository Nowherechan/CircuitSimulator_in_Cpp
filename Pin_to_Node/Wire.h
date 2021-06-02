//
// Created by z on 6/2/21.
//

#ifndef PIN_TO_NODE_WIRE_H
#define PIN_TO_NODE_WIRE_H

typedef struct {    //端點 Pin, 有坐標x, y
    int x;
    int y;
}Pin;

class Wire {
private:
    Pin pin1;
    Pin pin2;
    bool status;
public:
    Wire(int pin1_x, int pin1_y, int pin2_x, int pin2_y);
    Pin get_pin1();
    Pin get_pin2();
    bool get_status();
};


#endif //PIN_TO_NODE_WIRE_H
