#include <vector>

using namespace std;

class binTree
{
    vector<pair<int, int>> a;
    vector<int> tree;
    vector<int> first_inception;
    void making(int v, int l, int r)
    {
        if(l == r)
        {
            tree[v] = a[l].second;
            return;
        }
        int mid = (l+r)/2;
        making(2*v, l, mid);
        making(2*v+1, mid+1, r);
        tree[v] = min(tree[2*v], tree[2*v+1]);
    }
    int minimum(int v, int l, int r, int x, int y)
    {
        if(l == x && r == y)
            return tree[v];
        int mid = (l+r)/2;
        if(y <= mid)
            return minimum(2*v, l, mid, x, y);
        if(mid < x)
            return minimum(2*v+1, mid+1, r, x, y);
        return min(minimum(2*v, l, mid, x, mid), minimum(2*v+1, mid+1, r, mid+1, y));
    }
public:
    build(vector<pair<int, int>> arr, vector<int> first_inc)
    {
        a = arr;
        first_inception = first_inc;
        tree.resize(4*arr.size());
        making(1, 0, arr.size()-1);
    }
    int get_min(int u, int v)
    {
        if(first_inception[u] > first_inception[v])
            swap(u, v);
        return minimum(1, 0, a.size()-1, first_inception[u], first_inception[v]);
    }
};
