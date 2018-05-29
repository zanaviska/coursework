#include "all_way_algorithm.h"

using namespace std;

void structLCA::push(int u, int v)
{
    while((int)way.size() <= max(u, v))
        way.push_back({});
    way[u].push_back(v);
    way[v].push_back(u);
}

void structLCA::dfs(int now, int pred, int high)
{
    first_inception[now] = arr.size();
    arr.push_back({high, now});
    for(auto to:way[now])
        if(to != pred)
        {
            dfs(to, now, high+1);
            arr.push_back({high, now});
        }
}

void structLCA::build()
{
    first_inception.resize(way.size());
    dfs(root, -1, 0);
    find_min.build(arr, first_inception);
}

int structLCA::get_lca(int u, int v)
{
    return find_min.get_min(u, v);
}
