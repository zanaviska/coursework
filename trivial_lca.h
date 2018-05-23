#include <vector>
#include <iostream>

using namespace std;

class trivialLCA
{
    vector<vector<int>> way;
    vector<int> perent;
    vector<int> high;
    int root;
public:
    trivialLCA():
        root(0)
    {};
    void push(int u, int v);
    void build(int new_root);
    int get_lca(int u, int v);
};
