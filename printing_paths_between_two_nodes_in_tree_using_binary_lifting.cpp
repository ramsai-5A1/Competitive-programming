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

int timer;
int Start[N], End[N], Flat_arr[2 * N];
int level[N], up[N][20];

void dfs(int src, int par, int ht)
{
	Start[src] = timer;
	Flat_arr[timer] = src;
	level[src] = ht;
	timer++;

	for(int neigh: adj[src])
	{
		if(neigh != par)
			dfs(neigh, src, ht + 1);
	}

	End[src] = timer;
	Flat_arr[timer] = src;
	timer++;
}


void binary_lifting(int src, int par)
{
	up[src][0] = par;

	for(int i = 1; i <= 19; i++)
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

		else if(k >= (1 << i))
		{
			k -= (1 << i);
			node = up[node][i];
		}
	}

	return node;
}



int LCA(int u, int v)
{
	if(level[v] > level[u])
		swap(u, v);

	u = up_lift(u, level[u] - level[v]);
	if(u == v)
		return u;

	for(int i = 19; i >= 0; i--)
	{
		if(up[u][i] != up[v][i])
		{
			u = up[u][i];
			v = up[v][i];
		}
	}

	return up[u][0];
}







void print_path(int u, int v)
{
	if(Start[u] > Start[v])
		swap(u, v);

	int S = Start[u], E = Start[v], lca = LCA(u, v);
	
	unordered_set<int> st;
	unordered_map<int, int> freq;
	if(lca == u)
	{
		for(int i = S; i <= E; i++)
		{
			freq[Flat_arr[i]]++;
			if(freq[Flat_arr[i]] == 1)
				st.insert(Flat_arr[i]);
			else if(freq[Flat_arr[i]] == 2)
				st.erase(Flat_arr[i]);
		}

		for(int i: st)
			cout << i << " --> ";
		cout << endl;
	}
	else
	{
		for(int i = End[u]; i <= E; i++)
		{
			freq[Flat_arr[i]]++;
			if(freq[Flat_arr[i]] == 1)
				st.insert(Flat_arr[i]);
			else if(freq[Flat_arr[i]] == 2)
				st.erase(Flat_arr[i]);
		}
		for(int i: st)
			cout << i << " --> ";
		cout << lca;
		cout << endl;
	}
}



void runtestcase()
{
    int n, u, v, q;
    cin >> n;

    for0(i, n - 1)
    {
    	cin >> u >> v;
    	adj[u].pb(v);
    }

    timer = 1;
    dfs(1, -1, 0);
    binary_lifting(1, -1);

    cin >> q;
    for0(i, q)
    {
    	cin >> u >> v;
    	print_path(u, v);
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
