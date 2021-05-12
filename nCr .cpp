

#include "bits/stdc++.h"
using namespace std;

#define int unsigned long long
#define endl "\n"
#define debug(x) cout << #x << " " << x << endl

const int MOD = (int)(1e9 + 7);
const int N = (int)(1e6 + 1);
int fact[N];

void precompute()
{
    fact[0] = 1;
    for(int i = 1; i < N; i++)
        fact[i] = (i * fact[i - 1]) % MOD;
}


int power(int x, int n, int mod)
{
    int ans = 1;
    x = x % mod;
    
    while(n > 0)
    {
        if(n&1)
        {
            ans = (ans * x) % mod;
            n--;
        }
        else
        {
            x = (x * x) % mod;
            n >>= 1;
        }
    }
    
    return ans;
}

int nCr(int n, int r, int mod)
{
    int ans = 0;
    
    ans = fact[n];
    int den = (fact[r] * fact[n - r]) % mod;
    
    ans = (ans * power(den, mod - 2, mod)) % mod;
    
    return ans;
}


void testcase()
{
    int n, r, p;
    cin >> n >> r >> p;
    int ans = nCr(n, r, p);
    debug(ans);
}


signed main()
{
    precompute();
    int t;
    cin >> t;
    
    while(t--)
        testcase();
        
    return 0;
}
