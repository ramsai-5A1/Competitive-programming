#include "bits/stdc++.h"
using namespace std;
#define fastio ios_base::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL)
#define int long long

void constructor()
{
	fastio;
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

}

//----------------------------------> MAIN CODE <--------------------------------------------------

void floyd_warshall(vector<vector<int>> &adj, int n)
{
	for(int k = 1; k <= n; k++)
	{
		for(int i = 1; i <= n; i++)
		{
			for(int j = 1; j <= n; j++)
			{
				if(adj[i][k] != LLONG_MAX && adj[k][j] != LLONG_MAX && adj[i][j] > adj[i][k] + adj[k][j])
					adj[i][j] = adj[i][k] + adj[k][j];
			}
		}
	}
}


void runtestcase()
{
    int n, m, q;
    cin >> n >> m >> q;
    vector<vector<int>> adj(n + 1, vector<int>(n + 1, LLONG_MAX));

    for(int i = 1; i <= n; i++)
    	adj[i][i] = 0;

    for(int i = 0; i < m; i++)
    {
    	int a, b, c;
    	cin >> a >> b >> c;

    	if(adj[a][b] > c)
    		adj[a][b] = c;
    	if(adj[b][a] > c)
    		adj[b][a] = c;
    }


    floyd_warshall(adj, n);

    while(q--)
    {
    	int a, b;
    	cin >> a >> b;

    	if(adj[a][b] == LLONG_MAX)
    		cout << "-1\n";
    	else
    		cout << adj[a][b] << "\n";
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
