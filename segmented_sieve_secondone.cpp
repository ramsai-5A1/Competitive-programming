#include "bits/stdc++.h"
using namespace std;

const int N = 1000000;
bool sieve[N + 1];

void fillSieve()
{
    for(int i = 2; i <= N; i++)
        sieve[i] = true;
        
    for(int i = 2; i * i <= N; i++)
    {
        if(sieve[i])
        {
            for(int j = i * i; j <= N; j += i)
                sieve[j] = false;
        }
    }
}



vector<int> givePrimes(int R)
{
    vector<int> primes;
    primes.push_back(2);
    
    for(int i = 3; i * i <= R; i += 2)
    {
        if(sieve[i])
            primes.push_back(i);
    }
    
    return primes;
}



signed main()
{
    fillSieve();
    int TC;
    cin >> TC;
    while(TC--)
    {
        int l, r;
        cin >> l >> r;
        
        bool seg[r - l + 1];
        for(int i = l; i <= r; i++)
            seg[i - l] = true;
            
        vector<int> primes = givePrimes(r);
        for(int ele: primes)
        {
            int firstM = (l / ele) * ele;
            firstM += (firstM < l) ? ele : 0;
            
            firstM = max(firstM, ele * ele);
            for(int i = firstM; i <= r; i += ele)
                seg[i - l] = false;
        }
        
        
        for(int i = l; i <= r; i++)
        {
            if(seg[i - l] && i > 1)
                cout << i << " ";
        }
        cout << endl;
    }
    return 0;
}
