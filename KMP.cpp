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


vector<int> KMP(string &pat, string &str)
{
	vector<int> ans;
	int n = str.length(), m = pat.length();
	str = pat + "$" + str;
	int len = 0, i = 1;
	vector<int> arr(n + m + 1, 0);


	while(i <= n + m)
	{
		if(str[i] == str[len])
		{
			len++;
			arr[i] = len;
			i++;
		}
		else
		{
			if(len != 0)
				len = arr[len - 1];
			else
			{
				arr[i] = len;
				i++;
			}
		}
	}


	for(i = m + 1; i <= n + m; i++)
	{
		int curr = i - (m + 1);
		if(arr[i] == m)
			ans.push_back(curr - (m - 1));
	}




	return ans;
}


void runtestcase()
{
    int n;
    while(cin >> n)
    {
    	string pat, str;
    	cin >> pat >> str;
    	vector<int> ans = KMP(pat, str);
    	for(int i: ans)
    		cout << i << endl;
    	cout << endl;
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
