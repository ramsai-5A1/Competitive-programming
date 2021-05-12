#include <iostream>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <climits>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <string>
#include <queue>
#include <stack>
#include <deque>
#include <list>
#include <iterator>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <utility>
#include <functional>
#include <numeric>
#include <sstream>
#include <bitset>
#include <cstring>
 
 
using namespace std;
#define int long long
#define endl "\n"
#define fastio ios_base::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL);
 
 
const int N = 1e6 + 1;
bool isprime[N];
 
void normalsieve()
{
    memset(isprime, true, sizeof(isprime));
    isprime[1] = false;
 
    for(int i = 2; i*i < N; i++)
    {
        if(isprime[i])
        {
            for(int j = i*i; j < N; j += i)
                isprime[j] = false;
        }
    }
}
 
 
void segmentedsieve(int &n, int &m)
{
    bool arr[m - n + 1];
    memset(arr, true, sizeof(arr));
 
    vector<int> primes;
    primes.push_back(2);
 
    for(int i = 3; i*i <= m; i += 2)
    {
        if(isprime[i])
            primes.push_back(i);
    }
 
    for(int ele: primes)
    {
        int firstelement = (int)(n/ele) * ele;
 
        if(firstelement < n)
            firstelement += ele;
 
 
        for(int i = firstelement; i <= m; i += ele)
            arr[i - n] = false;
            
        if(firstelement == ele)
            arr[firstelement - n] = true;
    }
 
    for(int i = n; i <= m; i++)
    {
        if(arr[i - n] && i > 1)
            cout << i << endl;
    }
    cout<<endl;
}
 
 
void testcase()
{
    int n, m;
    cin >> n >> m;
    segmentedsieve(n, m);
}
 
 
signed main(){
 
 
    fastio
    normalsieve();
 
 
    int tc=1;
    cin >> tc;
    while(tc--)
    {
        testcase();
    }
    return 0;
}
 
