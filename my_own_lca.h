#include <vector>

using namespace std;

class ownLCA
{
    vector<vector<int>> way;
    vector<int> perent;
    vector<int> sqrt_perent;
    vector<int> high;
    int root;
public:
    ownLCA():
        root(1)
    {};
    void push(int u, int v);
    void build(int new_root);
    int get_lca(int u, int v);
};
