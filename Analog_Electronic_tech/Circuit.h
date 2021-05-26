//
// Created by z on 5/25/21.
//

#ifndef ANALOG_ELECTRONIC_TECH_CIRCUIT_H
#define ANALOG_ELECTRONIC_TECH_CIRCUIT_H
#include "pch.h"
#include "Element.h"
#include "Matrix.h"

using std::vector;
typedef vector<Element> Ele_List;

class Circuit {
private:
    Ele_List *List = new Ele_List;
    Matrix *A = new Matrix(1, 1);
    Matrix *b = new Matrix(1, 1);
    Matrix *x = new Matrix(1, 1);
    int Amount_of_Nodes = 0;
public:
    Circuit();
    void add_To_List(Element e);
    void sort_Elements();
    void generate_Nodes();
    void build_A_and_b();



};


#endif //ANALOG_ELECTRONIC_TECH_CIRCUIT_H
