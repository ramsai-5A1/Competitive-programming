#include "bits/stdc++.h"
using namespace std;
 
#define endl "\n"
#define tab "\t"
#define int long long
#define fastio ios_base::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL)
#define F first
#define S second
#define pi pair<int, int>
#define maxpq priority_queue<int>
#define minpq priority_queue<int, vector<int>, greater<int>>
#define inf (int) (1e18)
#define vi vector<int>
#define vpi vector<pi>
#define sz(v) (int)v.size()
#define for0(i, n) for(int i = 0; i < n; i++)
#define pb emplace_back
#define prec(n) fixed<<setprecision(n)
#define debug(x) cout << #x << ": " << x << endl
 
 
const int mod = (int)(1e9 + 7);
const int MAXN =  (int)((1e5) + 100);
int max(int a, int b) { if(a > b) return a; else return b;}
int min(int a, int b) { if(a > b) return b; else return a;}
int gcd(int a, int b) { if(a == 0) return b; return gcd(b%a, a);}
const int dx[4] = { 0, -1, 0, 1};
const int dy[4] = { -1, 0, 1, 0};
const int N = (int)(5 * 1e5 + 10);
vector<int> adj[N];
 
void constructor()
{
	fastio;
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
 
}
 
//-----------------------------------------------------------------------------------
 
int up[N][20];
int level[N];
 
 
void dfs(int src, int par, int ht)
{
	level[src] = ht;
	for(int neigh: adj[src])
	{
		if(neigh != par)
			dfs(neigh, src, ht + 1);
	}
}
 
 
void binary_lifting(int src, int par)
{
	up[src][0] = par;
	for(int i = 1; i < 20; i++)
	{
		if(up[src][i - 1] != -1)
			up[src][i] = up[up[src][i - 1]][i - 1];
		else
			up[src][i] = -1;
	}
 
	for(int neigh: adj[src])
	{
		if(neigh != par)
			binary_lifting(neigh, src);
	}
}
 
 
int up_lift(int node, int k)
{
	for(int i = 19; i >= 0; i--)
	{
		if(node == -1 || k == 0)
			break;
 
		if(k >= (1 << i))
		{
			k -= (1 << i);
			node = up[node][i];
		}
	}
 
	return node;
}
 
 
 
int LCA(int a, int b)
{
	if(level[a] < level[b])
		swap(a, b);
 
 
	a = up_lift(a, level[a] - level[b]);
	if(a == b)
		return a;
 
	for(int i = 19; i >= 0; i--)
	{
		if(up[a][i] != up[b][i])
		{
			a = up[a][i];
			b = up[b][i];
		}
	}
 
	return up[a][0];
}
 
 
 
void runtestcase()
{
    int n, q, a, b, x;
    cin >> n >> q;
    for(int i = 2; i <= n; i++)
    {
    	cin >> x;
    	adj[x].pb(i);
    	adj[i].pb(x);
    }
 
 
    dfs(1, -1, 0);
    binary_lifting(1, -1);
 
    while(q--)
    {
    	cin >> a >> b;
    	cout << LCA(a, b) << endl;
    }
}
 
 
 
signed main(){
    
    constructor();
    int tc=1;
    //cin >> tc;
    while(tc--)
        runtestcase();
    return 0;
}
