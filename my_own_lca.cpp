#include "my_own_lca.h"
#include <queue>
#include <algorithm>

typedef struct{int first, second, third;} triple;

void ownLCA::push(int u, int v)
{
    while(way.size() <= max(u, v))
        way.push_back({}),
        perent.push_back(0),
        sqrt_perent.push_back(0),
        high.push_back(0);
    way[u].push_back(v);
    way[v].push_back(u);
}

void ownLCA::build(int new_root)
{
    root = new_root;
    queue<triple> q;
    q.push({new_root, new_root, 0});
    queue<pair<int, int>> sqrt_q;
    while(!q.empty())
    {
        int now = q.front().first;
        int pred = q.front().second;
        int h = q.front().third;
        q.pop();
        high[now] = h;
        perent[now] = pred;
        if(now != root && way[now].size() == 1)
            sqrt_q.push({now, -1});
        for(auto to:way[now])
            if(to != pred)
                q.push({to, now, h+1});
    }
    while(!sqrt_q.empty())
    {
        int now = sqrt_q.front().first;
        int sqrt_pred = sqrt_q.front().second;
        sqrt_q.pop();
        int korin = sqrt(way.size());
        if(sqrt_pred == -1)
        {
            sqrt_pred = now;
            for(int i = 0; i < korin; i++)
                sqrt_pred = perent[sqrt_pred];
        }
        sqrt_perent[now] = sqrt_pred;
        if(now != sqrt_pred)
            sqrt_q.push({perent[now], perent[sqrt_pred]});
    }
}

int ownLCA::get_lca(int u, int v)
{
    if(high[v] > high[u])
        swap(u, v);
    while(high[sqrt_perent[u]] > high[v])
        u = sqrt_perent[u];
    while(high[u] != high[v])
        u = perent[u];
    while(sqrt_perent[u] != sqrt_perent[v])
        u = sqrt_perent[u],
        v = sqrt_perent[v];
    while(u != v)
        u = perent[u],
        v = perent[v];
    return u;
}
