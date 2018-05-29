#include <vector>
#include <iostream>
#include "sqrt_decomposition.h"
#include "tree_of_dis.h"

using namespace std;

class structLCA
{
    vector<vector<int>> way;
    vector<pair<int, int>> arr;
    vector<int> first_inception;
    int root;

    //sqrtDecomposition find_min;//both of this class work, and you can use any of them/// is not work yet
    binTree find_min;//both of this class work, and you can use any of them
    void dfs(int now, int pred, int h);
public:
    structLCA(int new_root):
        root(new_root)
    {};
    structLCA():
        root(1)
    {};
    void push(int u, int v);
    void build();
    int get_lca(int u, int v);
};
