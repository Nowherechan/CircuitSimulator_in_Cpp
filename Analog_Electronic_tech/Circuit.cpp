//
// Created by z on 5/25/21.
//

#include "Circuit.h"
#include "pch.h"
using std::endl;
using std::cout;
using std::sort;

bool cmp_Type_sort (Element a, Element b) {
    if (a.get_Type() != b.get_Type())
        return a.get_Type() < b.get_Type();
    else
        return a.get_ID() < b.get_ID();
}

bool cmp_ID_sort (Element a, Element b) {
    return a.get_ID() < b.get_ID();
}

Circuit::Circuit() = default;

void Circuit::add_To_List(Element e) { List.push_back(e); }

void Circuit::ID_sort_Elements()
{
    sort(List.begin(), List.end(), cmp_ID_sort);
}

void Circuit::Type_sort_Elements()
{
    sort(List.begin(), List.end(), cmp_Type_sort);
}

void Circuit::dfs_gen_Nodes(Element e)
{
    e.modify_Node_1(Amount_of_Nodes);
    e.modify_Node_2(Amount_of_Nodes);
    for (int i = 0; List[i].get_Type() == 0; i++) {

        if (List[i].get_pin1() == e.get_pin1() || List[i].get_pin2() == e.get_pin1()
         || List[i].get_pin1() == e.get_pin2() || List[i].get_pin2() == e.get_pin2()) {

            List[i].modify_Node_1(Amount_of_Nodes);
            List[i].modify_Node_1(Amount_of_Nodes);

            dfs_gen_Nodes(List[i]);

        }

    }

    Amount_of_Nodes++;

}

void Circuit::generate_Nodes()                               // Must have been sorted !
{
    for (int i = 0; List[i].get_Type() == 0; i++ ) {         // Initialize the Node_Num
        List[i].modify_Node_1(-1);
        List[i].modify_Node_2(-1);
    }

    for (int i = 0; List[i].get_Type() == 0; i++ ) {
        if (List[i].get_Node_Num1() != -1) continue;
        else dfs_gen_Nodes(List[i]);
    }

}

void Circuit::match_Nodes()
{
    for (int i = 0; List[i].get_Type() != 0; i++) {
        if (List[i].get_Type() == 0) continue;
        else {
            for (int j = 0; List[j].get_Type() == 0; j++ ) {
                if (List[j].get_pin1() == List[i].get_pin1()) {
                    List[i].modify_Node_1(List[j].get_Node_Num1());
                }
                if (List[j].get_pin2() == List[i].get_pin2()) {
                    List[i].modify_Node_2(List[j].get_Node_Num2());
                }
            }
        }
    }
}

void Circuit::add_R(Element e)
{
    if (e.get_Node_Num1() != 0 && e.get_Node_Num2() != 0) {
        A->insert_num(e.get_Node_Num1(), e.get_Node_Num2(),A->get_num(e.get_Node_Num1(), e.get_Node_Num2()) + (-1 / e.get_R()));
        A->insert_num(e.get_Node_Num2(), e.get_Node_Num1(),A->get_num(e.get_Node_Num2(), e.get_Node_Num1()) + (-1 / e.get_R()));
    }
    if (e.get_Node_Num1() != 0)
        A->insert_num(e.get_Node_Num1(), e.get_Node_Num1(), A->get_num(e.get_Node_Num1(), e.get_Node_Num1()) + e.get_R());
    if (e.get_Node_Num2() != 0)
        A->insert_num(e.get_Node_Num2(), e.get_Node_Num2(), A->get_num(e.get_Node_Num2(), e.get_Node_Num2()) + e.get_R());
}

void Circuit::add_I(Element e)
{
    if (e.get_Node_Num1() != 0)
        b->insert_num(e.get_Node_Num1(), 1, (0 - e.get_I_1to2()));
    if (e.get_Node_Num2())
        b->insert_num(e.get_Node_Num2(), 1, e.get_I_1to2());
}

void Circuit::add_V(Element e)//NOT_YET
{
    A->add_Row();
    A->add_Col();
    b->add_Col();
    double V_pin2_upto_pin1 = e.get_V_pin2() - e.get_V_pin1();
    if (e.get_Node_Num2() != 0) {
        A->insert_num(A->get_rows_num(), e.get_Node_Num2(), 1);       // Should the 1 be added ?
        A->insert_num(e.get_Node_Num2(), A->get_cols_num(), -1);
    }
    if (e.get_Node_Num1() != 0) {
        A->insert_num(A->get_rows_num(), e.get_Node_Num1(), -1);
        A->insert_num(e.get_Node_Num1(), A->get_cols_num(), 1);
    }
}

void Circuit::build_A_and_b()
{
    for (int i = 0; i < (int)List.size(); i++) {
        if (List[i].get_Type() == 0) continue;
        else {
            switch (List[i].get_Type()) {
                case 1:
                    add_R(List[i]);
                case 2:
                    add_V(List[i]);
                case 3:
                    add_I(List[i]);
            }
        }
    }
}

void Circuit::modify_W(Element e)
{
    e.modify_V_pin1(x->get_num(e.get_Node_Num1(), 1));
    e.modify_V_pin2(x->get_num(e.get_Node_Num2(), 1));
    e.modify_I_1to2(0);     //-------------------------------------Wait to solve
}

void Circuit::modify_R(Element e)
{
    e.modify_V_pin1(x->get_num(e.get_Node_Num1(), 1));
    e.modify_V_pin2(x->get_num(e.get_Node_Num2(), 1));
    e.modify_I_1to2((e.get_V_pin1() - e.get_V_pin2()) / e.get_R());
}

void Circuit::modify_V_S(Element e)
{
    e.modify_V_pin1(x->get_num(e.get_Node_Num1(), 1));
    e.modify_V_pin2(x->get_num(e.get_Node_Num2(), 1));
    e.modify_I_1to2(0);     //-------------------------------------Wait to solve
}

void Circuit::modify_I_S(Element e)
{
    e.modify_V_pin1(x->get_num(e.get_Node_Num1(), 1));
    e.modify_V_pin2(x->get_num(e.get_Node_Num2(), 1));
}

void Circuit::Solve_and_Modify()
{
    *x = Matrix::Solve(*A, *b);         // Solve
    for (int i = 0; i < (int)List.size(); i++) {
        if (List[i].get_Type() == 0) continue;
        else {
            switch (List[i].get_Type()) {
                case 0:
                    modify_W(List[i]);
                case 1:
                    modify_R(List[i]);
                case 2:
                    modify_V_S(List[i]);
                case 3:
                    modify_I_S(List[i]);
            }
        }
    }
}

Ele_List* Circuit::get_List()
{
    
}