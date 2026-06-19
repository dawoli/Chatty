#include<bits/stdc++.h>
using namespace std;
const int MAXN=100;
int poke[MAXN];
int arr[MAXN*MAXN];
int n,ans;
string str;
int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    //init
    for(int i='2';i<='9';i++)
        arr[i]=i-'0';
    arr['A']=1;
    arr['T']=10;
    arr['J']=11;
    arr['Q']=12;
    arr['K']=13;
    arr['D']=0*13;
    arr['C']=1*13;
    arr['H']=2*13;
    arr['S']=3*13;
    ans=52;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        cin>>str;
        int key=arr[str[0]]+arr[str[1]];
        if(poke[key]==0)
        {
            ans--;
            poke[key]=1;
        }
    }
    printf("%d",ans);
    return 0;
}

