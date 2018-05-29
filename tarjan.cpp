#include "tarjan.h"
#include <algorithm>

using namespace std;

void tarjanLCA::push_edge(int u, int v)
{
    while((int)way.size() <= max(u, v))
        way.push_back({}),
        request.push_back({}),
        dsu.push_back(0),
        ancestor.push_back(0),
        vis.push_back(0);
    way[u].push_back(v);
    way[v].push_back(u);
}

void tarjanLCA::push_request(int u, int v)
{
    request[u].push_back({v, request_cnt});
    request[v].push_back({u, request_cnt});
    request_cnt++;
}

void tarjanLCA::dsu_unite(int ver1, int ver2, int new_ancestor)
{
    ver1 = dsu_get(ver1);
    ver2 = dsu_get(ver2);
	if (rand()&1)
        swap(ver1, ver2);
	dsu[ver1] = ver2;
	ancestor[ver2] = new_ancestor;
}

void tarjanLCA::dfs(int now, vector<int> &res)
{
    vis[now] = 1;
    dsu[now] = now;
    ancestor[now] = now;
    for(auto to:way[now])
        if(!vis[to])
        {
            dfs(to, res);
            dsu_unite(now, to, now);
        }
    for(auto i:request[now])
        if(vis[i.first])
            res[i.second] = ancestor[dsu_get(i.first)];
}

vector<int> tarjanLCA::get_lca(int new_root)
{
    vector<int> res(request_cnt, 0);
    dfs(new_root, res);
    return res;
}
