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
    Ele_List List;
    Matrix *A = new Matrix(1, 1);
    Matrix *b = new Matrix(1, 1);
    Matrix *x = new Matrix(1, 1);
    int Amount_of_Nodes = 0;        // 最終 Node 的數量，在進行有關 Node 的計算中，使用 int i = 0; i < Amount_of_Nodes; ...
public:
    Circuit();
    void add_To_List(Element e);
    void ID_sort_Elements();        // 通過ID排序
    void Type_sort_Elements();      // 通過Type排序
    void dfs_gen_Nodes(Element e);  // 搜索相同Node的導線
    void generate_Nodes();          // Must have been sorted !
    void match_Nodes();             // 爲除導線外的其他元件匹配 Node
    void add_R(Element e);
    void add_I(Element e);
    void add_V(Element e);
    void build_A_and_b();
    void solve();                   // 算出待求數值
    Ele_List* get_List();           // 返回數據

};


#endif //ANALOG_ELECTRONIC_TECH_CIRCUIT_H
