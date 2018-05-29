#include "binary_lca.h"

bool binaryLCA::upper(int higer, int toler)
{
    return tin[toler] <= tin[higer] && tout[higer] <= tout[toler];
}

void binaryLCA::push(int u, int v)
{
    while((int)way.size() <= max(u, v))
        way.push_back({}),
        up.push_back({}),
        tin.push_back(0),
        tout.push_back(0);
    way[u].push_back(v);
    way[v].push_back(u);
}

void binaryLCA::dfs(int now, int pred)
{
    tin[now] = ++timer;
    up[now][0] = pred;
    for(int i = 1; i < ln; i++)
        up[now][i] = up[up[now][i-1]][i-1];
    for(auto to:way[now])
        if(to != pred)
            dfs(to, now);
}

void binaryLCA::build()
{
    ln = 1;
    while((1<<ln) < (int)way.size())
        ln++;
    for(auto &i:up)
        i.resize(ln+1);
    dfs(root, root);
}

int binaryLCA::get_lca(int u, int v)
{
    if(upper(u, v)) return u;
    if(upper(v, u)) return v;
    for(int i = ln; i >= 0; i--)
        if(!upper(up[u][i], v))
            u = up[u][i];
    return up[u][0];
}
