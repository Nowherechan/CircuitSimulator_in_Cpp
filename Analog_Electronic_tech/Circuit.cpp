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
    A->insert_num(e.get_Node_Num1(), e.get_Node_Num2(), (-1/e.get_R()));
    A->insert_num(e.get_Node_Num2(), e.get_Node_Num1(), (-1/e.get_R()));
    A->insert_num(e.get_Node_Num1(), e.get_Node_Num1(), (1/e.get_R()));
    A->insert_num(e.get_Node_Num2(), e.get_Node_Num2(), (1/e.get_R()));
}

void Circuit::add_I(Element e)
{
    b->insert_num(e.get_Node_Num1(), 1, (0 - e.get_I_1to2()));
    b->insert_num(e.get_Node_Num2(), 1, e.get_I_1to2());
}

void Circuit::add_V(Element e)
{

}

void Circuit::build_A_and_b()
{
    for (int i = 0; List[i].get_Type() != 0; i++) {
        if (List[i].get_Type() == 0) continue;
        else {

        }
    }
}

void Circuit::solve()
{

}

Ele_List* Circuit::get_List()
{

}