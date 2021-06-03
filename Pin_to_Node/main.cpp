#include <iostream>
#include "Graph.h"
#include "pch.h"


int main() {
    std::cout << "Hello, World!" << std::endl;

    Graph g;
    g.build_m(x坐標有多少, y坐標有多少);

    G_Wire xx(1,1,3,3);
    // ... 新建很多導線
    g.add_wire(xx);
    // ... 添加這些導線
    g.get_m()->insert_num(要修改的y坐標, x, 1);
    // 事先矩陣中元素都被初始化爲0, 修改爲1
    g.sync_it();
    // 矩陣已經更新完成
    // 通過以下方式讀取
    g.get_m()->get_num(y, x);





    return 0;
}
