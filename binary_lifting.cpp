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
 
 
int findans(int node, int k)
{
	if(node == -1 || k == 0)
		return node;
 
	for(int i = 19; i >= 0; i--)
	{
		if(k >= (1 << i))
			return findans(up[node][i], k - (1 << i));
	}
 
	return 0;
}
 
void runtestcase()
{
    int n, q, x, node, k;
    cin >> n >> q;
    for(int i = 2; i <= n; i++)
    {
    	cin >> x;
    	adj[x].pb(i);
    	adj[i].pb(x);
    }
 
    binary_lifting(1, -1);
 
    while(q--)
    {
    	cin >> node >> k;
    	cout << findans(node, k) << endl;
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
