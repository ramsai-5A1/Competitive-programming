int nCr(int n, int r)
{
    int ans = 1, num = 1, den = 1;
    
    for(int i = 1; i <= r; i++)
    {
        num = (num * (n - i + 1));
        den = den * i;
    }
    
    ans = num/den;
    
    return ans;
}
