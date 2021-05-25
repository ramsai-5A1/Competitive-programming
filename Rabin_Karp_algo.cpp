#include "bits/stdc++.h"
using namespace std;


const int mod = (int)(1e9 + 7);
#define int long long


signed main()
{
    string s, pat;
    cin >> s >> pat;
    
    
    int patHash = 0, pr1 = 1, k = pat.length(), n = s.length();
    
    for(int i = 0; i < k; i++)
    {
        patHash = (patHash + ((pat[i] - 'a' + 1) * pr1) % mod) % mod;
        pr1 = (pr1 * 31) % mod;
    }
    
    int strHash = 0;
    pr1 = 1;
    
    for(int i = 0; i < k; i++)
    {
        strHash = (strHash + ((s[i] - 'a' + 1) * pr1) % mod) % mod;
        pr1 = (pr1 * 31) % mod;
    }
    
    int count = 0;
    
    if(patHash == strHash)
    {
        cout << 0 << endl;
        count++;
    }
    
    
    int left = 0, right = k, pr2 = 1;
    
    while(right < n)
    {
        strHash = (strHash - (((s[left] - 'a' + 1) * pr2) % mod) + mod) % mod;
        strHash = (strHash + ((s[right] - 'a' + 1) * pr1) % mod) % mod;
        pr2 = (pr2 * 31) % mod;
        pr1 = (pr1 * 31) % mod;
        
        left++;
        right++;
        
        patHash = (patHash * 31) % mod;
        
        if(strHash == patHash)
        {
            cout << left << endl;
            count++;
        }
    }
    
    cout << "Total: " << count << endl;
    
    return 0;
}
