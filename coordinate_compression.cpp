void compress(long long arr[], long long N)
{
    set<long long> st;
    int timer = 1;
    
    for(long long int i = 0; i < N; i++)
        st.insert(arr[i]);
    
    map<long long, long long> Mpp;
    for(auto i: st)
    {
        Mpp[i] = timer;
        timer++;
    }
    
    for(long long int i = 0; i < N; i++)
        arr[i] = Mpp[arr[i]];
}
