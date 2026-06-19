#include <bits/stdc++.h>
using namespace std;

bool cmp(int a,int b)
{
    return a>b;
}

int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin>>s;
    int n=s.size();
    int j=0;
    int a[n];
    for(int i=0;i<n;i++)
    {
        if(s[i]>='0'&&s[i]<='9')
        {
            a[j]=s[i]-'0';
            j++;
        }
    }
    sort(a,a+j,cmp);
    if(a[0]==0)
    {
        cout<<0;
        return 0;
    }
    else
    {
        for(int i=0;i<j;i++)
        {
            cout<<a[i];
        }
    }
    return 0;
}
