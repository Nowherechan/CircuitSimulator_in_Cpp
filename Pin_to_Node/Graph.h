//
// Created by z on 6/2/21.
//

#ifndef PIN_TO_NODE_GRAPH_H
#define PIN_TO_NODE_GRAPH_H
#include "pch.h"
#include "Wire.h"
using std::vector;

bool cmp_node(Wire a, Wire b) {
    return a.get_node_num() < b.get_node_num();
};

class Graph {
private:
    vector<Wire> w_list;
    int node_amount;
public:
    Graph();

    void dfs(Wire in);             // 用來尋找 node
    void match_nodes();     // 給每個 Wire 匹配一個 node
};


#endif //PIN_TO_NODE_GRAPH_H
