#include<bits/stdc++.h>
using namespace std;

void sovea(int n)
{
    cout<<n/2;
    return ;
}
/*
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    bool problema=1;
    long long n,k;
    cin>>n>>k;
    vector<int> a(n+1,0);
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        if(a[i]!=1) problema=0;
    }
    if(problema) sovea(n);
    else cout<<2;
    return 0;
}*/

int ans;

bool check(vector<int> &choice)
{
    int n=choice.size();
    int now=0;
    for(int i=0;i<n;i++)
    {
        now+=choice[i];
        if(now>=2) return 0;
    }
    return 1;
}

void dfs(vector<int> &choice,vector<pair<int,int>> &ways,int nowat,int nowchoice)
{
    if(nowat==ways.size())
    {
        ans=max(nowchoice,ans);
        return ;
    }
    int one=ways[nowat].first,two=ways[nowat].second+1;
    choice[one]++;
    choice[two]--;
    if(check(choice))
    {
        dfs(choice,ways,nowat+1,nowchoice+1);
    }
    choice[one]--;
    choice[two]++;
    dfs(choice,ways,nowat+1,nowchoice);
}

int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    bool problema=1;
    int n,k;
    cin>>n>>k;
    vector<int> a(n+1,0);
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        if(a[i]!=1) problema=0;
        a[i]^=a[i-1];
    }
    if(problema and k==0) sovea(n);
    else
    {
    vector<pair<int,int>> ways;
    for(int i=1;i<=n;i++)
    {
        for(int j=i;j<=n;j++)
        {
            if((a[j]^a[i-1])==k)
                ways.push_back(make_pair(i,j));
        }
    }
    vector<int> choice(n+2,0);
    dfs(choice,ways,0,0);
    cout<<ans<<endl;
    }
    return 0;
}
