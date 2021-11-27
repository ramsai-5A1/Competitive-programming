#include <bits/stdc++.h>
using namespace std;


#define int long long
#define endl "\n"
#define tab "\t"
#define fastio ios_base::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL)
#define prec(n) fixed<<setprecision(n)

const int inf = (int) (1e18);
const int mod = (int) 1e9+7;
const int N = (int)(5 * 1e5 + 10);

//const int dx[4] = { 0, -1, 0, 1};
//const int dy[4] = { -1, 0, 1, 0};
//vector<int> adj[N];
vector<int> fact(N);


int gcd(int a, int b)
{
  if(b == 0)
    return a;
  return gcd(b, a % b);
}


bool isPalindrome(string &word)
{
  int left = 0, right = word.length() - 1;
  while(left < right)
  {
    if(word[left] != word[right])
      return false;
    left++, right--;
  }
  return true;
}


bool isPrime(int n)
{
  if(n <= 1)
    return false;
  else if(n <= 3)
    return true;
  else if(!(n & 1))
    return false;
  for(int i = 2; i * i <= n; i++)
    if(n % i == 0)
      return false;
  return true;
}


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
    //cin >> tc;
    
    while(tc--)
      runTestCase();

    return 0;
}
