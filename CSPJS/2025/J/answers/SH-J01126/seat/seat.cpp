#include<bits/stdc++.h>
using namespace std;

bool cmp(int a,int b)
{
    return a>b;
}

int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    vector<int> sor(n*m+1,0);
    for(int i=1;i<=n*m;i++)
        cin>>sor[i];
    int rsor=sor[1];
    sort(sor.begin()+1,sor.end(),cmp);
    int rat=0;
    for(int i=1;i<=n*m;i++)
    {
        if(sor[i]==rsor)
        {
            rat=i;
            break;
        }
    }
    int lat=ceil(rat/double(m));
    int hat=rat%m;
    if(lat%2==0)
        hat=n-hat+1;
    cout<<lat<<' '<<(hat?hat:m)<<endl;
    return 0;
}
