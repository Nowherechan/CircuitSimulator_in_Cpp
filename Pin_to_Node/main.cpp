#include "pch.h"
#include "G_Wire.h"
#include "Graph.h"
#include "Matrix.h"

int main() {
    std::cout << "Hello, World!" << std::endl;

    Graph *g = new Graph();
    g->build_m(10,10);
    g->get_m()->Show();
    G_Wire a1(1,1,1,2);
    G_Wire a2(1,2,1,3);
    G_Wire a3(2,1,1,3);
    G_Wire b1(6,1,6,2);
    G_Wire b2(6,1,7,1);
    G_Wire b3(9,2,6,1);
    g->add_wire(a1);
    g->add_wire(a2);
    g->add_wire(a3);
    g->add_wire(b1);
    g->add_wire(b2);
    g->add_wire(b3);
    g->sync_it();
    g->get_m()->Show();
    g->change_level(9,2,1);
    g->change_level(1,3,1);
    g->sync_it();
    g->get_m()->Show();

    return 0;
}
