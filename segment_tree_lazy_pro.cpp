#include "bits/stdc++.h"
using namespace std;

const int N = (int)(1e5 + 1);
int tree[4 * N + 1], lazy[4 * N + 1];



void buildTree(int index, int start, int end, int arr[])
{
    if(start == end)
    {
        tree[index] = arr[start];
        return;
    }
    
    int mid = start + ((end - start) >> 1);
    buildTree(2 * index, start, mid, arr);
    buildTree(2 * index + 1, mid + 1, end, arr);
    tree[index] = tree[2 * index] + tree[2 * index + 1];
}


int query(int index, int start, int end, int qs, int qe)
{
    if(lazy[index] != 0)
    {
        int temp = lazy[index];
        lazy[index] = 0;
        
        tree[index] += (temp * (end - start + 1));
        
        if(start != end)
        {
            lazy[2 * index] += temp;
            lazy[2 * index + 1] += temp;
        }
    }
    
    if(end < qs || qe < start)
        return 0;
        
    else if(qs <= start && end <= qe)
        return tree[index];
        
    int mid = start + ((end - start) >> 1);
    int left = query(2 * index, start, mid, qs, qe);
    int right = query(2 * index + 1, mid + 1, end, qs, qe);
    
    return left + right;
}


void update(int index, int start, int end, int qs, int qe, int val)
{
    if(lazy[index] != 0)
    {
        int temp = lazy[index];
        lazy[index] = 0;
        tree[index] += (val * (end - start + 1));
        
        if(start != end)
        {
            lazy[2 * index] += val;
            lazy[2 * index + 1] += val;
        }
    }
    
    if(end < qs || qe < start)
        return;
        
    else if(qs <= start && end <= qe)
    {
        int curr = val * (end - start + 1);
        tree[index] += curr;
        
        if(start != end)
        {
            lazy[2 * index] += val;
            lazy[2 * index + 1] += val;
        }
        return;
    }
    
    int mid = start + ((end - start) >> 1);
    update(2 * index, start, mid, qs, qe, val);
    update(2 * index + 1, mid + 1, end, qs, qe, val);
    
    tree[index] = tree[2 * index] + tree[2 * index + 1];
}


signed main()
{
    int arr[] = {-1, 2, 1, 0, 4, 3, -2, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    buildTree(1, 0, n - 1, arr);
    
    int q;
    cin >> q;
    while(q--)
    {
        int op, l, r, val;
        cin >> op;
        if(op == 1)
        {
            cin >> l >> r;
            cout << query(1, 0, n - 1, l, r) << endl;
        }
        else
        {
            cin >> l >> r >> val;
            update(1, 0, n - 1, l, r, val);
        }
    }
    
    
    return 0;
}
