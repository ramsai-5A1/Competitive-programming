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
#define FOR(i, a, b) for(int i = a; i <= b; i++)
#define pb emplace_back
#define prec(n) fixed<<setprecision(n)
#define mod (int) 1e9+7

const int MAXN =  (int)((1e5) + 100);
int max(int a, int b) { if(a > b) return a; else return b;}
int min(int a, int b) { if(a > b) return b; else return a;}
int gcd(int a, int b) { if(a == 0) return b; return gcd(b%a, a);}

const int dx[4] = { 0, -1, 0, 1};
const int dy[4] = { -1, 0, 1, 0};
const int N = (int)(5 * 1e5 + 10);
vector<int> adj[N];
vector<int> fact(N);

int moduloExponentation(int base, int n, int M = mod)
{
    int ans = 1;
    while(n > 0)
    {
        if(n & 1)
        {
            ans = (ans * base) % M;
            n--;
        }
        else
        {
            base = (base * base) % M;
            n >>= 1;
        }
    }
    return ans;
}

int inverse(int n)
{
    return (moduloExponentation(n, mod - 2) % mod + mod) % mod;
}


int binomialCoeff(int n, int r)
{
    if(n < 0 || r < 0)
        return 0;
    return (((fact[n] * inverse(fact[r])) % mod * inverse(fact[n - r])) % mod + mod) % mod;
}


void constructor()
{
    fact[0] = 1;
    for(int i = 1; i < N; i++)
        fact[i] = (fact[i - 1] * i) % mod;
    
    fastio;
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
}

//-----------------------------------> MAIN CODE <--------------------------------------------

void runTestCase()
{
   
}


signed main()
{
    constructor();
    int tc = 1;
    cin >> tc;
    
    while(tc--)
      runTestCase();

    return 0;
}
