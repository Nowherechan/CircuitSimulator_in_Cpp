//
// Created by z on 6/2/21.
//

#include "Graph.h"

Graph::Graph() { node_amount = 0; }

bool equal_pins(Pin a, Pin b)
{
    return a.x == b.x && a.y == b.y;
}

void Graph::dfs(Wire in)
{
    in.change_node_num(node_amount);
    for (int i = 0; i < w_list.size(); i++) {
        if (w_list[i].get_node_num() != -1) continue;
        else {
            if (      equal_pins(in.get_pin1(), w_list[i].get_pin1() )
                   || equal_pins(in.get_pin2(), w_list[i].get_pin2() )
                   || equal_pins(in.get_pin1(), w_list[i].get_pin2() )
                   || equal_pins(in.get_pin2(), w_list[i].get_pin1() ) )
                dfs(w_list[i]);
        }
    }
}

void Graph::match_nodes()
{
    for (int i = 0; i < w_list.size(); i++) {
        if (w_list[i].get_node_num() != -1) continue;
        else {
            dfs(w_list[i]);
            node_amount++;
        }
    }
}
