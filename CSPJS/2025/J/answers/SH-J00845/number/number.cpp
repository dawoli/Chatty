#include <bits/stdc++.h>
using namespace std;

string s;
long long a[1000005];

bool cmp(int a,int b){
    return a>b;


}

int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    long long l=s.size();
    memset(a,-1,sizeof(a));
    s=' '+s;
    for(int i = 1;i<=l;i++)
    {
        if(s[i]>=48&&s[i]<=57)a[i]=s[i]-'0';
    }
    sort(a+1,a+l+1,cmp);
    for(int i = 1;i<=l;i++)
    {
        if(a[i]!=-1)cout<<a[i];
    }



    return 0;
}
