//
// Created by z on 5/25/21.
//

#ifndef ANALOG_ELECTRONIC_TECH_ELEMENT_H
#define ANALOG_ELECTRONIC_TECH_ELEMENT_H
#include "pch.h"
typedef std::pair<int, int>pin;

class Element {         // 電路元件
private:                // 電源視爲理想電源，故R爲0；未賦值時初始值爲-1
    int ID;             // 導線R爲0，V_pin1 == V_pin2
    int Type;           //
    double V_pin1;      // Type:
    double V_pin2;      //      導線 --- 0
    double I_1to2;      //      電阻 --- 1
    double R;           //      電壓源 --- 2
    pin pin1;           //      電流源 --- 3
    pin pin2;           //
    int Node_Num1 = 0;  // 開關這種東西，你就寫成“這裏有一根導線”和“這裏沒有這樣一根導線”吧...
    int Node_Num2 = 0;  // Node_Num1 對應於 pin1，Node_Num2 類似
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
    int get_Node_Num1() const;
    int get_Node_Num2() const;
    void modify_V_pin1 (double in);                                             //修改值
    void modify_V_pin2 (double in);
    void modify_I_1to2 (double in);
    void modify_Node_1 (int in);
    void modify_Node_2 (int in);
};


#endif //ANALOG_ELECTRONIC_TECH_ELEMENT_H
