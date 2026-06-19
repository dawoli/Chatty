#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string a;
    cin>>a;
    int numhave[10]={};
    int n=a.size();
    for(int i=0;i<n;i++)
    {
        if(a[i]>='0' and a[i]<='9')
            numhave[a[i]-'0']++;
    }
    for(int i=9;i>=0;i--)
    {
        while(numhave[i]--)
            cout<<i;
    }
    return 0;
}
