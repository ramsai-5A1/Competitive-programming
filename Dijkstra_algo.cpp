#include "bits/stdc++.h"
using namespace std;
#define int long long
 
void constructor()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
 
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
 
}
 
//----------------------------------> MAIN CODE <--------------------------------------------------
struct box
{
	int node, d;
	box(int node, int d)
	{
		this -> node = node;
		this -> d = d;
	}
};
 
 
class cmp
{
public:
	bool operator()(box a, box b)
	{
		if(a.d != b.d)
			return a.d > b.d;
		return a.node > b.node;
	}
};
 
 
void dijkstra(int dist[], vector<pair<int, int>> adj[], int &n)
{
	
	priority_queue<box, vector<box>, cmp> pq;
	pq.push(box(1, 0));
	
 
	while(pq.size() > 0)
	{
		box curr = pq.top();
		pq.pop();
 
		if(dist[curr.node] != INT_MAX)
			continue;
 
		dist[curr.node] = curr.d;	
 
		for(pair<int, int> neigh: adj[curr.node])
		{
			if(dist[neigh.first] == INT_MAX)
				pq.push(box(neigh.first, curr.d + neigh.second));
		}
	}
}
 
 
void runtestcase()
{
    int n, m, a, b, c;
    cin >> n >> m;
    vector<pair<int, int>> adj[n + 1];
 
    for(int i = 0; i < m; i++)
    {
    	cin >> a >> b >> c;
    	adj[a].push_back({b, c});
    }
 
    int dist[n + 1];
    for(int i = 1; i <= n; i++)
    	dist[i] = INT_MAX;
 
    dijkstra(dist, adj, n);
 
    for(int i = 1; i <= n; i++)
    	cout << dist[i] << " ";
}
 
 
 
signed main(){
    
    constructor();
    int tc=1;
    //cin >> tc;
    while(tc--)
        runtestcase();
    return 0;
}
