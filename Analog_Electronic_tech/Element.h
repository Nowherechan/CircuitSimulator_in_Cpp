//
// Created by z on 5/25/21.
//

#ifndef ANALOG_ELECTRONIC_TECH_ELEMENT_H
#define ANALOG_ELECTRONIC_TECH_ELEMENT_H
#include "pch.h"
typedef std::pair<int, int>pin;

class Element {         // 電路元件
private:                // 電源視爲理想電源，故R爲0；未賦值時初始值爲-1
    int ID;
    int Type;
    double V_pin1;
    double V_pin2;
    double I_1to2;
    double R;
    pin pin1;
    pin pin2;
public:
    Element (int ID, int Type, double V_pin1, double V_pin2,
             double I_1to2, double R, int p1_x, int p1_y, int p2_x, int p2_y);  //構造, (x, y)表示坐標
    pin get_pin1();                                                             //返回成員變量
    pin get_pin2();
    double get_V_pin1() const;
    double get_V_pin2() const;
    double get_I_1to2() const;
    double get_R() const;
    int get_Type() const;
    int get_ID() const;
    void modify_V_pin1 (double in);                                             //修改值
    void modify_V_pin2 (double in);
    void modify_I_1to2 (double in);
};


#endif //ANALOG_ELECTRONIC_TECH_ELEMENT_H
