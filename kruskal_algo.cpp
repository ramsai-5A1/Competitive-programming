#include "bits/stdc++.h"
using namespace std;
#define endl "\n"
#define tab "\t"
#define sp " "
#define int long long
#define fastio ios_base::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL)

void constructor()
{
    fastio;
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

}

//----------------------------------> MAIN CODE <--------------------------------------------------

class box
{
public:
    int src, dest, wt;
    box(int _src, int _dest, int _wt)
    {
        src = _src;
        dest = _dest;
        wt = _wt;
    }
};


class cmp
{
public:
    bool operator()(box a, box b)
    {
        return a.wt > b.wt;
    }
};


int getparent(int u, vector<int> &parent)
{
    while(parent[u] != u)
        u = parent[u];
    return u;
}



bool is_cycle(int u, int v, vector<int> &parent, vector<int> &sze)
{
    int par_u = getparent(u, parent);
    int par_v = getparent(v, parent);

    if(par_u == par_v)
        return true;

    if(sze[par_u] > sze[par_v])
    {
        sze[par_u] += sze[par_v];
        sze[par_v] = 0;
        parent[par_v] = par_u;
    }
    else
    {
        sze[par_v] += sze[par_u];
        sze[par_u] = 0;
        parent[par_u] = par_v;
    }
    return false;
}


void runtestcase()
{
    int n, m;
    cin >> n >> m;
    priority_queue<box, vector<box>, cmp> pq;

    for(int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        pq.push(box(a, b, c));
    }

    int lim = n - 1;
    vector<int> parent(n + 1);
    vector<int> sze(n + 1, 1);

    for(int i = 0; i <= n; i++)
        parent[i] = i;

    int ans = 0;

    while(lim > 0 && pq.size() > 0)
    {
        box curr = pq.top();
        pq.pop();

        if(is_cycle(curr.src, curr.dest, parent, sze) == false)
        {
            lim--;
            ans += curr.wt;
        }
    }

    if(lim > 0)
        cout << "IMPOSSIBLE";
    else
        cout << ans << endl;
}



signed main(){
    
    constructor();
    int tc=1;
    //cin >> tc;
    while(tc--)
        runtestcase();
    return 0;
}
