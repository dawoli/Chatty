#include<bits/stdc++.h>
using namespace std;
int main()
{
    bool isPrime[1005]={};
    int n,prime[1005],psize=0;
    cin>>n;
    for(int i=2;i<=n;++i)
        isPrime[i]=true;
    for(int i=2;i<=n;++i)
    {
        if(isPrime[i])
            prime[++psize]=i;
        for(int j=1;j<=psize&&i*prime[j]<=n;++j)
        {
            isPrime[i*prime[j]]=false;
            if(i%prime[j]==0)
                break;
        }
    }
    for(int i=2;i<=n;++i)
    {
        if(isPrime[i])
            cout<<i<<endl;
    }
    return 0;
} 
