#include <vector>

using namespace std;

class tarjanLCA
{
    vector<vector<int>> way;
    vector<vector<pair<int, int>>> request;
    vector<bool> vis;
    vector<int> dsu;
    vector<int> ancestor;
    int root;
    int request_cnt = 0;

    int dsu_get(int ver)
    {
        return ver == dsu[ver] ? ver : dsu[ver] = dsu_get(dsu[ver]);
    }
    void dsu_unite(int ver1, int ver2, int new_ancestor);
    void dfs(int, vector<int>&);
public:
    tarjanLCA():
        root(1)
    {};
    void push_edge(int u, int v);
    void push_request(int u, int v);
    vector<int> get_lca(int new_root);
};
