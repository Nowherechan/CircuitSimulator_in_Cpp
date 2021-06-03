//
// Created by z on 6/2/21.
//

#include "Graph.h"
#include "pch.h"
using std::sort;

bool cmp_node(G_Wire a, G_Wire b) {
    return a.get_node_num() < b.get_node_num();
};

Graph::Graph() { node_amount = 0; }

bool equal_pins(Pin a, Pin b)
{
    return a.x == b.x && a.y == b.y;
}

void Graph::dfs(G_Wire &in)
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
    sort(w_list.begin(), w_list.end(), cmp_node);
}

void Graph::power_pins()
{
    for (int i = 0; i < w_list.size(); i++) {
        if (m->get_num(w_list[i].get_pin1().y, w_list[i].get_pin1().x) != 0
        ||  m->get_num(w_list[i].get_pin2().y, w_list[i].get_pin2().x) != 0)
            w_list[i].change_status(1);
    }
    int cnt1 = 0, cnt0 = 0;                                 // cnt0爲node較小側
    for (int i = 0; i < node_amount; i++) {
        cnt0 = cnt1;
        int temp = 0;
        for (; cnt1 < w_list.size(); cnt1++) {
            if (w_list[cnt1].get_node_num() != i) break;
            temp += w_list[cnt1].get_status();
        }
        if (temp) {
            for (int j = cnt0; j < cnt1; j++) {
                w_list[j].change_status(1);
            }
        }
    }

    for (int i = 0; i < w_list.size(); i++) {
        if (w_list[i].get_status()) {                      // 縱坐標對應於矩陣“行號”
            m->insert_num(w_list[i].get_pin1().y, w_list[i].get_pin1().x, 1);
            m->insert_num(w_list[i].get_pin2().y, w_list[i].get_pin2().x, 1);
        }
    }
}

void Graph::build_m(int x_num, int y_num)
{
    m = new Matrix(y_num, x_num);
}

void Graph::add_wire(G_Wire &in)
{
    w_list.push_back(in);
}

void Graph::sync_it()
{
    match_nodes();
    power_pins();
}

Matrix * Graph::get_m()
{
    return m;
}

void Graph::change_level(int x, int y, int in)
{
    m->insert_num(y, x, in);
}

bool Graph::get_level(int x, int y)
{
    return (bool)m->get_num(y, x);
}

void Graph::del_wire(G_Wire &in)
{
    for (int i = 0; i < w_list.size(); i++) {
        if (w_list[i].get_pin1().x == in.get_pin1().x
         && w_list[i].get_pin1().y == in.get_pin1().y
         && w_list[i].get_pin2().x == in.get_pin2().x
         && w_list[i].get_pin2().y == in.get_pin2().y)
            w_list.erase(w_list.begin() + i);
    }
}