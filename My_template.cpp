#include "bits/stdc++.h"
using namespace std;

#define int long long
#define endl "\n"
#define tab "\t"
#define fastio ios_base::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL)
#define fi first
#define se second
#define pi pair<int, int>
#define maxpq priority_queue<int>
#define minpq priority_queue<int, vector<int>, greater<int>>
#define inf (int) (1e18)
#define vi vector<int>
#define vpi vector<pi>
#define sz(v) v.size()
#define for0(i, n) for(int i = 0; i < n; i++)
#define pb emplace_back
#define prec(n) fixed<<setprecision(n)
#define MOD (int) 1e9+7

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

//-----------------------------------> MAIN CODE <--------------------------------------------

void runtestcase()
{
    int n;
    cin >> n;
    cout << n + 1 << endl;
}


signed main()
{
    constructor();
    int tc = 1;
    cin >> tc;
    
    while(tc--)
      runtestcase();

    return 0;
}
