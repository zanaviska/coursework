#include <iostream>
#include "tarjan.h"

int main()
{
    //trivialLCA lca;
    //structLCA lca;
    tarjanLCA lca;
    lca.push_edge(1, 2);
    lca.push_edge(2, 4);
    lca.push_edge(2, 5);
    lca.push_edge(5, 7);
    lca.push_edge(5, 8);
    lca.push_edge(1, 3);
    lca.push_edge(3, 6);
    lca.push_edge(3, 9);
    lca.push_request(7, 9);//1
    lca.push_request(5, 1);//2
    lca.push_request(4, 8);//1
    lca.push_request(3, 2);//1
    vector<int> res = lca.get_lca(1);
    for(auto i:res)
        cout << i << '\n';
}
