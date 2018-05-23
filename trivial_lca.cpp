#include "trivial_lca.h"
#include <queue>

typedef struct{int first, second, third;} triple;

void trivialLCA::push(int u, int v)
{
    while(way.size() <= max(u, v))
        way.push_back({}),
        perent.push_back(0),
        high.push_back(0);
    way[u].push_back(v);
    way[v].push_back(u);
}

void trivialLCA::build(int new_root)
{
    root = new_root;
    queue<triple> q;
    q.push({new_root, -1, 0});
    while(!q.empty())
    {
        int now = q.front().first;
        int pred = q.front().second;
        int h = q.front().third;
        q.pop();
        high[now] = h;
        perent[now] = pred;
        for(auto to:way[now])
            if(to != pred)
                q.push({to, now, h+1});
    }
}

int trivialLCA::get_lca(int u, int v)
{
    while(u != v)
        if(high[u] > high[v])
            u = perent[u];
        else
            v = perent[v];
    return u;
}
