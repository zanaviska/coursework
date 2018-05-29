#include <vector>
#include <iostream>

using namespace std;

class binaryLCA
{
    vector<vector<int>> way;
    vector<vector<int>> up;
    vector<int> tin;
    vector<int> tout;
    int root;
    int timer = 0;
    int ln;
    bool upper(int higer, int toler);
    void dfs(int now, int pred);
public:
    binaryLCA(int new_root):
        root(new_root)
    {};
    binaryLCA():
        root(1)
    {};
    void push(int u, int v);
    void build();
    int get_lca(int u, int v);
};
