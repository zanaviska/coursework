#include "trivial_lca.h"
#include "my_own_lca.h"
#include "all_way_algorithm.h"

int main()
{
    //trivialLCA lca;
    structLCA lca;
    lca.push(1, 2);
    lca.push(2, 4);
    lca.push(2, 5);
    lca.push(5, 7);
    lca.push(5, 8);
    lca.push(1, 3);
    lca.push(3, 6);
    lca.push(3, 9);
    lca.build();
    cout << lca.get_lca(7, 9) << '\n';//1
    cout << lca.get_lca(5, 1) << '\n';//1
    cout << lca.get_lca(4, 8) << '\n';//2
    cout << lca.get_lca(3, 2) << '\n';//1
}
