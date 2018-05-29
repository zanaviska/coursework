#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class sqrtDecomposition
{
    vector<pair<int, int>> arr;
    vector<pair<int, int>> sqrt_arr;
    vector<int> first_inception;
    int sqrt_len;
public:
    build(vector<pair<int, int>> a, vector<int> first_inc)
    {
        first_inception = first_inc;
        arr = a;
        sqrt_len = sqrt((int)a.size());
        sqrt_arr.resize(sqrt_len);
        for(int i = 0; i < sqrt_len; i++)
        {
            sqrt_arr[i] = {2e9, 2e9};
            for(int j = 0; i*sqrt_len+j < (int)a.size() && j < sqrt_len; j++)
                sqrt_arr[i] = min(sqrt_arr[i], arr[i]);
        }
        for(auto i:a)
            cerr << i.first << ' ' << i.second << '\n';
        for(auto i:first_inc)
            cerr << i << ' ';
        cerr << '\n';
        cerr << sqrt_len;
        cerr << '\n';
        for(auto i:sqrt_arr)
            cerr << i.second << ' ';
        cerr << '\n';
    }
    int get_min(int u, int v)
    {
        cerr << "\n\n\n\n\n\n\n";
        pair<int, int> ans = {2e9, 2e9};
        if(first_inception[u] > first_inception[v])
            swap(u, v);
        int pos = first_inception[u]/sqrt_len + (first_inception[u]%sqrt_len != 0);
        for(int i = first_inception[u]; i%sqrt_len != 0 && i < (int)arr.size(); i++)
            cerr << i << ' ',
            ans = min(ans, arr[i]);
        for(int i = pos; (i+1)*sqrt_len <= first_inception[v]; i++, pos++)
            cerr << '(' << pos*sqrt_len << ' ' << (i+1)*sqrt_len << ") ",
            ans = min(ans, sqrt_arr[i]);
        for(int i = pos*sqrt_len; i < first_inception[v]; i++)
            cerr << i << ' ',
            ans = min(ans, arr[i]);
        return ans.second;
    }
};
